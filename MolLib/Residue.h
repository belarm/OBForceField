#ifndef RESIDUE_H
#define RESIDUE_H
#include <vector>
#include <string>
#include <map>
#include <glm/glm.hpp>

namespace belarmProteins
{
	using namespace std;
	using namespace glm;


	struct Atom {
		dvec3 pos;
		string type;
	public:
		string CifLine();
	};
	typedef struct Atom Atom;


	class Residue
	{
	public:
		string name;
		vector<Atom> sidechain;
		Atom N,CA,C,CB;
		string toString();
		Residue();
		~Residue();
//		Residue(char code, string file);
		void AddAtom(Atom a);
		void MakeCIF(string filename, int model = 1);
		
//		static map<char,string> CtoCode;
		void Transform(dmat4 tform);
//		void Residue::makePDB(string filename, bool append = false);
		
		static Residue GetRes(char c);
		static Residue GetRes(string s);

		static Residue ALA;
		static Residue ASX;
		static Residue CYS;
		static Residue ASP;
		static Residue GLU;
		static Residue PHE;
		static Residue GLY;
		static Residue HIS;
		static Residue ILE;
		static Residue LYS;
		static Residue LEU;
		static Residue MET;
		static Residue ASN;
		static Residue PYL;
		static Residue PRO;
		static Residue GLN;
		static Residue ARG;
		static Residue SER;
		static Residue THR;
		static Residue SEC;
		static Residue VAL;
		static Residue TRP;
		static Residue TRY;
		static Residue GLX;
	
	private:
		string PDBLine(Atom a);
		static map<char,Residue *> AAbyC;
		static map<string,Residue *> AAbyS;
		static Residue ResidueFromFile(string name);
	};
}
#include "Residue.cpp"
#endif // RESIDUE_H
