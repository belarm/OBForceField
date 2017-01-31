#ifndef _ATOM_TYPES_H
#define _ATOM_TYPES_H
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/normalize_dot.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/normal.hpp>

#include <string.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

#define _res(C,X) std::pair<char,Residue>((C),Residue((C),(X)))
using namespace std;
using namespace glm;
static std::map<char,string> CtoCode;


class Residue;

class Atom {
public:
	Residue *Parent;
	int t_offset;
	dvec3 pos;
	string atype;
	
//	Atom();
//	Atom(string _type);
//	Atom(string _type,dvec3 _pos);
//	Atom(string _type, double x, double y, double z);
//	Atom(string _type, double x, double y, double z, Residue *_parent, int _transform);
	Atom(string _type, dvec3 _pos, Residue *_parent, int _transform);
	const string Type();
//	dvec3 Pos();
//	string Lbl();
	string element();
//	static dvec3 getPos(const Atom &a);
	void Move(dvec3 translate);

private:
};

class Residue {
public:
	dmat4x4 Transforms[3];
	
	Residue();
	Residue(char rcode, std::vector<Atom> _atoms);
	Residue(const Residue &obj);
	bool Set(char rcode,std::vector<Atom> _atoms);
	void apply_transform(dmat4 transform, int offset = 0);
	dvec3 Pos();
	char Code();
	string Lbl();
	void MakeCIF(string filename, int model = 1);
	dvec3 GetBond(int b);
//	void rot(dquat rotation, int offset = 0);
	void rot(dquat rotation, dvec3 pivot = dvec3(), int offset = 0);

	void move(dvec3 rotation, int offset = 0);
	dvec3 GetCACB();
	dvec3 CAPos();
	Atom* Atom_by_code(string code);


private:
	
	char code;
	vector<Atom *> atoms;
	map<string,int> _lookup_atom;
	Residue *next;
	
};

typedef std::pair<char,Residue> rpair;

class ResidueDB {
private:
	std::map<char,Residue> _db;
	Residue load_from_CIF(char code, string file);
public:
	string Desc(Residue r);
	ResidueDB();
	Residue *GetRes(char r);
};


#endif