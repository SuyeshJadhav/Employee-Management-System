#include "EmpMain.c"
int main()
{
      head = NULL;
      int ch = 0;
      while (ch != 6)
      {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("\n1 -> Add Employee\n2 -> Delete Employee\n3 -> Update Employee Details\n4 -> Search Employee\n5 -> Display Employee Details\n6 -> Add Employee Details to a file\n7->Exit");
            printf("\nEnter Input: ");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
                  addEmployee();
                  break;
            case 2:
                  removeEmployee();
                  break;
            case 3:
                  updateEmployeeDetails();
                  break;
            case 4:
                  searchEmployee();
                  break;
            case 5:
                  displayEmployeeDetails();
                  break;
            // case 6:
            //       displayEmployeeDetails();
            //       break;

            default:
                  printf("INVALID INPUT");
                  break;
            }
      }

      return 0;
}
