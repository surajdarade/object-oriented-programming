/*

---------- MULTIPLE INHERITANCE ----------

Multiple inheritance is a feature of C++ where a class can inherit from more than one base class. 
This allows the derived class to combine and extend the functionality of multiple classes.

            A     B
              \ /
               |
               C

---------- USES ----------

Combining Functionality: Combine features from multiple classes into one.
Modeling Complex Relationships: Represent complex relationships where a derived class should inherit behavior from multiple sources.
Code Reusability: Reuse code from multiple classes without duplicating it.
Interface Implementation: Implement multiple interfaces in one class.

---------- REAL-WORLD APPLICATIONS ----------

Academic Roles: A TeachingAssistant class that inherits from both Student and Teacher.
Vehicles: A FlyingCar class that inherits from both Car and Aircraft.
Company Structure: A ManagerEngineer class that inherits from both Manager and Engineer.
Gadgets: A SmartWatch class that inherits from both Watch and FitnessTracker

---------- SOFTWARE-RELATED APPLICATIONS ----------

UI Development: A ClickableDraggable class that inherits from both Clickable and Draggable interfaces.
Game Development: A FlyingShootingCharacter class that inherits from both FlyingCharacter and ShootingCharacter.
Database Management: A MySQLPostgreSQLConnector class that inherits from both MySQLConnector and PostgreSQLConnector.
Networking: A WiFiBluetoothDevice class that inherits from both WiFiDevice and BluetoothDevice.

---------- RULES AND GUIDELINES ----------

Ambiguity Resolution: If two base classes have a member with the same name, use scope resolution to specify which one to use.
Constructor Initialization: All base class constructors must be called explicitly in the derived class constructor initializer list.
Virtual Inheritance: Use virtual inheritance to prevent multiple "instances" of a base class when using multiple inheritance.
Access Control: Respect the access specifiers of the base classes (public, protected, private).

*/

#include <iostream>
using namespace std;

// Base class 1
class Person {
public:
    Person(string name) : name(name) {
        cout << "Person constructor called." << endl;
    }

    ~Person() {
        cout << "Person destructor called." << endl;
    }

    void showName() {
        cout << "Name: " << name << endl;
    }

private:
    string name;
};

// Base class 2
class Employee {
public:
    Employee(int id) : employeeID(id) {
        cout << "Employee constructor called." << endl;
    }

    ~Employee() {
        cout << "Employee destructor called." << endl;
    }

    void showID() {
        cout << "Employee ID: " << employeeID << endl;
    }

private:
    int employeeID;
};

// Derived class
class Manager : public Person, public Employee {
public:
    Manager(string name, int id) : Person(name), Employee(id) {
        cout << "Manager constructor called." << endl;
    }

    ~Manager() {
        cout << "Manager destructor called." << endl;
    }

    void display() {
        showName();
        showID();
    }
};

int main() {
    cout << "Creating a Manager object:" << endl;
    Manager mgr("John Doe", 101);
    mgr.display();
    cout << "Exiting main function." << endl;
    return 0;
}