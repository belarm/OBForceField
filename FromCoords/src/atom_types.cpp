#include "atom_types.h"

using namespace std;
using namespace glm;

Residue::Residue() {
	Transforms[0] = dmat4();
	Transforms[1] = dmat4();
	Transforms[2] = dmat4();
}

Residue::Residue(const Residue &obj) {
	memccpy(Transforms,obj.Transforms,3,sizeof(dvec3));
	code = obj.code;
	next = obj.next;
	atoms = vector<Atom *>();
	for(Atom *a : obj.atoms) {
		_lookup_atom.insert(pair<string,int>(a->Type(),atoms.size()));
		atoms.push_back(new Atom(a->atype,a->pos,this,a->t_offset));
	}
}

//Residue::Residue(char code, vector<Atom *>

void Residue::rot(dquat rotation, dvec3 pivot, int offset) {
	for(Atom *a : atoms) {
		if(a->t_offset >= offset) {
			cout << a->pos.x << " " << a->pos.y << " " << a->pos.z << endl;
			a->pos = rotation * (a->pos - pivot) + pivot;
			cout << a->pos.x << " " << a->pos.y << " " << a->pos.z << endl << endl;
		}
	}
}

void Residue::move(dvec3 move, int offset) {
	for(auto a : atoms) {
		if(a->t_offset >= offset) {
			a->Move(move);
		}
	}
}

dvec3 Residue::GetCACB() {
	int a = _lookup_atom["CB"];
	int b = _lookup_atom["CA"];
	return atoms[a]->pos - atoms[b]->pos;
}

void Residue::apply_transform(dmat4 transform, int offset) {
	for(Atom *a : atoms) {
		if(a->t_offset >= offset) {
		}
	}
	for(int i = offset;i<3;i++) {
		Transforms[i] = Transforms[i] * transform;
	}
}

char Residue::Code() { return code;}
string Residue::Lbl() { return CtoCode[code]; };

void Residue::MakeCIF(string filename, int model) {
	ofstream ofs = ofstream(filename,model > 1 ? ios::app : ios::out);
	if(model == 1) {
		
		ofs << "data_" << Lbl() << endl;
		ofs << "#" << endl;
		ofs << "_pdbx_nmr_ensemble.conformers_submitted_total_number\t2\n";
		ofs << "loop_\n";
		ofs << "_atom_site.label_comp_id\n";
		ofs << "_atom_site.id\n";
		ofs << "_atom_site.type_symbol\n";
		ofs << "_atom_site.Cartn_x\n";
		ofs << "_atom_site.Cartn_y\n";
		ofs << "_atom_site.Cartn_z\n";
		ofs << "_atom_site.pdbx_PDB_model_num\n";
	}
	for(auto a : atoms) {
		if(a->t_offset == 1) {
//		dvec3 pos = a->Pos();
		ofs << Lbl() << " ";
		ofs.width(4);
		ofs << left << a->atype << " ";
		ofs << a->element() << " ";
		ofs << a->pos.x << " ";
		ofs << a->pos.y << " ";
		ofs << a->pos.z << " ";
		ofs << model << endl;
		}
	}
//	ofs << "#";
	ofs.close();
}

Atom* Residue::Atom_by_code(string code) {
	return atoms[_lookup_atom[code]];
}

dvec3 Residue::GetBond(int b) {
	if(b > 1) {
		cout << "I don't have that many bonds\n";
		return dvec3();
	}
	return atoms[b+1]->pos - atoms[b]->pos;
}
	Atom::Atom(string _type, dvec3 _pos, Residue *_parent, int _transform) {
		Parent = _parent;
		t_offset = _transform;
		atype = _type;
		pos = _pos;
	}
	const string Atom::Type() { return atype; };
		
	string Atom::element() {
		if(atype.length() > 1 && atype[0] == 'S' && atype[1] == 'E')
			return "SE";
		return atype.substr(0,1);
	}
	
	void Atom::Move(dvec3 move) {
		pos += move;
	}
	
	Residue ResidueDB::load_from_CIF(char code, string file) {
		string name = CtoCode[code];
		string filename = "/home/belarm/source/ideal_ligands/" + file + ".cif";
		ifstream cif = ifstream(filename);
		if(!cif)
			cout << "FAILED" << endl;
		string line("");
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		getline(cif,line);
		string buf;
		string label;
		double x,y,z;
		vector<Atom *> atoms;
		Atom *cur;
		Residue ret;
		while(cif.peek() != EOF) {
			cif.ignore(4);
			cif >> label;
			cif >> buf;
			cif >> x;
			cif >> y;
			cif >> z;
			if(label != "HXT" && label != "OXT" && label != "H2") {
				if(label == "H" || label == "N")
					cur = new Atom(label,dvec3(x,y,z),&ret,0);
				else if (label == "C" || label == "O")
					cur = new Atom(label,dvec3(x,y,z),&ret,2);
				else 
					cur = new Atom(label,dvec3(x,y,z),&ret,1);
				atoms.push_back(cur);
			}
			getline(cif,buf);
		}
		return Residue(code,atoms);
	}
ResidueDB::ResidueDB()
{
	CtoCode = map<char,string>(
		{
			pair<char,string>('A', "ALA"),
			pair<char,string>('B', "ASX"),
			pair<char,string>('C', "CYS"),
			pair<char,string>('D', "ASP"),
			pair<char,string>('E', "GLU"),
			pair<char,string>('F', "PHE"),
			pair<char,string>('G', "GLY"),
			pair<char,string>('H', "HIS"),
			pair<char,string>('I', "ILE"),
			pair<char,string>('J', "XLE"),
			pair<char,string>('K', "LYS"),
			pair<char,string>('L', "LEU"),
			pair<char,string>('M', "MET"),
			pair<char,string>('N', "ASN"),
			pair<char,string>('O', "PYL"),
			pair<char,string>('P', "PRO"),
			pair<char,string>('Q', "GLN"),
			pair<char,string>('R', "ARG"),
			pair<char,string>('S', "SER"),
			pair<char,string>('T', "THR"),
			pair<char,string>('U', "SEC"),
			pair<char,string>('V', "VAL"),
			pair<char,string>('W', "TRP"),
			pair<char,string>('Y', "TRY"),
			pair<char,string>('Z', "GLX")
		}
	);
	
	cout << "LOADING RESIDUES\n";
	
	_db.insert(rpair('A',load_from_CIF('A',"ALA")));
	_db.insert(rpair('B',load_from_CIF('B',"ASX")));
	_db.insert(rpair('C',load_from_CIF('C',"CYS")));
	_db.insert(rpair('D',load_from_CIF('D',"ASP")));
	_db.insert(rpair('E',load_from_CIF('E',"GLU")));
	_db.insert(rpair('F',load_from_CIF('F',"PHE")));
	_db.insert(rpair('G',load_from_CIF('G',"GLY")));
	_db.insert(rpair('H',load_from_CIF('H',"HIS")));
	_db.insert(rpair('I',load_from_CIF('I',"ILE")));
	_db.insert(rpair('K',load_from_CIF('K',"LYS")));
	_db.insert(rpair('L',load_from_CIF('L',"LEU")));
	_db.insert(rpair('M',load_from_CIF('M',"MET")));
	_db.insert(rpair('N',load_from_CIF('N',"ASN")));
	_db.insert(rpair('O',load_from_CIF('O',"PYL")));
	_db.insert(rpair('P',load_from_CIF('P',"PRO")));
	_db.insert(rpair('Q',load_from_CIF('Q',"GLN")));
	_db.insert(rpair('R',load_from_CIF('R',"ARG")));
	_db.insert(rpair('S',load_from_CIF('S',"SER")));
	_db.insert(rpair('T',load_from_CIF('T',"THR")));
	_db.insert(rpair('U',load_from_CIF('U',"SEC")));
	_db.insert(rpair('V',load_from_CIF('V',"VAL")));
	_db.insert(rpair('W',load_from_CIF('W',"TRP")));
	_db.insert(rpair('Y',load_from_CIF('Y',"TRY")));
	_db.insert(rpair('Z',load_from_CIF('Z',"GLX")));
}

//
//string ResidueDB::Desc(Residue r) {
//	return CtoCode[r.Code()] + " @ " + to_string(r.Pos());
//}


Residue *ResidueDB::GetRes(char r) {
	return new Residue(_db[r]);
}