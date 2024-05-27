/*

---------- HIERARCHICAL INHERITANCE ----------

Function overloading is a feature in C++ that allows you to define multiple functions with the same name but with different parameters. 
This enables the functions to perform similar but slightly different tasks, enhancing code readability and usability.

---------- USES ----------

Improved Readability: Using the same function name for similar operations makes the code easier to read and understand.
Code Maintenance: Simplifies code maintenance by reducing the number of function names.
Function Specialization: Allows for function specialization based on different parameter types or numbers.
Simplifies API Design: Makes APIs more intuitive by allowing the same function name for different functionalities.

---------- REAL-WORLD APPLICATIONS ----------

Mathematical Operations: Different overloads for addition, subtraction, multiplication, etc., of various data types.
Input/Output Operations: Overloading functions for reading/writing different types of data.
String Manipulations: Functions for concatenating, comparing, or searching within strings.
Geometric Calculations: Functions for calculating area or volume of different shapes (e.g., circle, rectangle, box).

---------- SOFTWARE-RELATED APPLICATIONS ----------

Graphics Libraries: Overloading functions to draw different shapes with varying parameters.
File Handling: Functions to open files in different modes (read, write, append).
Database Access: Functions to query databases with different criteria.
GUI Development: Functions to handle different types of user input.

---------- RULES AND GUIDELINES ----------

Different Parameters: Functions must have different parameter lists (number, types, or order).
Return Type: Return type alone is not sufficient to overload functions.
Scope: Functions must be in the same scope.
Function Signature: Overloaded functions must have a different function signature (name and parameter types).

*/

#include <iostream>
#include <string>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

// Function to concatenate two strings
string add(const string& a, const string& b) {
    return a + b;
}

int main() {
    // Using overloaded functions
    cout << "Sum of 5 and 10: " << add(5, 10) << endl;                 // Calls add(int, int)
    cout << "Sum of 1, 2, and 3: " << add(1, 2, 3) << endl;            // Calls add(int, int, int)
    cout << "Sum of 4.5 and 5.5: " << add(4.5, 5.5) << endl;           // Calls add(double, double)
    cout << "Concatenation of 'Hello' and 'World': " << add("Hello, ", "World!") << endl; // Calls add(string, string)

    return 0;
}