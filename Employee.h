#include <stdio.h>
#include <stdlib.h>

void addEmployee();
int checkDuplicate(int id);
void removeEmployee();
void displayEmployeeDetails();
void updateEmpDetails();

struct employee
{
      int age, salary, id, experience;
      char fname[20];
      char lname[20];
      struct employee *next;
      
}*head;
