#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    string species;
    string birthSeason;
    string color;
    string gender;
    double weight;
    string origin;

public:
    // Constructor
    Animal(string n, int a, string s, string bSeason, string c, string g, double w, string o)
        : name(n), age(a), species(s), birthSeason(bSeason), color(c), gender(g), weight(w), origin(o) {}

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getSpecies() const { return species; }
    string getBirthSeason() const { return birthSeason; }
    string getColor() const { return color; }
    string getGender() const { return gender; }
    double getWeight() const { return weight; }
    string getOrigin() const { return origin; }

    // Display all details
    virtual void display() const {
        cout << species << ": " << name << " (" << age << " years old)" << endl;
        cout << "Birth Season: " << birthSeason << ", Color: " << color << ", Gender: " << gender
             << ", Weight: " << weight << " pounds" << endl;
        cout << "Origin: " << origin << endl;
    }
};

class Hyena : public Animal {
public:
    Hyena(string n, int a, string bSeason, string c, string g, double w, string o)
        : Animal(n, a, "Hyena", bSeason, c, g, w, o) {}

    void display() const override {
        cout << "Hyena: " << name << " (" << age << " years old)" << endl;
        cout << "Birth Season: " << birthSeason << ", Color: " << color << ", Gender: " << gender
             << ", Weight: " << weight << " pounds" << endl;
        cout << "Origin: " << origin << endl;
    }
};

class Lion : public Animal {
public:
    Lion(string n, int a, string bSeason, string c, string g, double w, string o)
        : Animal(n, a, "Lion", bSeason, c, g, w, o) {}

    void display() const override {
        cout << "Lion: " << name << " (" << age << " years old)" << endl;
        cout << "Birth Season: " << birthSeason << ", Color: " << color << ", Gender: " << gender
             << ", Weight: " << weight << " pounds" << endl;
        cout << "Origin: " << origin << endl;
    }
};

class Tiger : public Animal {
public:
    Tiger(string n, int a, string bSeason, string c, string g, double w, string o)
        : Animal(n, a, "Tiger", bSeason, c, g, w, o) {}

    void display() const override {
        cout << "Tiger: " << name << " (" << age << " years old)" << endl;
        cout << "Birth Season: " << birthSeason << ", Color: " << color << ", Gender: " << gender
             << ", Weight: " << weight << " pounds" << endl;
        cout << "Origin: " << origin << endl;
    }
};

class Bear : public Animal {
public:
    Bear(string n, int a, string bSeason, string c, string g, double w, string o)
        : Animal(n, a, "Bear", bSeason, c, g, w, o) {}

    void display() const override {
        cout << "Bear: " << name << " (" << age << " years old)" << endl;
        cout << "Birth Season: " << birthSeason << ", Color: " << color << ", Gender: " << gender
             << ", Weight: " << weight << " pounds" << endl;
        cout << "Origin: " << origin << endl;
    }
};
