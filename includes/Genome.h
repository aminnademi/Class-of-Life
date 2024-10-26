#ifndef GENOME_H
#define GENOME_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Genome
{
private:
    string RNA;
    pair<string, string> DNA;

    char getCompBase(char base);
    // Helper function to get the complementary base by the biology rules.

    string getCompStrand(const string &strand);
    // Helper function to create the complementary string for a given strand using 'getCompBase'. 

public:
    Genome();
    // Default Constructor

    Genome(const string &rna, const string &dnaStrand1, const string &dnaStrand2);
    // Alternate constructor to initialize RNA and DNA

    Genome(const string &dnaStrand1, const string &dnaStrand2);
    // Alternate constructor for DNA-only initialization (used in Cell)

    Genome(const string &rna);
    // Alternate constructor for RNA-only initialization (used in Virus)
};

#endif