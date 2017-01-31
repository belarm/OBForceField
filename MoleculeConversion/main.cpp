#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/normalize_dot.hpp>
#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/obiter.h>

using namespace OpenBabel;
using namespace std;
using namespace glm;

OBMol *GetMol(const std::string &filename)
{
	OBMol *mol(new OBMol);
	OBConversion conv;
	OBFormat *format = conv.FormatFromExt(filename.c_str());
	conv.SetInFormat(format);
	conv.SetOutFormat("pdb");
	std::ifstream ifs(filename.c_str());
	conv.Read(mol, &ifs);
	conv.SetOutFormat("fasta");
	conv.AddOption("n");
	conv.Write(mol,&cout);
//	//Move molecule to origin for testing
//	vector3 shift = -mol->GetAtomById(0)->GetVector();
//	OBMolAtomIter ait(mol);
//	for(;ait;++ait) {
//		ait->SetVector(ait->GetVector() + shift);
//	}
//	mol->EndModify();
	return mol;
}

glm::dvec3 v2v3(vector3 in) {
	return dvec3(in.x(),in.y(),in.z());
}

dvec3 spherize(dvec3 &bond1, dvec3 &norm1, dvec3 &v1, dvec3 v2) {
	dvec3 bond2 = v2 - v1;
	dvec3 norm2 = cross(bond1,bond2);
	dvec3 ret;
	ret.x = length(bond2);
	ret.y = orientedAngle(normalize(norm2),normalize(norm1),normalize(bond1));
	ret.z = acos(normalizeDot(bond2,bond1));
	bond1 = bond2;
	norm1 = norm2;
	v1 = v2;
	return ret;
}

vector<dvec3> to_spherical(OBMol *mol) {
	vector<dvec3> ret;
	dvec3 lastbond = dvec3(0,-1,0);
	dvec3 lastnorm = dvec3(0,0,1);
	dvec3 last_v = v2v3(mol->GetAtomById(0)->GetVector());
	bool first = true;
	for(OBResidueIter res_iter(mol);res_iter;++res_iter) {
		OBResidueAtomIter atom(*res_iter);
		if(!first)
			ret.push_back(spherize(lastbond,lastnorm,last_v,v2v3((atom++)->GetVector())));
		else
			atom++;
		ret.push_back(spherize(lastbond,lastnorm,last_v,v2v3((atom++)->GetVector())));
		ret.push_back(spherize(lastbond,lastnorm,last_v,v2v3((atom)->GetVector())));
		first = false;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	OBMol *mol = GetMol(argv[1]);
	vector<dvec3> spherical = to_spherical(mol);
		dmat4 tform; //identity
	vector<dvec3>::iterator it;
	
	for(it = spherical.begin();it != spherical.end();++it) {
		cout << it->x << '\t';
		cout << it->y << '\t';
		cout << it->z << '\n';
	}
	return 0;
}