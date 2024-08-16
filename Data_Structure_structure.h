//Author : Yaser Imtiyaz Ahmed Shaikh
#ifndef _MY_PG_LIB_  // TO prevent multiple inclusions of the header file
#define _MY_PG_LIB_ 
#include<stdbool.h>
extern int max_count;
extern int admin_count;
extern int owner_count;
extern int Mode;
extern int rtn;
extern int uni_user_id;
extern char uni_name[20];
extern char uni_email[20];
extern char uni_phone[20];
extern char uni_pgname[20];
extern char uni_pgtype[30]; 
extern char uni_pglocation[20];
extern int uni_pgcost;
extern char uni_in_dd[20];
extern char uni_in_mm[20];
extern char uni_in_yy[20];
extern char uni_out_dd[20];
extern char uni_out_mm[20];
extern char uni_out_yy[20];
extern char uni_bk_date[25];




//structures
struct Registration
{
	int ID;
	char Name[20];
	char Gender[10];
	char Phone[20];
	char Email[20];
	char Address[20];
	char City[20];
	char State[20];
	char Password[12];
	char CPassword[12];
	char Date_Of_User_Added[100];
	int data1;
	int array[100];
	struct Registration *Next;
};

struct Admin
{
	char Admin_Username[10];
	char Admin_Password[15];
	struct Admin *Direction;
	int array1[100];
};

struct Owner
{
	int Owner_ID;
	char Owner_Name[10];
	char Owner_Gender[10];
	char Owner_Phone[20];
	char Owner_Email[20];
	char Owner_Address[20];
	char Owner_City[20];
	char Owner_State[20];
	char Owner_Password[12];
	char Owner_CPassword[12];
	char Date_Of_Owner_Added[100];
	int data2;
	struct Owner *Link;
};

struct PG
{
	int Owner_id;
	int User_id;
	int Pg_Id;
	int pg_type;
	int fac;
	char pg_name[50];
	char pg_types[50];
	char fac1[50];
	char fac2[50];
	char fac3[50];
	char fac4[50];
	char fac5[50];
	char fac6[50];
	char fac7[50];
	char fac8[50];
	char fac9[50];
	char fac10[50];
	char Room_Description[300];
	char num_ppl[3];
	int price_of_pg;
	char Date_of_PG_ADDED[150];
	char PG_LOcation[200];
	struct PG *Pointer;
	struct PG *Arrow;

	//Bookings
	int check_in_dd,check_in_mm,check_in_yy;		//CheckIn date
	int check_out_dd,check_out_mm,check_out_yy;	//CheckOut date
	char cd_dd[10],cd_mm[10],cd_yy[10];					//CheckIn date
	char cc_dd[10],cc_mm[10],cc_yy[10];					//CheckOut date
	char Booking_Date[100];											//Booking Date
	int Rooms_Id;
	int Booking_Id;
};

struct AtmCard
{
	int Card_Id;
	char Card_Holder_name[20];
	char Card_Number[20];
	char Exp_Month[3];
	char Exp_Year[5];
	char CVV[5];
	struct AtmCard *PPP;
};


typedef struct Registration R;
typedef struct Admin A;
typedef struct Owner O;
typedef struct PG P;
typedef struct AtmCard C;



//Using array 'array' Globally
R * array[100];
A * array1[100]; 
O * array2[100];
P * array3[100];
C * array4[100];

//Function Prototypes For Every Mode
void menu(int Mode);																		//Modes Main Menu
bool isNumber(char s[50]); 															//To check if string contains only digit or not


//Function Prototypes : Admin
void Admin();																						//Admin Details
int log_in(A  array1[],int count);											//Admin Login
int admin_insertion(A  array1[],int count);							//Admin's Username And Password Are Stored Here
A * search_Username_Admin(char key[20],char key1[20]);	//Search For Admin Username And Password
void Admin_Menu();																			//Admin Menu

//Function Prototypes : User
void User();																						//User Details
int insertion(R  array[],int count); 	 				 					//Transfer Data From Client To Server
int Register(R array[],int count); 	 				    				//Registration Process
void Display_Registration(); 		 												//Registration Display
void ViewMydata_Registration();	 												//View User's Personal Details To Itself Only
int R_login(R array[],int count);	 											//Login 
R * search_Email(char key[20],char key1[20]);						//Find Email
void User_Menu();																				//User Menu
R * search_Usernamex(char key[20]);											//Check If Email Exists Before Entering
R * De_Registration();														      //Deletion of An Registered Account

//Function Prototypes : Owner
void Owner();
int Owner_Register(O array2[],int count1);							//Owner Registration
int Owner_Insertion(O  array2[],int count1);						//Transfer Data From Client To Server	
void Owner_Menu();																			//Owner Menu
void ViewMydataOwner_Registration();										//View Owner's Personal Details To Itself Only
void Display_Registration_Owner();											//Admin Use
int O_login(O array2[],int count1);											//Owner Login				
O * search_owner_email(char key[20],char key1[20]);			//Find Owner Email
O * De_Owner_Registration();														//Deletion of An Owner Registered Account

//Function Prototypes : PG
int Add_room(P array3[],int count2);										//Add Room
int Insertion_room(P array3[],int count2);							//Inserting Room Into Circular Linked List
void Display_All_PGS();																	//Display All PGS of All Owners Based On when they have Added them 
P * Remove_PG(int X);																		//Delete PG
void Display_mY_PGs();																	//Display Certain Details To User For Booking


//Function Prototypes : Booking
int Add_Booking(P array3[],int count2,int n);						//Search For Room Before Booking
P * Search_PGS(int key);																//Search Pg is Exists Before Booking
int Bookings(P array3[],int count2);							      //Go For Bookings
int Insertion_Bookings(P array3[],int count2);					//Booking Confirm
void Display_bookings();																//Display Bookings Done
P * Remove_Bookings_made(int M);												//Delete Bookings Made
int search_booked_PG(int key);													//Search for Room Before Booking
void generate_bill();																		//Display Generate Bill
void print_bill();																			//Write the Data to A File


//Function Prototypes : Card
int Add_card(C array4[],int count3);										//Insert Card
int store_card_details(C array4[],int count3);					//Store Care Details In server for Booking	

//Function Prototypes : Validation For Integer Input
void empty_stdin (void);
#endif     