#include <stdio.h>
#include <stdlib.h>

void addEmployee();
void removeEmployee();
void displayEmployeeDetails();
void updateEmployeeDetails();
void addToFile();
int checkDuplicate(int id);
struct employee * searchEmployee();

struct employee
{
      int age, salary, id, experience;
      char fname[20];
      char lname[20];
      struct employee *next;
      
}*head;
