/*

---------- SINGLE INHERITANCE ----------

Single inheritance is a type of inheritance in which a derived class inherits the members (attributes and methods) 
of a single base class. This allows the derived class to reuse the code of the base class and extend its functionality.

---------- USES -------

Code Reusability: Inherit methods and properties from a base class to avoid duplicating code.
Relationship Modeling: Establish an "is-a" relationship between classes (e.g., a Dog is an Animal).
Enhanced Modularity: Break down functionality into smaller, manageable parts.
Polymorphism: Enable polymorphic behavior through function overriding.

---------- REAL-WORLD APPLICATIONS ----------

Animal Hierarchy: Animal as a base class, with Dog, Cat, etc., as derived classes.
Employee Management System: Employee base class with Manager, Engineer, etc., as derived classes.
Shape Hierarchy: Shape as a base class with Circle, Rectangle, etc., as derived classes.
Vehicle Types: Vehicle as a base class with Car, Truck, etc., as derived classes.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Development: Derive specific widgets from a base widget class.
Database Management: Base class for database connections with derived classes for specific database types.
Game Development: Inherit base game object functionalities to create specific game objects.
Networking: Base class for network connections with derived classes for different protocols.

---------- RULES AND GUIDELINES ----------

Access Control: Derived classes can access public and protected members of the base class.
Construction and Destruction: Base class constructors and destructors are called automatically.
Function Overriding: Derived classes can override base class methods to provide specific implementations.
Inheritance Depth: Classes can inherit from a single base class at a time.
Constructor Order: The constructor of the base class is called first, followed by the constructor of the derived class.
Destructor Order: The destructor of the derived class is called first, followed by the destructor of the base class.

*/

#include <iostream>
using namespace std;

// Base class
class Animal {
private:
    string type;

public:
    Animal(string t) : type(t) {}

    void setType(string t) {
        type = t;
    }

    string getType() const {
        return type;
    }

    void eat() {
        cout << "Animal is eating." << endl;
    }

    void sleep() {
        cout << "Animal is sleeping." << endl;
    }
};

// Derived class
class Dog : public Animal {
private:
    string name;

public:
    Dog(string t, string n) : Animal(t), name(n) {}

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void bark() {
        cout << "Dog " << name << " is barking." << endl;
    }
};

int main() {
    // Create an object of the derived class
    Dog myDog("Canine", "Buddy");

    // Accessing base class methods
    myDog.eat();
    myDog.sleep();

    // Accessing derived class methods
    myDog.bark();

    // Accessing base class member variables
    cout << "Type of the animal: " << myDog.getType() << endl;

    // Accessing derived class member variables
    cout << "Name of the dog: " << myDog.getName() << endl;

    return 0;
}