#include "Residue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/gtx/string_cast.hpp>
using namespace belarmProteins;
Residue::Residue(){
//	N.type = "N";
//	CA.type = "CA";
//	C.type = "C";
//	CB.type = "CB";
}

Residue::~Residue(){
}

string Residue::PDBLine(Atom a) {
	
//		sstream
	
//        ofs.width(6);
//       dvec3 pos = a.Pos();
       ofs << "ATOM  ";
       ofs.width(5);
       ofs << offset++ << ' ';
       ofs.width(5);
       ofs << left << a.type;
       ofs.width(4);
       ofs << Lbl();
//        ofs << ;
       ofs << right << " ";
       ofs.width(4);
       ofs << resid << "    ";
       ofs.width(8);
       ofs << fixed << setprecision(3) << pos.x;
       ofs.width(8);
       ofs << fixed << setprecision(3) << pos.y;
       ofs.width(8);
       ofs << fixed << setprecision(3) << pos.z;
       ofs.width(6);
       ofs << fixed << setprecision(2) << 1.0f;
       ofs.width(6);
       ofs << fixed << setprecision(2) << 1.0f;
       ofs.width(12);
       ofs << right << a.element();
//        ofs <<
//        ofs << code;
       ofs << endl;

}

string Atom::CifLine() {
		string ret;
		ret += " ";
//		ofs.width(4);
		ret += type + " ";
		ret += type.substr(0,1) + " ";
//		ofs << a.type[0] << " ";
		ret += to_string(pos.x);
		ret += " ";
		ret += to_string(pos.y);
		ret += " ";
		ret += to_string(pos.z);
		ret += " ";
		return ret;
}

string Residue::toString() {
	string ret(""); 
	ret += name + ":\n";
	ret += "N\t: " + to_string(N.pos) + "\n";
	ret += "CA\t: " + to_string(CA.pos) + "\n";
	ret += "C\t: " + to_string(C.pos) + "\n";
	ret += "CB\t: " + to_string(CB.pos) + "\n";
	for(Atom a : sidechain) 
		ret += a.type + "\t: " + to_string(a.pos) + "\n";
	return ret;
}

Residue Residue::ResidueFromFile(string name) {
//	string name = CtoCode[code];
	Residue ret;
	ret.name = name;
	string filename = "/home/belarm/source/ideal_ligands/" + name + ".cif";
	ifstream cif = ifstream(filename);
	if(!cif)
		cout << name + " FAILED" << endl;
	string line;
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
	Atom cur;
	while(cif.peek() != EOF) {
		cif.ignore(4);
		cif >> label;
		cif >> buf;
		cif >> x;
		cif >> y;
		cif >> z;
		if(label != "HXT" && label != "OXT" && label != "H2") {
			cur.type = label;
			cur.pos = dvec3(x,y,z);
			if(label == "N")
				ret.N = cur;
			else if (label == "CA")
				ret.CA = cur;
			else if (label == "C")
				ret.C = cur;
			else if (label == "CB")
				ret.CB = cur;
			else
				ret.AddAtom(cur);
		}
		getline(cif,buf);
	}
	return ret;
}

void Residue::AddAtom(Atom a) {
	sidechain.push_back(a);
}


Residue Residue::ALA = ResidueFromFile("ALA");
Residue Residue::ASX = ResidueFromFile("ASX");
Residue Residue::CYS = ResidueFromFile("CYS");
Residue Residue::ASP = ResidueFromFile("ASP");
Residue Residue::GLU = ResidueFromFile("GLU");
Residue Residue::PHE = ResidueFromFile("PHE");
Residue Residue::GLY = ResidueFromFile("GLY");
Residue Residue::HIS = ResidueFromFile("HIS");
Residue Residue::ILE = ResidueFromFile("ILE");
//Residue Residue::XLE = ResidueFromFile("XLE");
Residue Residue::LYS = ResidueFromFile("LYS");
Residue Residue::LEU = ResidueFromFile("LEU");
Residue Residue::MET = ResidueFromFile("MET");
Residue Residue::ASN = ResidueFromFile("ASN");
Residue Residue::PYL = ResidueFromFile("PYL");
Residue Residue::PRO = ResidueFromFile("PRO");
Residue Residue::GLN = ResidueFromFile("GLN");
Residue Residue::ARG = ResidueFromFile("ARG");
Residue Residue::SER = ResidueFromFile("SER");
Residue Residue::THR = ResidueFromFile("THR");
Residue Residue::SEC = ResidueFromFile("SEC");
Residue Residue::VAL = ResidueFromFile("VAL");
Residue Residue::TRP = ResidueFromFile("TRP");
Residue Residue::TRY = ResidueFromFile("TRY");
Residue Residue::GLX = ResidueFromFile("GLX");
//map<string,Residue *> Residue::AAbyS;
map<string,Residue *> Residue::AAbyS = {
	{ "ALA", &Residue::ALA },
	{ "ASX", &Residue::ASX },
	{ "CYS", &Residue::CYS },
	{ "ASP", &Residue::ASP },
	{ "GLU", &Residue::GLU },
	{ "PHE", &Residue::PHE },
	{ "GLY", &Residue::GLY },
	{ "HIS", &Residue::HIS },
	{ "ILE", &Residue::ILE },
	//{ "XLE", &Residue::XLE },
	{ "LYS", &Residue::LYS },
	{ "LEU", &Residue::LEU },
	{ "MET", &Residue::MET },
	{ "ASN", &Residue::ASN },
	{ "PYL", &Residue::PYL },
	{ "PRO", &Residue::PRO },
	{ "GLN", &Residue::GLN },
	{ "ARG", &Residue::ARG },
	{ "SER", &Residue::SER },
	{ "THR", &Residue::THR },
	{ "SEC", &Residue::SEC },
	{ "VAL", &Residue::VAL },
	{ "TRP", &Residue::TRP },
	{ "TRY", &Residue::TRY },
	{ "GLX", &Residue::GLX }
};

map<char,Residue *> Residue::AAbyC = {
	{ 'A',&Residue::ALA },
	{ 'B',&Residue::ASX },
	{ 'C',&Residue::CYS },
	{ 'D',&Residue::ASP },
	{ 'E',&Residue::GLU },
	{ 'F',&Residue::PHE },
	{ 'G',&Residue::GLY },
	{ 'H',&Residue::HIS },
	{ 'I',&Residue::ILE },
	{ 'K',&Residue::LYS },
	{ 'L',&Residue::LEU },
	{ 'M',&Residue::MET },
	{ 'N',&Residue::ASN },
	{ 'O',&Residue::PYL },
	{ 'P',&Residue::PRO },
	{ 'Q',&Residue::GLN },
	{ 'R',&Residue::ARG },
	{ 'S',&Residue::SER },
	{ 'T',&Residue::THR },
	{ 'U',&Residue::SEC },
	{ 'V',&Residue::VAL },
	{ 'W',&Residue::TRP },
	{ 'Y',&Residue::TRY },
	{ 'Z',&Residue::GLX }
};

Residue Residue::GetRes(char c) {
	return *AAbyC[c];
}
Residue Residue::GetRes(string s) {
	return *AAbyS[s];
}

void Residue::MakeCIF(string filename, int model) {
	ofstream ofs = ofstream(filename,model > 1 ? ios::app : ios::out);
	if(model == 1) {
		
		ofs << "data_" << name << endl;
		ofs << "#" << endl;
//		ofs << "_pdbx_nmr_ensemble.conformers_submitted_total_number\t2\n";
		ofs << "loop_\n";
		ofs << "_atom_site.label_comp_id\n";
		ofs << "_atom_site.id\n";
		ofs << "_atom_site.type_symbol\n";
		ofs << "_atom_site.Cartn_x\n";
		ofs << "_atom_site.Cartn_y\n";
		ofs << "_atom_site.Cartn_z\n";
		ofs << "_atom_site.pdbx_PDB_model_num\n";
	}
		ofs << name << N.CifLine() << model << endl;
		ofs << name << C.CifLine() << model << endl;
		ofs << name << CA.CifLine() << model << endl;
		ofs << name << CB.CifLine() << model << endl;
	for(Atom a : sidechain) {
		ofs << name << a.CifLine() << model << endl;
		
//		
////		if(a.t_offset == 1) {
////		dvec3 pos = a->Pos();
//		ofs << name << " ";
//		ofs.width(4);
//		ofs << left << a.type << " ";
////		ofs << a.type[0] << " ";
//		ofs << a.pos.x << " ";
//		ofs << a.pos.y << " ";
//		ofs << a.pos.z << " ";
//		ofs << model << endl;
////		}
	}
//	ofs << "#";
	ofs.close();
}


void Residue::Transform(dmat4 tform) {
	N.pos = tform * dvec4(N.pos,1);
	CA.pos = tform * dvec4(CA.pos,1);
	C.pos = tform * dvec4(C.pos,1);
	CB.pos = tform * dvec4(CB.pos,1);
	for(Atom &a : sidechain) {
		cout << to_string(a.pos) << endl;;
		a.pos = tform * dvec4(a.pos,1);
		cout << to_string(a.pos) << endl;
	}
}