/*

---------- SUPER KEYWORD ----------


Certainly! In C++, super pointer is not a keyword or feature in the same way this is, but you can achieve similar functionality 
using inheritance and the super keyword in other languages like Java or C#. In C++, the equivalent concept is achieved using base 
class pointers and base class member access, which I'll explain below.

Base Class Pointers in C++
In C++, when you have a derived class inheriting from a base class, you can use a pointer to the base class to access members and 
functions of the base class. This serves a similar purpose to the super keyword in other languages.

---------- USES ----------

Accessing Base Class Members: When you need to access a member or function of the base class from within a derived class.
Overriding Base Class Methods: Provides a way to override base class methods while still allowing access to the base class version.
Calling Specific Implementations: Allows calling a specific implementation of a method in the inheritance hierarchy.

---------- REAL-WORLD APPLICATIONS ----------

GUI Frameworks: Different widgets may need to access common base class methods while still implementing their own specialized behavior.
Database Frameworks: Different database access objects (DAOs) may need to implement specific queries while still accessing common connection or transaction management methods.
Game Development: Different game entities may need to access common base class methods for rendering, updating, etc., while still implementing their specific behavior.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Frameworks: Different widgets accessing common base class methods while implementing specific behaviors.
Database Frameworks: Specific query implementation while accessing common connection methods.
Game Development: Accessing common methods for rendering, updating, etc., with specific behavior implementation.
Networking Applications: Uniform handling of network messages and events across different protocols.

---------- RULES AND GUIDELINES ----------

Inheritance: Derived classes inherit all non-private members of the base class.
Member Access: Base class members can be accessed using the Base:: scope resolution operator.
Polymorphism: Derived classes can override base class methods with their own implementations.
Pointer Types: Base class pointers can point to derived class objects, allowing polymorphic behavior.

*/

#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void display() {
        cout << "Base class display function" << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    void display() {
        cout << "Derived class display function" << endl;
    }

    void callBaseDisplay() {
        // Using base class pointer to call base class method
        Base::display();
    }
};

int main() {
    Derived derivedObj;
    
    // Call derived class method
    derivedObj.display(); // Output: Derived class display function
    
    // Call base class method using base class pointer
    derivedObj.callBaseDisplay(); // Output: Base class display function
    
    return 0;
}