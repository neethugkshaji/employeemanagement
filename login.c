#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define myuser "neethu"
#define mypass "1234"
void adminlogin();
void addemp();
int validate(char *);
void delemp();
void seemp();
void editemp();
void employeelogin();
void menu();
int n;
int main()
{
        system("clear");
        printf("\n\n\n\n\n\t\t\t\tWELCOME TO MY WEBSITE");
        printf("\n\t\t\t\t=====================");
        printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
        if(getchar()==13)
        {
                system("clear");
        }
        printf("\n\n\n\t\t\t1. ADMIN LOGIN\t\t2. EMPLOYEE LOGIN");
        printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1: system("clear");
                adminlogin();
                break;
        case 2: system("clear");
                //employeelogin();
                break;
        default: printf("\n\n\t\t\t\tWRONG CHOICE");
        if(getchar()==13)
        {
                system("clear");
        }
  }
  return 0;
}
void adminlogin()
{
        int c,d;
        char username[30],password[30];
        printf("\n\n\t\t\t\tWELCOME TO ADMIN LOGIN");
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",username);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        scanf("%s",password);
        c=strcmp(username,myuser);
        d=strcmp(password,mypass);
        if(c==0 && d==0)
        {
                printf("\n\n\t\t\t\tLOGIN SUCCESSFULLY\n");
                system("clear");
                menu();
        }
        else
        {
                printf("\n\n\t\t\t\tINVALID USERNAME OR PASSWORD!!!\n");
        }
}

void menu()
{
        system("clear");
        printf("\n\t\t\t\t\t MENU\n\t\t\t\t _____________________________________________");
        printf("\n\t\t\t\t| [1] ADD EMPLOYEE                             |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [2] DELETE EMPLOYEE                          |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [3] SEARCH EMPLOYEE                          |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [4] EDIT EMPLOYEE                            |");
        printf("\n\t\t\t\t| _____________________________________________|");
        printf("\n\t\t\t\t| [5] EXIT                                     |");
        printf("\n\n\t\t\t\tPLEASE CHOOSE A NUMBER FROM THE MENU ABOVE :");
        scanf("%d",&n);
        switch(n)
        {
                case 1: addemp();
                        break;
                case 2: delemp();
                        break;
                case 3: seemp();
                        break;
                case 4: editemp();
                        break;
                case 5: printf("\n\t\t\t\tThank you..Have a Nice day;)\n");
                        exit(0);
                        break;
                default: printf("\n\n\t\t\t\tINVALID CHOICE");
        }

}

void addemp()
{
        char name[50];
        char address[100];
        char phone[15];
        char id[30];
        float salary;
        float hours;
        int v;
        FILE *fp;
        fp=fopen("empfile.txt", "a+");
        do
        {
                fscanf(fp, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, address, phone, id, &salary, &hours);
                if(feof(fp))
                {
                break;
                }
        }while(!(feof(fp)));
        system("clear");
        printf("\t\t\t\tADD EMPLOYEE DETAILS\n");
        printf("\nName:");
        getchar();
         gets(name);
        printf("\nAddress:");
        gets(address);
        printf("\nPhone:");
        gets(phone);
        printf("\nID:");
        gets(id);
        printf("\nSalary:");
        scanf("%f", &salary);
        printf("\nHours:");
        scanf("%f", &hours);
        v=validate(id);
        if(v==1)
        {
                printf("employee exists!!!");
        }
        else
        {
                fprintf(fp, "%s/%s/%s/%s/%.2f %.2f\n", name, address, phone, id, salary, hours);
        }
        fclose(fp);
        getchar();
        system("clear");
        printf("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
                system("clear");
        }
        menu();
}

void delemp()
{
        int i=0;
        char name[50];
        char address[100];
        char phone[15];
        char id[30];
        char idDel[30];
        float salary;
        float hours;
        FILE *fp1;
	FILE *fp2;
        fp1=fopen("empfile.txt", "r+");
        fp2 = fopen("tmpfile.txt", "w+");
        system("clear");
        printf("\t\t\t\tDELETE EMPLOYEE\n\n");
        printf("Enter Employee ID to Delete : ");
        getchar();
        gets(idDel);
        do
        {
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, address, phone, id, &salary, &hours);
                if((strcmp(id, idDel))== 0)
                {
                        i=1;
                }
                if(feof(fp1))
                {
                        break;
                }
                if((strcmp(id, idDel))!= 0)
                {
                        fprintf(fp2, "%s/%s/%s/%s/%.2f %.2f\n", name, address, phone, id, salary, hours);
                }
        }while(!(feof(fp1)));
        fclose(fp1);
        fclose(fp2);
        remove("empfile.txt");
        rename("tmpfile.txt", "empfile.txt");
        if(i==0)
        {
                printf("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
        }
        printf("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
        system("clear");
        }
        menu();
}
void seemp()
{

        FILE *fp1;
        char sid[30];
        char name[50];
        char address[100];
        char phone[15];
        char id[30];
        float salary;
        float hours;
        fp1=fopen("empfile.txt","r+");
        int i=0;
        system("clear");
        printf("\t\t\t\tSEARCH EMPLOYEE\n\n");
        printf("Enter the Employee Id ");
        getchar();
        gets(sid);
        do
        {
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, address, phone, id, &salary, &hours);
                if(feof(fp1))
                {
                        break;
                }
                if((strcmp(id,sid))==0)
                {
                        i=1;
                        printf("Name :%s \nAddress : %s\nPhone : %s\nId : %s\nSalary : %.1f\nHours : %.2f\n",name,address,phone,id,salary,hours);
                        break;
                }                                                                                                                                                                       }while(!(feof(fp1)));
        fclose(fp1);
        if(i==0)
        {
                printf("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
        }
        printf("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
                system("clear");
                
        }
        menu();
}

void editemp()
{
        int i=0;
        char name[50];
        char address[100];
        char phone[15];
        char id[5];
        char idEdit[5];
        float salary;
        float hours;
        FILE *fp1;
        FILE *fp2;
        fp1=fopen("empfile.txt", "r+");
        fp2=fopen("tmpfile.txt", "w+");
        system("clear");
        printf("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
        printf("Enter Employee ID to Edit : ");
        scanf("%s",idEdit);
        do
        {
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, address, phone, id, &salary, &hours);
                if(feof(fp1))
                {
                break;
                }
                if((strcmp(id,idEdit))==0)
                {
                        i=1;
                        system("clear");
                        printf("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
                        printf("Enter the changed name of the Employee : ");
                        getchar();
                        gets(name);
                        printf("Enter the new Address : ");
                        gets(address);
                        printf("Enter the new Phone number : ");
                        gets(phone);
                        printf("Enter new basic salary : ");
                        scanf("%f",&salary);
                        printf("Enter the new number of hours worked : ");
                        scanf("%f",&hours);
                }
                fprintf(fp2, "%s/%s/%s/%s/%.2f %.2f\n", name, address, phone, id, salary, hours);
        }while(!(feof(fp1)));
        fclose(fp1);
        fclose(fp2);
        remove("empfile.txt");
        rename("tmpfile.txt","empfile.txt");
        if(i==0)
        {
                printf("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
        }
        system("clear");
	getchar();
        printf("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
                system("clear");
        }
        menu();
}

int validate(char *p)
{
        FILE *fp1;
        char sid[30];
        char name[50];
        char address[100];
        char phone[15];
        char id[30];
        float salary;
        float hours;
        fp1=fopen("empfile.txt","r+");
        int i=0;
        strcpy(sid,p);
        system("clear");
        do
        {
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, address, phone, id, &salary, &hours);
                if(feof(fp1))
                {
                	
                        break;
                }
                if((strcmp(id,sid))==0)
                {
                        i=1;
                        return 1;

                }


          }while(!(feof(fp1)));
        fclose(fp1);

}

