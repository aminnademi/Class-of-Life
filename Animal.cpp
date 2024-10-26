#include "includes/Animal.h"

using namespace std;

Animal::Animal(const vector<pair<string, string>> &chromosomeDNA) : Cell(chromosomeDNA) {}

double Animal::calculateGeneticSimilarity(const Animal &other) const
{
    int matches = 0;
    int total = 0;

    for (size_t i = 0; i < chromosomes.size(); i++)
    {
        string dna1_s1 = chromosomes[i].getDNA().first;
        string dna1_s2 = chromosomes[i].getDNA().second;
        string dna2_s1 = other.chromosomes[i].getDNA().first;
        string dna2_s2 = other.chromosomes[i].getDNA().second;

        for (size_t j = 0; j < dna1_s1.length(); j++)
        {
            if (dna1_s1[j] == dna2_s1[j])
            {
                matches++;
            }
            if (dna1_s2[j] == dna2_s2[j])
            {
                matches++;
            }
            total += 2;
        }
    }

    return (double(matches) / total) * 100;
}

bool Animal::operator==(const Animal &other) const
{
    if (chromosomes.size() != other.chromosomes.size())
        return false;

    return calculateGeneticSimilarity(other) > 70.0;
}