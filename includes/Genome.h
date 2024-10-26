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

    void printGeneticContents() const;
    // A convenient method for displaying the full genetic information of an organism.

    string getRNA() const;
    // Retrieve the RNA strand to allow external access without exposing the internal representation for processing or mutation operations.

    pair<string, string> getDNA() const;
    /* Retrieve the DNA strands to allow external access to the DNA data
    without exposing the internal representation for processing or mutation operations. */

    string getCompFromRNA();
    // Computes and returns the complementary strand of the RNA using 'getCompStrand'.

    void smallMutation(char from, char to, int n);
    /* This method iterates through each base in the RNA & DNA. For each base in strands,
    when it encounters a base matching 'from', it replaces it with 'to' and increments the mutation count until it reaches 'n' mutations,
    ensuring the complementary base in the other DNA strand is updated to reflect the mutation. */

    void largeMutation(const string &S1, const string &S2);
    /* This method first searches for S1 in the RNA strand & replaces the first occurrence of S1 with S2.
    Next, it searches for S1 in the two DNA strands. If S1 is found in the first DNA strand,
    it replaces it with S2 and updates the second strand by replacing the same section with the complementary string of S2.
    If S1 is found in the second strand, the roles reverse. */

    void reverseMutation(const string &S1);
    /* This method locates S1 in the RNA strand. If found, it reverses the substring and replaces it.
    Then It searches for S1 in the DNA strands similarly.
    When S1 is found in the first strand, it reverses it and replaces the occurrence in the first strand
    while also reversing its complementary sequence in the second strand. The process is mirrored if S1 is found in the second strand. */
};

#endif