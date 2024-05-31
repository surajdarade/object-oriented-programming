/*

---------- MEMBER FUNCTIONS ----------

Member functions are defined inside the class definition. They can be declared in the class header and 
then defined outside the class using the scope resolution operator ::.

---------- TYPES ----------

a. Instance Member Functions

Instance member functions are functions that operate on individual objects of a class. 
They have access to all members (both data members and other member functions) of an object.

class MyClass {
public:
    void memberFunction() {
        // Instance member function
    }
};

b. Static Member Functions

Static member functions belong to the class rather than any object of the class. 
They can be called using the class name and the scope resolution operator ::.

class MyClass {
public:
    static void staticMemberFunction() {
        // Static member function
    }
};

c. Const Member Functions

Const member functions are member functions that do not modify the state of the object. 
They are declared with the const keyword at the end of the function declaration.

class MyClass {
public:
    int getValue() const {
        // Const member function
    }
};

---------- USES ----------

Encapsulation: Member functions encapsulate the operations that can be performed on an object.
Data Abstraction: They hide the internal details and provide an interface to interact with objects.
Code Reusability: Functions can be reused across different objects of the same class.
Modularity: Enhances code modularity by breaking down functionality into smaller, manageable parts.

---------- REAL - WORLD APPLICATIONS ----------

Bank Account: Member functions for deposit, withdrawal, and balance checking.
Employee: Functions for salary calculation, promotion, and employee details.
Car: Functions for accelerating, braking, and checking mileage.
Library Management System: Functions for borrowing, returning, and searching books.

---------- SOFTWARE - RELATED APPLICATIONS ----------

GUI Frameworks: Member functions for handling user input and updating GUI elements.
Networking: Functions for sending and receiving data packets.
Game Development: Functions for updating game state, handling collisions, and rendering.
Database Management: Functions for querying and updating database records.

---------- RULES ----------

Access Specifiers: Choose appropriate access specifiers (public, private, protected) for member functions based on their intended use.
Const-Correctness: Use const member functions to ensure objects are not modified unintentionally.
Static Member Functions: Use static member functions for operations that do not depend on specific object instances.
Overloading: Member functions can be overloaded based on different parameter lists.

*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double len, double wid) : length(len), width(wid) {}

    // Instance member function declaration
    double area();

    // Static member function
    static bool isSquare(const Rectangle& rect) {
        return rect.length == rect.width;
    }

    // Const member function
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }
};

// Definition of member function outside of class
double Rectangle::area() {
    return length * width;
}

int main() {
    Rectangle rect1(4.0, 6.0);
    Rectangle rect2(3.0, 3.0);

    cout << "Area of rect1: " << rect1.area() << endl;
    cout << "Area of rect2: " << rect2.area() << endl;

    if (Rectangle::isSquare(rect1)) {
        cout << "rect1 is a square." << endl;
    } else {
        cout << "rect1 is not a square." << endl;
    }

    cout << "Length of rect2: " << rect2.getLength() << endl;
    cout << "Width of rect2: " << rect2.getWidth() << endl;

    return 0;
}
