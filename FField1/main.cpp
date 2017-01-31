#include "getmol.h"
#include "util.h"
#include <math.h>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/normalize_dot.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/normal.hpp>
//#include <openbabel/obconversion.h>
//#include <openbabel/math/vector3.h>
using namespace OpenBabel;
using namespace std;
using namespace glm;

dvec3 get_spherical(dvec3 target, dvec3 source, dvec3 &lastNormal)
{
//		dvec3 new_v = get_vec3(ait);
//		dvec3 newbond = new_v - last_v;
		dvec3 newnorm = cross(target,source);
		dvec3 ret;
		ret.z = acos(normalizeDot(source,target));
		ret.y = orientedAngle(normalize(cross(target,source)),normalize(lastNormal),normalize(target));
		ret.x = glm::length(source);
		lastNormal = newnorm;
		return ret;
}




int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	
	
	OBMol *mol = GetMol(argv[1]);
	OBMol newmol;
	OBMolAtomIter ait(newmol);
	OBConversion convert;
	int lastCb = -1;
	std::ofstream *pdb = new std::ofstream("backbone.pdb");
	convert.SetOutFormat("fasta");
	cout << convert.WriteString(mol) << endl;
	
	newmol.Clear();
	for(OBResidueIter res_iter(mol);res_iter;res_iter++) {
		OBResidueAtomIter ater(*res_iter);
			newmol.AddAtom(*ater++);
			newmol.AddAtom(*ater++);
			newmol.AddAtom(*ater);
			lastCb = newmol.NumAtoms();
			newmol.AddBond(lastCb-1,lastCb,1);
			newmol.AddBond(lastCb-2,lastCb-1,1);
			if(lastCb > 3)
				newmol.AddBond(lastCb-3,lastCb-2,2);
	}
//	cout << newmol.NumAtoms() << endl;
	newmol.EndModify(true);
	convert.SetOutFormat("pdb");
	convert.Write(&newmol,pdb);
	((ofstream *)pdb)->close();
	
	
	dvec3 lastbond = dvec3(0,-1,0);
	dvec3 lastnorm = dvec3(0,0,1);
	dvec3 last_v = dvec3(0,0,0);
	vector<dvec3> spherical;

	for(ait = OBMolAtomIter(newmol), ait++; ait; ++ait) {
		dvec3 new_v = get_vec3(ait);
		dvec3 newbond = new_v - last_v;
		dvec3 sc = get_spherical(lastbond,newbond,lastnorm);
//		dvec3 newnorm = cross(lastbond,newbond);
//		double theta = acos(normalizeDot(newbond,lastbond));
//		double psi = orientedAngle(normalize(newnorm),normalize(lastnorm),normalize(lastbond));
//		double r = glm::length(newbond);
//		spherical.push_back(dvec3(r,psi,theta));
		spherical.push_back(sc);
//		cout << to_string(lastnorm) << endl;
//		cout << to_string(sc) << endl;
		lastbond = newbond;
//		lastnorm = newnorm;
		last_v = new_v;
	}
	dmat4 tform; //identity
	vector<dvec3>::iterator it;
	map<OBAtom *, vector<dvec3>::iterator> a2v;
	for(ait = OBMolAtomIter(newmol),ait++,it = spherical.begin();it != spherical.end();++it,++ait) {
		tform = tform * mk_transform(*it);
		dvec3 pos = dvec3(tform * dvec4(0,0,0,1));
		ait->SetVector(pos.x,pos.y,pos.z);
	}
	newmol.EndModify(true);

	pdb = new std::ofstream("generated.pdb");
	convert.Write(&newmol,pdb);
	((ofstream *)pdb)->close();
}