#  Employee Management System Readme

Overview:
This C program implements a simple Employee Management System using a linked list. The system allows users to perform operations such as adding, deleting, searching, and displaying employee information. The program aims to provide a user-friendly interface for managing a list of employees efficiently.

Operations:
Add Employee (Enter 1):
Enter employee ID, name, position, and salary.
Checks for duplicate names before adding.
Delete Employee (Enter 2):
Enter the employee ID to delete the corresponding employee.
Search Employee (Enter 3):
Enter the employee name to search for and display details if found.
Display Employees (Enter 4):
Displays information about all employees in the system.
Exit (Enter 0):
Exits the program.

Design and Structure:
Data Structure:
The program uses a linked list to store employee information efficiently.
Each employee is represented by a structure (struct employee).
Functions:
checkDuplicate:
Checks if an employee with the given name already exists.
addEmployee:
Adds a new employee to the linked list, checking for duplicates.
deleteEmployee:
Deletes an employee based on the employee ID.
searchEmployee:
Searches for an employee by name and displays their information if found.
displayEmployees:
Displays information about all employees in the linked list.
Memory Management:
Proper memory allocation and deallocation are implemented to prevent memory leaks.
Challenges and Considerations

Memory Management:
Ensuring proper allocation and deallocation of memory for dynamic structures.
String Comparison:
Carefully comparing strings to handle duplicates and searches accurately.
User Input Handling:
Validating user inputs to prevent errors and ensure correct data types.
Linked List Operations:
Implementing linked list operations with attention to pointer management.

Limitations:
The program has a limit of 50 employees to prevent potential performance issues or excessive memory usage. This limit can be adjusted based on specific requirements.

Conclusion:
This Employee Management System provides a basic yet functional tool for managing employee data. Users can interact with the system through a menu-driven interface, and the program employs a linked list for efficient storage and retrieval of employee information.

