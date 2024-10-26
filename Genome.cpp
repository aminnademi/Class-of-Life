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

void Genome::smallMutation(char from, char to, int n)
{
    int count = 0;
    for (char &base : RNA)
    {
        if (base == from && count < n)
        {
            base = to;
            count++;
        }
    }

    count = 0;

    for (int i = 0; i < DNA.first.length(); i++)
    {
        if (DNA.first[i] == from && count < n)
        {
            DNA.first[i] = to;
            DNA.second[i] = getCompBase(to);
            count++;
        }
        else if (DNA.second[i] == from && count < n)
        {
            DNA.second[i] = to;
            DNA.first[i] = getCompBase(to);
            count++;
        }
    }
}

void Genome::largeMutation(const string &S1, const string &S2)
{
    size_t rnaPos = RNA.find(S1);

    if (rnaPos != string::npos)
        RNA.replace(rnaPos, S1.length(), S2);

    size_t dna1Pos = DNA.first.find(S1);
    size_t dna2Pos = DNA.second.find(S1);

    if (dna1Pos != string::npos)
    {
        DNA.first.replace(dna1Pos, S1.length(), S2);
        string comp = getCompStrand(S2);
        DNA.second.replace(dna1Pos, S1.length(), comp);
    }
    else
    {
        DNA.second.replace(dna2Pos, S1.length(), S2);
        string comp = getCompStrand(S2);
        DNA.first.replace(dna2Pos, S1.length(), comp);
    }
}

void Genome::reverseMutation(const string &S1)
{

    string newS1 = S1;
    size_t rnaPos = RNA.find(S1);

    if (rnaPos != string::npos)
    {
        reverse(newS1.begin(), newS1.end());
        RNA.replace(rnaPos, S1.length(), newS1);
    }

    size_t dna1Pos = DNA.first.find(S1);
    size_t dna2Pos = DNA.second.find(S1);

    if (dna1Pos != string::npos)
    {
        string newS1 = S1;
        reverse(newS1.begin(), newS1.end());
        DNA.first.replace(dna1Pos, S1.length(), newS1);

        string comp = getCompStrand(S1);
        reverse(comp.begin(), comp.end());
        DNA.second.replace(dna1Pos, S1.length(), comp);
    }
    else
    {
        string newS1 = S1;
        reverse(newS1.begin(), newS1.end());
        DNA.second.replace(dna2Pos, S1.length(), newS1);

        string comp = getCompStrand(S1);
        reverse(comp.begin(), comp.end());
        DNA.first.replace(dna2Pos, S1.length(), comp);
    }
}