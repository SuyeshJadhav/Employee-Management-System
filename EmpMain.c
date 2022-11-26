#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

void addEmployee()
{
      int n;
      printf("Enter the number of entries: ");
      scanf("%d", &n);

      for (int i = 0; i < n; i++)
      {
            printf("\n");
            struct employee *newEmp = (struct employee *)malloc(sizeof(struct employee));
            printf("Enter the FirstName: ");
            scanf("%s", &newEmp->fname);

            printf("Enter the LastName: ");
            scanf("%s", &newEmp->lname);

            printf("Enter the age: ");
            scanf("%d", &newEmp->age);
            
            printf("Enter Experience: ");
            scanf("%d", &newEmp->experience);

            printf("Enter salary: ");
            scanf("%d", &newEmp->salary);

            printf("Enter id: ");
            scanf("%d", &newEmp->id);

            if (checkDuplicate(newEmp->id))
            {
                  printf("\nEmployee with same id already exixts..");
            }
            else
            {
                  if (head == NULL)
                  {
                        head = newEmp;
                        newEmp->next = NULL;
                  }
                  else
                  {
                        struct employee *node = head;
                        while (node->next!= NULL)
                        {
                              node = node->next;
                        }
                        node->next = newEmp;
                        newEmp->next = NULL;
                  }
            }
            
      }
}

int checkDuplicate(int id)
{
      if (head == NULL)
      {
            return 0;
      }
      struct employee *ptr = head;
      while (ptr)
      {
            if (ptr->id == id)
            {
                  return 1;
            }
            ptr = ptr->next;
      }
      return 0;
}

void displayEmployeeDetails()
{
      struct employee *ptr;
      ptr = head;
      printf("\n\nEmployee Name\t\t||\tEmployee ID\t||\tEmployee age\t||\tEmployee Salary\t||\tEmployee Tenure\n");
      printf("\n==================================================================================================================\n");
      while (ptr != NULL)
      {
            printf("%s %s\t\t||\t%d\t\t||\t%d\t\t||\t%d\t\t||\t%d\n\n", ptr->fname, ptr->lname, ptr->id, ptr->age, ptr->salary, ptr->experience);
            ptr = ptr->next;
      }
}

void removeEmployee()
{
      int empId;
      struct employee *temp1, *temp2;

      if (head == NULL)
      {
            printf("Employee List Empty");
      }
      else
      {
            printf("Enter Employee Id: ");
            scanf("%d", &empId);
            temp1 = head;
            while (temp1->id != empId)
            {
                  temp2 = temp1;
                  temp1 = temp1->next;
            }
            temp2->next = temp1->next;
            free(temp1);
      }
}

void updateEmpDetails(){}

void searchEmployee()
{
      int empID;
      struct employee *temp1;
      if (head == NULL)
      {
            printf("Employee List Empty");
      }
      else
      {
            printf("Enter the Employee ID : ");
            scanf("%d", &empID);
            temp1 = head;
            while (temp1->id != empID)
            {
                  temp1 = temp1->next;
            }
            printf("Employee ID: %d", empID);
            printf("Employee Name: %s %s", temp1->fname,temp1->lname);
            printf("Employee Age: %d", temp1->age);
            printf("Employee Salary: %d", temp1->salary);
            printf("Employee Tenure: %d", temp1-> experience);
      }
}