/*

---------- MEMBER VARIABLES ----------

Member variables are variables that are declared within a class and are associated with objects of that class. 
They represent the attributes or properties that describe the state of the objects.
Member variables are defined inside the class definition. They can be either public, private, or protected, 
depending on their intended access level.


---------- TYPES OF MEMBER VARIABLES ----------

a. Private Member Variables

Private member variables are only accessible within the class. They encapsulate the internal state of the object.

b. Public Member Variables

Public member variables are accessible from outside the class. They expose the internal data directly to external code.

c. Protected Member Variables

Protected member variables are accessible within the class and by derived classes. They are useful in class hierarchies 
to share data between base and derived classes.

---------- USES OF MEMBER VARIABLES ----------

Encapsulation: Member variables encapsulate the state of objects and control access to them.
Data Abstraction: They hide the internal details of how data is stored and managed, providing an interface to interact with objects.
Object Initialization: Member variables are initialized in the constructor and provide the initial state of objects.
Modularity: Enhances code modularity by breaking down objects into smaller, manageable parts.

---------- REAL-WORLD APPLICATIONS ----------

Bank Account: Member variables for account number, balance, and customer details.
Employee: Variables for employee ID, salary, and department.
Car: Variables for model, color, and current speed.
Student: Variables for student ID, name, and grades.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Frameworks: Variables for widget properties such as size, position, and visibility.
Game Development: Variables for game objects like position, rotation, and health.
Database Management: Variables for database connections, queries, and results.
Networking: Variables for connection details, data packets, and transfer status.

---------- RULES AND GUIDELINES ----------

Access Specifiers: Choose appropriate access specifiers (public, private, protected) for member variables based on their intended use.
Initialization: Initialize member variables properly in constructors to ensure objects start in a consistent state.
Encapsulation: Use member functions to control access to member variables, following encapsulation principles.
Data Validation: Validate and sanitize member variable inputs to maintain object integrity and security.

*/

#include <iostream>
using namespace std;

// Base class
class Base {
private:
    int privateVar;      // Private member variable
protected:
    int protectedVar;    // Protected member variable
public:
    int publicVar;       // Public member variable

    // Constructor
    Base(int pv, int protv, int pubv)
        : privateVar(pv), protectedVar(protv), publicVar(pubv) {}

    // Display function to access member variables
    void display() {
        cout << "Private Variable: " << privateVar << endl;
        cout << "Protected Variable: " << protectedVar << endl;
        cout << "Public Variable: " << publicVar << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived(int pv, int protv, int pubv)
        : Base(pv, protv, pubv) {}

    // Function to access protected member variable
    void accessProtected() {
        // Access protectedVar directly
        cout << "Accessing Protected Variable from Derived: " << protectedVar << endl;
    }
};

int main() {
    // Create an object of the Derived class
    Derived derivedObj(10, 20, 30);

    // Access public member variable
    cout << "Accessing Public Variable from Main: " << derivedObj.publicVar << endl;

    // Access protected member variable via a function
    derivedObj.accessProtected();

    // Access base class display function
    derivedObj.display();

    return 0;
}
