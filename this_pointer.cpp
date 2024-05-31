/*

---------- THIS KEYWORD ----------

In C++ programming, this is a keyword that refers to the current instance of the class. 
There can be 3 main usage of this keyword in C++.

    1. It can be used to pass current object as a parameter to another method.
    2. It can be used to refer current class instance variable.
    3. It can be used to declare indexers.

this is a pointer that holds the address of the current object. 
It is automatically available within all non-static member functions.

---------- USES ----------

Reference Current Object: Allows access to the current instance of the class.
Return Current Object: Used to return the current object from a member function.
Avoid Name Conflicts: Helps differentiate between class members and parameters with the same name.
Chaining Member Functions: Enables chaining of member function calls on the same object.

---------- REAL-WORLD APPLICATIONS ----------

Banking Systems: Manage accounts and transactions using this for account operations.
Inventory Management: Track and update product information using this for product modifications.
Employee Records: Maintain employee details and roles using this for access control.
Automated Testing Tools: Create and manipulate mock objects using this for testing purposes.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Object-Oriented Programming: Access and manipulate class attributes using this for object instantiation.
Embedded Systems: Control and monitor hardware devices using this for device-specific functionality.
Web Development: Manage user interactions and events using this for client-side scripting.
Mobile Applications: Implement real-time updates and notifications using this for data synchronization.

---------- RULES AND GUIDELINES ----------

Member Functions: Access member functions and attributes of the current class instance.
Class Scope: Refer to class attributes and methods within a member function.
Pointer Arithmetic: Employ pointer arithmetic to manage dynamic memory allocation and deallocation.
Data Structures: Define data structures such as arrays and lists to perform complex computations

*/

#include <iostream>
using namespace std;

class MyClass {
private:
    int num;

public:
    // Constructor
    MyClass(int num) {
        // Using 'this' to differentiate between parameter and member variable
        this->num = num;
    }

    // Member function to display the number
    void display() {
        cout << "Number: " << this->num << endl;
    }

    // Member function to add two numbers
    MyClass add(MyClass other) {
        MyClass result(this->num + other.num);
        return result;
    }
};

int main() {
    // Create an object of MyClass
    MyClass obj1(5);
    MyClass obj2(10);

    // Display number using member function
    obj1.display(); // Output: Number: 5

    // Add two objects using member function
    MyClass sum = obj1.add(obj2);
    sum.display(); // Output: Number: 15

    return 0;
}