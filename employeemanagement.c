#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2cRyP_Ti!C"
#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 100
#define MAX_POSITION_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_EMAIL_LENGTH 100
#define MAX_NID_LENGTH 20
#define MAX_BANK_LENGTH 30

// Arrays to store employee details
int employeeIds[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][MAX_NAME_LENGTH];
char employeePositions[MAX_EMPLOYEES][MAX_POSITION_LENGTH];
int employeeSalaries[MAX_EMPLOYEES];
char employeeAddresses[MAX_EMPLOYEES][MAX_ADDRESS_LENGTH];
char employeeNIDs[MAX_EMPLOYEES][MAX_NID_LENGTH];
char employeeEmails[MAX_EMPLOYEES][MAX_EMAIL_LENGTH];
char employeeBankAccounts[MAX_EMPLOYEES][MAX_BANK_LENGTH];
int nextEmployeeId = 1;
int employeeCount = 0;

// Function to check password
int checkPassword()
{
    char input[20];
    printf("Enter password: ");
    scanf("%s", input);

    if (strcmp(input, PASSWORD) == 0)
    {
        printf("Correct password.\n");
        return 1;
    }
    else
    {
        printf("Incorrect password.\n");
        return 0;
    }
}

// Function to add an employee
void addEmployee()
{
    if (!checkPassword())
        return; // Exit if password is incorrect

    printf("Employee name: ");
    scanf(" %[^\n]", employeeNames[employeeCount]);
    printf("Position: ");
    scanf(" %[^\n]", employeePositions[employeeCount]);
    printf("Salary: ");
    scanf("%d", &employeeSalaries[employeeCount]);
    printf("Address: ");
    scanf(" %[^\n]", employeeAddresses[employeeCount]);
    printf("NID: ");
    scanf(" %[^\n]", employeeNIDs[employeeCount]);
    printf("Email: ");
    scanf(" %[^\n]", employeeEmails[employeeCount]);
    printf("Bank account: ");
    scanf(" %[^\n]", employeeBankAccounts[employeeCount]);

    employeeIds[employeeCount] = nextEmployeeId++;
    employeeCount++;
    printf("Employee added successfully! ID: %d\n", employeeIds[employeeCount - 1]);
}

// Function to view all employees
void viewEmployees()
{
    if (employeeCount == 0)
    {
        printf("No employees in the system.\n");
        return;
    }

    printf("\nList of employees:\n\n");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("ID: %d\n  Name: %s\n\n  Position: %s\n\n  Salary: %d\n\n  Address: %s\n\n  NID: %s\n\n  Email: %s\n\n  Bank Account: %s\n\n",
               employeeIds[i], employeeNames[i], employeePositions[i],
               employeeSalaries[i], employeeAddresses[i], employeeNIDs[i], employeeEmails[i], employeeBankAccounts[i]);
        printf("----------------------------\n");
    }
}

// Function to search for an employee by name
void searchEmployeeByName()
{
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeNames[i], searchName) == 0)
        {
            printf("ID: %d\n  Name: %s\n  Position: %s\n  Salary: %d\n  Address: %s\n  NID: %s\n  Email: %s\n  Bank Account: %s\n\n",
                   employeeIds[i], employeeNames[i], employeePositions[i],
                   employeeSalaries[i], employeeAddresses[i], employeeNIDs[i], employeeEmails[i], employeeBankAccounts[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Employee not found.\n");
    }
}

// Function to search for an employee by ID
void searchEmployeeById()
{
    int searchId;
    int found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIds[i] == searchId)
        {
            printf("ID: %d\n  Name: %s\n  Position: %s\n  Salary: %d\n  Address: %s\n  NID: %s\n  Email: %s\n  Bank Account: %s\n\n",
                   employeeIds[i], employeeNames[i], employeePositions[i],
                   employeeSalaries[i], employeeAddresses[i], employeeNIDs[i], employeeEmails[i], employeeBankAccounts[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

// Function to delete an employee by ID
void deleteEmployee()
{
    if (!checkPassword())
        return; // Exit if password is incorrect

    int deleteId;
    printf("Enter employee ID to delete: ");
    scanf("%d", &deleteId);

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIds[i] == deleteId)
        {
            for (int j = i; j < employeeCount - 1; j++)
            {
                employeeIds[j] = employeeIds[j + 1];
                strcpy(employeeNames[j], employeeNames[j + 1]);
                strcpy(employeePositions[j], employeePositions[j + 1]);
                employeeSalaries[j] = employeeSalaries[j + 1];
                strcpy(employeeAddresses[j], employeeAddresses[j + 1]);
                strcpy(employeeNIDs[j], employeeNIDs[j + 1]);
                strcpy(employeeEmails[j], employeeEmails[j + 1]);
                strcpy(employeeBankAccounts[j], employeeBankAccounts[j + 1]);
            }
            employeeCount--;
            found = 1;
            printf("Employee deleted successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Employee ID not found.\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nEmployee Management System\n\n");
        printf("1. Add Employee (Password Protected)\n");
        printf("2. View Employees\n");
        printf("3. Search Employee by Name\n");
        printf("4. Search Employee by ID\n");
        printf("5. Delete Employee (Password Protected)\n");
        printf("6. Exit\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            viewEmployees();
            break;
        case 3:
            searchEmployeeByName();
            break;
        case 4:
            searchEmployeeById();
            break;
        case 5:
            deleteEmployee();
            break;
        case 6:
            printf("Exit\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
