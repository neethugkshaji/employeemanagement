//preprocessor directives
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
	//prompt the user to enter choice
	pr("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
	//accept the choice to n
	sc("%d",&n);
	switch(n)
  	{
    	case 1: //call function to login as admin
                system("clear");
            	adminlogin();
                break;
    	case 2: //call function to login as employee
                system("clear");
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

//function to login as admin
void adminlogin()
{
    //declare variables
	int c,d;
	char username[30],password[30];
	pr("\n\n\t\t\tWELCOME TO ADMIN LOGIN");
	//prompt the user for username
	pr("\n\n\t\t\t  ENTER USERNAME: ");
    sc("%s",username);
    //prompt the user for password
    pr("\n\n\t\t\t  ENTER PASSWORD: ");
	sc("%s",password);
	//compare the entered user id with administrator userid
	c=strcmp(username,myuser);
	//compare the entered password with administrator password
	d=strcmp(password,mypass);
	//if user id  and password are correct call menu function
 	if(c==0 && d==0)
	{
		pr("\n\n\t\t\t\tLOGIN SUCCESSFULLY\n");
		system("clear");
		menu();
	}
	//if user id and password not correct display message invalid user
	else
	{
		pr("\n\n\t\t\t\tINVALID USERNAME OR PASSWORD!!!\n");
	}
}

//menu function
void menu()
{
	system("clear");
	//display the fucntions
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
    //prompt the user for the choice
 	pr("\n\n\t\t\tPLEASE CHOOSE A NUMBER FROM THE MENU ABOVE :");
	sc("%d",&n);
	switch(n)
	{
		case 1:	//call function to add employee
                addemp();
                break;
		case 2: //call function to delete employee
                delemp();
                break;
        case 3:	//call function to search employee
                seemp();
                break;
		case 4:	//call function to edit employee
                editemp();
                break;
		case 5: pr("\n\t\t\t\tThank you..Have a Nice day;)\n");
                exit(0);
                break;
		default: pr("\n\n\t\t\t\tINVALID CHOICE");
 	}

}

//function to add employee
void addemp()
{
    //declare variables
	int v=0;
	char name[50];
	char designation[50];
	char address[100];
	char phone[15];
	char id[30];
	float salary;
	float hours;
	FILE *fp;
	//open the file in append mode
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
	//prompt the user for employee name
	pr("\nName:");
	getchar();
	gets(name);
	//prompt the user for designation
	pr("\nDesignation:");
	gets(designation);
	//prompt the user for address
	pr("\nAddress:");
	gets(address);
	//prompt the user for phone number
	pr("\nPhone:");
	gets(phone);
	//prompt the user for id
	pr("\nID:");
	gets(id);
	//prompt the user for salary
	pr("\nSalary:");
	sc("%f", &salary);
	//prompt the user for number of hours worked
	pr("\nHours:");
	sc("%f", &hours);
	//validate if the id exist
	v=validate(id);
	//if id exist display message id exist
    if(v==1)
    {
        pr("\t\t\tEMPLOYEE ALREADY EXISTS!!!\n");
    }
    //if id does not exist add details
    else
    {
        fprintf(fp, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
    }
    //close the file
	fclose(fp);
	getchar();
	system("clear");
	//display message press enter to return to main menu
	pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
	if(getchar()==13)
	{
   		system("clear");
	}
	//call menu function
	menu();
}


//function to delete an employee
void delemp()
{
    //declare variables
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

	//open the file in read mode
	fp1=fopen("empfile.txt", "r+");
	//open the temporary file in write mode
	fp2 = fopen("tmpfile.txt", "w+");
	system("clear");
	pr("\t\t\t\tDELETE EMPLOYEE\n\n");
	//prompt the user for employee id to delete
	pr("Enter Employee ID to Delete : ");
	getchar();
	gets(idDel);
	do
	{   //read details of each employee record
		fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		//compare received id with the each record
		//check if id exist
		if((strcmp(id, idDel))== 0)
		{
			i=1;
			pr("\t\t\tDELETED SUCCESSFULLY\n");
			break;
		}
		if(feof(fp1))
		{
			break;
		}
		//if id doesn't exist
		if((strcmp(id, idDel))!= 0)
		{
			fprintf(fp2, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
		}
	}while(!(feof(fp1)));
	//close the files
	fclose(fp1);
	fclose(fp2);
	remove("empfile.txt");
	rename("tmpfile.txt", "empfile.txt");
	if(i==0)
	{
		pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
	}
	//display message press enter to return to main menu
	pr("\nPRESS ENTER TO RETURN TO MAIN MENU  >>>");
	if(getchar()==13)
	{
        system("clear");
	}
	//call menu function
	menu();
}

//function to search employee and display details
void seemp()
{
    //declare the variables
    FILE *fp1;
    char sid[30];
	char name[50];
	char designation[50];
	char address[100];
	char phone[15];
	char id[30];
	float salary;
	float hours;
	//open the file in read mode
    fp1=fopen("empfile.txt","r+");
    int i=0;
	system("clear");
    pr("\t\t\t\tSEARCH EMPLOYEE\n\n");
    //prompt user for employee id
    pr("Enter the Employee Id : ");
	getchar();
    gets(sid);
	do
    {   //read details of each employee
        fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		//check id file exist
		if(feof(fp1))
        {
            break;
        }
        //compare the received id with each record in the file
        //if id exist in file
        if((strcmp(id,sid))==0)
        {
            i=1;
            //print the details of the employee
            pr("Name :%s \nDesignation :%s\nAddress : %s\nPhone : %s\nId : %s\nSalary : %.2f\nHours : %.2f\n",name,designation,address,phone,id,salary,hours);
			break;
        }
        }while(!(feof(fp1)));
        //close the file                                                                                                                                                        		}while(!(feof(fp1)));
        fclose(fp1);
        //if employee doesn't exist display the message
        if(i==0)
        {
                pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
        }
        //display message press enter to return to main menu
        pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
        if(getchar()==13)
        {
                system("clear");

        }
        //call the menu function
        menu();
}


//function to edit details of employee
void editemp()
{
    //declare the variables
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

	//open the file in read mode
	fp1=fopen("empfile.txt", "r+");
	//open temp file in write mode
	fp2=fopen("tmpfile.txt", "w+");
	system("clear");
	pr("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
	//prompt the user for employee id to search
	pr("Enter Employee ID to Edit : ");
	//accept the id to idEdit
	sc("%s",idEdit);
	do
	{
	    //read details of each employee
		fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
		//check if file exists
		if(feof(fp1))
		{
		break;
		}
		//compare the received id with each record in file
		//if id exists in file
		if((strcmp(id,idEdit))==0)
		{
			i=1;
			system("clear");
			pr("\t\t\t\tEDIT EMPLOYEE DETAILS\n\n");
			//display menu to change details
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
                //prompt the user to enter the choice
                pr("\n\n\t\t\tPLEASE CHOOSE A NUMBER FROM THE MENU ABOVE :");
                //accept the choice to n
                sc("%d",&n);
                system("clear");
                switch(n)
                {
                    case 1:	//prompt the user for new name
                            pr("Enter the changed name of the Employee : ");
                            getchar();
                            gets(name);
                            break;
                    case 2:	//prompt the user for new designation
                            pr("Enter the new Designation : ");
                            getchar();
                            gets(designation);
                            break;
                    case 3: //prompt the user for new address
                            pr("Enter the new Address : ");
                            getchar();
                            gets(address);
                            break;
                    case 4: //prompt the user for new phone number
                            pr("Enter the new Phone number : ");
                            getchar();
                            gets(phone);
                            break;
                    case 5:	//prompt the user for new basic salary
                            pr("Enter new basic salary : ");
                            sc("%f",&salary);
                            break;
                    case 6:	//prompt the user for new number of hours worked
                            pr("Enter the new number of hours worked : ");
                            sc("%f",&hours);
                            break;
                    default://display invalid choice
                            pr("\t\t\tINVALID CHOICE!!!");
                }
                //prompt the user to change more details or not
                pr("\t\t\tDo you want to edit more? 1:yes/2:no ");
                //accept the choice to c
                sc("%d",&c);
                }while(c==1);
            }
            fprintf(fp2, "%s/%s/%s/%s/%s/%.2f %.2f\n", name, designation, address, phone, id, salary, hours);
            }while(!(feof(fp1)));
    //close the files
    fclose(fp1);
    fclose(fp2);
    //remove empfile.txt file
    remove("empfile.txt");
    //rename the temp file as empfile
    rename("tmpfile.txt","empfile.txt");
    //if id does not exist display employee doesn't exist
    getchar();
    if(i==0)
    {
        pr("\t\t\tEMPLOYEE-ID DOESN'T EXIST!!!\n\n");
    }
    getchar();
	system("clear");
	//press enter to return to main menu
	pr("PRESS ENTER TO RETURN TO MAIN MENU  >>>");
	if(getchar()==13)
	{
        	system("clear");
	}
	//call menu function
	menu();

}

//function to check a user exists
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

        //open file in read mode
        fp1=fopen("empfile.txt","r+");
        //copy the received id to sid
        strcpy(sid,p);
        system("clear");
        do
        {
                //read details of each employee
                fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%f %f%*c", name, designation, address, phone, id, &salary, &hours);
                //check if file exists
                if(feof(fp1))
                {

                        break;
                }
                //compare received id with each record in file
                if((strcmp(id,sid))==0)
                {
                        i=1;
                        //if id exists return 1
                        return 1;

                }


        }while(!(feof(fp1)));
        //close the file
        fclose(fp1);

}
