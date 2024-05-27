/*

---------- FUNCTION OVERRIDING ----------

Function overriding occurs when a derived class provides a specific implementation of a function that is already defined in its base class. 
This allows the derived class to modify or extend the behavior of the base class method.


---------- USES ----------

Polymorphism: Enables runtime polymorphism, allowing the program to decide at runtime which function to invoke.
Customization: Customize or extend base class functionality in the derived class.
Consistency: Ensure that the derived class adheres to the interface defined by the base class while providing specific implementations.
Flexibility: Allows derived classes to offer specialized behaviors while still being treated as instances of the base class.

---------- REAL-WORLD APPLICATIONS ----------

Academic System: Person base class with an overridden getRole function in Student, Teacher, and Staff classes.
Vehicles: Vehicle base class with an overridden startEngine function in Car, Bike, and Truck classes.
Payment Systems: Payment base class with an overridden processPayment function in CreditCardPayment, PayPalPayment, and BankTransferPayment classes.
Animals: Animal base class with an overridden makeSound function in Dog, Cat, and Bird classes.

---------- SOFTWARE-RELATED APPLICATIONS ----------

GUI Framework: Widget base class with an overridden draw function in Button, Slider, and Checkbox classes.
Game Development: Character base class with an overridden attack function in Warrior, Mage, and Archer classes.
Networking: Connection base class with an overridden connect function in HTTPConnection, FTPConnection, and WebSocketConnection classes.
File Handling: File base class with an overridden open function in TextFile, BinaryFile, and CSVFile classes.

---------- RULES AND GUIDELINES ----------

Same Signature: The overridden function must have the same signature (name, return type, and parameters) as the function in the base class.
Access Specifier: The access specifier of the overridden function in the derived class should be the same or less restrictive than that in the base class.
Virtual Keyword: The function in the base class should be marked with the virtual keyword to enable overriding.
Override Keyword: The function in the derived class can use the override keyword for clarity and to avoid mistakes.

*/

/*


In C++, function overriding is technically possible without declaring the function as virtual in the base class, but doing so will not enable runtime polymorphism. 
Without the virtual keyword, the function call is resolved at compile-time, which means that the method of the base class will be called even if the object is of the derived class. 
This is known as static binding.

To achieve dynamic binding or runtime polymorphism, where the correct function is called based on the actual type of the object at runtime, the virtual keyword is necessary.

*/

#include <iostream>
using namespace std;

// Base class
class Base {
public:
    virtual void display() {
        cout << "Display from Base" << endl;
    }

    virtual ~Base() = default; // Virtual destructor for proper cleanup
};

// Derived class
class Derived : public Base {
public:
    void display() override {
        cout << "Display from Derived" << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    
    basePtr = &derivedObj;

    // This will call Derived's display method
    basePtr->display();

    return 0;
}