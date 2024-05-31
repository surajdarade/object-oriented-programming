/*

---------- FRIEND FUNCTIONS ----------

A friend function in C++ is a function that is not a member of a class but still has access to its private and protected members. 
Friend functions are defined outside of a class's scope, yet they can access the class's private and protected data. 
They are declared by the keyword friend within the class whose members they will access.

---------- USES ----------

Access Control: Allows controlled access to private and protected members of a class without exposing them to the public interface.
Operator Overloading: Often used to overload operators that need to access private data from different classes.
Utility Functions: Can be used to write utility functions that operate on multiple classes.
Inter-Class Communication: Facilitates the interaction between two or more classes by allowing them to access each other's private members.

---------- REAL-WORLD APPLICATIONS ----------

Banking System: Allowing a global function to access and modify private account details for auditing purposes.
Library Management System: Enabling functions to check and update private book details across different classes.
Employee Management System: Functions that need to access and update private employee data from different classes.
Vehicle Management: Functions that manage vehicle data across different types of vehicles, needing access to private attributes.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Matrix Operations: Overloading operators for matrix addition and multiplication by accessing private matrix data.
Complex Number Operations: Overloading operators to perform arithmetic operations on complex numbers.
Graphics Libraries: Functions that need to manipulate private graphical object data.
Game Development: Allowing functions to access and modify private game object attributes for complex interactions.

---------- RULES AND GUIDELINES ----------

Declaration: Must be declared within the class but defined outside.
Access: Can access private and protected members of the class that declares them as friends.
Scope: Friend functions are not members of the class but have special access rights.
Encapsulation: Use them judiciously to maintain the benefits of encapsulation.

*/

#include <iostream>
using namespace std;
 
class base {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    base()
    {
        private_variable = 10;
        protected_variable = 99;
    }
     
      // friend function declaration
    friend void friendFunction(base& obj);
};
 
 
// friend function definition
void friendFunction(base& obj)
{
    cout << "Private Variable: " << obj.private_variable
         << endl;
    cout << "Protected Variable: " << obj.protected_variable;
}
 
// driver code
int main()
{
    base object1;
    friendFunction(object1);
 
    return 0;
}