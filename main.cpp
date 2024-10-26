#include "includes/Genome.h"
#include "includes/Cell.h"
#include "includes/Animal.h"

using namespace std;

void displayMenu()
{
    cout << "\n====== Genetic Simulation Menu ======\n";
    cout << "1. Genome Operations\n";
    cout << "2. Cell Operations\n";
    cout << "3. Animal Operations\n";
    cout << "4. Virus Operations\n";
    cout << "5. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void displayGenomeMenu()
{
    cout << "\n====== Genome Operations ======\n";
    cout << "1. Create Genome (DNA and RNA)\n";
    cout << "2. Print Complement from RNA\n";
    cout << "3. Perform Small Mutation on Genome\n";
    cout << "4. Perform Large Mutation on Genome\n";
    cout << "5. Perform Reverse Mutation on Genome\n";
    cout << "6. Display Created Genomes\n";
    cout << "7. Back\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void displayCellMenu()
{
    cout << "\n====== Cell Operations ======\n";
    cout << "1. Create Cell (Chromosomes)\n";
    cout << "2. Perform Cell Death Check\n";
    cout << "3. Perform Large Mutation on Chromosome\n";
    cout << "4. Perform Small Mutation on Chromosome\n";
    cout << "5. Perform Reverse Mutation on Chromosome\n";
    cout << "6. Find Complementary Palindromes in a Chromosome\n";
    cout << "7. Display Created Cells\n";
    cout << "8. Back\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void displayAnimalMenu()
{
    cout << "\n====== Animal Operations ======\n";
    cout << "1. Create Animal (Chromosomes)\n";
    cout << "2. Check Genetic Similarity between Animals\n";
    cout << "3. Check If 2 Animals Are from A Same Species\n";
    cout << "4. Asexual Reproduction\n";
    cout << "5. Sexual Reproduction (+ operator)\n";
    cout << "6. Delete Prolematic Chromosomes\n";
    cout << "7. Display Created Animals\n";
    cout << "8. Back\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void displayVirusMenu()
{
    cout << "\n====== Virus Operations ======\n";
    cout << "1. Create Virus (RNA)\n";
    cout << "2. Check if Virus is Harmful to Animal\n";
    cout << "3. Display Created Viruses\n";
    cout << "4. Back\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

void displayGenomes(const vector<Genome> &genomes)
{
    if (genomes.empty())
    {
        cout << "\nNo genomes created yet.\n";
        return;
    }

    int i = 0;
    cout << "\n====== List of Genomes ======\n";
    for (const auto &genome : genomes)
    {
        cout << "Genome " << i + 1 << ": \n";
        genome.printGeneticContents();
        i++;
    }
    cout << "=====================================\n";
}

void displayCells(const vector<Cell> &cells)
{
    if (cells.empty())
    {
        cout << "\nNo cells created yet.\n";
        return;
    }

    int i = 0;
    cout << "\n====== List of Cells ======\n";
    for (const auto &cell : cells)
    {
        cout << "Cell " << i + 1 << ": \n";
        cell.printChromosomeContents();
        i++;
    }
    cout << "=====================================\n";
}

void displayAnimals(const vector<Animal> &animals)
{
    if (animals.empty())
    {
        cout << "\nNo animals created yet.\n";
        return;
    }

    int i = 0;
    cout << "\n====== List of Animals ======\n";
    for (const auto &animal : animals)
    {
        cout << "Animal " << i + 1 << ": \n";
        animal.printChromosomeContents();
        i++;
    }
    cout << "=====================================\n";
}

void displayViruses(const vector<Virus> &viruses)
{
    if (viruses.empty())
    {
        cout << "\nNo viruses created yet.\n";
        return;
    }

    int i = 0;
    cout << "\n====== List of Viruses ======\n";
    for (const auto &virus : viruses)
    {
        cout << "Virus " << i + 1 << ": RNA: " << virus.getRNA() << "\n";
        i++;
    }
    cout << "=====================================\n";
}

void createGenome(vector<Genome> &genomes)
{
    string rna, dna1, dna2;
    cout << "Enter RNA strand: ";
    cin >> rna;
    cout << "Enter DNA strand 1: ";
    cin >> dna1;
    cout << "Enter DNA strand 2: ";
    cin >> dna2;
    genomes.push_back(Genome(rna, dna1, dna2));
    cout << "Genome created successfully.\n";
}

void createCell(vector<Cell> &cells)
{
    int n;
    cout << "Enter number of chromosomes for the cell: ";
    cin >> n;

    vector<pair<string, string>> data;

    for (int i = 0; i < n; i++)
    {
        string dna1, dna2;
        cout << "Enter DNA strand 1 for chromosome " << i + 1 << ": ";
        cin >> dna1;
        cout << "Enter DNA strand 2 for chromosome " << i + 1 << ": ";
        cin >> dna2;
        data.push_back(make_pair(dna1, dna2));
    }

    cells.push_back(Cell(data));
    cout << "Cell created successfully.\n";
}

void createAnimal(vector<Animal> &animals)
{
    int n;
    cout << "Enter number of chromosomes for the animal: ";
    cin >> n;

    vector<pair<string, string>> data;

    for (int i = 0; i < n; i++)
    {
        string dna1, dna2;
        cout << "Enter DNA strand 1 for chromosome " << i + 1 << ": ";
        cin >> dna1;
        cout << "Enter DNA strand 2 for chromosome " << i + 1 << ": ";
        cin >> dna2;
        data.push_back(make_pair(dna1, dna2));
    }

    animals.push_back(Animal(data));
    cout << "Animal created successfully.\n";
}

void createVirus(vector<Virus> &viruses)
{
    string rna;
    cout << "Enter RNA strand for the virus: ";
    cin >> rna;
    viruses.push_back(Virus(rna));
    cout << "Virus created successfully.\n";
}

void complementFromRNA(vector<Genome> &genomes)
{
    displayGenomes(genomes);

    int idx;
    cout << "Select Genome index: ";
    cin >> idx;

    if (idx <= 0 || idx > genomes.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    cout << "RNA Complement: " << genomes[idx - 1].getCompFromRNA() << "\n";
}

void smallMutationOnGenome(vector<Genome> &genomes)
{
    displayGenomes(genomes);

    int idx, n;
    char from, to;

    cout << "Select Genome index: ";
    cin >> idx;

    if (idx <= 0 || idx > genomes.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    cout << "Enter character to replace: ";
    cin >> from;
    cout << "Enter replacement character: ";
    cin >> to;
    cout << "Enter number of replacements: ";
    cin >> n;

    string rna = genomes[idx - 1].getRNA();
    string dna1 = genomes[idx - 1].getDNA().first;
    string dna2 = genomes[idx - 1].getDNA().second;

    if (count(rna.begin(), rna.end(), from) < n)
    {
        cout << "Invalid number of replacements for RNA, Try Again!\n";
        return;
    }
    else if (count(dna1.begin(), dna1.end(), from) + count(dna2.begin(), dna2.end(), from) < n)
    {
        cout << "Invalid number of replacements for DNA, Try Again!\n";
        return;
    }
    else
    {
        genomes[idx - 1].smallMutation(from, to, n);
        cout << "Small mutation applied.\n";
    }
}

void largeMutationOnGenome(vector<Genome> &genomes)
{
    displayGenomes(genomes);

    int idx;
    string s1, s2;

    cout << "Select Genome index: ";
    cin >> idx;

    if (idx <= 0 || idx > genomes.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    cout << "Enter the substring to replace: ";
    cin >> s1;
    cout << "Enter the replacement substring: ";
    cin >> s2;

    string rna = genomes[idx - 1].getRNA();
    string dna1 = genomes[idx - 1].getDNA().first;
    string dna2 = genomes[idx - 1].getDNA().second;

    size_t rna_pos = rna.find(s1);
    size_t dna1_pos = dna1.find(s1);
    size_t dna2_pos = dna2.find(s1);

    if (rna_pos == string::npos)
    {
        cout << "Substring not found in desired RNA, Try Again!\n";
        return;
    }
    else if (dna1_pos == string::npos && dna2_pos == string::npos)
    {
        cout << "Substring not found in desired DNA, Try Again!\n";
        return;
    }
    else
    {
        genomes[idx - 1].largeMutation(s1, s2);
        cout << "Large mutation applied.\n";
    }
}

void reverseMutationOnGenome(vector<Genome> &genomes)
{
    displayGenomes(genomes);

    int idx;
    string s1;

    cout << "Select Genome index: ";
    cin >> idx;

    if (idx <= 0 || idx > genomes.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    cout << "Enter the substring to reverse: ";
    cin >> s1;

    string rna = genomes[idx - 1].getRNA();
    string dna1 = genomes[idx - 1].getDNA().first;
    string dna2 = genomes[idx - 1].getDNA().second;

    size_t rna_pos = rna.find(s1);
    size_t dna1_pos = dna1.find(s1);
    size_t dna2_pos = dna2.find(s1);

    if (rna_pos == string::npos)
    {
        cout << "Substring did not found in desired RNA, Try Again!\n";
        return;
    }
    else if (dna1_pos == string::npos && dna2_pos == string::npos)
    {
        cout << "Substring did not found in desired DNA, Try Again!\n";
        return;
    }
    else
    {
        genomes[idx - 1].reverseMutation(s1);
        cout << "Reverse mutation applied.\n";
    }
}

void checkCellDeath(vector<Cell> &cells)
{
    displayCells(cells);

    int idx;
    cout << "Select Cell index: ";
    cin >> idx;

    if (idx <= 0 || idx > cells.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    if (cells[idx - 1].checkForCellDeath())
    {
        cout << "Cell death triggered due to chromosome issues.\n";
        cells.erase(cells.begin() + idx - 1);
    }
    else
    {
        cout << "Cell is healthy.\n";
    }
}

void largeMutationOnCell(vector<Cell> &cells)
{
    displayCells(cells);

    int idx, n, m;
    string s1, s2;

    cout << "Enter the cell index: ";
    cin >> idx;

    if (idx <= 0 || idx > cells.size())
    {
        cout << "Invalid cell index.\n";
        return;
    }

    int chromosomeCount = cells[idx - 1].count();
    cout << "Enter the first chromosome index (n): ";
    cin >> n;
    cout << "Enter the second chromosome index (m): ";
    cin >> m;

    if (n <= 0 || n > chromosomeCount || m <= 0 || m > chromosomeCount)
    {
        cout << "Invalid chromosome index (indices).\n";
        return;
    }

    vector<Genome> chromosomes = cells[idx - 1].getChromosomes();
    string dna1_n = chromosomes[n - 1].getDNA().first;
    string dna2_n = chromosomes[n - 1].getDNA().second;
    string dna1_m = chromosomes[m - 1].getDNA().first;
    string dna2_m = chromosomes[m - 1].getDNA().second;

    cout << "Enter the substring S1 to be replaced: ";
    cin >> s1;
    cout << "Enter the substring S2 to replace with: ";
    cin >> s2;

    size_t pos1_n = dna1_n.find(s1);
    size_t pos2_n = dna2_n.find(s1);
    size_t pos1_m = dna1_m.find(s2);
    size_t pos2_m = dna2_m.find(s2);

    if (pos1_n == string::npos && pos2_n == string::npos)
    {
        cout << "Substring S1 not found in desired chromosome.\n";
        return;
    }
    else if (pos1_m == string::npos && pos2_m == string::npos)
    {
        cout << "Substring S2 not found in desired chromosome.\n";
        return;
    }
    else
    {
        cells[idx - 1].largeMutation(s1, n - 1, s2, m - 1);
        cout << "Large mutation successfully applied.\n";
    }
}

void smallMutationOnCell(vector<Cell> &cells)
{
    displayCells(cells);

    int idx, n, m;
    char from, to;

    cout << "Enter the cell index: ";
    cin >> idx;

    if (idx <= 0 && idx > cells.size())
    {
        cout << "Invalid index.\n";
        return;
    }

    int chromosomeCount = cells[idx - 1].count();

    cout << "Enter the chromosome index: ";
    cin >> m;

    if (m <= 0 || m > chromosomeCount)
    {
        cout << "Invalid chromosome index.\n";
        return;
    }

    cout << "Enter the source character (from): ";
    cin >> from;
    cout << "Enter the target character (to): ";
    cin >> to;
    cout << "Enter the number of occurrences to replace (n): ";
    cin >> n;

    vector<Genome> chromosomes = cells[idx - 1].getChromosomes();
    string dna1 = chromosomes[m - 1].getDNA().first;
    string dna2 = chromosomes[m - 1].getDNA().second;

    if (count(dna1.begin(), dna1.end(), from) + count(dna2.begin(), dna2.end(), from) < n)
    {
        cout << "Invalid number of replacements for DNA, Try Again!\n";
        return;
    }
    else
    {
        cells[idx - 1].smallMutation(from, to, n, m - 1);
        cout << "Small mutation applied.\n";
    }
}

void reverseMutationOnCell(vector<Cell> &cells)
{
    displayCells(cells);

    int idx, m;
    string s1;

    cout << "Enter the cell index: ";
    cin >> idx;

    if (idx <= 0 || idx > cells.size())
    {
        cout << "Invalid cell index.\n";
        return;
    }

    int chromosomeCount = cells[idx - 1].count();

    cout << "Enter the chromosome index: ";
    cin >> m;

    if (m <= 0 || m > chromosomeCount)
    {
        cout << "Invalid chromosome index.\n";
        return;
    }

    cout << "Enter the substring to reverse: ";
    cin >> s1;

    vector<Genome> chromosomes = cells[idx - 1].getChromosomes();
    string dna1 = chromosomes[m - 1].getDNA().first;
    string dna2 = chromosomes[m - 1].getDNA().second;

    size_t pos1 = dna1.find(s1);
    size_t pos2 = dna2.find(s1);

    if (pos1 == string::npos && pos2 == string::npos)
    {
        cout << "Substring not found in the desired chromosome.\n";
        return;
    }

    if (pos1 != string::npos)
    {
        cells[idx - 1].reverseMutation(s1, m - 1);
    }
    else if (pos2 != string::npos)
    {
        cells[idx - 1].reverseMutation(s1, m - 1);
    }

    cout << "Reverse mutation applied.\n";
}

void findPalindromesInCell(vector<Cell> &cells)
{
    displayCells(cells);

    int idx, m;
    cout << "Select Cell index: ";
    cin >> idx;

    if (idx <= 0 || idx > cells.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    int chromosomeCount = cells[idx - 1].count();

    cout << "Enter the selected cell chromosome index: ";
    cin >> m;

    if (m <= 0 || m > chromosomeCount)
    {
        cout << "Invalid chromosome index.\n";
        return;
    }

    cells[idx - 1].findComplementaryPalindromes(m - 1);
}

void GeneticSimilarity(vector<Animal> &animals)
{
    displayAnimals(animals);
    cout << "NOTE: The Animals you choose you have same number of chromosomes\n";

    int idx1, idx2;
    cout << "Select Animal 1 index: ";
    cin >> idx1;
    cout << "Select Animal 2 index: ";
    cin >> idx2;

    if (idx1 <= 0 || idx1 > animals.size() ||
        idx2 <= 0 || idx2 > animals.size())
    {
        cout << "Invalid index (indices)!\n";
        return;
    }

    vector<Genome> chromosomes1 = animals[idx1 - 1].getChromosomes();
    vector<Genome> chromosomes2 = animals[idx2 - 1].getChromosomes();

    if (chromosomes1.size() != chromosomes2.size())
    {
        cout << "Chromosome count mismatch.\n";
        return;
    }

    double similarity = animals[idx1 - 1].calculateGeneticSimilarity(animals[idx2 - 1]);
    cout << "Genetic similarity between Animal " << idx1 << " and Animal " << idx2 << ": " << similarity << "%\n";
}

void animalSameSpecies(vector<Animal> &animals)
{
    displayAnimals(animals);

    int idx1, idx2;
    cout << "Select Animal 1 index: ";
    cin >> idx1;
    cout << "Select Animal 2 index: ";
    cin >> idx2;

    if (idx1 <= 0 || idx1 > animals.size() ||
        idx2 <= 0 || idx2 > animals.size())
    {
        cout << "Invalid index (indices)!\n";
        return;
    }

    if (animals[idx1 - 1] == animals[idx2 - 2])
        cout << "Animal " << idx1 << " and Animal " << idx2 << " are from a same species\n";
    else
        cout << "Animal " << idx1 << " and Animal " << idx2 << " are not from a same species\n";
}

void asexualReproduction(vector<Animal> &animals)
{
    displayAnimals(animals);

    int idx;
    cout << "Select Animal index: ";
    cin >> idx;

    if (idx <= 0 || idx > animals.size())
    {
        cout << "Invalid index!\n";
        return;
    }

    Animal offspring = animals[idx - 1].asexualReproduction();
    animals.push_back(offspring);
    cout << "Asexual reproduction completed. Offspring created.\n";
}

void sexualReproduction(vector<Animal> &animals)
{
    displayAnimals(animals);
    cout << "NOTE: The Animals you choose you have same number of chromosomes\n";

    int idx1, idx2;
    cout << "Select Animal 1 index: ";
    cin >> idx1;
    cout << "Select Animal 2 index: ";
    cin >> idx2;

    if (idx1 <= 0 || idx1 > animals.size() ||
        idx2 <= 0 || idx2 > animals.size())
    {
        cout << "Invalid index (indices)!\n";
        return;
    }

    vector<Genome> chromosomes1 = animals[idx1 - 1].getChromosomes();
    vector<Genome> chromosomes2 = animals[idx2 - 1].getChromosomes();

    if (chromosomes1.size() != chromosomes2.size())
    {
        cout << "Chromosome count mismatch.\n";
        return;
    }

    Animal child = animals[idx1 - 1] + animals[idx2 - 1];
    animals.push_back(child);
    cout << "Sexual reproduction completed. Child created.\n";
}

void deleteProlematicChromosomes(vector<Animal> &animals)
{
    displayAnimals(animals);

    int idx;
    cout << "Enter the animal index: ";
    cin >> idx;

    if (idx <= 0 || idx > animals.size())
    {
        cout << "Invalid animal index.\n";
        return;
    }

    animals[idx - 1].checkChromosomesForIssues();
    cout << "Checked for chromosome issues and removed problematic chromosomes.\n";
}

void VirusIsHarmful(vector<Virus> &viruses, vector<Animal> &animals)
{
    displayAnimals(animals);
    displayViruses(viruses);

    int idx1, idx2;
    cout << "Choose a virus to check: ";
    cin >> idx1;

    if (idx1 <= 0 || idx1 > viruses.size())
    {
        cout << "Invalid virus index.\n";
        return;
    }

    cout << "Choose an animal to check against: ";
    cin >> idx2;

    if (idx2 <= 0 || idx2 > animals.size())
    {
        cout << "Invalid animal index.\n";
        return;
    }

    Virus selectedVirus = viruses[idx1 - 1];
    Animal selectedAnimal = animals[idx2 - 1];

    bool isHarmful = selectedVirus.isHarmful(selectedAnimal);

    if (isHarmful)
        cout << "The virus is harmful to the selected animal.\n";
    else
        cout << "The virus is not harmful to the selected animal.\n";
}

int main()
{
    vector<Genome> genomes;
    vector<Cell> cells;
    vector<Animal> animals;
    vector<Virus> viruses;

    int choice;
    while (true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            int genomeChoice;
            while (true)
            {
                displayGenomeMenu();
                cin >> genomeChoice;
                if (genomeChoice == 1)
                    createGenome(genomes);
                else if (genomeChoice == 2)
                    complementFromRNA(genomes);
                else if (genomeChoice == 3)
                    smallMutationOnGenome(genomes);
                else if (genomeChoice == 4)
                    largeMutationOnGenome(genomes);
                else if (genomeChoice == 5)
                    reverseMutationOnGenome(genomes);
                else if (genomeChoice == 6)
                    displayGenomes(genomes);
                else if (genomeChoice == 7)
                    break;
                else
                    cout << "Invalid choice, please try again.\n";
            }
        }
        else if (choice == 2)
        {
            int cellChoice;
            while (true)
            {
                displayCellMenu();
                cin >> cellChoice;
                if (cellChoice == 1)
                    createCell(cells);
                else if (cellChoice == 2)
                    checkCellDeath(cells);
                else if (cellChoice == 3)
                    largeMutationOnCell(cells);
                else if (cellChoice == 4)
                    smallMutationOnCell(cells);
                else if (cellChoice == 5)
                    reverseMutationOnCell(cells);
                else if (cellChoice == 6)
                    findPalindromesInCell(cells);
                else if (cellChoice == 7)
                    displayCells(cells);
                else if (cellChoice == 8)
                    break;
                else
                    cout << "Invalid choice, please try again.\n";
            }
        }
        else if (choice == 3)
        {
            int animalChoice;
            while (true)
            {
                displayAnimalMenu();
                cin >> animalChoice;
                if (animalChoice == 1)
                    createAnimal(animals);
                else if (animalChoice == 2)
                    GeneticSimilarity(animals);
                else if (animalChoice == 3)
                    animalSameSpecies(animals);
                else if (animalChoice == 4)
                    asexualReproduction(animals);
                else if (animalChoice == 5)
                    sexualReproduction(animals);
                else if (animalChoice == 6)
                    deleteProlematicChromosomes(animals);
                else if (animalChoice == 7)
                    displayAnimals(animals);
                else if (animalChoice == 8)
                    break;
                else
                    cout << "Invalid choice, please try again.\n";
            }
        }
        else if (choice == 4)
        {
            int virusChoice;
            while (true)
            {
                displayVirusMenu();
                cin >> virusChoice;
                if (virusChoice == 1)
                    createVirus(viruses);
                else if (virusChoice == 2)
                    VirusIsHarmful(viruses, animals);
                else if (virusChoice == 3)
                    displayViruses(viruses);
                else if (virusChoice == 4)
                    break;
                else
                    cout << "Invalid choice, please try again.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}