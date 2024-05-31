/*

---------- CLASS ----------

Class: A class is a blueprint or prototype that defines the variables and methods (functions) common
to all objects of a certain kind. It encapsulates data for the object and methods to manipulate that data.

class Car {
public:
    string brand;
    string model;
    int year;

    void start() {
        cout << "Car started" << endl;
    }
};

---------- OBJEcT ----------

Object: An object is an instance of a class. When a class is defined, no memory is allocated until an
object of that class is created.

Car myCar;  // Object of class Car
myCar.brand = "Toyota";
myCar.model = "Corolla";
myCar.year = 2020;
myCar.start();  // Calling the start method

---------- USES ----------

Uses of Classes and Objects
Encapsulation: Classes encapsulate data and methods that operate on the data, restricting direct access
to some of an object's components, which is a means of preventing unintended interference and misuse of the methods.
Code Reusability: Classes enable the reuse of code, allowing developers to create multiple objects from the same class.
Abstraction: Classes can provide a clear structure by hiding the complex implementation details and showing
only the necessary features of an object.
Inheritance: Classes allow properties and methods to be inherited from other classes, promoting code reuse and
the creation of hierarchical relationships.

---------- REAL - WORLD APPLICATIONS ----------

Blueprint for Buildings: A class can represent the blueprint for buildings with attributes like number of floors,
type of materials, and methods like construction or demolition.
Vehicle Manufacturing: A class can represent different types of vehicles (cars, trucks) with attributes like brand,
model, and methods like accelerate or brake.
Bank Accounts: A class can represent bank accounts with attributes like account number, balance, and methods for
deposit and withdrawal.
Library Management System: A class can represent books with attributes like title, author, and methods to borrow
or return the book.

---------- SOFTWARE - RELATED APPLICATIONS ----------

GUI Widgets: Classes are used to create buttons, text fields, and other GUI components in software applications.
File Management: A class can represent files with methods for reading, writing, and modifying the file content.
Database Management: Classes can represent tables in a database, encapsulating the data and providing methods to
interact with the database.
Networking: Classes can represent network connections with attributes like IP address, port, and methods to send
and receive data.

---------- RULES ----------

Class Declaration: Must start with the keyword class followed by the class name and a body enclosed in braces.
Access Specifiers: Control the visibility of the class members. Common specifiers are public, private, and protected.
Member Variables: Variables defined inside a class. They can be accessed by the class methods.
Member Functions: Functions defined inside a class. They can manipulate the member variables.

---------- OBJECTS ----------

Stack Objects: Objects created on the stack are automatically destroyed when they go out of scope. 
Stack space is limited, so creating too many objects on the stack can lead to a stack overflow.

void createStackObjects() {
    MyClass obj1(1);
    MyClass obj2(2);
    // More objects...
}  // obj1 and obj2 are automatically destroyed here

Heap Objects: Objects created on the heap must be manually managed (using new and delete). 
Failure to delete heap objects can lead to memory leaks.

void createHeapObjects() {
    MyClass* obj1 = new MyClass(1);
    MyClass* obj2 = new MyClass(2);
    // More objects...

    delete obj1;  // Manual deletion required
    delete obj2;
}

Dynamic Arrays: You can create arrays of objects if you need a large number of instances.

MyClass* objArray = new MyClass[100];  // Array of 100 MyClass objects
delete[] objArray;  // Clean up the array

*/

#include <bits/stdc++.h>

using namespace std;

class Student{

private:
    string name;
    int age;
    vector<int> grades;

public:
    Student(string n, int a) : name(n), age(a) {}

    void addGrade(int grade){

        grades.push_back(grade);

    }

    // A const member function ensures that the function will not alter any class members (attributes). 
    // This allows you to call the function on const objects or through const references/pointers.

    double getAverageGrade() const{ 

        if (grades.empty())
            return 0.0;

        int sum = 0;

        for (int grade : grades){

            sum += grade;
        }

        // static_cast<double> is a C++ casting operator used to convert one data type to another. 
        // In this specific case, static_cast<double> is used to convert a value to the double data type.

        return static_cast<double>(sum) / grades.size();

    }

    void printInfo() const{

        cout << "Name: " << name << ", Age: " << age << ", Average Grade: " << getAverageGrade() << endl;

    }
};

int main() {

    Student student1("Suraj", 20);
    student1.addGrade(85);
    student1.addGrade(90);
    student1.addGrade(78);
    
    Student student2("Vishal", 22);
    student2.addGrade(88);
    student2.addGrade(76);
    student2.addGrade(95);

    student1.printInfo();
    student2.printInfo();

    return 0;

}
