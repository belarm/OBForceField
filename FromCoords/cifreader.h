Residue read_CIF(string filename) {
	ifstream cif = ifstream(filename);
	string line("");
	while(line.substr(0,28) != "_chem_comp_atom.pdbx_ordinal") {
		getline(cif,line);
	}
//	getline(cif,line);
	string buf;
	string label;
	double x,y,z;
	char element;
	vector<Atom> atoms;
	while(cif.peek() != '#') {
//		getline(cif,line);
//		cout << line;
		cif.ignore(4);
		cif >> label;
		cif >> buf;
		cif >> element;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> buf;
		cif >> x;
		cif >> y;
		cif >> z;
		atoms.push_back(Atom(label,x,y,z));
		getline(cif,buf);
	}
	return Residue('K',atoms);
}