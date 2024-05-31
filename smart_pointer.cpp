/*

---------- SMART POINTER ----------

As we’ve known unconsciously not deallocating a pointer causes a memory leak that may lead to a crash of the program. 
Languages Java, C# has Garbage Collection Mechanisms to smartly deallocate unused memory to be used again. 
The programmer doesn’t have to worry about any memory leaks. C++ comes up with its own mechanism that’s Smart Pointer. 
When the object is destroyed it frees the memory as well. So, we don’t need to delete it as Smart Pointer will handle it.

A Smart Pointer is a wrapper class over a pointer with an operator like * and -> overloaded. The objects of the smart 
pointer class look like normal pointers. But, unlike Normal Pointers, it can deallocate and free destroyed object memory.

The idea is to take a class with a pointer, destructor, and overloaded operators like * and ->. Since the destructor is 
automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted 
(or the reference count can be decremented).

---------- USES ----------

Automatic Memory Management: Automatically deallocates memory when the pointer is no longer needed.
Prevents Memory Leaks: Ensures resources are properly released, preventing memory leaks.
Facilitates Resource Management: Manages resources like dynamically allocated memory, files, and other objects.
Provides Ownership Semantics: Clarifies ownership and helps prevent dangling pointer issues.

---------- REAL-WORLD APPLICATIONS ----------

File Handling: Automatic closing of file handles when no longer needed.
Graphics: Managing resources like textures and buffers in a game engine.
Database Connections: Ensuring database connections are closed properly.
Multi-threading: Ensuring thread-safe access to shared resources.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Object-Oriented Programming: Managing object lifetimes in complex class hierarchies.
Resource Management: Ensuring resources are released in exception-prone code.
Concurrency: Enabling thread-safe access to shared resources.
Memory Management: Preventing memory leaks and use-after-free errors.

---------- RULES AND GUIDELINES ----------

Ownership Management: Clarifies and automates resource ownership.
Exception Safety: Provides exception safety guarantees.
Thread Safety: Ensures thread-safe access to shared resources.
Performance Overhead: May incur some overhead due to reference counting.

*/

// C++ program to demonstrate the working of Smart Pointer
#include <iostream>
using namespace std;
 
class SmartPtr {
    int* ptr; // Actual pointer
public:
    // Constructor: Refer
    // https://www.geeksforgeeks.org/g-fact-93/ for use of
    // explicit keyword
    explicit SmartPtr(int* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
};
 
int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
 
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is
    // automatically called and destructor does delete ptr.
 
    return 0;
}