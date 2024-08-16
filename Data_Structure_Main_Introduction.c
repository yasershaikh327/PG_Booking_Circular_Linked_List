//Author :  Yaser Imtiyaz Ahmed Shaikh
#include <stdio.h>
#include <time.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>
#include "Data_Structure_structure.h"
int max_count=100;
int admin_count=1;
int owner_count=10;
int Mode;
int rtn;
#define Size 50
int main()
{
    char *data1[100],*data2[100],*data3[100],*data4[100],*data5[100],*data6[100],*data66[100],*data7[100],*data8[100],*data9[100],*data10[100],*data11[100],*data12[100],*data13[100],*data14[100],*data15[100],*data16[100],*data17[100];
    *data1="It has become easier to find a paying guest accommodation near your work place.";
    *data2="Earlier it was difficult to go to work places which were situated at long-dista";
    *data3="nces and hence good opportunities were lost, as we couldn’t find a place to li";
    *data4="ve and were unfamiliar with a new city. But now it has become easier to find an";
    *data5="accommodation near the work place at cheaperrates. In our website, users can ";
    *data6="find a number of paying guest accommodations near their work places or a desired ";
    *data66="location.";
    *data7="'Ashraya' provides a platform for one to easily access the relevant informati";
    *data8="on and make necessary judgement while selecting the accommodation.User can t";
    *data9="ake a look at different aspects of the information like location map, food, pri";
    *data10="ce, security measures, proper maintenance and transportation facilities an";
    *data11="d select the best accommodationof their choice.The Land lord can also add his/";
    *data12="her own properties and get the tenant easily by just uploading pictures and det";
    *data13="ails of the respective place.User can also check rentals for the accommodatio";
    *data14="n and after getting the desirable price, he/she can select the place he/she is i";
    *data15="nterested in. On finalizing the accommodation, the user can get details of the";
    *data16="owner. He/she can then proceed to fulfil the necessary requirements,documentation";
    *data17="and details.";
    
	/* clock */
	time_t t ;
	struct tm *tmp ;
	char Date[Size];
	time( &t );
	
	tmp = localtime( &t );
	strftime(Date, sizeof(Date), "%I:%M %p", tmp);
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\033[1;33m%s\n", Date);
	printf("\033[0m"); 
    
	
	
	
	
    printf("\n\n");
    printf("\t\t\t\033[1;32m         Ashraya - Paying Guest House Reservation System\033[0m");
    printf("\n\n\n        %s",*data1);
    printf("\n\t\t%s",*data2);
    printf("\n\t\t%s",*data3);
    printf("\n\t\t%s",*data4);
    printf("\n\t\t%s",*data5);
    printf("\n\t\t%s",*data6);
    printf("\n\t\t%s",*data66);
    
    printf("\n\n\n\n");
    
    printf("\n\t\t%s",*data7);
    printf("\n\t\t%s",*data8);
    printf("\n\t\t%s",*data9);
    printf("\n\t\t%s",*data10);
    printf("\n\t\t%s",*data11);
    printf("\n\t\t%s",*data12);
    printf("\n\t\t%s",*data13);
    printf("\n\t\t%s",*data14);
    printf("\n\t\t%s",*data15);
    printf("\n\t\t%s",*data16);
    printf("\n\t\t%s",*data17);
	printf("\n\n");
	
	//System Startup
	char txt[20];
	char *f="Windows";
	printf("\t\tEnter the Password To Start The System : ");
	scanf("%s",txt);
	
	//Check if Password Entered is Correct or Not
	while(strcmp(txt,"windows")!=0)
	{
		printf("\t\t\033[1;31mError\033[0m : Please Re - Enter the Password To Start The System : ");
		scanf("%s",txt);
	}

	//Wait for 5 seconds before starting the system
	printf("\t\t\033[1;36mPlease Wait....\n");
	printf("\t\t\033[1;32mLogin Successful");
	printf("\033[0m");
	sleep(2);
	
	if(strcmp(txt,"windows")==0)
	{
		printf("\n\n");
		printf("MENU DRIVEN PROGRAM FOR PG RESERVATION SYSTEM");
		
		//Choose Between User,Owner & Admin
		do
		{
		printf("\nMAIN MENU");
		printf("\nChoose From The Following Mode:");
		printf("\n1: Admin Mode");
		printf("\n2: User Mode");
		printf("\n3: Owner Mode");
		printf("\n4: Exit");
		printf("\nThe Choice of Mode is : ");
		rtn = 	scanf("%d",&Mode);
		printf("\n");
		if (rtn == 0) 
		{    
    printf("\033[1;31mError: Invalid integer input.\033[0m\n");
    empty_stdin();
    }
		else
		menu(Mode);
		}while(Mode!=4);
	}
	
	return 0;
}
