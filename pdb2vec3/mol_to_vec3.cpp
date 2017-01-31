#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace OpenBabel;

size_t get_mol_verts(string fname, double **points) {
	OBMol *mol(new OBMol);
	OBConversion conv;
	OBFormat *format = conv.FormatFromExt(fname);
	conv.SetInFormat(format);
	ifstream molfile(fname);
	if(!molfile) {
		cout << "Could not open file " << fname << endl;
	}
	if (!conv.Read(mol, &molfile)) {
		std::cout << "Could not read molecule from file " << fname << std::endl;
	}
	//conv.Read(mol,molfile);
	cout << "Got a molecule with " << mol->NumAtoms() << " atoms\n";
	(*points) = (double *)malloc(sizeof(double) * 3 * mol->NumAtoms());
	int i(0);
	for(OBMolAtomIter atom_iter(mol);atom_iter;atom_iter++) {
		cout << '.' << endl;
		(*points)[i++] = atom_iter->GetX();
		(*points)[i++] = atom_iter->GetY();
		(*points)[i++] = atom_iter->GetZ();
	}
	return i;
}