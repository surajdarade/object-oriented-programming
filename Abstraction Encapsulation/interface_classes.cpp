/*

---------- INTERFACE CLASSES ----------

An interface class in C++ is an abstract class that has only pure virtual functions and no data members or non-pure virtual functions. 
It defines a contract that derived classes must fulfill by providing implementations for all its pure virtual functions. 
Interface classes ensure that derived classes adhere to a specific interface, promoting consistency and interoperability.

---------- USES ----------

Defining Contracts: Ensure derived classes implement specific functionalities.
Decoupling Implementation: Separate interface from implementation, allowing flexible and interchangeable components.
Polymorphism: Enable polymorphic behavior by using base class pointers or references.
Code Organization: Improve code organization by clearly defining roles and responsibilities.

---------- REAL-WORLD APPLICATIONS ----------

Payment Systems: An interface IPaymentMethod with pure virtual function processPayment().
Shape Drawing: An interface IShape with pure virtual function draw().
File Handling: An interface IFileHandler with pure virtual function open().
Notification Systems: An interface INotifier with pure virtual function sendNotification().

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Frameworks: An interface IWidget with pure virtual function render().
Networking: An interface IProtocol with pure virtual function sendData().
Game Development: An interface IGameObject with pure virtual function update().
Logging Systems: An interface ILogger with pure virtual function logMessage().

---------- RULES AND GUIDELINES ----------

Pure Virtual Functions: All functions must be pure virtual (i.e., virtual void func() = 0;).
No Data Members: Typically, interface classes should not have data members.
Cannot be Instantiated: Interface classes cannot be instantiated directly.
Implementation in Derived Classes: Derived classes must implement all pure virtual functions.

*/

#include <iostream>

// Interface class
class IShape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Virtual destructor
    virtual ~IShape() {}
};

class Circle : public IShape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public IShape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle\n";
    }
};

int main() {
    IShape* shape1 = new Circle();
    IShape* shape2 = new Rectangle();

    shape1->draw(); // Output: Drawing Circle
    shape2->draw(); // Output: Drawing Rectangle

    delete shape1;
    delete shape2;

    return 0;
}