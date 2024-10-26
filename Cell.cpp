#include "Cell.h"

using namespace std;

Cell::Cell(const vector<pair<string, string>> &chromosomeDNA)
{
    for (const auto &dnaPair : chromosomeDNA)
        chromosomes.push_back(Genome(dnaPair.first, dnaPair.second));
}

void Cell::printChromosomeContents() const
{
    for (size_t i = 0; i < chromosomes.size(); i++)
    {
        cout << "Chromosome " << i + 1 << " - DNA Strand 1: " << chromosomes[i].getDNA().first << endl;
        cout << "Chromosome " << i + 1 << " - DNA Strand 2: " << chromosomes[i].getDNA().second << endl;
    }
}

vector<Genome> Cell::getChromosomes() const
{
    return chromosomes;
}


int Cell::count() const
{
    return chromosomes.size();
}