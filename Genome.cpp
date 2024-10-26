#include "includes\Genome.h"

using namespace std;

char Genome::getCompBase(char base)
{
    switch (base)
    {
    case 'A':
        return 'T';
    case 'T':
        return 'A';
    case 'C':
        return 'G';
    case 'G':
        return 'C';
    default:
        return '?';
    }
}

string Genome::getCompStrand(const string &strand)
{
    string comp;
    for (char base : strand)
        comp += getCompBase(base);

    return comp;
}

Genome::Genome() : RNA(""), DNA("", "") {}

Genome::Genome(const string &rna, const string &dna1, const string &dna2) : RNA(rna), DNA(dna1, dna2) {}

Genome::Genome(const string &dna1, const string &dna2) : DNA(dna1, dna2) {}

Genome::Genome(const string &rna) : RNA(rna) {}

void Genome::printGeneticContents() const
{
    cout << "RNA: " << RNA << endl;
    cout << "DNA Strand 1: " << DNA.first << endl;
    cout << "DNA Strand 2 (complementary): " << DNA.second << endl;
}

string Genome::getRNA() const
{
    return RNA;
}

pair<string, string> Genome::getDNA() const
{
    return DNA;
}

string Genome::getCompFromRNA()
{
    string comp = getCompStrand(RNA);
    return comp;
}