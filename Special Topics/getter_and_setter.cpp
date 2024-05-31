/*

---------- GETTER AND SETTER ----------

Getters and setters are special member functions used to access and modify the private data members of a class.
They are a part of the concept of encapsulation, which ensures that the internal representation of an object is hidden 
from the outside.

---------- USES ----------

Encapsulation: Protect internal state by providing controlled access to the class's private data members.
Data Validation: Validate data before modifying it through setters.
Read-Only Access: Provide read-only access to private data members using getters.
Consistency: Ensure that data consistency rules are enforced when data is accessed or modified.

---------- REAL-WORLD APPLICATIONS ----------

Bank Account: Getters and setters for account balance, ensuring proper transactions.
Employee Management: Getters and setters for employee details like salary and position.
Vehicle Management: Getters and setters for vehicle attributes like speed and fuel level.
User Profile: Getters and setters for user profile information like name and email.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Configuration Management: Getters and setters for configuration settings in an application.
Game Development: Getters and setters for game character attributes like health and score.
Data Modeling: Getters and setters for accessing and modifying database record fields.
GUI Applications: Getters and setters for GUI component properties like size and color.

---------- RULES AND GUIDELINES ----------

Access Specifiers: Typically, getters and setters are public, while the data members they access are private.
Naming Conventions: Common naming conventions are getVariableName for getters and setVariableName for setters.
Const Correctness: Getters should be marked as const to ensure they do not modify the object.
Validation Logic: Setters can include validation logic to ensure data integrity.

*/

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(const string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int newAge) {
        if (newAge > 0) {
            age = newAge;
        }
    }
};

int main() {
    Person person;
    person.setName("John Doe");
    person.setAge(30);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}