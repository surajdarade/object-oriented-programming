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

---------- CLASS TEMPLATE ----------

A class template in C++ allows you to define a class that can operate with different data types. 
Similar to function templates, class templates provide a way to create a generic class that can be reused for various types without having 
to define multiple classes for each type.

---------- USES ----------

Generic Data Structures: Create data structures like linked lists, stacks, queues, and trees that can store any data type.
Container Classes: Implement containers (e.g., vectors, maps) that can hold any type of elements.
Reusability: Avoid code duplication by writing a single class that can handle different data types.
Flexibility: Easily extend classes to handle additional types by simply instantiating the template with new types.

---------- REAL-WORLD APPLICATIONS ----------

Generic Collections: Implement collections that can store various types of data, such as integers, floats, or user-defined types.
Data Wrappers: Create wrapper classes that provide additional functionality for any data type.
Mathematical Libraries: Implement mathematical structures like matrices and vectors that can work with any numerical type.
Custom Containers: Develop custom container classes for specific applications, like game development or scientific computing.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Standard Template Library (STL): The STL uses class templates extensively for containers and algorithms.
Database Systems: Implement generic classes for database records and query results.
Graphics Libraries: Create template classes for handling different types of graphical objects and coordinates.
Networking Libraries: Develop template-based classes for handling different types of network messages and protocols.

---------- RULES AND GUIDELINES ----------

Template Declaration: Use the template keyword followed by template parameters in angle brackets.
Template Definition: Define the class using the template parameters.
Instantiation: The compiler generates specific versions of the class for the types used.
Type Deduction: The compiler can deduce the type from the class instantiation.

*/

#include <iostream>
#include <string>

using namespace std;

// Class template for a generic pair
template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}

    T1 getFirst() const {
        return first_;
    }

    T2 getSecond() const {
        return second_;
    }

    void setFirst(T1 first) {
        first_ = first;
    }

    void setSecond(T2 second) {
        second_ = second;
    }

private:
    T1 first_;
    T2 second_;
};

int main() {
    // Using the template class with different types
    Pair<int, double> intDoublePair(1, 2.5);
    Pair<string, string> stringPair("Hello", "World");

    cout << "intDoublePair: (" << intDoublePair.getFirst() << ", " << intDoublePair.getSecond() << ")" << endl;
    cout << "stringPair: (" << stringPair.getFirst() << ", " << stringPair.getSecond() << ")" << endl;

    intDoublePair.setFirst(10);
    intDoublePair.setSecond(20.5);
    cout << "Updated intDoublePair: (" << intDoublePair.getFirst() << ", " << intDoublePair.getSecond() << ")" << endl;

    return 0;
}