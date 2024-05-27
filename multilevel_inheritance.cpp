/*

---------- SINGLE INHERITANCE ----------

Multilevel inheritance is a type of inheritance where a class is derived from another derived class, 
forming a chain of inheritance. For example, if class B is derived from class A, and class C is derived from class B, 
then this forms a multilevel inheritance hierarchy.

                A
                |
                B
                |
                C

---------- USES -------

Hierarchical Modeling: Model complex hierarchies where each level adds more specific behavior.
Incremental Development: Add functionality incrementally by extending derived classes.
Code Reusability: Reuse code across multiple levels of the inheritance chain.
Specialization: Create more specialized classes by inheriting and extending functionality.

---------- REAL-WORLD APPLICATIONS ----------

Academic System: Person -> Student -> GraduateStudent.
Company Structure: Person -> Employee -> Manager.
Vehicle Types: Vehicle -> Car -> ElectricCar.
Animal Kingdom: Animal -> Mammal -> Human.

---------- SOFTWARE-RELATED APPLICATIONS ----------

UI Components: Widget -> Button -> IconButton.
Game Characters: Character -> NPC -> Merchant.
Data Handling: DataSource -> DatabaseSource -> MySQLSource.
Error Handling: Exception -> IOException -> FileIOException.

---------- RULES AND GUIDELINES ----------

Access Control: Derived classes can access public and protected members of all ancestor classes.
Constructor/Destructor Chain: Constructors and destructors are called in the order of inheritance.
Function Overriding: Any level in the hierarchy can override functions from any ancestor.
Base Class Initialization: Each derived class must initialize its immediate base class.
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
};

// Derived class
class Mammal : public Animal {
public:
    void breathe() {
        cout << "Mammal is breathing." << endl;
    }
};

// Further derived class
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

int main() {
    // Create an object of the most derived class
    Dog myDog;

    // Access base class methods
    myDog.eat();      // From Animal
    myDog.breathe();  // From Mammal
    myDog.bark();     // From Dog

    return 0;
}
