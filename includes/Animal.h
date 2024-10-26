#ifndef ANIMAL_H
#define ANIMAL_H

#include "Cell.h"
#include <random>

using namespace std;

class Animal : public Cell
{
public:
    Animal(const vector<pair<string, string>> &chromosomeDNA);
    /* Initializes the Animal object with the provided chromosome DNA pairs 
    by calling the constructor of the Cell class,which handles the chromosome storage. */

    double calculateGeneticSimilarity(const Animal &other) const;
    /* This method counts matching chromosomes across both strands 
    and divides that count by the total number of positions to return a similarity percentage. */

    bool operator==(const Animal &other) const;
    /* Overloads the equality operator to determine if two Animal objects are of the same species.
    It first checks if the number of chromosomes is identical,
    and then it uses the calculateGeneticSimilarity method to see if the genetic similarity exceeds 70%.*/
};

#endif