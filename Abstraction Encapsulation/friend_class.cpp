/*

---------- FRIEND CLASS ----------

A friend class can access private and protected members of other classes in which it is declared as a friend. 
It is sometimes useful to allow a particular class to access private and protected members of other classes. 
For example, a LinkedList class may be allowed to access private members of Node.

We can declare a friend class in C++ by using the friend keyword.

---------- USES ----------

Access Control: Allows controlled access to private and protected members of a class.
Close Collaboration: Facilitates tight integration and collaboration between classes.
Encapsulation: Helps maintain encapsulation by providing specific access rather than making members public.
Complex Data Structures: Useful in implementing complex data structures that require inter-class access.

---------- REAL-WORLD APPLICATIONS ----------

Banking System: Different classes for account management and transaction processing may need to share private data.
Library Management System: Classes representing books and library operations might need access to each other's private members.
Employee Management System: Classes for employee details and payroll processing might share private information.
Vehicle Management: Classes for vehicle specifications and maintenance records may need to access each other’s private data.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Matrix Operations: Classes representing different matrix operations might need to access private data from a matrix class.
Graphics Libraries: Different graphical object classes might share private data to render complex scenes.
Game Development: Game engine classes may need access to private members of game object classes for rendering and physics calculations.
Database Management: Classes representing database connections and query operations may share private information for efficient data handling.

---------- RULES AND GUIDELINES ----------

Declaration: Declare a friend class using the friend keyword within the class whose members need to be accessed.
Access: The friend class has access to private and protected members of the class that declares it as a friend.
Scope: Friendship is not reciprocal; if Class A is a friend of Class B, Class B is not automatically a friend of Class A.
Encapsulation: Use friend classes judiciously to maintain encapsulation and avoid exposing too much internal state.

*/

#include <iostream>
using namespace std;
 
class GFG {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    GFG()
    {
        private_variable = 10;
        protected_variable = 99;
    }
 
    // friend class declaration
    friend class F;
};
 
// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F {
public:
    void display(GFG& t)
    {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable;
    }
};
 
// Driver code
int main()
{
    GFG g;
    F fri;
    fri.display(g);
    return 0;
}