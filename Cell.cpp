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

bool Cell::checkForCellDeath()
{
    int mismatches = 0;
    int AT = 0, CG = 0;
    for (const auto &chromosome : chromosomes)
    {
        string dna1 = chromosome.getDNA().first;
        string dna2 = chromosome.getDNA().second;

        for (size_t i = 0; i < dna1.length(); i++)
        {
            char c1 = dna1[i];
            char c2 = dna2[i];

            if (!((c1 == 'A' && c2 == 'T') || (c1 == 'T' && c2 == 'A') ||
                  (c1 == 'C' && c2 == 'G') || (c1 == 'G' && c2 == 'C')))
            {
                mismatches++;
            }

            if ((c1 == 'A' && c2 == 'T') || (c1 == 'T' && c2 == 'A'))
            {
                AT++;
            }
            else if ((c1 == 'C' && c2 == 'G') || (c1 == 'G' && c2 == 'C'))
            {
                CG++;
            }
        }

        if (mismatches > 5 || AT > 3 * CG)
            return true;
    }

    return false;
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

void Cell::findComplementaryPalindromes(int m)
{
    int count = 0;
    string s1 = chromosomes[m].getDNA().first;
    string s2 = chromosomes[m].getDNA().second;

    for (size_t s = 0; s < s1.length(); s++)
    {
        for (size_t len = 3; s + len <= s1.length(); len++)
        {
            string subStr1 = s1.substr(s, len);
            string subStr2 = s2.substr(s, len);

            string reverseSubStr2(subStr2.rbegin(), subStr2.rend());

            if (subStr1 == reverseSubStr2)
            {
                cout << "Complementary palindrome found: " << subStr1 << "\n";
                count++;
            }
        }
    }

    if (count == 0)
        cout << "No complementary palindrome found!\n";
}