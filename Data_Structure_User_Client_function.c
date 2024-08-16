#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include "Data_Structure_structure.h"


//User Mode Details
//Registration Process
//Author : Yaser Imtiyaz Ahmed Shaikh
int Register(R  array[],int count)
{
	//User Inputs
	if(count > max_count -1)
	{
		printf("\033[1;33mNo More Registrations Can Be Be Made ⚠ \033[0m");
	}
	else
	{
		printf("REGISTRATION PROCESS :");
	
		
		//Name
		printf("\nEnter The Name : ");
		scanf(" %[^\n]%*c",array[count].Name);
		while(strlen(array[count].Name)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Name : ");
			scanf(" %[^\n]%*c",array[count].Name);
		}
		
		//Gender
		printf("Enter the Gender Male/Female : ");
		scanf(" %[^\n]%*c",array[count].Gender);
		while(strlen(array[count].Gender)>10)
		{
			printf("Array Size is exceeding \033[1;31mMax[10]\033[0m.\nPlease Enter The Gender : ");
			scanf(" %[^\n]%*c",array[count].Gender);
		}

		//Phone Number
		printf("Enter the Phone Number : ");
		scanf("%s",array[count].Phone);
		while(!isNumber(array[count].Phone) || strlen(array[count].Phone)>11 || strlen(array[count].Phone)!=10)
		{
			printf("Please Enter A Valid \033[1;31m10-Digit Integer Number From [0-9]\033[0m : ");
			scanf("%s",array[count].Phone);
		}
		
		//Address
		printf("Enter The Address : ");
		scanf(" %[^\n]%*c",array[count].Address);
		while(strlen(array[count].Address)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Address : ");
			scanf(" %[^\n]%*c",array[count].Address);
		}
		
		//State
		printf("Enter the State : ");
		scanf(" %[^\n]%*c",array[count].State);
		while(strlen(array[count].State)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The State : ");
			scanf(" %[^\n]%*c",array[count].State);
		}
		
		//City
		printf("Enter the City : "); 
		scanf(" %[^\n]%*c",array[count].City);
		while(strlen(array[count].City)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The City : ");
			scanf(" %[^\n]%*c",array[count].City);
		}
		
		//Email Address
		printf("Enter the Email Address :");
		scanf(" %[^\n]%*c",array[count].Email);
		while(strlen(array[count].Email)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Email : ");
			scanf(" %[^\n]%*c",array[count].Email);
		}
		
		//Password
		printf("Enter the Password :");
		scanf(" %[^\n]%*c",array[count].Password);
		while(strlen(array[count].Password)>12)
		{
			printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Password : ");
			scanf(" %[^\n]%*c",array[count].Password);
		}
		
		//Re-Enter Password(Confirmation)
		printf("Enter the Confirm Password :");
		scanf(" %[^\n]%*c",array[count].CPassword);
		while(strlen(array[count].Password)>12)
		{
			printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Password : ");
			scanf(" %[^\n]%*c",array[count].CPassword);
		}
		
		//Comparing Password and Confirm Password
		while(strcmp(array[count].CPassword,array[count].Password))
		{
			printf("\n\033[1;31mPasswords Doesn't Match\033[0m.\nPlease Re-Enter the Confirm Password : ");
			scanf(" %[^\n]%*c",array[count].CPassword);
		}

		//Date Function
		time_t t ;
		struct tm *tmp ;
		time( &t );
		tmp = localtime( &t );

    //Storing Date and Time of Room Added
		strftime(array[count].Date_Of_User_Added, sizeof(array[count].Date_Of_User_Added), "Date : %x  \nTime : %I:%M%p", tmp);
		
	}
	return count;
}

//User Menu
//Author : Yaser Imtiyaz Ahmed Shaikh
void User_Menu()
{
	int user_mini_menu;
	int ch;
	int no_of_bookings=0;
	int no_of_bookings_make=0;
	int bookings_insertion=0;
	int index;
	int n;
	P P_Bookings[max_count];
	
	printf("\n\nChoose The Following Option");
	printf("\n1: View My Registration Details");
	printf("\n2: Display PG'S");
	printf("\n3: Booking");
	printf("\n4: Log Out");
	printf("\n5: De-Register");
	printf("\nThe Choice Entered By The User is : ");
	rtn = scanf("%d",&user_mini_menu);
	if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid integer input.\033[0m\n");
		empty_stdin();
	}
	else
	
	//Menu For User
	switch(user_mini_menu)
	{
		case 1:
		ViewMydata_Registration();
		User_Menu();
		break;
		
		case 2:
		Display_mY_PGs();
		User_Menu();
		break;

		case 3:
		printf("Enter the PG ID You Want To Book : ");
		rtn = scanf("%d", &n);
		if (rtn == 0) 
		{    
    	printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    	empty_stdin();
    }
		else
		index = search_booked_PG(n);
		if (index == -1)
		{
			printf("There is NO Pg with ID : \033[1;31m%d\033[0m\n", n);
		}
		else 
		{
			if((index + 1)>1)
			{
				printf("\033[1;33mThis Pg is Already Booked ⚠/Invalid User Input \033[0m");
			}
			else if((index + 1)==0)
			{
				printf("There is NO Pg with ID : \033[1;31m%d\033[0m\n", n);
			}
			else
			{
				printf("\nBOOKING\n");
				no_of_bookings=Add_Booking(P_Bookings,no_of_bookings,n);	//1
			}
		}
		User_Menu();
		break;

		case 4:
		printf("\n\033[1;32mLogout Successfully\033[0m");
		User();
		break;
		
		case 5:
		printf("\n\033[1;31mYou are About Tou Delete Your Account : \033[0m\nAll The Bookings Made Will be Deleted :\nDo you Wish To Continue :\nPress 1 To Proceed :\nPress Any other Digit to Decline");
		printf("\nThe Choice Entered is : ");
		rtn = scanf("%d",&ch);
		if (rtn == 0) 
		{    
    	printf("\033[1;31mError : Invalid integer input.\033[0m\n");
    	empty_stdin();
			User_Menu();
    }
		else if(ch==1)
		{
			printf("\033[0;33mAccount Deleted Successfully\033[0m ⚠ ");
			De_Registration();
			User();
		}
		else
		{
			User_Menu();
		}
		break;
		
		default:
		printf("\033[1;31mInvalid Choice\033[0m");
	
	}
	
}