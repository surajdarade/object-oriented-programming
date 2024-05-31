/*

---------- TEMPLATE ----------

A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that 
we don’t need to write the same code for different data types. For example, a software company may need to sort() 
for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass the datatype as a parameter. 

C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by the keyword ‘class’.

How Do Templates Work?
Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type-checking 
before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain 
multiple copies of the same function/class. 

*/

/*

---------- FUNCTION TEMPLATE ----------

A function template in C++ allows you to write a single function that can operate with different data types. 
It provides a way to define generic functions that can work with any data type without having to overload the function for each type.

---------- USES ----------

Code Reusability: Write generic functions that can work with any data type, reducing code duplication.
Type Safety: Ensure type safety at compile-time for operations on different data types.
Flexibility: Easily create functions that can handle multiple data types with a single definition.
Maintainability: Simplify maintenance by having a single function definition for multiple data types.

---------- REAL-WORLD APPLICATIONS ----------

Mathematical Operations: Functions for operations like add, subtract, multiply, and divide that work with integers, floats, and doubles.
Sorting Algorithms: Generic sort functions that can sort arrays or containers of any data type.
Data Structures: Functions for manipulating data structures like linked lists, trees, and queues for various data types.
Utility Functions: Generic utility functions like swap, min, max, and compare.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Standard Template Library (STL): The STL uses templates extensively to provide generic classes and functions.
Generic Algorithms: Algorithms in the STL like sort, find, and accumulate are implemented using templates.
Custom Libraries: Creating custom libraries with generic functions to handle different data types.
Code Refactoring: Refactoring existing code to use templates for better code reuse and maintainability.

---------- RULES AND GUIDELINES ----------

Template Declaration: Use the template keyword followed by template parameters in angle brackets.
Template Definition: Define the function using the template parameters.
Instantiation: The compiler generates specific versions of the function for the types used.
Type Deduction: The compiler can often deduce the type from the function arguments.

*/

#include <iostream>
#include <string>

using namespace std;

// Function template for adding two values
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // Using the template function with different types
    int intResult = add(10, 20);           // Works with integers
    double doubleResult = add(5.5, 2.3);   // Works with doubles
    string strResult = add(string("Hello, "), string("World!"));  // Works with strings

    cout << "intResult: " << intResult << endl;         // Output: intResult: 30
    cout << "doubleResult: " << doubleResult << endl;   // Output: doubleResult: 7.8
    cout << "strResult: " << strResult << endl;         // Output: strResult: Hello, World!

    return 0;
}