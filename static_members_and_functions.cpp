/*

---------- STATIC MEMBERS AND FUNCTIONS ----------

Static members (variables and functions) in C++ belong to the class rather than any specific instance of the class. 
This means that static members are shared among all instances of the class. They can be accessed using the class name itself, 
without creating an object.

1. Static Member Variables: These are variables declared with the static keyword inside a class. 
There is only one copy of the static member variable shared by all objects of the class.
2. Static Member Functions: These are functions declared with the static keyword inside a class. 
They can access only static member variables and other static member functions. They cannot access non-static members.

---------- USES ----------

Shared Data: Static members can be used to store data that needs to be shared across all instances of a class.
Utility Functions: Static member functions can be used to implement utility functions that do not depend on object-specific data.
Factory Methods: Static member functions can be used to implement factory methods that create instances of the class.
Counting Instances: Static member variables can be used to keep track of the number of instances of a class.

---------- REAL-WORLD APPLICATIONS ----------

Database Connections: Maintaining a single connection pool shared across all instances of a database access class.
Configuration Settings: Storing application-wide settings that need to be accessed by various parts of an application.
Logging: Implementing a logging mechanism that is accessible throughout the application.
Resource Management: Managing shared resources like memory pools or thread pools.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Singleton Pattern: Using a static member function to ensure only one instance of a class is created.
Global Counters: Keeping track of the number of active objects or other global statistics.
Math Libraries: Implementing utility functions such as trigonometric calculations or random number generation.
Configuration Managers: Accessing global configuration settings across different modules of a software system.

---------- RULES AND GUIDELINES ----------

Declaration and Definition: Static member variables must be defined outside the class definition, in addition to being declared inside it.
Access: Static members can be accessed using the class name, without needing an object instance.
Scope: Static members have class scope but not object scope.
Restrictions: Static member functions can only access static member variables and other static member functions.

*/

#include <iostream>
using namespace std;

class Counter {
private:
    static int count; // Static member variable

public:
    // Static member function
    static void increment() {
        count++;
    }

    static int getCount() {
        return count;
    }
};

// Definition of the static member variable
int Counter::count = 0;

int main() {
    // Accessing static member function using class name
    Counter::increment();
    Counter::increment();
    
    cout << "Count after accessing via class name: " << Counter::getCount() << endl;

    // Creating objects
    Counter c1, c2;
    
    // Accessing static member function using objects
    c1.increment();
    c2.increment();
    
    cout << "Count after accessing via objects: " << Counter::getCount() << endl;

    return 0;
}