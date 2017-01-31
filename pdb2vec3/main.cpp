#include <iostream>


using namespace std;

extern size_t get_mol_verts(string fname, double *points[]);
int main(int argc, char **argv)
{
	double *verts;
	int nverts = get_mol_verts(argv[1],&verts);
	cout << "Got " << nverts << " Vertices\n";
	for(int i(0);i<nverts;) {
		cout << '(' << verts[i++]
			  << ',' << verts[i++]
			  << ',' << verts[i++]
			  << ")\n";
	}
	free(verts);
}
