/*

---------- ABSTRACTION ----------

Abstraction is one of the fundamental principles of Object-Oriented Programming (OOP). It involves showing only the necessary 
details to the user while hiding the complex implementation details. This allows programmers to work with objects at a higher 
level without needing to understand all the intricacies of how those objects work internally.

In C++, abstraction is mainly achieved through classes and interfaces. For example, when you use a class like std::vector, 
you interact with its public methods without needing to know how those methods are implemented internally.

---------- USES ----------

Simplification: It simplifies complex systems by breaking them down into more manageable pieces.
Maintainability: Makes code easier to maintain and update since changes in implementation do not affect the user interface.
Reusability: Facilitates code reusability by allowing developers to use components without understanding their internal workings.
Security: Provides a level of security by restricting access to the internal details and allowing only certain operations to be performed.

---------- REAL-WORLD APPLICATIONS ----------

Automobiles: Drivers use the steering wheel, pedals, and buttons without knowing the internal workings of the engine or transmission.
TV Remote: Users can change channels and adjust the volume without knowing the circuitry inside the remote.
Smartphones: Users interact with the user interface without needing to understand the underlying operating system or hardware components.
Banking System: Customers can perform transactions via ATMs or online banking without knowing the backend processes.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Libraries: Abstract away the details of rendering graphics and handling user input.
Database Systems: Allow users to perform CRUD operations without knowing the details of how data is stored or indexed.
Network Protocols: Users can send and receive data over a network without understanding the underlying protocols.
File Systems: Users can read and write files without knowing how data is managed on the disk.

---------- RULES AND GUIDELINES ----------

Access Specifiers: Use public, private, and protected access specifiers to control access to class members.
Interface and Implementation Separation: Separate the interface (what the object does) from the implementation (how it does it).
Encapsulation: Combine data and methods that operate on that data within a single unit (class).
Information Hiding: Hide the internal state and implementation details from the user.

*/

#include <iostream>
#include <string>
using namespace std;

class AbstractAnimal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
};

class Dog : public AbstractAnimal {
private:
    string breed;
public:
    Dog(string b) : breed(b) {}
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
    string getBreed() const {
        return breed;
    }
};

class Cat : public AbstractAnimal {
private:
    string color;
public:
    Cat(string c) : color(c) {}
    void makeSound() const override {
        cout << "Meow! Meow!" << endl;
    }
    string getColor() const {
        return color;
    }
};

int main() {
    AbstractAnimal* dog = new Dog("Labrador");
    AbstractAnimal* cat = new Cat("White");

    dog->makeSound(); // Outputs: Woof! Woof!
    cat->makeSound(); // Outputs: Meow! Meow!

    delete dog;
    delete cat;

    return 0;
}