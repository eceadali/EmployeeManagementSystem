#include <stdio.h>
#include <stdlib.h>

// Define a structure for an employee
struct employee {
    char name[50];
    int employee_id;
    char position[50];
    float salary;
    struct employee *next; // Pointer to the next employee in the linked list
};

struct employee *head = NULL;
struct employee *temp = NULL;

// Function to check if an employee with the given name already exists
int checkDuplicate(const char *name) {
    temp = head;
    while (temp != NULL) {
        int i;
        // Compare each character of the names
        for (i = 0; i < 50 && temp->name[i] != '\0' && name[i] != '\0'; ++i) {
            if (temp->name[i] != name[i]) {
                break;
            }
        }

        if (i == 50 || (temp->name[i] == '\0' && name[i] == '\0')) {
            // Employee with the same name already exists
            return 1;
        }

        temp = temp->next;
    }
    // Employee with the given name does not exist
    return 0;
}

//Function to add a new employee to the linked list
void addEmployee(int id, float salary, const char *name, const char *position) {
    if (checkDuplicate(name)) {
        printf("Employee with name '%s' already exists. Cannot add duplicate employees.\n", name);
        return;
    }

    // Allocate memory for a new employee
    struct employee *newEmployee;
    newEmployee = (struct employee *)malloc(sizeof(struct employee));
    if (newEmployee == NULL) {
            printf("Memory allocation failed. Exiting program.\n");
            exit(EXIT_FAILURE);
        }
    // Initialize the new employee's fields
    newEmployee->employee_id = id;
    newEmployee->salary = salary;

    // Copy the name to the new employee's structure
    int i;
    for (i = 0; i < 50 && name[i] != '\0'; ++i) {
        newEmployee->name[i] = name[i];
    }
    newEmployee->name[49] = '\0';
    // Copy the position to the new employee's structure
    for (i = 0; i < 50 && position[i] != '\0'; ++i) {
        newEmployee->position[i] = position[i];
    }
    newEmployee->position[49] = '\0';
 
    // Add the new employee to the beginning of the linked list
    newEmployee->next = head;
    head = newEmployee;
}

// Function to delete an employee from the linked list based on employee ID
void deleteEmployee(int id) {
    struct employee *current = head;
    struct employee *prev = NULL;

    // Traverse the linked list to find the employee with the given ID
    while (current != NULL && current->employee_id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        // Employee with the given ID not found
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        // If the employee to be deleted is the first one
        head = current->next;
    } else {
        // If the employee to be deleted is not the first one
        prev->next = current->next;
    }

    free(current); // Free the memory occupied by the deleted employee
    printf("Employee with ID %d deleted successfully.\n", id);
}

// Function to search for an employee with a given name in the linked list
void searchEmployee(const char *searchName) {
    temp = head;

    while (temp != NULL) {
        int i;
        // Compare each character of the names
        for (i = 0; i < 50 && temp->name[i] != '\0' && searchName[i] != '\0'; ++i) {
            if (temp->name[i] != searchName[i]) {
                break;
            }
        }

        if (i == 50 || (temp->name[i] == '\0' && searchName[i] == '\0')) {
            // Either the end of the strings is reached or both strings match
            printf("Employee found:\n");
            printf("Employee ID: %d,\nName: %s,\nPosition: %s,\nSalary: %.2f\n",
                   temp->employee_id, temp->name, temp->position, temp->salary);
            return;
        }

        temp = temp->next; // Move to the next employee in the linked list
    }

    printf("Employee with name '%s' not found.\n", searchName);
}
// Function to display information about all employees in the linked list
void displayEmployees(void) {
    temp = head;
    if (temp == NULL) {
        printf("No employees to display.\n");
        return;
    }

    printf("Employee Information:\n");
    while (temp != NULL) {
        // Display information about each employee
        printf("Employee ID: %d,\nName: %s\nPosition: %s\nSalary:$%.2f\n\n",
               temp->employee_id, temp->name, temp->position, temp->salary);
        temp = temp->next;
    }
}
// Main function where the program execution begins
int main(void) {
    int choice, id, selected = 0;
    char name[50], position[50], searchName[50];
    float salary;

    // Main loop to interact with the user
    do {
        printf("\nEnter 1 to add employee\nEnter 2 to delete employee\nEnter 3 to search employee\nEnter 4 to display emplooyees\nEnter 0 to exit\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &id);

                printf("Enter employee name: ");
                scanf("%s", name);

                printf("Enter employee position: ");
                scanf("%s", position);

                printf("Enter employee salary: ");
                scanf("%f", &salary);
               
                addEmployee(id, salary, name, position);
                selected++;
                printf("Employee '%s' added succesfully.",name);
                break;

            case 2:
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(id);
                break;
                
            case 3:
                printf("Enter employee name to search: ");
                scanf("%s", searchName);
                searchEmployee(searchName);
                break;
            case 4:
                displayEmployees(); // Updated to display all employees
                break;
            case 0:
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, 3, 4 or 0.\n");
        }

    } while (choice != 0 && selected < 50);
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

