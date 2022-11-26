#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
                        while (node->next != NULL)
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

void updateEmployeeDetails()
{

      if (head == NULL)
            printf("Employee List Empty");

      else
      {

            struct employee *temp = searchEmployee();
            if (temp == NULL)
            {
                  return;
            }
            else
            {
                  int ch = 0, elem;
                  char name[20];
                  printf("\n1.Edit Age\n2.Edit Salary\n3.Edit FirstName\n4.Edit LastName\n5.Edit Experience\n6.Exit");
                  printf("\nEnter choice: ");
                  scanf("%d", &ch);

                  switch (ch)
                  {
                  case 1:
                        printf("Enter new Age: ");
                        scanf("%d", &elem);
                        temp->age = elem;
                        break;
                  case 2:
                        printf("Enter new Salary: ");
                        scanf("%d", &elem);
                        temp->salary = elem;
                        break;
                  case 3:
                        printf("Enter new First Name: ");
                        scanf("%s", &name);
                        for (int i = 0; i < strlen(name); i++)
                        {
                              temp->fname[i] = name[i];
                        }

                        break;
                  case 4:
                        printf("Enter new Last Name: ");
                        scanf("%s", &name);
                        for (int i = 0; i < strlen(name); i++)
                        {
                              temp->lname[i] = name[i];
                        }
                        break;
                  case 5:
                        printf("Enter Experience: ");
                        scanf("%d", &elem);
                        temp->experience = elem;
                        break;
                  case 6:
                        break;

                  default:
                        printf("Invalid Input");
                        break;
                  }
            }
      }
}

struct employee *searchEmployee()
{
      int empID, flag = 0;
      struct employee *temp1;
      if (head == NULL)
      {
            printf("Employee List Empty");
            return head;
      }
      else
      {
            printf("Enter the Employee ID : ");
            scanf("%d", &empID);
            temp1 = head;
            while (temp1->id != empID)
            {
                  temp1 = temp1->next;
                  if (temp1->id == empID)
                  {
                        flag = 1;
                        break;
                  }
            }
            if (!flag)
            {
                  printf("\nEmployee Not found");
                  temp1 = NULL;
                  return temp1;
            }
            else
            {
                  printf("\nEmployee ID: %d", empID);
                  printf("\nEmployee Name: %s %s", temp1->fname, temp1->lname);
                  printf("\nEmployee Age: %d", temp1->age);
                  printf("\nEmployee Salary: %d", temp1->salary);
                  printf("\nEmployee Tenure: %d \n", temp1->experience);
            }

            return temp1;
      }
}