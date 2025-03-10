#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include "animal.cpp"  // Include the animal class definitions

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
        string name, species, birthSeason, color, gender, origin;
        int age;
        double weight;

        cout << "Reading line: " << line << endl;  // Debug line

        // First, split the line using commas (',') and handle each part
        stringstream ss(line);
        string temp;

        // Split the string into parts by commas and extract necessary information
        getline(ss, temp, ',');  // "4 year old female hyena"

        // Extract name, species, and gender info from the first part
        stringstream partStream(temp);
        partStream >> age >> temp >> temp >> gender >> species;  // Expects "4 year old female hyena"

        // Extract birth season (after the first comma)
        getline(ss, birthSeason, ',');  // "born in spring"
        birthSeason = birthSeason.substr(10);  // Remove "born in " part

        // Extract color and weight (after the next comma)
        getline(ss, color, ',');  // "tan color"
        color = color.substr(0, color.find(" color"));  // Remove " color" part
        ss >> weight;  // "70 pounds"

        // Extract origin (after the next comma)
        ss.ignore();  // Ignore the "from" part
        getline(ss, origin);  // "Friguia Park, Tunisia"

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
            cout << "Unknown species: " << species << endl;  // Debug line for unknown species
        }

        // Debugging: Print number of animals added to vector
        cout << "Animals in vector: " << animals.size() << endl;
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
