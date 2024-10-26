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

    Animal asexualReproduction();
    /* This method implements asexual reproduction by duplicating the chromosomes
    and creating a new Animal from a random selection of these duplicated chromosomes.
    It ensures that the resulting offspring has a genetic similarity of more than 70% with its parent.
    This method uses a loop to randomly select chromosomes and calculates the genetic similarity
    until the desired threshold is met, simulating a natural reproduction process. */

    Animal operator+(Animal &other);
    /* Overloads the + operator to facilitate sexual reproduction between two Animal objects.
    It performs asexual reproduction on both parents to generate two offspring,
    then randomly selects half of the chromosomes from each offspring to create a new child.
    It checks the genetic similarity of the child against both parents to ensure it exceeds 70%. */
};

#endif