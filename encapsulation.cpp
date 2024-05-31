/*

---------- ENCAPSULATION ----------

Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. In Object Oriented Programming, 
Encapsulation is defined as binding together the data and the functions that manipulate them.

Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, 
finance section, sales section, etc. Now,

The finance section handles all the financial transactions and keeps records of all the data related to finance.
Similarly, the sales section handles all the sales-related activities and keeps records of all the sales.
Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month.

In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales 
section and then request him to give the particular data.


This is what Encapsulation is. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name “sales section”. 

Two Important  property of Encapsulation 

1. Data Protection: Encapsulation protects the internal state of an object by keeping its data members private. 
Access to and modification of these data members is restricted to the class’s public methods, ensuring controlled and secure data manipulation.
2. Information Hiding: Encapsulation hides the internal implementation details of a class from external code. Only the public interface of the class is accessible, 
providing abstraction and simplifying the usage of the class while allowing the internal implementation to be modified without impacting external code.

---------- USES ----------

Data Hiding: Encapsulation helps protect the object's data from unauthorized access and modification.
Modularity: It separates the interface from the implementation, making the code more modular and easier to manage.
Maintainability: Changes in the implementation of a class can be made without affecting other parts of the program that use the class.
Controlled Access: It provides controlled access to the class's data through methods (getters and setters).

---------- REAL-WORLD APPLICATIONS ----------

Bank Account: Only the owner can access and modify the balance, typically through methods like deposit and withdraw.
Car: The engine's internal workings are hidden from the driver, who interacts with it through pedals and a steering wheel.
Mobile Phone: Internal components like CPU and battery are encapsulated, and the user interacts with the phone via the touchscreen interface.
Medical Records: Patient data is encapsulated to ensure privacy and is accessed or modified only by authorized personnel.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Database Management Systems: Data is encapsulated within objects and accessed through query methods.
Graphical User Interfaces (GUIs): Widgets encapsulate their state and behavior, exposing methods to interact with them.
Networking Libraries: Network connection details are hidden, and users interact through high-level APIs.
Game Development: Game entities encapsulate their attributes and behaviors, allowing for clean and modular code.

---------- RULES AND GUIDELINES ----------

Use Access Specifiers: Define the visibility of class members using private, protected, and public.
Provide Public Methods: Use public methods to access and modify private data members (getters and setters).
Maintain Integrity: Ensure the internal state of the object is always valid by performing validation within setters.
Encapsulate Everything: Make as many data members and helper methods private or protected as possible, exposing only what is necessary.

*/

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    // Getter for account holder
    std::string getAccountHolder() const {
        return accountHolder;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds!" << std::endl;
        }
    }
};

int main() {
    // Create a BankAccount object
    BankAccount myAccount("John Doe", 1000.0);

    // Accessing account holder and balance through getters
    std::cout << "Account Holder: " << myAccount.getAccountHolder() << std::endl;
    std::cout << "Initial Balance: " << myAccount.getBalance() << std::endl;

    // Deposit and withdraw money using public methods
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.withdraw(1500.0); // Attempt to withdraw more than balance

    return 0;
}