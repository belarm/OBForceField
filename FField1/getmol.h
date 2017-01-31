#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/generic.h>

using namespace OpenBabel;
OBMol *GetMol(const std::string &filename)
{
	OBMol *mol(new OBMol);
	OBConversion conv;
	OBFormat *format = conv.FormatFromExt(filename.c_str());
	conv.SetInFormat(format);
	conv.SetOutFormat("pdb");
	std::ifstream ifs(filename.c_str());
	conv.Read(mol, &ifs);
//	mol->AddHydrogens();
//	mol->ConnectTheDots();
//	conv.Write(mol,ofs);
	return mol;
}
