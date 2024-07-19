
        //      A
        //     / \
        //    B   C
        //     \ /
        //      D


// Diamond Problem
// In this setup, class D inherits from both B and C. Since both B and C inherit from A, D ends up with two copies of the properties and methods of A. This can lead to ambiguity and inconsistencies, such as:

// Ambiguous Method Calls: If A has a method that B and C both override, it can be unclear which version of the method D should use.
// Duplicate Data: D might inherit multiple copies of the data members from A.

// #include <bits/stdc++.h>

// using namespace std;

// class A{
// public:
//     void eat(){
//         cout << "Eating from base class A." << endl;
//     }
// };

// class B: public A {
//     public:
//     void eat() {
//         cout << "Eating from class B which inherits base class A.";
//     }
// };

// class C: public A {
//     public:
//     void eat() {
//         cout << "Eating from class Bc which inherits base class A.";
//     }
// };

// class D: public B, public C {
//     public:
//     void eat() {
//         cout << "Eating from class D which inherits class B and C who inherits base class A.";
//     }
// };

// int main(){

//     D obj;
//     obj.eat();

//     return 0;
// }

// TO solve the diamond problem we have the virtual inheritance in c++

// Virtual Inheritance

// Using the virtual keyword in front of the base class when inheriting from it ensures that only a single instance of 
// the base class is shared among all the derived classes, thus preventing duplication.

#include<bits/stdc++.h>

class A {
public:
    A() { std::cout << "A's constructor\n"; }
    void display() { std::cout << "A's display\n"; }
};

// Class B inherits virtually from A
class B : virtual public A {
public:
    B() { std::cout << "B's constructor\n"; }
};

// Class C inherits virtually from A
class C : virtual public A {
public:
    C() { std::cout << "C's constructor\n"; }
};

// Class D inherits from both B and C
class D : public B, public C {
public:
    D() { std::cout << "D's constructor\n"; }
};

int main() {
    D d;         // Create an instance of D
    d.display(); // Call the display method of A

    return 0;
}
