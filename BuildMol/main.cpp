//#include <stdio.h>
#include <iostream>
#include "../MolLib/Protein.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace belarmProteins;

int main(int argc, char **argv)
{
	Residue r = Residue::GetRes(argv[1]);
	r.MakeCIF(string(argv[1]) + "-out.cif");
//	r.N.pos += dvec3(0,.5,0);
	r.Transform(translate(dmat4(),dvec3(1,0,0)));
	r.MakeCIF(string(argv[1]) + "-out2.cif");
	
//	cout << Residue::AAbyS[argv[1]]->toString();
//	cout << Residue::ALA.toString() << endl;
//	Residue res('A',"ALA");
//	printf("hello world\n");
	return 0;
}
