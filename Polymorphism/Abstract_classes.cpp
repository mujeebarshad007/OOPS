#include <iostream>
using namespace std;

// Abstract class
class Animals
{
public:
    virtual void MakeNoise() = 0; // Pure virtual function
    virtual void Move() = 0;      // Pure virtual function
};

// Derived class Dog
class Dog : public Animals
{
public:
    void MakeNoise() override
    {
        cout << "Woof!" << endl; // Dog-specific noise
    }
    void Move() override
    {
        cout << "Running" << endl; // Dog-specific movement
    }
};

// Derived class Cat
class Cat : public Animals
{
public:
    void MakeNoise() override
    {
        cout << "Meow!" << endl; // Cat-specific noise
    }
    void Move() override
    {
        cout << "Walking" << endl; // Cat-specific movement
    }
};

int main()
{
    // Creating objects of derived classes
    Dog dog;
    Cat cat;

    // Demonstrating polymorphism
    Animals *animalPtr; // Pointer to base class (Animals)

    // Using the Dog object through the base class pointer
    animalPtr = &dog;
    cout << "Dog says: ";
    animalPtr->MakeNoise(); // Calls Dog's MakeNoise()
    cout << "Dog moves: ";
    animalPtr->Move(); // Calls Dog's Move()

    cout << endl;

    // Using the Cat object through the base class pointer
    animalPtr = &cat;
    cout << "Cat says: ";
    animalPtr->MakeNoise(); // Calls Cat's MakeNoise()
    cout << "Cat moves: ";
    animalPtr->Move(); // Calls Cat's Move()

    return 0;
}
