#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include "Data_Structure_structure.h"

//Owner Mode Details
//Owner Registartion
//Author :  Yaser Imtiyaz Ahmed Shaikh
int Owner_Register(O array2[],int count1)
{
	//User Inputs
	if(count1 > max_count -1)
	{
		printf("\033[0;33m NO MORE REGISTRATIONS CAN BE MADE \033[0m⚠");
	}
	else
	{
		//Owner Enter Details
		//Date Function
		time_t t ;
		struct tm *tmp ;
		time( &t );
		tmp = localtime( &t );
		
		printf("OWNER REGISTRATION PROCESS :");
		
		//Name
		printf("\nEnter The Owner Name : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_Name);
		while(strlen(array2[count1].Owner_Name)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Owner Name : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_Name);
		}
		
		//Gender
		printf("Enter the Gender Male/Female : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_Gender);
		while(strlen(array2[count1].Owner_Gender)>10)
		{
			printf("Array Size is exceeding \033[1;31mMax[10]\033[0m.\nPlease Enter The Gender : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_Gender);
		}
			
		
		//Phone Number
		printf("Enter the Owner Phone Number : ");
		scanf("%s",array2[count1].Owner_Phone);
		while(!isNumber(array2[count1].Owner_Phone) || strlen(array2[count1].Owner_Phone)>11 || strlen(array2[count1].Owner_Phone)!=10)
		{
			printf("Please Enter A Valid \033[1;31m10-Digit Integer Number From [0-9]\033[0m : ");
			scanf("%s",array2[count1].Owner_Phone);
		}
		
		//Address
		printf("Enter The Owner Address : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_Address);
		while(strlen(array2[count1].Owner_Address)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Address : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_Address);
		}
		
		//State
		printf("Enter the Owner State : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_State);
		while(strlen(array2[count1].Owner_State)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The State : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_State);
		}
		
		//City
		printf("Enter the Owner City : "); 
		scanf(" %[^\n]%*c",array2[count1].Owner_City);
		while(strlen(array2[count1].Owner_City)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The City : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_City);
		}
		
		//Email Address
		printf("Enter the Owner Email Address : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_Email);
		while(strlen(array2[count1].Owner_Email)>20)
		{
			printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Email : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_Email);
		}
		
		//Password
		printf("Enter the Password : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_Password);
		while(strlen(array2[count1].Owner_Password)>12)
		{
			printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Password : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_Password);
		}
		
		//Re-Enter Password(Confirmation)
		printf("Enter the Confirm Password : ");
		scanf(" %[^\n]%*c",array2[count1].Owner_CPassword);
		while(strlen(array2[count1].Owner_CPassword)>12)
		{
			printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Password : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_CPassword);
		}
		
		//Comparing Password and Confirm Password
		while(strcmp(array2[count1].Owner_Password,array2[count1].Owner_CPassword))
		{
			printf("\n\033[1;31mPasswords Doesn't Match\033[0m.\nPlease Re-Enter the Confirm Password : ");
			scanf(" %[^\n]%*c",array2[count1].Owner_CPassword);
		}

		//Registration Date of Owner
		strftime(array2[count1].Date_Of_Owner_Added, sizeof(array2[count1].Date_Of_Owner_Added), "Date : %x  \nTime : %I:%M%p", tmp);

	}
	return count1;
}

//Owner Add Room
//Author :  Yaser Imtiyaz Ahmed Shaikh & Seema Santosh Naik
int Add_room(P array3[],int count2)
{
	//Date Function
	time_t t ;
	struct tm *tmp ;
	time( &t );
	tmp = localtime( &t );
	
	
	//printf("\nADD ROOM IN CIRCULAR LINKED LIST :");
	printf("\nEnter the Name For Your PG :");
	scanf(" %[^\n]%*c",array3[count2].pg_name);

	//Validate
	while(strlen(array3[count2].pg_name)>20)
	{
		printf("\nArray Size Is Exceeding \033[1;31mMax[20]\033[0m.\nEnter the Name For Your PG : ");
		scanf(" %[^\n]%*c",array3[count2].pg_name);
	}

	printf("\nEnter the PG Type : ");
	printf("\n1 : Single Bedroom To Accomdate 1 Person : ");
	printf("\n2 :	Double Bedroom To Accomdate 2 People : ");
	printf("\n3 : Triple Bedroom To Accomdate 3 People : ");
	printf("\n4 : Quad Bedroom To Accomdate 4 People : ");
	printf("\n5 : Dormant Bedroom To Accomdate 5 People : ");
	printf("\nThe Choice Entered is : ");
	rtn = scanf("%d",&array3[count2].pg_type);
		if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
		empty_stdin();
		return 0;
  }
	while(array3[count2].pg_type > 5 || array3[count2].pg_type < 0)
	{
		printf("\033[1;33mRe-Enter From 1-5 : \033[0m");
		rtn = scanf("%d",&array3[count2].pg_type);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
			return 0;
		}
	}

	//Choose Type Of Pg's To Add
	switch(array3[count2].pg_type)
	{
		//Single Bedroom To Accomdate 1 Person
		case 1 :
		//All Facilities
		strcpy(array3[count2].fac1,"No"); 
    strcpy(array3[count2].fac2, "Yes");
		strcpy(array3[count2].fac3, "Yes"); 
		strcpy(array3[count2].fac4, "No");
		strcpy(array3[count2].fac5, "Yes");
		strcpy(array3[count2].fac6, "No");
		strcpy(array3[count2].fac7, "No");
		strcpy(array3[count2].fac8, "Yes");
		strcpy(array3[count2].fac9, "No"); 
		strcpy(array3[count2].fac10, "No");

		//Room Type
		char RTP[]="Single Bedroom To Accomdate 1 Person";
    strcpy(array3[count2].pg_types, RTP);
	
		//Room Description 
		printf("Enter the Description : ");
		scanf(" %[^\n]%*c", array3[count2].Room_Description);

		while(strlen(array3[count2].Room_Description) > 300)
		{
			printf("Array Size is Exceeding \033[1;31mMAX[300]\033[0m : Please Re - Enter the Description : ");
			scanf(" %[^\n]%*c", array3[count2].Room_Description);
		}

		//Price of Pg
		printf("\nEnter the Price : ");
		scanf("%d",&array3[count2].price_of_pg);

		//validate
		while(array3[count2].price_of_pg <= 0)
		{
			printf("\nInvalid Value for Price .\033[1;31mPlease Enter the Price Value Greater Then Zero \033[0m: ");
			scanf("%d",&array3[count2].price_of_pg);
		}

		//PG Location
		printf("\nEnter the PG Location : ");
		scanf(" %[^\n]%*c", array3[count2].PG_LOcation);

		//Validate
		while(strlen(array3[count2].PG_LOcation) > 200)
		{
			printf("\nArray SIze is Exceeding \033[1;31mMax[200]\033[0m. Please Re-Enter the PG Location : ");
			scanf(" %[^\n]%*c", array3[count2].PG_LOcation);
		}

		//No of People
		char RP1[]="1";
    strcpy(array3[count2].num_ppl, RP1);
		
		//Storing Date and Time of Room Added
		strftime(array3[count2].Date_of_PG_ADDED, sizeof(array3[count2].Date_of_PG_ADDED), "Date : %x  \nTime : %I:%M%p", tmp);
		break;

		//Double Bedroom To Accomdate 2 People
		case 2:
		//All Facilities
		strcpy(array3[count2].fac1,"Yes"); 
    strcpy(array3[count2].fac2, "Yes");
		strcpy(array3[count2].fac3, "Yes"); 
		strcpy(array3[count2].fac4, "No");
		strcpy(array3[count2].fac5, "Yes");
		strcpy(array3[count2].fac6, "Yes");
		strcpy(array3[count2].fac7, "No");
		strcpy(array3[count2].fac8, "Yes");
		strcpy(array3[count2].fac9, "Yes");
		strcpy(array3[count2].fac10, "Yes");
		
		//Room Type
		char RTP2[]="Double Bedroom To Accomdate 2 People";
    strcpy(array3[count2].pg_types, RTP2);
	
		//Room Description 
		printf("Enter the Description : ");
		scanf(" %[^\n]%*c", array3[count2].Room_Description);

		while(strlen(array3[count2].Room_Description) > 300)
		{
			printf("Array Size is Exceeding \033[1;31mMAX[300]\033[0m : Please Re - Enter the Description : ");
			scanf(" %[^\n]%*c", array3[count2].Room_Description);
		}

		//Price of Pg
		printf("\nEnter the Price : ");
		scanf("%d",&array3[count2].price_of_pg);

		//validate
		while(array3[count2].price_of_pg <= 0)
		{
			printf("\nInvalid Value for Price .\033[1;31mPlease Enter the Price Value Greater Then Zero \033[0m: ");
			scanf("%d",&array3[count2].price_of_pg);
		}

		//PG Location
		printf("\nEnter the PG Location : ");
		scanf(" %[^\n]%*c", array3[count2].PG_LOcation);

		//Validate
		while(strlen(array3[count2].PG_LOcation) > 200)
		{
			printf("\nArray SIze is Exceeding \033[1;31mMax[200]\033[0m. Please Re-Enter the PG Location : ");
			scanf(" %[^\n]%*c", array3[count2].PG_LOcation);
		}

		//No of People
		char RP2[]="2";
    strcpy(array3[count2].num_ppl, RP2);
		
		//Storing Date and Time of Room Added
		strftime(array3[count2].Date_of_PG_ADDED, sizeof(array3[count2].Date_of_PG_ADDED), "Date : %x  \nTime : %I:%M%p", tmp);
		break;

		//Triple Bedroom To Accomdate 3 People
		case 3:
		//All Facilities
		strcpy(array3[count2].fac1,"Yes"); 
    strcpy(array3[count2].fac2, "Yes");
		strcpy(array3[count2].fac3, "Yes"); 
		strcpy(array3[count2].fac4, "No");
		strcpy(array3[count2].fac5, "Yes");
		strcpy(array3[count2].fac6, "Yes");
		strcpy(array3[count2].fac7, "No");
		strcpy(array3[count2].fac8, "Yes");
		strcpy(array3[count2].fac9, "Yes");
		strcpy(array3[count2].fac10, "Yes");
		
		//Room Type
		char RTP3[]="Triple Bedroom To Accomdate 3 People";
    strcpy(array3[count2].pg_types, RTP3);
	
		//Room Description 
		printf("Enter the Description : ");
		scanf(" %[^\n]%*c", array3[count2].Room_Description);

		while(strlen(array3[count2].Room_Description) > 300)
		{
			printf("Array Size is Exceeding \033[1;31mMAX[300]\033[0m : Please Re - Enter the Description : ");
			scanf(" %[^\n]%*c", array3[count2].Room_Description);
		}

		//Price of Pg
		printf("\nEnter the Price : ");
		scanf("%d",&array3[count2].price_of_pg);

		//validate
		while(array3[count2].price_of_pg <= 0)
		{
			printf("\nInvalid Value for Price .\033[1;31mPlease Enter the Price Value Greater Then Zero \033[0m: ");
			scanf("%d",&array3[count2].price_of_pg);
		}

		//PG Location
		printf("\nEnter the PG Location : ");
		scanf(" %[^\n]%*c", array3[count2].PG_LOcation);

		//Validate
		while(strlen(array3[count2].PG_LOcation) > 200)
		{
			printf("\nArray SIze is Exceeding \033[1;31mMax[200]\033[0m. Please Re-Enter the PG Location : ");
			scanf(" %[^\n]%*c", array3[count2].PG_LOcation);
		}

		//No of People
		char RP3[]="3";
    strcpy(array3[count2].num_ppl, RP3);
		
		//Storing Date and Time of Room Added
		strftime(array3[count2].Date_of_PG_ADDED, sizeof(array3[count2].Date_of_PG_ADDED), "Date : %x  \nTime : %I:%M%p", tmp);
		break;

		//Quad Bedroom To Accomdate 4 People
		case 4:
		//All Facilities
		strcpy(array3[count2].fac1,"Yes"); 
    strcpy(array3[count2].fac2, "Yes");
		strcpy(array3[count2].fac3, "Yes"); 
		strcpy(array3[count2].fac4, "Yes");
		strcpy(array3[count2].fac5, "Yes");
		strcpy(array3[count2].fac6, "Yes");
		strcpy(array3[count2].fac7, "Yes");
		strcpy(array3[count2].fac8, "Yes");
		strcpy(array3[count2].fac9, "Yes");
		strcpy(array3[count2].fac10, "Yes");
		
		//Room Type
		char RTP4[]="Quad Bedroom To Accomdate 4 People";
    strcpy(array3[count2].pg_types, RTP4);
	
		//Room Description 
		printf("Enter the Description : ");
		scanf(" %[^\n]%*c", array3[count2].Room_Description);

		while(strlen(array3[count2].Room_Description) > 300)
		{
			printf("Array Size is Exceeding \033[1;31mMAX[300]\033[0m : Please Re - Enter the Description : ");
			scanf(" %[^\n]%*c", array3[count2].Room_Description);
		}

		//Price of Pg
		printf("\nEnter the Price : ");
		scanf("%d",&array3[count2].price_of_pg);

		//validate
		while(array3[count2].price_of_pg <= 0)
		{
			printf("\nInvalid Value for Price .\033[1;31mPlease Enter the Price Value Greater Then Zero \033[0m: ");
			scanf("%d",&array3[count2].price_of_pg);
		}

		//PG Location
		printf("\nEnter the PG Location : ");
		scanf(" %[^\n]%*c", array3[count2].PG_LOcation);

		//Validate
		while(strlen(array3[count2].PG_LOcation) > 200)
		{
			printf("\nArray SIze is Exceeding \033[1;31mMax[200]\033[0m. Please Re-Enter the PG Location : ");
			scanf(" %[^\n]%*c", array3[count2].PG_LOcation);
		}

		//No of People
		char RP4[]="4";
    strcpy(array3[count2].num_ppl, RP4);
		
		//Storing Date and Time of Room Added
		strftime(array3[count2].Date_of_PG_ADDED, sizeof(array3[count2].Date_of_PG_ADDED), "Date : %x  \nTime : %I:%M%p", tmp);
		break;

		//Dormant Bedroom To Accomdate 5 People
		case 5:
		//All Facilities
		strcpy(array3[count2].fac1,"Yes"); 
    strcpy(array3[count2].fac2, "Yes");
		strcpy(array3[count2].fac3, "Yes"); 
		strcpy(array3[count2].fac4, "Yes");
		strcpy(array3[count2].fac5, "Yes");
		strcpy(array3[count2].fac6, "Yes");
		strcpy(array3[count2].fac7, "Yes");
		strcpy(array3[count2].fac8, "Yes");
		strcpy(array3[count2].fac9, "Yes");
		strcpy(array3[count2].fac10, "Yes");
		
		//Room Type
		char RTP5[]="Dormant Bedroom To Accomdate 5 People";
    strcpy(array3[count2].pg_types, RTP5);
	
		//Room Description 
		printf("Enter the Description : ");
		scanf(" %[^\n]%*c", array3[count2].Room_Description);

		while(strlen(array3[count2].Room_Description) > 300)
		{
			printf("Array Size is Exceeding \033[1;31mMAX[300]\033[0m : Please Re - Enter the Description : ");
			scanf(" %[^\n]%*c", array3[count2].Room_Description);
		}

		//Price of Pg
		printf("\nEnter the Price : ");
		scanf("%d",&array3[count2].price_of_pg);

		//validate
		while(array3[count2].price_of_pg <= 0)
		{
			printf("\nInvalid Value for Price .\033[1;31mPlease Enter the Price Value Greater Then Zero \033[0m: ");
			scanf("%d",&array3[count2].price_of_pg);
		}

		//PG Location
		printf("\nEnter the PG Location : ");
		scanf(" %[^\n]%*c", array3[count2].PG_LOcation);

		//Validate
		while(strlen(array3[count2].PG_LOcation) > 200)
		{
			printf("\nArray SIze is Exceeding \033[1;31mMax[200]\033[0m. Please Re-Enter the PG Location : ");
			scanf(" %[^\n]%*c", array3[count2].PG_LOcation);
		}

		//No of People
		char RP5[]="5";
    strcpy(array3[count2].num_ppl, RP5);
		
		//Storing Date and Time of Room Added
		strftime(array3[count2].Date_of_PG_ADDED, sizeof(array3[count2].Date_of_PG_ADDED), "Date : %x  \nTime : %I:%M%p", tmp);
		break;
	}	
	return count2;
}


//Booking Process
//Author :  Seema Santosh Naik
int Bookings(P array3[],int count2)	//2
{

	//Check In Date
	//Enter The Date
	printf("Check In Date : ");
	printf("\nEnter the Date from  1 - 31 : ");
	rtn = scanf("%d",&array3[count2].check_in_dd);
	if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
		empty_stdin();
  }
	
	//Validate Date
	while(array3[count2].check_in_dd > 31 || array3[count2].check_in_dd < 1)
	{
		printf("Please Re-Enter the Date from \033[1;31m1 - 31\033[0m : ");
		rtn = scanf("%d",&array3[count2].check_in_dd);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
		}
	}
	
	//Enter The Month
	printf("Enter the Month from  1 - 12 : ");
	rtn = scanf("%d",&array3[count2].check_in_mm);
	if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
		empty_stdin();
  }
	
	//Validate Month
	while(array3[count2].check_in_mm > 12 || array3[count2].check_in_mm < 1)
	{
		printf("Please Re-Enter the Month from \033[1;31m1 - 12\033[0m : ");
		rtn = scanf("%d",&array3[count2].check_in_mm);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
		}
	}
	
	//Enter The Year
	printf("Enter the Year from  20 - 23 : ");
	rtn = scanf("%d",&array3[count2].check_in_yy);
	if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
		empty_stdin();
  }
	
	//Validate Year
	while(array3[count2].check_in_yy > 23 || array3[count2].check_in_yy < 20)
	{
		printf("Please Re-Enter the Year from \033[1;31m20 - 23\033[0m : ");
		rtn = scanf("%d",&array3[count2].check_in_yy);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
		}
	}
	
	/* Convert Integer To String */
	sprintf(array3[count2].cd_dd,"%d",array3[count2].check_in_dd);
	sprintf(array3[count2].cd_mm,"%d",array3[count2].check_in_mm);
	sprintf(array3[count2].cd_yy,"%d",array3[count2].check_in_yy);
	
	printf("The CheckIn Date is %s/%s/%s",array3[count2].cd_dd,array3[count2].cd_mm,array3[count2].cd_yy);	//Checkin date
	
	
	do{
		//Check Out Date
		//Enter The Date
		printf("\n\nCheck Out Date : ");
		printf("\nEnter the Date from  1 - 31 : ");
		rtn = scanf("%d",&array3[count2].check_out_dd);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
		}
		
		//Validate Date
		while(array3[count2].check_out_dd > 31 || array3[count2].check_out_dd < 1 )
		{
			printf("Please Re-Enter the Date from \033[1;31m1 - 31\033[0m and Make Sure The Check In Date is \033[1;31mNot Equal\033[0m to Check Out Date : ");
			rtn = scanf("%d",&array3[count2].check_out_dd);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
				empty_stdin();
			}
		}
		
		//Enter The Month
		printf("Enter the Month from  1 - 12 : ");
		rtn = scanf("%d",&array3[count2].check_out_mm);
		if (rtn == 0) 
		{    
			printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
			empty_stdin();
		}
		
		//Validate Month
		while(array3[count2].check_out_mm > 12 || array3[count2].check_out_mm < 1)
		{
			printf("Please Re-Enter the Month from \033[1;31m1 - 12\033[0m : ");
			rtn = scanf("%d",&array3[count2].check_out_mm);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
				empty_stdin();
			}
		}
		
		//Enter The Year
		printf("Enter the Year from  20 - 23 : ");
		rtn = scanf("%d",&array3[count2].check_out_yy);
		
		//Validate Year
		while(array3[count2].check_out_yy > 23 || array3[count2].check_out_yy < 20)
		{
			printf("Please Re-Enter the Year from \033[1;31m20 - 23\033[0m : ");
			scanf("%d",&array3[count2].check_out_yy);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
				empty_stdin();
			}
		}
		
		/* Convert Integer To String */
		sprintf(array3[count2].cc_dd,"%d",array3[count2].check_out_dd);
		sprintf(array3[count2].cc_mm,"%d",array3[count2].check_out_mm);
		sprintf(array3[count2].cc_yy,"%d",array3[count2].check_out_yy);
		
		printf("The CheckOut Date is %s/%s/%s",array3[count2].cc_dd,array3[count2].cc_mm,array3[count2].cc_yy);	//CheckOut date
		if(array3[count2].check_in_dd==array3[count2].check_out_dd && array3[count2].check_in_mm==array3[count2].check_out_mm && array3[count2].check_in_yy==array3[count2].check_out_yy)
		{
			printf("/n/n\033[1;31mCheck In Date Should not Be Equal To Check Out Date.Please Re - Enter Check Out Date\033[0m ⚠");
		}
	}
	while(array3[count2].check_in_dd==array3[count2].check_out_dd && array3[count2].check_in_mm==array3[count2].check_out_mm && array3[count2].check_in_yy==array3[count2].check_out_yy);
 
	//Day of Booking
	time_t t ;
	struct tm *tmp ;
	time( &t );
	tmp = localtime( &t );
	strftime(array3[count2].Booking_Date, sizeof(array3[count2].Booking_Date), "%x - %I:%M %p", tmp);
	return count2;
}

//Card Payment
//Seema Santosh Naik
int Add_card(C array4[],int count3)				
{
	//Card Holder Name
	printf("\nEnter the Card Holder Name  : ");
	scanf(" %[^\n]%*c",array4[count3].Card_Holder_name);
		
	//Validate
	while(strlen(array4[count3].Card_Holder_name ) > 20)
	{
		printf("\nArray Size is Exceeding \033[1;31mMax[20]\033[0m.\nEnter the Card Holder Name  : ");
		scanf(" %[^\n]%*c",array4[count3].Card_Holder_name);
	}
	
	//Card Number
	printf("\nEnter the Card 16 Digit Number  : ");
	scanf("%s",array4[count3].Card_Number);
	
	//Validate 
	while(!isNumber(array4[count3].Card_Number) || strlen(array4[count3].Card_Number)>16 || strlen(array4[count3].Card_Number)!=16)
	{
		printf("\n\033[1;31mInvalid\033[0m .\nPlease enter the Card 16 Digit Number  : \nPlease Enter \033[1;31mDigit [0-9]\033[0m :\n");
		scanf("%s",array4[count3].Card_Number);
	}
	
	//Expiry Month
	printf("\nEnter the Card Expiry Month  Enter From 1-12: ");
	printf("\n1 : January");
	printf("\n2 : February");
	printf("\n3 : March ");
	printf("\n4 : April");
	printf("\n5 : May");
	printf("\n6 : June");
	printf("\n7: July");
	printf("\n8: August");
	printf("\n9: September");
	printf("\n10: October");
	printf("\n11: November");
	printf("\n12: December");	
	printf("\nThe Choice Entered is : ");
	scanf("%s",array4[count3].Exp_Month);
		
	//Validate
	while(strcmp(array4[count3].Exp_Month,"1")!=0 && strcmp(array4[count3].Exp_Month,"2")!=0 && strcmp(array4[count3].Exp_Month,"3")!=0 && strcmp(array4[count3].Exp_Month,"4")!=0 && strcmp(array4[count3].Exp_Month,"5")!=0 && strcmp(array4[count3].Exp_Month,"6")!=0 && strcmp(array4[count3].Exp_Month,"7")!=0 && strcmp(array4[count3].Exp_Month,"8")!=0 && strcmp(array4[count3].Exp_Month,"9")!=0 && strcmp(array4[count3].Exp_Month,"10")!=0 && strcmp(array4[count3].Exp_Month,"11")!=0 && strcmp(array4[count3].Exp_Month,"12")!=0)
	{
		printf("\n\033[1;31mEnter the Card Expiry Month\033[0m .\nPlease Enter From 1-12 : \n Refer ABove For The Corresponging Number For The Particlar Month : ");
		printf("\nThe Choice Entered is : ");
		scanf("%s",array4[count3].Exp_Month);
	}

	//Expiry Year
	printf("\nEnter the 4 Digit Card Expiry Year  : ");
	scanf("%s",array4[count3].Exp_Year);
	
	//Validate
	while(!isNumber(array4[count3].Exp_Year)  || strlen(array4[count3].Exp_Year) >4 || strlen(array4[count3].Exp_Year) !=4 || atoi(array4[count3].Exp_Year) < 2021)
	{
		printf("\n\033[1;31mInvalid\033[0m .\nPlease Enter the 4 Digit Number[0-9] for Year with Year Above 2020 Year Again : ");
		scanf("%s",array4[count3].Exp_Year);
	}
	
	//CVV
	printf("\nEnter the 3 Digit CVV Number : ");
	scanf("%s",array4[count3].CVV);
	
	//Validate
	while(!isNumber(array4[count3].CVV) || strlen(array4[count3].CVV) >3 || strlen(array4[count3].CVV) !=3)
	{
		printf("\n\033[1;31mInvalid\033[0m .\nPlease enter the 3 Digit Number  for CVV Again : ");
		scanf("%s",array4[count3].CVV);
	}
	return count3;
}



//Owner Main Menu
//Author :  Yaser Imtiyaz Ahmed Shaikh
void Owner_Menu()
{
	int owner_mini_menu;
	int no_of_pgs=0;
	int no_of_pgs_insert=0;
	int ch;
	P P_PG[max_count];

	printf("\n\nChoose The Following Option :");
	printf("\n1: View My Registration Details :");
	printf("\n2: Add PG");
	printf("\n3: Display My PG");
	printf("\n4: Log Out");
	printf("\n5: De-Register Account");
	printf("\nThe Choice Entered By The User is : ");
	rtn = scanf("%d",&owner_mini_menu);
	if (rtn == 0) 
	{    
		printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
		empty_stdin();
  }
	
	//Menu For User
	switch(owner_mini_menu)
	{
		case 1:
		ViewMydataOwner_Registration();
		Owner_Menu();
		break;
		
		case 2:
		no_of_pgs=Add_room(P_PG,no_of_pgs);	
		no_of_pgs_insert=Insertion_room(P_PG,no_of_pgs);
		Owner_Menu();
		break;

		case 3:
		Display_All_PGS();
		Owner_Menu();
		break;

		case 4:
		printf("\nLogout Successfully :");
		Owner();
		break;
		
		case 5:
		printf("\nYou are About Tou Delete Your Account :\nDo you Wish To Continue :\nPress 1 To Proceed :\nPress 0 to Decline");
		printf("\nThe Choice Entered is :");
		scanf("%d",&ch);
		if(ch==1)
		{
			De_Owner_Registration();
			Owner();
		}
		else if(ch==0)
		{
			Owner();
		}
		break;
		
		default:
		printf("Invalid Choice:");
	
	}
	
}