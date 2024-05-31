/*

---------- MOVE CONSTRUCTOR ----------

A move constructor in C++ is a special constructor that enables the resources owned by an rvalue object to be moved to a new object. 
This is more efficient than copying because it involves transferring ownership of resources (e.g., memory, file handles) without duplicating them.

---------- USES ----------

Performance Optimization: Avoids unnecessary deep copies of objects, improving performance.
Resource Management: Efficiently transfers ownership of resources.
Temporary Objects: Optimizes the handling of temporary objects.
Container Classes: Improves performance of STL containers and user-defined containers.

---------- REAL - WORLD APPLICATIONS ----------

File Management: Transferring ownership of file handles between objects.
Network Connections: Moving ownership of network sockets.
Multimedia Applications: Efficiently transferring large multimedia files.
Database Connections: Moving ownership of database connection handles.

---------- SOFTWARE - RELATED APPLICATIONS ----------

Smart Pointers: Transferring ownership in smart pointer implementations.
STL Containers: Optimizing vector, map, and other container operations.
Thread Management: Transferring ownership of thread handles.
Graphics Processing: Moving ownership of large graphical resources.

---------- RULES ----------

Signature: The move constructor takes an rvalue reference to the object.
No-throw Guarantee: Should be noexcept to ensure compatibility with standard containers.
Transfer Ownership: Transfers ownership of resources from the source object to the new object.
Invalidation: The source object is left in a valid but unspecified state.

*/

/*

---------- MOVE ASSIGNMENT OPERATOR ----------

A move assignment operator in C++ transfers the ownership of resources from one object to another existing object. 
This operator is used when an existing object needs to take over the resources of another object (typically an rvalue).

---------- USES ----------

Performance Improvement: Reduces the overhead of copying resources.
Resource Reallocation: Efficiently reallocates resources between objects.
Temporary Objects: Optimizes the assignment of temporary objects.
Dynamic Resource Management: Manages dynamic resources like memory, file handles, etc.

---------- REAL - WORLD APPLICATIONS ----------

File Handling: Reassigning file handles to different file objects.
Network Sockets: Moving network socket ownership between objects.
Media Streaming: Reassigning large media buffers.
Database Connections: Transferring database connections between objects.

---------- SOFTWARE - RELATED APPLICATIONS ----------

Container Classes: Reassigning elements in STL containers.
Thread Management: Moving thread handles between thread objects.
Resource Pools: Reassigning resources in a resource pool.
Graphics Libraries: Moving large graphical resources.

---------- RULES ----------

Signature: The move assignment operator takes an rvalue reference to the object.
No-throw Guarantee: Should be noexcept for compatibility with standard containers.
Transfer Ownership: Transfers ownership of resources from the source object.
Self-assignment Check: Must handle self-assignment correctly.

*/

#include <iostream>
#include <utility> // For std::move

class Simple {
private:
    int* data;
public:
    // Constructor
    Simple(int value) : data(new int(value)) {
        std::cout << "Constructor called\n";
    }

    // Destructor
    ~Simple() {
        delete data;
        std::cout << "Destructor called\n";
    }

    // Move Constructor
    Simple(Simple&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move Constructor called\n";
    }

    // Move Assignment Operator
    Simple& operator=(Simple&& other) noexcept {
        if (this != &other) { // Self-assignment check
            delete data; // Free existing resource
            data = other.data; // Transfer ownership
            other.data = nullptr;
            std::cout << "Move Assignment Operator called\n";
        }
        return *this;
    }

    // Function to print value
    void print() const {
        if (data) {
            std::cout << "Value: " << *data << '\n';
        } else {
            std::cout << "Data is nullptr\n";
        }
    }

    // Delete copy constructor and copy assignment operator
    Simple(const Simple&) = delete;
    Simple& operator=(const Simple&) = delete;
};

int main() {
    Simple obj1(42);  // Constructor
    Simple obj2 = std::move(obj1); // Move Constructor
    obj2.print();    // Value: 42
    obj1.print();    // Data is nullptr

    Simple obj3(99);  // Constructor
    obj3 = std::move(obj2); // Move Assignment Operator
    obj3.print();    // Value: 42
    obj2.print();    // Data is nullptr

    return 0;
}