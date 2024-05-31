/*

---------- PURE VIRTUAL FUNCTIOAN AND ABSTRACT CLASS ----------

Abstract Class:

An abstract class is a class that cannot be instantiated on its own and is designed to be inherited by other classes. 
It typically contains one or more pure virtual functions. Abstract classes are used to define common interfaces and force 
derived classes to provide specific implementations.

Pure Virtual Function:

A pure virtual function is a function declared in a base class with no definition in that class. 
It is specified by assigning 0 to the function declaration. This makes the class containing it an abstract class.

---------- USES ----------

Interface Definition: Abstract classes define interfaces that derived classes must implement.
Enforcing Implementation: Pure virtual functions ensure that derived classes implement specific functionalities.
Polymorphism: Allows for runtime polymorphism by using base class pointers or references to manage derived class objects.
Code Organization: Promotes better code organization and separation of concerns by defining clear and consistent interfaces.

---------- REAL-WORLD APPLICATIONS ----------

Payment Systems: An abstract class PaymentMethod with a pure virtual function processPayment().
Shape Drawing: An abstract class Shape with a pure virtual function draw().
File Handling: An abstract class FileHandler with a pure virtual function open().
Notification Systems: An abstract class Notifier with a pure virtual function sendNotification().

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Frameworks: An abstract class Widget with a pure virtual function render().
Networking: An abstract class Protocol with a pure virtual function sendData().
Game Development: An abstract class GameObject with a pure virtual function update().
Logging Systems: An abstract class Logger with a pure virtual function logMessage().

---------- RULES AND GUIDELINES ----------

Declaration: Pure virtual functions are declared by assigning 0 in the base class.
Instantiation: Abstract classes cannot be instantiated.
Implementation in Derived Classes: Pure virtual functions must be overridden and defined in derived classes.
Inheritance: Abstract classes can be inherited by other abstract classes, passing on the requirement to implement the pure virtual functions.

*/

#include <iostream>

// Abstract base class with a pure virtual function
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // A virtual destructor to ensure proper cleanup
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle\n";
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Output: Drawing Circle
    shape2->draw(); // Output: Drawing Rectangle

    delete shape1;
    delete shape2;

    return 0;
}