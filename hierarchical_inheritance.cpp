/*

---------- HIERARCHICAL INHERITANCE ----------

Hierarchical inheritance is a type of inheritance where multiple classes are derived from a single base class. 
This allows the derived classes to inherit properties and methods from the common base class, providing a shared foundation.

            Animal
          /   |   \
        Dog  Cat  Bird


---------- USES ----------

Shared Functionality: Common functionality can be defined in the base class and shared by all derived classes.
Code Reusability: Avoid duplication of code by placing common features in the base class.
Specialization: Each derived class can extend or specialize the behavior of the base class.
Organized Structure: Helps in organizing code and reducing complexity by separating common and specialized functionalities.

---------- REAL-WORLD APPLICATIONS ----------

Academic System: Person base class with derived classes Student, Teacher, Staff.
Vehicles: Vehicle base class with derived classes Car, Bike, Truck.
Electronics: Device base class with derived classes Smartphone, Tablet, Laptop.
Animals: Animal base class with derived classes Dog, Cat, Bird.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Framework: Widget base class with derived classes Button, Slider, Checkbox.
Database Management: Database base class with derived classes MySQLDatabase, PostgreSQLDatabase, SQLiteDatabase.
Networking: Connection base class with derived classes HTTPConnection, FTPConnection, WebSocketConnection.
File Handling: File base class with derived classes TextFile, BinaryFile, CSVFile.

---------- RULES AND GUIDELINES ----------

Access Control: Derived classes can access public and protected members of the base class.
Constructor Initialization: Each derived class must call the constructor of the base class.
Function Overriding: Derived classes can override base class methods to provide specific implementations.
Inheritance Depth: Each derived class is directly related to the base class, not to each other.
Constructor Order: The constructor of the base class is called first, followed by the constructor of the derived class.
Destructor Order: The destructor of the derived class is called first, followed by the destructor of the base class.

*/

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }

    void sleep() {
        cout << "Animal is sleeping." << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat is meowing." << endl;
    }
};

// Derived class 3
class Bird : public Animal {
public:
    void fly() {
        cout << "Bird is flying." << endl;
    }
};

int main() {
    // Create objects of derived classes
    Dog myDog;
    Cat myCat;
    Bird myBird;

    // Accessing base class methods
    myDog.eat();
    myDog.sleep();
    myDog.bark();

    myCat.eat();
    myCat.sleep();
    myCat.meow();

    myBird.eat();
    myBird.sleep();
    myBird.fly();

    return 0;
}