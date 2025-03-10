#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include "animal.cpp"  // Include the animal class definitions
#include <regex>  // For better pattern matching

using namespace std;

// Function to read and parse data from a file
void readAnimalsFromFile(const string& filename, vector<Animal*>& animals) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open " << filename << " for reading" << endl;
        return;
    }

    cout << "File opened successfully!" << endl;

    string line;
    while (getline(inFile, line)) {
        cout << "Reading line: " << line << endl;

        string name, species, birthSeason, color, gender, origin;
        int age;
        double weight;

        // Use regex to extract the necessary information
        regex rgx("([A-Za-z]+), (\\d+) year old (\\w+) (\\w+), born in (\\w+), (\\w+) color, (\\d+) pounds, from (.+)");
        smatch matches;

        if (regex_search(line, matches, rgx)) {
            name = matches[1];  // Extract the name
            age = stoi(matches[2]);  // Extract the age
            gender = matches[3];  // Extract the gender
            species = matches[4];  // Extract the species
            birthSeason = matches[5];  // Extract birth season
            color = matches[6];  // Extract color
            weight = stod(matches[7]);  // Extract weight
            origin = matches[8];  // Extract origin

            // Debugging: Print parsed data
            cout << "Parsed data - Name: " << name << ", Species: " << species << ", Age: " << age
                 << ", Birth Season: " << birthSeason << ", Color: " << color << ", Weight: " << weight
                 << ", Origin: " << origin << endl;

            // Create animal object based on species
            if (species == "hyena") {
                animals.push_back(new Hyena(name, age, birthSeason, color, gender, weight, origin));
            } else if (species == "lion") {
                animals.push_back(new Lion(name, age, birthSeason, color, gender, weight, origin));
            } else if (species == "tiger") {
                animals.push_back(new Tiger(name, age, birthSeason, color, gender, weight, origin));
            } else if (species == "bear") {
                animals.push_back(new Bear(name, age, birthSeason, color, gender, weight, origin));
            } else {
                cout << "Unknown species: " << species << endl;
            }

            // Debugging: Print number of animals added to vector
            cout << "Animals in vector: " << animals.size() << endl;
        }
    }

    inFile.close();
}

// Function to generate a report about the animals
void generateReport(const vector<Animal*>& animals) {
    ofstream outFile("newAnimals.txt");  // Open the file to write
    if (!outFile) {
        cerr << "Error: Could not open animal_report.txt for writing" << endl;
        return;
    }

    // Debug: Check if animals vector is empty
    if (animals.empty()) {
        cout << "No animals to report!" << endl;
        outFile << "No animals to report!" << endl;  // Write to the file
        outFile.close();
        return;
    }

    map<string, int> speciesCount;
    for (const Animal* animal : animals) {
        speciesCount[animal->getSpecies()]++;
    }

    // Print species count to console and write it to the report file
    outFile << "Species Count:\n";
    for (const auto& entry : speciesCount) {
        outFile << entry.first << ": " << entry.second << " animals\n";
    }
    outFile << "\n\n";  // Add some space between species count and animal details

    // Write the detailed report for each animal by species
    outFile << "Animal Details:\n";
    for (const auto& entry : speciesCount) {
        outFile << "\nSpecies: " << entry.first << "\n";
        outFile << "------------\n";

        // Display animal details of the current species
        for (const Animal* animal : animals) {
            if (animal->getSpecies() == entry.first) {
                outFile << "Name: " << animal->getName() << ", Age: " << animal->getAge()
                        << " years old, Color: " << animal->getColor()
                        << ", Weight: " << animal->getWeight() << " pounds"
                        << ", Birth Season: " << animal->getBirthSeason()
                        << ", Origin: " << animal->getOrigin() << "\n";
            }
        }
        outFile << "\n";  // Add space between each species section
    }

    outFile.close();  // Close the file after writing
    cout << "Report generation completed!" << endl;
}

// Main function
int main() {
    vector<Animal*> animals;

    // File path
    string filePath = "C:/Users/NCG/CLionProjects/zoo/cmake-build-debug/arrivingAnimals.txt";

    // Reading animals from file
    readAnimalsFromFile(filePath, animals);

    // Display each animal's information
    for (Animal* animal : animals) {
        animal->display();
    }

    // Generate and save the report
    generateReport(animals);

    // Clean up dynamically allocated memory
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
