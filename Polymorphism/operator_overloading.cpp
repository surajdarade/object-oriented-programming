/*

---------- OPERATOR OVERLOADING ----------

Operator overloading is a feature in C++ that allows you to redefine the operators to work with user-defined types. 
This means you can use the operators to perform operations on objects of a class just like you use them with primitive data types.

---------- USES ----------

Improved Usability: Makes the syntax of user-defined types similar to built-in types.
Enhanced Readability: Allows intuitive use of operators with custom types.
Customized Behaviors: Enables specific behaviors of operators for custom types.
Simplifies Complex Operations: Provides a concise way to perform complex operations.

---------- REAL-WORLD APPLICATIONS ----------

Complex Number Arithmetic: Overloading +, -, *, / operators for complex number operations.
String Operations: Overloading +, +=, ==, !=, <, > operators for string concatenation and comparison.
Matrix Operations: Overloading +, -, * operators for matrix addition, subtraction, and multiplication.
Financial Calculations: Overloading operators for currency and money calculations.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Scientific Computing: Overloading operators for vector and matrix operations.
Game Development: Overloading operators for game-specific operations.
Database Management: Overloading operators for database queries.
GUI Development: Overloading operators for handling user interactions.

---------- RULES AND GUIDELINES ----------

Operators That Cannot Be Overloaded: . (dot), .* (pointer to member), :: (scope resolution), ?: (ternary operator).
Overloaded Operator's Function Signature:
    Must be a non-static member function with at least one parameter of the class type.
    Or, it can be a non-member function with at least one parameter of the class type (using friend keyword).

*/

#include <iostream>
#include <string>
using namespace std;

// Class definition
class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Overloaded + operator to add two Complex objects
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloaded - operator to subtract two Complex objects
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overloaded * operator to multiply with a scalar
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imaginary * scalar);
    }

    // Overloaded == operator to compare two Complex objects
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // Overloaded != operator to compare two Complex objects
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overloaded << operator to print Complex objects
    friend ostream& operator<<(ostream& os, const Complex& obj);

    // Getter methods
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }
};

// Overloaded << operator to print Complex objects
ostream& operator<<(ostream& os, const Complex& obj) {
    os << obj.real << " + " << obj.imaginary << "i";
    return os;
}

int main() {
    // Create two Complex objects
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -1.0);

    // Use overloaded operators
    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex scaled = c1 * 2.0;

    // Print results
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Scaled c1: " << scaled << endl;

    // Test == and != operators
    if (c1 == c2) {
        cout << "c1 is equal to c2" << endl;
    } else if (c1 != c2) {
        cout << "c1 is not equal to c2" << endl;
    }

    return 0;
}