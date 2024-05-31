/*

---------- VIRTUAL FUNCTIONS ----------


Virtual functions are functions in C++ that are declared with the virtual keyword in a base class and are overridden in derived classes. 
They enable dynamic polymorphism, which means the function call is resolved at runtime (late binding).

---------- USES ----------

Function Overriding: Allows a derived class to provide a specific implementation of a function that is already defined in its base class.
Runtime Polymorphism: Enables the selection of the function to be called at runtime, based on the type of the object being referenced or pointed to.
Base Class Pointer/Reference: Allows a base class pointer or reference to invoke derived class methods.

---------- REAL-WORLD APPLICATIONS ----------

Shape Hierarchy: In a shape hierarchy (e.g., circle, rectangle), a virtual calculateArea() method can be defined in the base class Shape and overridden in derived classes.
Employee Management: In an employee management system, a virtual calculateSalary() method can be defined in the base class Employee and overridden in derived classes (e.g., Manager, Developer).
Animal Classification: In an animal classification system, a virtual makeSound() method can be defined in the base class Animal and overridden in derived classes (e.g., Cat, Dog).
GUI Frameworks: Virtual functions can be used in GUI frameworks to handle events like onClick() for various UI elements.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Game Development: Virtual functions are used extensively in game development to define behaviors of game objects.
Framework Development: Virtual functions are used in developing software frameworks to define abstract behaviors.
Database Management: Virtual functions can be used in database management systems to define interfaces for different database operations.
Networking: In networking applications, virtual functions can define how data packets are handled based on their type.

---------- RULES AND GUIDELINES ----------

Virtual Function Declaration: Declared in a base class using the virtual keyword.
Function Signature: Must have the same name, parameters, and return type in both the base and derived classes.
Function Overriding: The overriding function in the derived class also uses the virtual keyword, but it's optional.
Dynamic Binding: Resolves the function call at runtime, based on the actual object type.

*/

#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* ptrAnimal1 = new Dog();
    Animal* ptrAnimal2 = new Cat();

    ptrAnimal1->makeSound(); // Output: Dog barks
    ptrAnimal2->makeSound(); // Output: Cat meows

    delete ptrAnimal1;
    delete ptrAnimal2;

    return 0;
}