/*

---------- ACCESS SPECIFIERS ----------

Access specifiers in C++ determine the accessibility of class members (attributes and methods) from outside the class. 
There are three access specifiers:

Public
Private
Protected
Each access specifier controls the visibility and accessibility of the class members declared under it.

1. Public
Members declared as public are accessible from anywhere in the program. This includes member functions and data members 
that can be accessed directly using an object of the class.

2. Private
Members declared as private are accessible only within the class itself. They cannot be accessed directly from outside the class, 
including from derived classes.

3. Protected
Members declared as protected are accessible within the class and by derived classes. However, they are not accessible from outside the class hierarchy.

---------- USES ----------

Encapsulation: Access specifiers help in encapsulating the data and methods, exposing only what is necessary and hiding the internal implementation details.
Data Protection: Prevents unauthorized access and modification of data by restricting access to certain members of the class.
Inheritance Control: Controls the accessibility of base class members in derived classes, aiding in proper use of inheritance.
Interface Definition: Public members define the interface of the class, while private members help in implementing the internal functionality.

---------- REAL - WORLD APPLICATIONS ----------

Banking System: private members for account balance, public methods for deposit and withdrawal.
Library Management System: protected members for common attributes, public methods for operations like book issue and return.
Inventory Management: private members for stock details, public methods for adding and removing items.
User Authentication: private members for storing passwords, public methods for login and logout.

---------- SOFTWARE - RELATED APPLICATIONS ----------

GUI Frameworks: Encapsulate widget properties using private or protected members, with public methods to manipulate them.
Game Development: Use private members for game state, with public methods for game logic and user interactions.
Database Connections: Encapsulate connection details with private members, providing public methods to open and close connections.
Networking: Encapsulate socket details with private members, providing public methods for sending and receiving data.

---------- RULES ----------

Default Access: Members of a class are private by default. Members of a struct are public by default.
Inheritance: Access specifiers can affect how members of the base class are inherited in the derived class.
Accessibility:
    public: Accessible from anywhere.
    private: Accessible only within the class.
    protected: Accessible within the class and derived classes.
Friend Classes/Functions: Can access private and protected members of the class they are friends with.

*/

#include <iostream>
using namespace std;

class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    int publicVar;

    Base() : privateVar(0), protectedVar(0), publicVar(0) {}

    void setPrivateVar(int val) {
        privateVar = val;
    }

    int getPrivateVar() const {
        return privateVar;
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        // privateVar = 10;  // Not accessible
        protectedVar = 20;   // Accessible
        publicVar = 30;      // Accessible
    }
};

int main() {
    Base base;
    Derived derived;

    // base.privateVar = 10;  // Not accessible
    // base.protectedVar = 20;  // Not accessible
    base.publicVar = 30;  // Accessible

    derived.accessBaseMembers();
    base.setPrivateVar(40);
    cout << "Private Variable: " << base.getPrivateVar() << endl;

    return 0;
}