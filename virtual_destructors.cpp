/*

---------- VIRTUAL DESTRUCTOR ----------

A virtual destructor is a destructor that can be overridden in derived classes. It ensures that the destructor of the derived class is called 
when an object is deleted through a pointer to the base class, enabling proper resource cleanup.

---------- USES ----------

Polymorphism: Ensures correct destructor call sequence in polymorphic base classes.
Resource Management: Properly releases resources in derived classes.
Memory Leak Prevention: Prevents memory leaks by ensuring complete destruction of derived objects.
Object Cleanup: Guarantees that destructors in the entire inheritance chain are called.

---------- REAL - WORLD APPLICATIONS ----------

File Handling: Proper cleanup of file handles in derived classes.
Network Connections: Correctly closing network connections in derived classes.
Database Connections: Properly closing database connections in derived classes.
GUI Applications: Correctly destroying UI components and releasing resources.

---------- SOFTWARE - RELATED APPLICATIONS ----------

Smart Pointers: Ensures correct object destruction in smart pointer implementations.
STL Containers: Manages resource cleanup for objects stored in containers.
Game Development: Properly destroys game objects and releases resources.
Plugin Architectures: Ensures correct destruction of plugin objects.

---------- RULES ----------

Polymorphic Base Classes: Use virtual destructors in base classes intended for polymorphic use.
Overriding: Can be overridden in derived classes.
Destructor Order: Ensures derived class destructors are called before base class destructors.
Virtual Keyword: Use the virtual keyword in the base class destructor declaration.

*/

#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called\n";
    }
    
    virtual ~Base() {
        std::cout << "Base destructor called\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor called\n";
    }
    
    ~Derived() {
        std::cout << "Derived destructor called\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Correctly calls Derived and then Base destructor
    return 0;
}