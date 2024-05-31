/*

---------- CONST FUNCTION ----------

A const member function in C++ is a member function that does not modify any member variables of the class. 
It is declared by appending the const keyword to the function declaration. These functions can be called on 
const instances of a class, ensuring that they do not alter the state of the object.

---------- TYPES OF CONSTRUCTOR ----------

Default Constructor: A constructor that takes no arguments.
Parameterized Constructor: A constructor that takes one or more arguments.
Copy Constructor: A constructor that initializes an object using another object of the same class.
Move Constructor: A constructor that transfers resources from one object to another, typically used with dynamic memory.

---------- USES ----------

Read-Only Access: Allows safe read-only access to member variables.
Const Correctness: Ensures that member functions do not accidentally modify the object's state.
Enhanced Code Safety: Prevents accidental changes to the object within functions that are meant to be read-only.
Documentation: Clearly indicates the intent that a function does not modify the object.

---------- REAL - WORLD APPLICATIONS ----------

Banking System: Functions that check account balance without modifying it.
Library Management System: Functions that retrieve book details without altering them.
Employee Management System: Functions that fetch employee details without changing them.
Vehicle Management: Functions that return vehicle specifications without modifying them.

---------- SOFTWARE - RELATED APPLICATIONS ----------

Configuration Management: Functions that read configuration settings without changing them.
Logging Systems: Functions that retrieve log details without modifying logs.
Database Queries: Functions that fetch data without altering the database.
Graphical User Interfaces: Functions that return the state of UI elements without changing them.

---------- RULES ----------

Declaration: Must be declared with the const keyword after the function name and parameter list.
Calling Const Functions: Can be called on both const and non-const objects.
Access: Can only call other const member functions and access member variables in a read-only manner.
Definition: The const keyword must be included in both the declaration and definition of the function.

*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Const member function
    double getLength() const {
        return length;
    }

    // Const member function
    double getWidth() const {
        return width;
    }

    // Non-const member function
    void setLength(double l) {
        length = l;
    }

    // Non-const member function
    void setWidth(double w) {
        width = w;
    }
};

int main() {
    const Rectangle rect(10.0, 5.0);

    // Calling const member functions on a const object
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;

    // The following lines would cause a compilation error
    // rect.setLength(15.0);
    // rect.setWidth(7.0);

    return 0;
}