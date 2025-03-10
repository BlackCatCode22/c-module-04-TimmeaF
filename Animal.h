#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
public:
    // Constructor to initialize all the data members
    Animal(const std::string& name, int age, const std::string& season, const std::string& color,
           const std::string& gender, double weight, const std::string& origin);

    // Getter methods to access private data members
    std::string getName() const;
    int getAge() const;
    std::string getSpecies() const; // You might want to add this method
    std::string getSeason() const;
    std::string getColor() const;
    std::string getGender() const;
    double getWeight() const;
    std::string getOrigin() const;

    // Function to display animal information
    virtual void displayInfo() const;

private:
    std::string name;
    int age;
    std::string species;
    std::string season;
    std::string color;
    std::string gender;
    double weight;
    std::string origin;
};

#endif // ANIMAL_H
