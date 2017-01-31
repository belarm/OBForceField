#ifndef PROTEIN_H
#define PROTEIN_H
#include "Residue.h"

namespace belarmProteins
{

class Protein
{
public:
	vector<Residue> residues;

	Protein();
	~Protein();

};

}
#include "Protein.cpp"
#endif // PROTEIN_H
