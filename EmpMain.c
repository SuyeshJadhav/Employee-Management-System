#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

void addEmployee()
{
      int n;
      printf("Enter the number of Employees: ");
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

            printf("Enter Experience years: ");
            scanf("%d", &newEmp->experience);

            printf("Enter salary: ");
            scanf("%d", &newEmp->salary);

            printf("Enter id: ");
            scanf("%d", &newEmp->id);

            if (checkDuplicate(newEmp->id))
            {
                  printf("\n\tEMPLOYEE WITH SAME ID ALREADY EXISTS");
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
      addToFile();
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
      printf("\n\nEmployee Name\t\t||\tEmployee ID\t||\tEmployee age\t||\tEmployee Salary\t||\tEmployee Experience\n");
      printf("\n==================================================================================================================\n");
      while (ptr != NULL)
      {
            printf("%s %s\t\t||\t%d\t\t||\t%d\t\t||\t%d\t\t||\t%d\n\n", ptr->fname, ptr->lname, ptr->id, ptr->age, ptr->salary, ptr->experience);
            ptr = ptr->next;
      }
}

void removeEmployee()
{

      int empId, flag = 0;
      struct employee *preptr, *ptr;
      if (head == NULL)
      {
            printf("\tEMPLOYEE LIST IS EMPTY\n");
      }
      else
      {
            printf("\nEnter Employee Id: ");
            scanf("%d", &empId);
            printf("\n--------1-------\n");
            ptr = head;

            while (ptr != NULL)
            {
                  if (ptr->id == empId)
                  {
                        flag = 1;
                        break;
                  }

                  ptr = ptr->next;
            }
            if (flag == 0)
            {
                  printf("\n\tEMPLOYEE NOT FOUND\n");
                  printf("\n-------2--------\n");
                  ptr = NULL;
                  return;
            }

            else
            {
                  if (empId == head->id)
                  {
                        ptr = head;
                        head = head->next;
                        free(ptr);
                        printf("\n\tEMPLOYEE DATA DELETED SUCCESSFULLY!!\n");
                        printf("\n-------3--------\n");
                  }
                  else
                  {
                        ptr = head;
                        printf("\n-------4--------\n");
                        while (ptr != NULL)
                        {
                              if (ptr->id == empId)
                              {
                                    break;
                              }
                              preptr = ptr;
                              ptr = ptr->next;
                        }
                        preptr->next = ptr->next;
                        free(ptr);
                        printf("\tEMPLOYEE DATA DELETED SUCCESSFULLY!!\n");
                  }
            }
      }
      addToFile();
}

void updateEmployeeDetails()
{
      if (head == NULL)
      {
            printf("\tEMPLOYEE LIST IS EMPTY\n");
      }
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
                        printf("Enter Experience years: ");
                        scanf("%d", &elem);
                        temp->experience = elem;
                        break;
                  case 6:
                        break;

                  default:
                        printf("\tINVALID INPUT\n");
                        break;
                  }
            }
      }
      addToFile();
}

struct employee *searchEmployee()
{

      int empID, flag = 0;
      struct employee *temp1;
      if (head == NULL)
      {
            printf("\n\tEMPLOYEE LIST IS EMPTY\n");
            return head;
      }
      else
      {
            printf("Enter the Employee ID : ");
            scanf("%d", &empID);
            temp1 = head;
            while (temp1 != NULL)
            {
                  if (temp1->id == empID)
                  {
                        flag = 1;
                        break;
                  }
                  temp1 = temp1->next;
            }
            if (flag == 0)
            {
                  printf("\n\tEMPLOYEE NOT FOUND\n");
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

void addToFile()
{
      FILE *fptr;

      fptr = fopen("EmployeeData.txt", "w");
      struct employee *ptr;
      ptr = head;
      fputs("\n\nEmployee Name\t\t||\tEmployee ID\t||\tEmployee age\t||\tEmployee Salary\t||\tEmployee Experience\n", fptr);
      fputs("\n==================================================================================================================\n", fptr);
      while (ptr != NULL)
      {
            fprintf(fptr, "%s %s\t\t||\t%d\t\t||\t%d\t\t||\t%d\t\t||\t%d\n\n", ptr->fname, ptr->lname, ptr->id, ptr->age, ptr->salary, ptr->experience);
            ptr = ptr->next;
      }
      fclose(fptr);
}