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

void Cell::largeMutation(const string &S1, int n, const string &S2, int m)
{
    chromosomes[n].largeMutation(S1, S2);
    chromosomes[m].largeMutation(S2, S1);
}

void Cell::smallMutation(char from, char to, int n, int m)
{
    chromosomes[m].smallMutation(from, to, n);
}

void Cell::reverseMutation(const string &S1, int n)
{
    chromosomes[n].reverseMutation(S1);
}