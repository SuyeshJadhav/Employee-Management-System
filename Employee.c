#include "EmpMain.c"
int main()
{
      head = NULL;
      int ch = 0;
      while (ch != 6)
      {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("\n1 -> Add Employee\n2 -> Delete Employee\n3 -> Update Employee Details\n4 -> Search Employee\n5 -> Display Employee Details\n7->Exit");
            printf("\nEnter Input: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
            {
                  printf("\n-------------------------------ADD EMPLOYEE--------------------------------------------\n\n");
                  addEmployee();
                  break;
            }
            case 2:
            {
                  printf("\n-------------------------------DELETE EMPOLYEE-----------------------------------------\n\n");
                  removeEmployee();
                  break;
            }
            case 3:
            {
                  printf("\n------------------------------UPDATE EMPLOYEE DETAIL----------------------------------\n\n");
                  updateEmployeeDetails();
                  break;
            }
            case 4:
            {
                  printf("\n-------------------------------SEARCH EMPLOYEE------------------------------------------\n\n");
                  searchEmployee();
                  break;
            }
            case 5:
            {
                  printf("\n-------------------------------DISPLAY EMPLOYEE DETAILS---------------------------------\n\n");
                  displayEmployeeDetails();
                  break;
            }
            default:
            {
                  printf("INVALID INPUT");
                  break;
            }
            }
      }

      return 0;
}
