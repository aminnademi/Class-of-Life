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

Animal Animal::asexualReproduction()
{
    vector<Genome> doubledChromosomes = chromosomes;

    for (const auto &chromosome : chromosomes)
        doubledChromosomes.push_back(chromosome);

    vector<pair<string, string>> selectedChromosomes;
    double similarity = 0.0;

    while (similarity <= 70.0)
    {
        selectedChromosomes.clear();
        for (size_t i = 0; i < chromosomes.size(); i++)
        {
            int idx = rand() % doubledChromosomes.size();
            string s1 = doubledChromosomes[idx].getDNA().first;
            string s2 = doubledChromosomes[idx].getDNA().second;
            selectedChromosomes.push_back({s1, s2});
        }
        similarity = calculateGeneticSimilarity(Animal(selectedChromosomes));
    }

    Animal offspring = Animal(selectedChromosomes);

    return offspring;
}

Animal Animal::operator+(Animal &other)
{
    Animal offspring1 = this->asexualReproduction();
    Animal offspring2 = other.asexualReproduction();

    vector<pair<string, string>> combinedChromosomes;
    double similarity1 = 0.0;
    double similarity2 = 0.0;

    while (similarity1 <= 70.0 && similarity2 <= 70.0)
    {
        combinedChromosomes.clear();

        for (size_t i = 0; i < offspring1.chromosomes.size() / 2; i++)
        {
            int idx = rand() % offspring1.chromosomes.size();
            string s1 = offspring1.chromosomes[idx].getDNA().first;
            string s2 = offspring1.chromosomes[idx].getDNA().second;
            combinedChromosomes.push_back({s1, s2});
        }

        for (size_t i = 0; i < offspring2.chromosomes.size() / 2; i++)
        {
            int idx = rand() % offspring2.chromosomes.size();
            string s1 = offspring2.chromosomes[idx].getDNA().first;
            string s2 = offspring2.chromosomes[idx].getDNA().second;
            combinedChromosomes.push_back({s1, s2});
        }

        Animal child = Animal(combinedChromosomes);
        similarity1 = this->calculateGeneticSimilarity(child);
        similarity2 = other.calculateGeneticSimilarity(child);
    }

    Animal child = Animal(combinedChromosomes);
    return child;
}

void Animal::checkChromosomesForIssues()
{
    for (int i = chromosomes.size() - 1; i >= 0; i--)
    {
        const Genome &chromosome = chromosomes[i];

        string dna1 = chromosome.getDNA().first;
        string dna2 = chromosome.getDNA().second;

        int mismatches = 0;
        int AT = 0, CG = 0;

        for (size_t j = 0; j < dna1.length(); j++)
        {
            char c1 = dna1[j];
            char c2 = dna2[j];

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
            chromosomes.erase(chromosomes.begin() + i);
    }
}

string Virus::findLCS(const vector<string> &strs)
{
    if (strs.empty())
        return "";

    string LCS = strs[0];

    for (size_t i = 1; i < strs.size(); i++)
    {
        string currStr = strs[i];
        string commonSubstr = "";

        for (size_t len = 1; len <= LCS.size(); len++)
        {
            for (size_t s = 0; s <= LCS.size() - len; s++)
            {
                string substr = LCS.substr(s, len);
                if (currStr.find(substr) != string::npos)
                {
                    commonSubstr = substr;
                }
            }
        }

        LCS = commonSubstr;

        if (LCS.length() <= 2)
        {
            return "";
            break;
        }
    }

    return LCS;
}

Virus::Virus(const string &rna) : viralRNA(rna) {}

string Virus::getRNA() const
{
    return viralRNA.getRNA();
}

bool Virus::isHarmful(const Animal &animal)
{
    vector<string> allChromosomes;

    for (const auto &chromosome : animal.getChromosomes())
    {
        string strand1 = chromosome.getDNA().first;
        string strand2 = chromosome.getDNA().second;
        allChromosomes.push_back(strand1);
        allChromosomes.push_back(strand2);
    }

    string LCS = findLCS(allChromosomes);
    if (LCS == "")
    {
        cout << "no Largest common substing found in desired animal chromosomes\n";
        return false;
    }
    else
    {
        cout << "Largest common substring: " << LCS << endl;

        return (viralRNA.getRNA().find(LCS) != string::npos || viralRNA.getCompFromRNA().find(LCS) != string::npos);
    }
}