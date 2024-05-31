/*

---------- EXCEPTION HANDLING ----------

Exception handling in C++ is a mechanism that allows you to manage runtime errors and other exceptional conditions in a structured way. 
It uses the try, catch, and throw keywords to catch and handle exceptions, which are events that disrupt the normal flow of the program.

---------- USES ----------

Error Handling: Provides a way to handle errors gracefully without crashing the program.
Separation of Concerns: Separates error handling code from the main logic, making the code cleaner and easier to read.
Resource Management: Ensures resources are released properly when an exception occurs.
Debugging and Logging: Helps in debugging by catching unexpected errors and logging them.

---------- REAL-WORLD APPLICATIONS ----------

File I/O: Handling file not found or read/write errors.
Network Communication: Managing connection timeouts or lost connections.
User Input: Handling invalid user input in applications.
Database Operations: Managing database connection failures or query errors.

---------- SOFTWARE-RELATED APPLICATIONS ----------

Web Development: Handling HTTP request/response errors.
GUI Applications: Managing exceptions in event handling.
Real-time Systems: Ensuring systems respond appropriately to unexpected conditions.
API Development: Handling errors in API calls and responses.

---------- RULES AND GUIDELINES ----------

Try Block: Encapsulate the code that might throw an exception within a try block.
Catch Block: Use catch blocks to handle specific exceptions. Multiple catch blocks can be used to handle different exceptions.
Throw Keyword: Use throw to raise an exception.
Catch Order: Catch more specific exceptions before more general ones.
Uncaught Exceptions: If an exception is not caught, the program will terminate.

*/

#include <iostream>
#include <stdexcept>

class Division {
public:
    static double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw std::runtime_error("Division by zero error");
        }
        return numerator / denominator;
    }
};

int main() {
    double num, denom, result;
    
    std::cout << "Enter numerator: ";
    std::cin >> num;
    
    std::cout << "Enter denominator: ";
    std::cin >> denom;
    
    try {
        result = Division::divide(num, denom);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}