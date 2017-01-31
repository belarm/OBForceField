#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/generic.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/normalize_dot.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/normal.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "atom_types.h"
//#include "cifreader.h"

using namespace std;
using namespace glm;
//FIXME
dmat4x4 mk_transform(dvec3 ryz) {
	dmat4 rot_z = eulerAngleZ(ryz.z);
	dmat4 rot_y = eulerAngleY(ryz.y);
	dmat4 tlate = translate(dmat4(),dvec3(0,-1,0)*ryz.x);
	return rot_z * rot_y * tlate;
}

dvec3 get_spherical(dvec3 target, dvec3 source, dvec3 &lastNormal)
{
//		dvec3 new_v = get_vec3(ait);
//		dvec3 newbond = new_v - last_v;
		dvec3 newnorm = cross(target,source);
		dvec3 ret;
		ret.z = acos(normalizeDot(source,target));
		ret.y = orientedAngle(newnorm,normalize(lastNormal),normalize(target));
		ret.x = glm::length(source);
		lastNormal = newnorm;
		return ret;
}


int main(int argc, char *argv[])
{
	static ResidueDB RDB;
	ifstream ifs(argv[1]);
	string fasta;
	getline(ifs, fasta);
	fasta += "\n";
	string temp;
	vector<dvec3> spherical;
	spherical.push_back(dvec3(0,0,0));
	while(true) {
		getline(ifs,temp,'\t');
		if(ifs.eof())
			break;
		double x = stod(temp);
		getline(ifs,temp,'\t');
		double y = stod(temp);
		getline(ifs,temp,'\n');
		double z = stod(temp);
		spherical.push_back(dvec3(x,y,z));
	}
	vector<dmat4> transforms;
	dmat4 tform;
	for(auto it = spherical.begin();it != spherical.end();++it) {
		tform = tform * mk_transform(*it);
		transforms.push_back(tform);
	}
	ifs.close();
	Residue *r;
//	string filename = "lig .cif";

	for(char c = 'A';c<='Z';c++) {
		if(c == 'X' || c == 'J')
			continue;
		r = RDB.GetRes(c);
		r->MakeCIF(r->Lbl() + ".cif");
		cout << r->Lbl() << endl;
		dvec3 lastbond = dvec3(0,-1,0);
		dvec3 lastnorm = dvec3(0,0,1);
		dvec3 newbond = r->GetCACB();
		dquat rot = rotation(normalize(newbond),lastbond);
		cout << "CA-CB: " << to_string(newbond) << endl << endl;
		r->rot(rot);
		r->MakeCIF(r->Lbl() + "2.cif");
	}
	r = RDB.GetRes('A');
	return 0;
}
