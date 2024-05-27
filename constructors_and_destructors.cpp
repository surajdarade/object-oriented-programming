/*

---------- CONSTRUCTOR ----------

A constructor is a special member function of a class that is automatically called when an object of the class 
is created. Constructors are used to initialize objects and can set initial values for the object's member variables.

---------- TYPES OF CONSTRUCTOR ----------

Default Constructor: A constructor that takes no arguments.
Parameterized Constructor: A constructor that takes one or more arguments.
Copy Constructor: A constructor that initializes an object using another object of the same class.
Move Constructor: A constructor that transfers resources from one object to another, typically used with dynamic memory.

---------- USES ----------

Uses of Constructors
Object Initialization: Initialize member variables with default or specific values.
Resource Management: Allocate resources like memory, file handles, or network connections.
Data Validation: Validate data during object creation to ensure the object is in a valid state.
Dependency Injection: Inject dependencies and initialize complex objects.

---------- REAL - WORLD APPLICATIONS ----------

Bank Account: Initialize account details like account number, balance, and owner.
Vehicle: Initialize properties like make, model, and year of a car.
Employee Record: Initialize employee details like name, ID, and position.
Library Book: Initialize book details like title, author, and ISBN.

---------- SOFTWARE - RELATED APPLICATIONS ----------

GUI Components: Initialize properties of GUI components like buttons and windows.
Network Connections: Initialize connection details like IP address and port.
File Handling: Open files and set up streams for reading or writing.
Game Entities: Initialize game characters, their attributes, and states.

---------- RULES ----------

Name: Must have the same name as the class.
No Return Type: Constructors do not have a return type, not even void.
Overloading: Multiple constructors can be defined with different parameters.
Automatic Invocation: Called automatically when an object is created.
Access:  Constructors in C++ can be declared as private or protected too.

*/

#include<bits/stdc++.h>

using namespace std;

class Student {

    private: 

    string name;
    int age;
    vector<int> grades;

    public:

    // default
    Student() : name("Unknown"), age(0) {}

    // parameretized
    Student(string n, int a) : name(n), age(a) {}

    // copy
    Student(const Student &other) : name(other.name), age(other.age), grades(other.grades) {}

    // move
    Student(Student &&other) noexcept : name(move(other.name)), age(other.age), grades(move(other.grades)) {
        other.age = 0;
    }

    void addGrade(int grade){
        grades.push_back(grade);
    }

    double getAverageGrade() const {
        if(grades.empty()) return 0.0;

        int sum = 0;

        for(int grade : grades) {
            sum += grade;
        }

        return static_cast<double>(sum) / grades.size();
    }

    void printInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Average Grade: " << getAverageGrade() << endl;
    }

};

int main() {
    Student student1; // Default Constructor
    Student student2("Suraj", 20); // Parameterized Constructor
    student2.addGrade(85);
    student2.addGrade(90);
    student2.addGrade(78);

    Student student3 = student2; // Copy Constructor
    Student student4 = move(student2); // Move Constructor

    student1.printInfo();
    student3.printInfo();
    student4.printInfo();

    return 0;
}


/*

---------- DESTRUCTOR ----------

A destructor is a special member function of a class that is automatically called when an object of the class 
goes out of scope or is explicitly deleted. Destructors are used to perform clean-up tasks such as releasing 
resources (e.g., memory, file handles, network connections) that the object may have acquired during its lifetime.

---------- SYNTAX ----------

The destructor has the same name as the class, prefixed with a tilde (~).
It does not take any parameters and does not return a value.

---------- USES ----------

Resource Deallocation: Release dynamically allocated memory to prevent memory leaks.
File Handling: Close open files to ensure all data is flushed and resources are freed.
Network Connections: Close network connections to ensure proper termination of communication.
General Clean-Up: Perform any necessary clean-up actions before the object is destroyed.

---------- REAL - WORLD APPLICATIONS ----------

File Management: Automatically close files when an object representing a file goes out of scope.
Database Connections: Clean up database connections when an object representing a connection is destroyed.
GUI Applications: Ensure that graphical resources are released when GUI elements are no longer needed.
Game Development: Release resources such as textures, sounds, and other assets when game objects are destroyed.

---------- SOFTWARE - RELATED APPLICATIONS ----------

Smart Pointers: Automatically manage the lifetime of dynamically allocated objects.
RAII (Resource Acquisition Is Initialization): Ensure that resources are properly released when objects go out of scope.
Custom Containers: Release memory and resources held by custom container classes.
Thread Management: Clean up thread resources when thread objects are destroyed.

---------- RULES ----------

One Destructor: A class can have only one destructor.
No Overloading: Destructors cannot be overloaded; there is only one destructor per class.
Automatic Call: Destructors are called automatically when an object goes out of scope or is explicitly deleted.
Order of Destruction: Destructors for member objects are called in the reverse order of their declaration.

*/

#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;  // Pointer to an array of pointers
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data = new int*[rows];  // Allocate memory for rows
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new int[cols];  // Allocate memory for columns in each row
        }
        cout << "Matrix of size " << rows << "x" << cols << " created." << endl;
    }

    // Destructor
    ~Matrix() {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];  // Delete each row
        }
        delete[] data;  // Delete the array of row pointers
        cout << "Matrix of size " << rows << "x" << cols << " deleted." << endl;
    }

    // Method to set value
    void setValue(size_t row, size_t col, int value) {
        if (row < rows && col < cols) {
            data[row][col] = value;
        }
    }

    // Method to get value
    int getValue(size_t row, size_t col) const {
        if (row < rows && col < cols) {
            return data[row][col];
        }
        return -1;  // Return an invalid value if out of range
    }

    // Method to print the matrix
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat(3, 4);  // Create a 3x4 matrix

    // Set some values in the matrix
    mat.setValue(0, 0, 1);
    mat.setValue(1, 1, 2);
    mat.setValue(2, 2, 3);

    // Print the matrix
    mat.print();

    // Destructor will be called automatically when mat goes out of scope
    return 0;
}