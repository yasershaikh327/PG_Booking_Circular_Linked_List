#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "Data_Structure_structure.h"
int count1;
int Owner_ID=1;	
int Pg_Id=1;
int Oid;
int Booking_Id=1;
int uni_user_id;
int uni_pg_id;
int Card_Id=1;
int bill_id=1;
char uni_name[20];
char uni_email[20];
char uni_phone[20];
char uni_pgname[20];
char uni_pgtype[30];
char uni_pglocation[20];
int uni_pgcost;
char uni_in_dd[20];
char uni_in_mm[20];
char uni_in_yy[20];
char uni_out_dd[20];
char uni_out_mm[20];
char uni_out_yy[20];
char uni_bk_date[25];

//Declaring head and tail pointer as null and I have declared it once because I will Be using In The entire Program.  
O * head1=NULL;
O * tail1=NULL;
O * search_user1=NULL;
O * ptr1=NULL;
O * current1=NULL;
O * search_owner_emails=NULL;

//Owner Registration Insertion
int Owner_Insertion(O  array2[],int count1)
{
	//Declaring Variables To Store The Data From Client into Server
	//Author :  Yaser Imtiyaz Ahmed Shaikh
	O * Owner_Name;
	O * Owner_Gender;
	O * Owner_Phone;
	O * Owner_Email;
	O * Owner_Address;
	O * Owner_City;
	O * Owner_State;
	O * Owner_Password;
	O * Owner_CPassword;

	//Registration Process
	//Circular Linked List
	O * NewOwner = (O*)malloc(1 * sizeof (O));
	NewOwner->Owner_ID=Owner_ID;																										//ID
	strcpy(NewOwner->Owner_Name,array2[count1].Owner_Name);													//Name
	strcpy(NewOwner->Owner_Gender,array2[count1].Owner_Gender);											//Gender
	strcpy(NewOwner->Owner_Phone,array2[count1].Owner_Phone);												//Phone
	strcpy(NewOwner->Owner_Email,array2[count1].Owner_Email);												//Email
	strcpy(NewOwner->Owner_Address,array2[count1].Owner_Address);										//Address
	strcpy(NewOwner->Owner_City,array2[count1].Owner_City);													//City
	strcpy(NewOwner->Owner_State,array2[count1].Owner_State);												//State
	strcpy(NewOwner->Owner_Password,array2[count1].Owner_Password);									//Password
	strcpy(NewOwner->Owner_CPassword,array2[count1].Owner_CPassword);								//Confirm Password
	strcpy(NewOwner->Date_Of_Owner_Added,array2[count1].Date_Of_Owner_Added);				//Owner Added Date
	Oid=NewOwner->Owner_ID=Owner_ID;		

	//Search For Duplicates
	//Author : Edphil Burce Cardozo
	if(head1 == NULL)
	{
		head1=NewOwner;
		tail1=NewOwner;
		NewOwner->Link=head1;
		printf("\n\033[1;32mREGISTERED SUCCESSFULLY\033[0m");
	}
	else
	{
    //search_userx = search_Usernamex(array[count].Email);
    ptr1 =head1;
		ptr1=ptr1->Link;
		if(strcmp(ptr1->Owner_Email, array2[count1].Owner_Email) == 0) //0->Valid
			{ 
				printf("\n\033[1;31mACCOUNT WITH THIS EMAIL ALREADY EXISTS\033[0m : ");
				//De_Registration();
				//User_Menu();
			}
			else
			{
        tail1->Link=NewOwner;
	    	tail1=NewOwner;
	    	tail1->Link=head1;
				printf("\n\033[1;32mREGISTERED SUCCESSFULLY\033[0m");
				//User();
			}
		}
	Owner_ID++;
  return count1;
}

//Displaying Data : Admin Use
//Author :  Yaser Imtiyaz Ahmed Shaikh
void Display_Registration_Owner()
{  
   current1 = head1;  
   if(head1 == NULL)
   {  
    printf("\033[1;33m ⚠ MESSAGE\033[0m [Owner] : No one Has Registered\n");  
   }  
   else
   {  
    do
    {
			printf("\nThe Name Of Owner : %s ", current1->Owner_Name);
			printf("\nThe Gender Of Owner : %s ", current1->Owner_Gender);
			printf("\nThe Address Of Owner: %s ", current1->Owner_Address);
			printf("\nThe City Of Owner : %s ", current1->Owner_City);
			printf("\nThe State Of Owner : %s ", current1->Owner_State); 
			printf("\n%s", current1->Date_Of_Owner_Added); 
			printf("\n\n");     	  
			current1 = current1->Link;  
    }
    while(current1 != head1) ;
  }
}


//Registration Details : Display Personal Details Of Owner
//Author :  Yaser Imtiyaz Ahmed Shaikh
void ViewMydataOwner_Registration()
{  
  // R *current = head; 
   if(head1 == NULL)
   {  
    printf("\n\033[1;33mMESSAGE ⚠\033[0m[Owner] : No one Has Registered\n");  
   }  
   else
   {  
    	printf("\nThe Registration ID Of Owner: %d ", ptr1->Owner_ID); 
			printf("\nThe Name Of Owner : %s ", ptr1->Owner_Name);
			printf("\nThe Gender Of Owner : %s ", ptr1->Owner_Gender);
			printf("\nThe Address Of Owner: %s ", ptr1->Owner_Address);
			printf("\nThe City Of Owner : %s ", ptr1->Owner_City);
			printf("\nThe State Of Owner : %s ", ptr1->Owner_State); 
			printf("\nThe Email Of Owner : %s ", ptr1->Owner_Email); 
			printf("\nThe Password Of Owner : %s ", ptr1->Owner_Password); 
			printf("\n%s", ptr1->Date_Of_Owner_Added); 
      printf("\n");   
     	Owner_Menu();
    }  
} 

//Owner Login Process
//Author :  Edphil Burce Cardozo
int O_login(O  array2[],int count1)
{
	O * head=NULL;
	
	printf("OWNER LOGIN");
	
	//Email
	printf("\nEnter the Owner Email : ");
	scanf("%s",array2[count1].Owner_Email);
	while(strlen(array2[count1].Owner_Email)>20)
	{
		printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Owner Email : ");
		scanf("%s",array2[count1].Owner_Email);
	}
	
	//Password
	printf("Enter the Owner Password : ");
	scanf("%s",array2[count1].Owner_Password);
	while(strlen(array2[count1].Owner_Password)>12)
	{
		printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Owner Password :");
		scanf("%s",array2[count1].Owner_Password);
	}

	//Check Is User is Exists or Not
	search_owner_emails = search_owner_email(array2[count1].Owner_Email,array2[count1].Owner_Password);
	return count1;
}


//Login Search :  Search If Email Exists or Not 
//Author :  Edphil Burce Cardozo
O * search_owner_email(char key[20],char key1[20])
{
	int flag=1;  
	ptr1 = head1;   
	if(ptr1 == NULL)  
	{  
		printf("\033[1;33mPlease Register\033[0m ⚠ ");
		return NULL;
	}  
	else  
	{   
		if(strcmp(head1->Owner_Email, key) == 0 )  
		{  
			if(strcmp(head1->Owner_Password, key1) == 0 )
			{
				printf("\033[1;32mLogin Successful\033[0m");
				Owner_Menu();
				flag=0;  
			//return 0;  
			}
		}  
		else   
		{  
			while (ptr1->Link != head1)  
			{  
				ptr1 = ptr1 -> Link; 
				if(strcmp(ptr1->Owner_Email, key) == 0 )  
				{  
					if(strcmp(ptr1->Owner_Password, key1) == 0 )
					{
						printf("\033[1;32mLogin Successful\033[0m");
						Owner_Menu(); 
						flag=0;  
						//return 0;
					}  
				}   
				else  
				{  
					flag=1;  
				}  
				//ptr = ptr -> Next; 
			}  
		}  
		if(flag != 0)  
		{  
			printf("\033[1;31mRegister/Invalid details\033[0m");
			Owner(); 
			return 0;  
		}  
	} 
}


//Register Delete : Delete Element from Circular Linked List 
//Author : Yaser Imtiyaz Ahmed Shaikh
O * De_Owner_Registration()
{
	int i,count;
	O *prev,*cur;

	if (head1 == NULL)
	{
			printf("\033[1;33mNot Registered\033[0m⚠.\n");
			return NULL;
	}

	count = 0;
	cur   = head1;
	prev  = cur;

	// Find node before head node
	while (prev->Link != head1)
	{
			prev = prev->Link;
			count++;
	}

	// Iterate till first node
	i = 0;
	while (i <= count)
	{
			if (cur->Owner_ID == ptr1->Owner_ID)
			{
					// Link prev node with next node of current
					if (cur->Link != cur)
							prev->Link = cur->Link;
					else
							prev->Link = NULL;

					// Adjust head node if needed
					if (cur == head1)
							head1 = prev->Link;

					// Delete current node
					free(cur);

					// Move current node ahead
					if (prev != NULL)
							cur = prev->Link;
					else
							cur = NULL;
			}
			else
			{
					prev = cur;
					cur  = cur->Link;
			}
i++;
	}
}



//PG Functions
//Declaring head and tail pointer as null and I have declared it once because I will Be using In The entire Program.  
P * head3=NULL;
P * tail3=NULL;
P * Pointer=NULL;
P * ptrxyz=NULL;
P * ptrown=NULL;
P * currently = NULL;
P * prev = NULL;

//Insertion Of Room
//Author : Yaser Imtiyaz Ahmed Shaikh
int Insertion_room(P array3[],int count2)
{
	//Declaring Variables To Store The Data From Client into Server
	P * pg_name[50];
	P * pg_types[50];
	P * fac1[50];
	P * fac2[50];
	P * fac3[50];
	P * fac4[50];
	P * fac5[50];
	P * fac6[50];
	P * fac7[50];
	P * fac8[50];
	P * fac9[50];
	P * fac10[50];
	P * Room_Description[300];
	P * num_ppl[3];
	P * price_of_pg;
	P * Date_of_PG_ADDED[150];
	P * PG_LOcation;

	//Room Insertion Process
	//Circular Linked List
	//Author : Yaser Imtiyaz Ahmed Shaikh
	P * NewPG = (P*)malloc(1 * sizeof (P));
	NewPG->Pg_Id=Pg_Id;																											//PG ID
	strcpy(NewPG->pg_name,array3[count2].pg_name);													//PG Name
	strcpy(NewPG->Room_Description,array3[count2].Room_Description);				//PG Description
	strcpy(NewPG->pg_types,array3[count2].pg_types);												//PG Type
	strcpy(NewPG->num_ppl,array3[count2].num_ppl);													//PG No of People
	strcpy(NewPG->fac1,array3[count2].fac1);																//Refrigerator
	strcpy(NewPG->fac2,array3[count2].fac2);																//Water Heater
	strcpy(NewPG->fac3,array3[count2].fac3);																//Power BackUp
	strcpy(NewPG->fac4,array3[count2].fac4);																//Dining Hall
	strcpy(NewPG->fac5,array3[count2].fac5);																//Wifi
	strcpy(NewPG->fac6,array3[count2].fac6);																//Parking
	strcpy(NewPG->fac7,array3[count2].fac7);																//Laundry
	strcpy(NewPG->fac8,array3[count2].fac8);																//Kitchen Accessories
	strcpy(NewPG->fac9,array3[count2].fac9);																//House Keeping
	strcpy(NewPG->fac10,array3[count2].fac10);															//AC
	strcpy(NewPG->Date_of_PG_ADDED,array3[count2].Date_of_PG_ADDED);				//PG Date Added
	NewPG->price_of_pg=array3[count2].price_of_pg;													//PG Cost Per Day
	strcpy(NewPG->PG_LOcation,array3[count2].PG_LOcation);									//PG Location
	NewPG->Owner_id=Oid;																										//Owner Id To Recognise Owner of PG

	if(head3 == NULL)
	{
		head3=NewPG;
		tail3=NewPG;
		NewPG->Pointer=head3;
		printf("\n\033[1;32mPG ADDED SUCCESSFULLY\033[0m");
	}
	else
	{
		tail3->Pointer=NewPG;
	  tail3=NewPG;
	  tail3->Pointer=head3;
		printf("\n\033[1;32mPG ADDED SUCCESSFULLY\033[0m");
	}
	Pg_Id++;
	return count2;
}

//Display All PGS To Admin
//Author : Yaser Imtiyaz Ahmed Shaikh
void Display_All_PGS()
{
	 ptrxyz = head3;
	 if(head3 == NULL)
   {  
   	printf("\n\033[1;33mMESSAGE ⚠\033[0m [PG] : There is No PG\n");  
   }  
   else
   {  
    	do
			{
			printf("\nThe ID of The PG : %d",ptrxyz->Pg_Id);
			printf("\nThe Registration ID Of Owner : %d ", ptrxyz->Owner_id); 
			printf("\nThe Name Of PG : %s ", ptrxyz->pg_name);
			printf("\nThe PG Type : %s ",ptrxyz->pg_types);
			printf("\nThe Location Of PG : %s",ptrxyz->PG_LOcation);
			printf("\nThe PG Description : %s ",ptrxyz->Room_Description);
			printf("\nThe PG No of People : %s ",ptrxyz->num_ppl);
			printf("\nThe PG Facility Refrigerator : %s ",ptrxyz->fac1);	
			printf("\nThe PG Facility Water Heater : %s ",ptrxyz->fac2);
			printf("\nThe PG Facility Power BackUp : %s ",ptrxyz->fac3);
			printf("\nThe PG Facility Dining Hall : %s ",ptrxyz->fac4);
			printf("\nThe PG Facility Wifi : %s ",ptrxyz->fac5);
			printf("\nThe PG Facility Parking : %s ",ptrxyz->fac6);
			printf("\nThe PG Facility Laundry : %s ",ptrxyz->fac7);
			printf("\nThe PG Facility Kitchen Accessories : %s ",ptrxyz->fac8);
			printf("\nThe PG Facility House Keeping : %s ",ptrxyz->fac9);
			printf("\nThe PG Facility AC : %s ",ptrxyz->fac10);
			printf("\nThe Cost Of Room is %d/Day ",ptrxyz->price_of_pg);
			printf("\n%s",ptrxyz->Date_of_PG_ADDED);
			printf("\n"); 
			ptrxyz=ptrxyz->Pointer;  
			}while(ptrxyz!=head3);
    }
	
}


//Display Room Details To User Only
//Author : Yaser Imtiyaz Ahmed Shaikh
void Display_mY_PGs()
{
	 ptrxyz = head3;
	 if(head3 == NULL)
   {  
   	printf("\n\033[1;33mMESSAGE ⚠\033[0m [PG] : There is No PG\n");  
   }  
   else
   {  
    	do
			{
			printf("\nThe ID Of PG : %d ", ptrxyz->Pg_Id);
			printf("\nThe Name Of PG : %s ", ptrxyz->pg_name);
			printf("\nThe PG Type : %s ",ptrxyz->pg_types);
			printf("\nThe Location Of PG : %s",ptrxyz->PG_LOcation);
			printf("\nThe PG Description : %s ",ptrxyz->Room_Description);
			printf("\nThe PG No of People : %s ",ptrxyz->num_ppl);
			printf("\nThe PG Facility Refrigerator : %s ",ptrxyz->fac1);	
			printf("\nThe PG Facility Water Heater : %s ",ptrxyz->fac2);
			printf("\nThe PG Facility Power BackUp : %s ",ptrxyz->fac3);
			printf("\nThe PG Facility Dining Hall : %s ",ptrxyz->fac4);
			printf("\nThe PG Facility Wifi : %s ",ptrxyz->fac5);
			printf("\nThe PG Facility Parking : %s ",ptrxyz->fac6);
			printf("\nThe PG Facility Laundry : %s ",ptrxyz->fac7);
			printf("\nThe PG Facility Kitchen Accessories : %s ",ptrxyz->fac8);
			printf("\nThe PG Facility House Keeping : %s ",ptrxyz->fac9);
			printf("\nThe PG Facility AC : %s ",ptrxyz->fac10);
			printf("\nThe Cost Of Room is %d/Day ",ptrxyz->price_of_pg);
			printf("\n%s",ptrxyz->Date_of_PG_ADDED);
			printf("\n"); 
			
			ptrxyz=ptrxyz->Pointer;  
			}while(ptrxyz!=head3);
    }
	User_Menu();
}

//Remove PG
//Author : Yaser Imtiyaz Ahmed Shaikh
P * Remove_PG(int X)
{
	int pos = 0;
	if(head3==NULL) 
	{
    printf("\033[1;33m NO MORE PG'S LEFT ⚠ \033[0m");
    return 0;
  } 

   if(head3->Pg_Id==X) {
      if(head3->Pointer != head3) {
         currently = head3;
         while(currently->Pointer!=head3) {
            currently = currently->Pointer;
         }
         
         currently->Pointer = head3->Pointer;
         head3 = head3->Pointer;
				 printf("\033[1;33mPG ID : %d Removed Successfully : \033[0m",X);
         return 0;
      } else {
         head3 = NULL;
         printf("List is empty\n"); 
         //exit(0);
      }
   
   } else if(head3->Pg_Id != X && head3->Pointer == NULL) {
      printf("\033[1;33mPG ID : %d Not found in the list \033[0m\n", Pg_Id);
      return 0;
   }

   currently = head3;

   while(currently->Pointer != head3 && currently->Pg_Id != X) {
      prev = currently;
      currently = currently->Pointer;
   }        

   if(currently->Pg_Id == X) {
      prev->Pointer = prev->Pointer->Pointer;
      free(currently);
			printf("\033[1;33mPG ID : %d Removed Successfully : \033[0m",X);
   } else
      printf("\033[1;31mPG ID : %d Not found in the list \033[0m\n", Pg_Id);
}





//Booking Function
//Search PG if Exists Before Bookings
//Declaring Varibale of AKA Struct
//Author : Seema Santosh Naik
P * search_pg_id_in_list=NULL;
P * ptx=NULL;
P * H=NULL;

//Search For Room Before Booking
int Add_Booking(P array3[],int count2,int n) //1
{
	//Check If Room ID Exists With This Search ID
	search_pg_id_in_list = Search_PGS(n);
	return count2;
}

//Check If Room ID Exists With This Search ID
//Author : Edphil Burce Cardozo
P * Search_PGS(int key)
{
	int flagx=1;
	int pb;  
	int no_of_bookings=0;
	int no_of_bookings_make=0;
	int bookings_insertion=0;
	int No_of_card=0;
	int No_of_card_insert=0;
	int No_of_bookings_made=0;
	P P_Bookings[max_count];
	C C_Cards[max_count];
	ptx = head3;   
	if(ptx == NULL)  
	{  
		printf("\033[1;33mThere are No PG\033[0m");
		return NULL;
	}  
	else  
	{   
		if(head3->Pg_Id==key)
		{  
			uni_pg_id=key;
			strcpy(uni_pgname,ptx->pg_name);
			strcpy(uni_pgtype,ptx->pg_types);
			strcpy(uni_pglocation,ptx->PG_LOcation);
			uni_pgcost=head3->price_of_pg;
			no_of_bookings_make=Bookings(P_Bookings,no_of_bookings); 						//2
			No_of_card=Add_card(C_Cards,No_of_card);														//1	
			No_of_card_insert=store_card_details(C_Cards,No_of_card);						//2
			No_of_bookings_made=Insertion_Bookings(P_Bookings,no_of_bookings);	//3
			generate_bill();
			printf("\n\n\033[1;33mPress 1 To Print The Bill Or Press 0 To Ignore : \033[0m");
			rtn = scanf("%d",&pb);
			if (rtn == 0) 
			{    
				printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
				empty_stdin();
			}
			if(pb==1)
			{
				print_bill();
			}
			User_Menu();
			flagx=0;
		}  
		else   
		{  
			while(ptx->Pointer != head3)  
			{  
				ptx = ptx -> Pointer; 
				if(ptx->Pg_Id==key)
				{  
					uni_pg_id=key;
					strcpy(uni_pgname,ptx->pg_name);
					strcpy(uni_pgtype,ptx->pg_types);
					strcpy(uni_pglocation,ptx->PG_LOcation);
					uni_pgcost=ptx->price_of_pg;
					no_of_bookings_make=Bookings(P_Bookings,no_of_bookings); 						//2
					No_of_card=Add_card(C_Cards,No_of_card);														//1	
					No_of_card_insert=store_card_details(C_Cards,No_of_card);						//2
					No_of_bookings_made=Insertion_Bookings(P_Bookings,no_of_bookings);	//3
					generate_bill();
					printf("\n\nPress 1 To Print The Bill Or Press 0 To Ignore : ");
					rtn = scanf("%d",&pb);
					if (rtn == 0) 
					{    
						printf("\033[1;31mError : Invalid Integer Input\033[0m.\n");
						empty_stdin();
					}
					if(pb==1)
					{
						print_bill();
					}
					User_Menu();
					flagx=0;
				}
				else  
				{  
					flagx=1;  
				}  
			}  
		}  
		if(flagx != 0)  
		{  
			printf("\033[1;31mPG With This ID Does Not Exists\033[0m");
			return 0;  
		}  
	}
}

//Booking Insertion
//Autor : Seema Santosh Naik
int Insertion_Bookings(P array3[],int count2) //3
{
	//Declaring Variables To Store The Data From Client into Server
	P * check_in_dd,check_in_mm,check_in_yy;				//CheckIn date
	P * check_out_dd,check_out_mm,check_out_yy;			//CheckOut date
	P * cd_dd[10],cd_mm[10],cd_yy[10];							//CheckIn date
	P * cc_dd[10],cc_mm[10],cc_yy[10];							//CheckOut date
	P * Booking_Date[100];
	P * Rooms_Id;
	P * trax;
	


	//Room Booking Insertion Process
	//Circular Linked List
	//Autor : Seema Santosh Naik
	P * NewBooking = (P*)malloc(1 * sizeof (P));
	NewBooking->Booking_Id=Booking_Id;															//Booking ID
	NewBooking->User_id=uni_user_id;																//Id Of Respective Owner
	NewBooking->Rooms_Id=uni_pg_id;																	//Id Of Booked PG
	NewBooking->check_in_dd=array3[count2].check_in_dd;							//Booking Check In Date
	NewBooking->check_in_mm=array3[count2].check_in_mm;							//Booking Check In Month
	NewBooking->check_in_yy=array3[count2].check_in_yy;							//Booking Check In Year
	NewBooking->check_out_dd=array3[count2].check_out_dd;						//Booking Check Out Date
	NewBooking->check_out_mm=array3[count2].check_out_mm;						//Booking Check Out Month
	NewBooking->check_out_yy=array3[count2].check_out_yy;						//Booking Check Out Year
	strcpy(NewBooking->cd_dd,array3[count2].cd_dd);									//Booking Check In Date String
	strcpy(NewBooking->cd_mm,array3[count2].cd_mm);									//Booking Check In Month String
	strcpy(NewBooking->cd_yy,array3[count2].cd_yy);									//Booking Check In Year String
	strcpy(NewBooking->cc_dd,array3[count2].cc_dd);									//Booking Check Out Date String
	strcpy(NewBooking->cc_mm,array3[count2].cc_mm);									//Booking Check Out Month String
	strcpy(NewBooking->cc_yy,array3[count2].cc_yy);									//Booking Check Out Year String
	strcpy(NewBooking->Booking_Date,array3[count2].Booking_Date);		//Booking Date
	strcpy(uni_in_dd,array3[count2].cd_dd);
	strcpy(uni_in_mm,array3[count2].cd_mm);
	strcpy(uni_in_yy,array3[count2].cd_yy);
	strcpy(uni_out_dd,array3[count2].cc_dd);
	strcpy(uni_out_mm,array3[count2].cc_mm);
	strcpy(uni_out_yy,array3[count2].cc_yy);
	strcpy(uni_bk_date,array3[count2].Booking_Date);
	if(head3 == NULL)
	{
		head3=NewBooking;
		tail3=NewBooking;
		NewBooking->Arrow=head3;
		printf("\n\033[1;32mBOOKED SUCCESSFULLY\033[0m");
	}
	else
	{
		tail3->Arrow=NewBooking;
		tail3=NewBooking;
		tail3->Arrow=head3;
		printf("\n\033[1;32mBOOKED SUCCESSFULLY\033[0m");
	}
	Booking_Id++;
	return count2;
}

//Delete Booking
//Autor : Seema Santosh Naik
P * electricx=NULL;
P * backx=NULL;
P * Remove_Bookings_made(int M)
{
	int pos = 0;
	if(head3==NULL) 
	{
    printf("\033[1;33m NO MORE BOOKING'S LEFT ⚠\033[0m");
    return 0;
  } 

   if(head3->Booking_Id==M) {
      if(head3->Arrow != head3) {
         electricx = head3;
         while(electricx->Arrow!=head3) {
            electricx = electricx->Arrow;
         }
         
         electricx->Arrow = head3->Arrow;
         head3 = head3->Arrow;
				 printf("\033[1;32mBOOKING ID : %d Removed Successfully : \033[0m",M);
         return 0;
      } else {
         head3 = NULL;
         printf("\033[1;33mList is empty\033[0m\n"); 
         //exit(0);
      }
   
   } else if(head3->Booking_Id != M && head3->Arrow == NULL) {
      printf("\033[1;33mBOOKING ID : %d Not found in the list\033[0m\n", Booking_Id);
      return 0;
   }

   electricx = head3;

   while(electricx->Arrow != head3 && electricx->Booking_Id != M) {
      backx = electricx;
      electricx = electricx->Arrow;
   }        

   if(electricx->Booking_Id == M) {
      backx->Arrow = backx->Arrow->Arrow;
      free(electricx);
			printf("\033[1;33mBOOKING ID : %d Removed Successfully : \033[0m",M);
   } else
      printf("\033[1;33mBOOKING ID : %d Not found in the list \033[0m\n", Booking_Id);
}

//Check if Someone has booked or not
//Autor : Edphil Burce Cardozo
int search_booked_PG(int key)
{
	int index = 0;
  P *currentx = head3;
	do 
  {
		// Nothing to look into
		if (currentx == NULL)
			return 0;
		
		if (currentx->Rooms_Id == key)
			return index;

    currentx = currentx->Arrow;
		index++;
    } while (currentx != head3);

    // Element not found in list
    return -1;
}




//Card Process
//Declaring head and tail pointer as null and I have declared it once because I will Be using In The entire Program.  
C *	head4=NULL;
C * tail4=NULL;

//Insert Card Details in Server
//Author : Seema Santosh Naik
int store_card_details(C array4[],int count3)
{
	//Declaring Variables To Store The Data From Client into Server
	C * Card_Holder_name[20];
	C * Card_Number[20]; 
	C * Exp_Month[3];
	C * Exp_Year[5];
	C * CVV[5];

	//Card Details Insertion Process
	//Circular Linked List
	//Author : Yaser Imtiyaz Ahmed Shaikh
	C * NewCard = (C*)malloc(1 * sizeof (C));
	NewCard->Card_Id=Card_Id;																						//ID Of Card
	strcpy(NewCard->Card_Holder_name,array4[count3].Card_Holder_name);	//Card Holder Name
	strcpy(NewCard->Card_Number,array4[count3].Card_Number);						//Card Number
	strcpy(NewCard->Exp_Month,array4[count3].Exp_Month);								//Card Expiry Month
	strcpy(NewCard->Exp_Year,array4[count3].Exp_Year);									//Card Expiry Year
	strcpy(NewCard->CVV,array4[count3].CVV);														//Card CVV
	if(head4 == NULL)
	{
		head4=NewCard;
		tail4=NewCard;
		NewCard->PPP=head4;
		printf("\n\033[1;32mPAYMENT SUCCESSFULLY\033[0m");
	}
	else
	{
		tail4->PPP=NewCard;
		tail4=NewCard;
		tail4->PPP=head4;
		printf("\n\033[1;32mPAYMENT SUCCESSFULLY\033[0m");
	}
	Card_Id++;
	return count3;
}

//Display Bookings Made
//Author : Yaser Imtiyaz Ahmed Shaikh
P * bkptr=NULL;
void Display_bookings()
{
	 bkptr = head3;
	 if(head3 == NULL)
   {  
   	printf("\n\033[1;33mMESSAGE ⚠\033[0m [PG] : There is No Booking Made\n");  
   }  
   else
   {  
    	do
			{
				printf("\nThe Booking ID : %d ", bkptr->Booking_Id);
				printf("\nThe User ID : %d ", bkptr->User_id);
				printf("\nThe Booked PG ID : %d ", bkptr->Rooms_Id);
				printf("\nThe Check In Date : %s/%s/%s ", bkptr->cd_dd,bkptr->cd_mm,bkptr->cd_yy);
				printf("\nThe Check Out Date : %s/%s/%s ",bkptr->cc_dd,bkptr->cc_mm,bkptr->cc_yy);
				printf("\nThe Date Of Booking : %s ", bkptr->Booking_Date);
				printf("\n"); 
				bkptr=bkptr->Arrow;  
			}while(bkptr!=head3);
    }
}


//Billl
//Generate Billl
//Author : Yaser Imtiyaz Ahmed Shaikh
void generate_bill()
{
	bkptr = head3;
	ptrxyz = head3;
	printf("\n\n");
	printf("\t\t\t\t*************************************************");
	printf("\n\t\t\t\t******************CUSTOMER BILL******************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t************CUSTOMER CONTACT DETAILS*************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tCustomer Name : %s",uni_name);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tCustomer Email : %s",uni_email);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tCustomer Phone : %s",uni_phone);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t***************CUSTOMER PG DETAILS***************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPG Name : %s",uni_pgname);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPG Type : %s",uni_pgtype);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPG Location : %s",uni_pglocation);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPG Cost/Day : %d",uni_pgcost);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t**************CUSTOMER BOOKING DETAILS***********");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tCheck IN Date : %s/%s/%s ", uni_in_dd,uni_in_mm,uni_in_yy);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tCheck Out Date : %s/%s/%s ",uni_out_dd,uni_out_mm,uni_out_yy);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tDate of Booking : %s",uni_bk_date);
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t**************CUSTOMER PAYMENT DETAILS***********");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPayment Type : Online");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\tPayment Status : Paid");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t*************************************************");
	printf("\n\t\t\t\t************** THANK YOU VISIT AGAIN🙏************");
}

//Print Bill
//Author : Yaser Imtiyaz Ahmed Shaikh
void print_bill()
{
	bkptr = head3;
	ptrxyz = head3;
	FILE *fptr;
	fptr = fopen("Customer's Bill.txt","w");
	if(fptr == NULL)
	{
		printf("\033[1;31mError!\033[0m");   
		exit(1);             
	}

	//Time Function
	time_t t ;
	struct tm *tmp ;
	char DateTime[100];
	time( &t );
	tmp = localtime( &t );
	strftime(DateTime, sizeof(DateTime), "%x : %I:%M%p", tmp);

	//Data is Written To File
	fprintf(fptr,"%s","\n\n");
	fprintf(fptr,"%s","\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t******************CUSTOMER BILL******************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t************CUSTOMER CONTACT DETAILS*************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tCustomer Name : ");
	fprintf(fptr,"%s",uni_name);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tCustomer Email : ");
	fprintf(fptr,"%s",uni_email);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tCustomer Phone : ");
	fprintf(fptr,"%s",uni_phone);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t***************CUSTOMER PG DETAILS***************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPG Name : ");
	fprintf(fptr,"%s",uni_pgname);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPG Type : ");
	fprintf(fptr,"%s",uni_pgtype);	
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPG Location : ");
	fprintf(fptr,"%s",uni_pglocation);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPG Cost/Day : ");
	fprintf(fptr,"%d",uni_pgcost);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t**************CUSTOMER BOOKING DETAILS***********");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tCheck IN Date : ");
	fprintf(fptr,"%s",uni_in_dd);
	fprintf(fptr,"%s","/");
	fprintf(fptr,"%s",uni_in_mm);
	fprintf(fptr,"%s","/");
	fprintf(fptr,"%s",uni_in_yy);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tCheck Out Date : ");
	fprintf(fptr,"%s",uni_out_dd);
	fprintf(fptr,"%s","/");
	fprintf(fptr,"%s",uni_out_mm);
	fprintf(fptr,"%s","/");
	fprintf(fptr,"%s",uni_out_yy);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tDate of Booking : ");
	fprintf(fptr,"%s",uni_bk_date);
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t**************CUSTOMER PAYMENT DETAILS***********");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPayment Type : Online");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\tPayment Status : Paid");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t*************************************************");
	fprintf(fptr,"%s","\n\t\t\t\t************* THANK YOU VISIT AGAIN🙏************");
	fprintf(fptr,"%s","\n");
	fprintf(fptr,"%s","        Date and Time of Report : ");
	fprintf(fptr,"%s",DateTime);
	fclose(fptr);

}