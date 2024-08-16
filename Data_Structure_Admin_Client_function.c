#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "Data_Structure_structure.h"
 
//Admin Mode
//Admin Login
int log_in(A  array1[],int count)
{
	//To Display Current Date and Time
	//Author :  Yaser Imtiyaz Ahmed Shaikh
	time_t t ;
	struct tm *tmp ;
	time( &t );
	tmp = localtime( &t );
	char timez[100];
	strftime(timez, sizeof(timez), "Date : %x  \nTime : %I:%M%p", tmp);
	
	//Enter Details for Username and Password with validations
	//Author :  Yaser Imtiyaz Ahmed Shaikh
	int user;
	int pass;
	A * search_user_admin=NULL;
  printf("\nADMIN LOGIN\n");
	printf("%s\n",timez);
	printf("Enter Admin Username : ");
	scanf("%s",array1[count].Admin_Username);	
	user=strcmp(array1[count].Admin_Username,"Admin");
	while(user!=0)
	{
		printf("\033[1;31mInvalid\033[0m \n : Re-Enter Admin Username : ");
		scanf("%s",array1[count].Admin_Username);
		user=strcmp(array1[count].Admin_Username,"Admin");
	}	

	printf("Enter Admin Password : ");
	scanf("%s",array1[count].Admin_Password);
	pass=strcmp(array1[count].Admin_Password,"Ankola@327");
	while(pass!=0)
	{
		printf("\033[1;31mInvalid\033[0m \n : Re-Enter Admin Password : ");
		scanf("%s",array1[count].Admin_Password);
		pass=strcmp(array1[count].Admin_Password,"Ankola@327");
	}

	//Check Is User is Exists or Not
	//Author : Edphil Burce Cardozo
	search_user_admin = search_Username_Admin(array1[count].Admin_Username,array1[count].Admin_Password);
	if(search_user_admin ==  NULL )
	{
		printf("Admin Please Sign In ⚠ : ");
		Admin();
	}
	else
	{
		//printf("Login Successful :");
		Admin_Menu();
	}
	return count;
}

//Admin Menu
//Author :  Yaser Imtiyaz Ahmed Shaikh
void Admin_Menu()
{
	int x,y,m,index;
	int admin_mini_menu;
	do
	{
		//Menu For Admin
		printf("\n\n\nChoose The Following Options");
		printf("\n1: Display All Registered User");
		printf("\n2: Display All Registered Owner");
		printf("\n3: Display All The PGS Of All Owners");
		printf("\n4: Display All Bookings Made");
		printf("\n5: Remove PG");
		printf("\n6: Delete Booking of User");
		printf("\n7: Logout");
		printf("\nThe Choice Entered By Admin is : "); 
		rtn = scanf("%d",&admin_mini_menu);
		printf("\n\n");
		if (rtn == 0) 
		{    
    	printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    	empty_stdin();
    }
		else
		switch(admin_mini_menu)
		{
			case 1:
			Display_Registration();
			Admin_Menu();
			break;
			
			case 2:
			Display_Registration_Owner();
			Admin_Menu();
			break;

			case 3:
			Display_All_PGS();
			Admin_Menu();
			break;

			case 4:
			Display_bookings();
			break;

			case 5:
			printf("Enter the Pg Id You Want To Remove : ");
			rtn = scanf("%d",&x);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid integer input.\033[0m\n");
				empty_stdin();
			}
			else
			{
				index = search_booked_PG(x);
				if (index == -1)
				{
					printf("There is NO Pg with ID : \033[1;31m%d\033[0m\n", x);
				}
				else 
				{
					if((index + 1)>1)
					{
						printf("\033[1;33mThis Pg is Already Booked ⚠ So cannot Delete/Invalid User Input \033[0m");
					}
					else if((index + 1)==0)
					{
						printf("There is NO Pg with ID : \033[1;31m%d\033[0m\n", x);
					}
					else
					{
						Remove_PG(x);
					}
				}
			}
			break;

			case 6:
			printf("Enter the Booking Id You Want To Remove : ");
			rtn = scanf("%d",&m);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid integer input.\033[0m\n");
				empty_stdin();
			}
			else
			Remove_Bookings_made(m);
			break;

			case 7:
			printf("\033[1;32mLogout Successfully\033[0m\n\n");
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
	}while(admin_mini_menu!=7);
}