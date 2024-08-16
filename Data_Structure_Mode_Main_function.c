//Author :  Yaser Imtiyaz Ahmed Shaikh
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include "Data_Structure_structure.h"

//Admin Functions
void Admin()
{
	int admin_choice;
	int no_of_admin=0;
	int admin_data=0;
	A A_Register[admin_count];

	//Menu For Admin
	do
	{
		printf("\nChoose The Following Options");
		printf("\n1: Log In");
		printf("\n2: Main Menu");
		printf("\nThe Choice Entered By Admin is : "); 
		rtn = scanf("%d",&admin_choice);
		printf("\n\n");
		if (rtn == 0) 
		{    
    	printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    	empty_stdin();
    }
		else
		switch(admin_choice)
		{
			case 1:
			admin_data=admin_insertion(A_Register,admin_data);
			no_of_admin=log_in(A_Register,no_of_admin);
			break;
			
			case 2:
			printf("\nMAIN MENU");
			printf("\nChoose From The Following Mode:");
			printf("\n1: Admin Mode");
			printf("\n2: User Mode");
			printf("\n3: Owner Mode");
			printf("\n4: Exit");
			printf("\nThe Choice of Mode is : ");
			rtn = scanf("%d",&Mode);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid integer input.\033[0m\n");
				empty_stdin();
			}
			else
			menu(Mode);
			break;
			
			default:
			printf("\033[1;31mInvalid Choice\033[0m\n");
			
		}
	}
	while(admin_choice!=2);
}


//User Functions
void User()
{	
	int choice;
	int no_of_Insert_registration=0;
	int no_of_Login=0;
	int no_of_registration=0;
	R R_Register[max_count];
	do
	{
		printf("\n\nUser Main Menu :");
		printf("\nChoose the Following :");
		printf("\n1: Registration");
		printf("\n2: Log In");
		printf("\n3: Main Menu");
		printf("\nThe Choice Entered By User is : "); 
		rtn = scanf("%d",&choice);
		printf("\n\n");
		if (rtn == 0) 
		{    
    printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    empty_stdin();
    }
		else
		switch(choice)
		{
			case 1:
			no_of_registration = Register(R_Register,no_of_registration);
			no_of_Insert_registration=insertion(R_Register,no_of_registration);
			break;
			
			case 2:
			no_of_Login = R_login(R_Register,no_of_registration);
			break;
			
			case 3:
			printf("Choose The Following :");
			printf("\n1: Admin");
			printf("\n2: User");
			printf("\n3: Owner");
			printf("\n4: Exit");
			printf("\nThe Choice Entered By User is : "); 
			rtn = scanf("%d",&Mode);
			if (rtn == 0) 
			{    
			printf("\033[1;31mError : Invalid integer input.\033[0m\n");
			empty_stdin();
			}
			else
			menu(Mode);
			break;
			
			default:
		printf("\033[1;31mInvalid Choice\033[0m\n");
		
		}
	}
	while(choice!=4);
}



//Owner Functions
void Owner()
{
	int owner_choice;
	int no_of_Owner_registration=0;
	int no_of_Owner_Login=0;
	int no_of_Insert_Owner_registration=0;
	O O_Register[max_count];
	do
	{
		printf("\n\nOwner Main Menu");
		printf("\n1: Owner Registration");
		printf("\n2: Owner login");
		printf("\n3: Main Menu");
		printf("\nThe Choice Entered is :");
		rtn = scanf("%d",&owner_choice);
		printf("\n");
		if (rtn == 0) 
		{    
    	printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    	empty_stdin();
    }
		else
		switch(owner_choice)
		{
			case 1:
			no_of_Owner_registration=Owner_Register(O_Register,no_of_Owner_registration);
			no_of_Insert_Owner_registration=Owner_Insertion(O_Register,no_of_Owner_registration);
			break;
			
			case 2:
			no_of_Owner_Login=O_login(O_Register,no_of_Owner_registration);
			break;

			case 3:
			printf("Choose The Following :");
			printf("\n1: Admin");
			printf("\n2: User");
			printf("\n3: Owner");
			printf("\n4: Exit");
			printf("\nThe Choice Entered By User is : "); 
			rtn = scanf("%d",&Mode);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid integer input.\033[0m\n");
				empty_stdin();
			}
			else
			menu(Mode);
			break;

			default:
			printf("\033[1;31mInvalid Choice\033[0m\n");
		}
	}
	while(owner_choice!=4);
}

//Function To Be used Globally Around The Project
 bool isNumber(char s[50])
{
    for (int i = 0; i < strlen(s); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}

//Function To Handle Input For Integer
void empty_stdin (void)
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}