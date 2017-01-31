#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;
using namespace glm;

vec4 _up(0,1,0,0);
vec4 _down(0,-1,0,0);
vec4 _left(-1,0,0,0);
vec4 _right(1,0,0,0);
vec4 _forward(0,0,1,0);
vec4 _back(0,0,-1,0);
//glm::dvec3 OpenBabel::OBMol::position(int idx) {
//	OpenBabel::OBAtom *a = this->GetAtomById()
//}


dmat4x4 mk_transform(dvec3 ryz) {
	dmat4 rot_z = eulerAngleZ(ryz.z);
	dmat4 rot_y = eulerAngleY(ryz.y);
	dmat4 tlate = translate(dmat4(),dvec3(0,-1,0)*ryz.x);
	return rot_y * rot_z * tlate;
//	return translate(eulerAngleZY(ryz.z,ryz.y),dvec3(0,1,0) * ryz.r);
}








dmat4x4 mk_transform(double r, double z_angle, double y_angle) {
	mat4 rot_z = eulerAngleZ(z_angle); // theta
	mat4 rot_y = eulerAngleY(y_angle); //p 
	mat4 tlate = translate(dmat4(),dvec3(0,-1,0) * r);
	return rot_y * rot_z * tlate;
//	return translate(eulerAngleZY(z_angle,y_angle),dvec3(0,1,0) * r);
}

//dmat4x4 mk_transform(dvec3 tl, double costheta, double cospsi) {
//	double sintheta = glm::sqrt(1 - costheta * costheta);
//	double sinpsi = glm::sqrt(1 - cospsi * cospsi);
//	return dmat4(costheta,0,-sintheta,0,
//				sintheta*sinpsi,cospsi,costheta*sinpsi,0,
//				sintheta*cospsi,-sinpsi,costheta*cospsi,0,
//				tl.x,tl.y,tl.z,1);
//}

void set_vec3(OBAtom *a, glm::vec3 p) {
	double *coords[] = {(double *)&p.x,(double *)&p.y,(double *)&p.z};
	a->SetCoordPtr(coords);
}
void set_vec3(OpenBabel::OBMolAtomIter a, glm::dvec4 p) {
	double *coords[] = {&p.x,&p.y,&p.z};
	a->SetCoordPtr(coords);
}

glm::dvec3 get_vec3(OBAtom *a) {
	return glm::dvec3(a->GetX(),a->GetY(),a->GetZ());
}
glm::dvec3 get_vec3(OpenBabel::OBMolAtomIter a) {
	return glm::dvec3(a->GetX(),a->GetY(),a->GetZ());
}


glm::vec3 get_vec3(double *coords) {
	glm::vec3 ret;
	ret.x = coords[0];
	ret.y = coords[1];
	ret.z = coords[2];
	cout << "Vector made" << endl;
	return ret;
}

glm::dvec4 v2v(vector3 in) {
	return dvec4(in.x(),in.y(),in.z(),1);
}
glm::dvec3 v2v3(vector3 in) {
	return dvec3(in.x(),in.y(),in.z());
}


glm::quat fromtwovectors(glm::vec3 u, glm::vec3 v)
{
	using namespace glm;
    float real_part = 1.0f + dot(u, v);
    vec3 w;
        w = cross(u, v);
    return normalize(quat(real_part, w.x, w.y, w.z));
}

