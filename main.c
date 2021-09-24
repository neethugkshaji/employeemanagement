#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define myuser "neethu"
#define mypass "1234"
#define pr printf
#define sc scanf
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
	pr("\n\n\n\n\n\t\t\t\tWELCOME TO PAYROLL MANAGEMENT");
	pr("\n\t\t\t\t============================");
	pr("\n\n\n\n\t\t\t\tPress Enter to proceed...!!");
	if(getchar()==13)
	{
 		system("clear");
	}
	pr("\n\n\n\t\t\t1. ADMIN LOGIN\t\t2. EMPLOYEE LOGIN");
	pr("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
	sc("%d",&n);
	switch(n)
  	{
    	case 1: system("clear");
            	adminlogin();
                break;
    	case 2: system("clear");
                //employeelogin();
                break;
    	default: pr("\n\n\t\t\t\tWRONG CHOICE");
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
	pr("\n\n\t\t\tWELCOME TO ADMIN LOGIN");
	pr("\n\n\t\t\t  ENTER USERNAME: ");
    sc("%s",username);
    pr("\n\n\t\t\t  ENTER PASSWORD: ");
	sc("%s",password);
	c=strcmp(username,myuser);
	d=strcmp(password,mypass);
	if(c==0 && d==0)
	{
		pr("\n\n\t\t\t\tLOGIN SUCCESSFULLY\n");
		system("clear");
		menu();
	}
	else
	{
		pr("\n\n\t\t\t\tINVALID USERNAME OR PASSWORD!!!\n");
	}
}

void menu()
{
	system("clear");
	pr("\n\t\t\t\t\t MENU\n\t\t\t ______________________________________________");
    pr("\n\t\t\t| [1] ADD EMPLOYEE                             |");
    pr("\n\t\t\t| _____________________________________________|");
    pr("\n\t\t\t| [2] DELETE EMPLOYEE                          |");
    pr("\n\t\t\t| _____________________________________________|");
    pr("\n\t\t\t| [3] SEARCH EMPLOYEE                          |");
    pr("\n\t\t\t| _____________________________________________|");
    pr("\n\t\t\t| [4] EDIT EMPLOYEE                            |");
    pr("\n\t\t\t| _____________________________________________|");
    pr("\n\t\t\t| [5] EXIT                                     |");
 	pr("\n\n\t\t\tPLEASE CHOOSE A NUMBER FROM THE MENU ABOVE :");
	sc("%d",&n);
	switch(n)
	{
		case 1:	addemp();
                break;
		case 2: delemp();
                break;
        case 3:	seemp();
                break;
		case 4:	editemp();
                break;
		case 5: pr("\n\t\t\t\tThank you..Have a Nice day;)\n");
                exit(0);
                break;
		default: pr("\n\n\t\t\t\tINVALID CHOICE");
 	}

}

void addemp()
{
	int v=0;
	char name[50];
	char designation[50];
	char address[100];
	char phone[15];
	char id[30];
	float salary;
	float hours;
	FILE *fp;
	fp=fopen("empfile.txt", "a+");
	do
	{
		fscanf(fp, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		if(feof(fp))
		{
		break;
		}
	}while(!(feof(fp)));
	system("clear");
	pr("\t\t\t\tADD EMPLOYEE DETAILS\n");
	pr("\nName:");
	getchar();
	gets(name);
	pr("\nDesignation:");
	gets(designation);
	pr("\nAddress:");
	gets(address);
	pr("\nPhone:");
	gets(phone);
	pr("\nID:");
	gets(id);
	pr("\nSalary:");
	sc("%f", &salary);
	pr("\nHours:");
	sc("%f", &hours);
	v=validate(id);
    if(v==1)
    {
        pr("\t\t\tEMPLOYEE ALREADY EXISTS!!!\n");
    }
    else
    {
        fprintf(fp, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
    }
	fclose(fp);
	getchar();
	system("clear");
	pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
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
	char designation[50];
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
	pr("\t\t\t\tDELETE EMPLOYEE\n\n");
	pr("Enter Employee ID to Delete : ");
	getchar();
	gets(idDel);
	do
	{
		fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		if((strcmp(id, idDel))== 0)
		{
			i=1;
			pr("\t\t\tDELETED SUCCESSFULLY\n");
		}
		if(feof(fp1))
		{
			break;
		}
		if((strcmp(id, idDel))!= 0)
		{
			fprintf(fp2, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
		}
	}while(!(feof(fp1)));
	fclose(fp1);
	fclose(fp2);
	remove("empfile.txt");
	rename("tmpfile.txt", "empfile.txt");
	if(i==0)
	{
		pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
	}
	pr("\nPRESS ENTER TO RETURN TO MAIN MENU  >>>");
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
	char designation[50];
	char address[100];
	char phone[15];
	char id[30];
	float salary;
	float hours;
    fp1=fopen("empfile.txt","r+");
    int i=0;
	system("clear");
    pr("\t\t\t\tSEARCH EMPLOYEE\n\n");
    pr("Enter the Employee Id : ");
	getchar();
    gets(sid);
	do
    {
        fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		if(feof(fp1))
        {
            break;
        }
        if((strcmp(id,sid))==0)
        {
            i=1;
            pr("Name :%s \nDesignation :%s\nAddress : %s\nPhone : %s\nId : %s\nSalary : %.2f\nHours : %.2f\n",name,designation,address,phone,id,salary,hours);
			break;
        }                                                                                                                                                         		}while(!(feof(fp1)));
        fclose(fp1);
        if(i==0)
        {
                pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
        }
        pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
                system("clear");

        }
        menu();
}

void editemp()
{
	int i=0,c;
	char name[50];
	char designation[50];
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
	pr("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
	pr("Enter Employee ID to Edit : ");
	sc("%s",idEdit);
	do
	{
		fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		if(feof(fp1))
		{
		break;
		}
		if((strcmp(id,idEdit))==0)
		{
			i=1;
			system("clear");
			pr("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
			do
			{
                pr("\n\t\t\t\t\t MENU\n\t\t\t_______________________________________________");
        		pr("\n\t\t\t| [1] CHANGE NAME                              |");
        		pr("\n\t\t\t| _____________________________________________|");
        		pr("\n\t\t\t| [2] CHANGE DESIGNATION                       |");
    			pr("\n\t\t\t| _____________________________________________|");
    			pr("\n\t\t\t| [3] CHANGE ADDRESS                           |");
    			pr("\n\t\t\t| _____________________________________________|");
    			pr("\n\t\t\t| [4] CHANGE PHONE NUMBER                      |");
    			pr("\n\t\t\t| _____________________________________________|");
    			pr("\n\t\t\t| [5] CHANGE SALARY                            |");
    			pr("\n\t\t\t| _____________________________________________|");
    			pr("\n\t\t\t| [6] CHANGE HOURS                             |");
                pr("\n\n\t\t\tPLEASE CHOOSE A NUMBER FROM THE MENU ABOVE :");
                sc("%d",&n);
                system("clear");
                switch(n)
                {
                    case 1:	pr("Enter the changed name of the Employee : ");
                            getchar();
                            gets(name);
                            break;
                    case 2:	pr("Enter the new Designation : ");
                            getchar();
                            gets(designation);
                            break;
                    case 3: pr("Enter the new Address : ");
                            getchar();
                            gets(address);
                            break;
                    case 4: pr("Enter the new Phone number : ");
                            getchar();
                            gets(phone);
                            break;
                    case 5:	pr("Enter new basic salary : ");
                            sc("%f",&salary);
                            break;
                    case 6:	pr("Enter the new number of hours worked : ");
                            sc("%f",&hours);
                            break;
                    default: pr("\t\t\tINVALID CHOICE!!!");
                }
                pr("\t\t\tDo you want to edit more? 1:yes/2:no ");
                sc("%d",&c);
                }while(c==1);
            }
            fprintf(fp2, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
            }while(!(feof(fp1)));
    fclose(fp1);
    fclose(fp2);
    remove("empfile.txt");
    rename("tmpfile.txt","empfile.txt");
    if(i==0)
    {
        pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
    }
    getchar();
	system("clear");
	pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
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
        char designation[50];
        char address[100];
        char phone[15];
        char id[30];
        float salary;
        float hours;
        int i=0;
        fp1=fopen("empfile.txt","r+");
        strcpy(sid,p);
        system("clear");
        do
        {
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
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
