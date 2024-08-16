
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>	
#include "Data_Structure_structure.h"
int count;
int ID=1;				
int uni_user_id;
char uni_name[20];
char uni_email[20];
char uni_phone[20];

//Declaring head and tail pointer as null and I have declared it once because I will Be using In The entire Program.  
R * head=NULL;
R * tail=NULL;
R * search_user=NULL;
R * ptr=NULL;
R * current=NULL; 


//Insertion
//Author : Yaser Imtiyaz Ahmed Shaikh
int insertion(R  array[],int count)
{
	
	//Declaring Variables To Store The Data From Client into Server
	R * Name;
	R * Gender;
	R * Phone;
	R * Email;
	R * Address;
	R * City;
	R * State;
	R * Password;
	R * CPassword;
	R * Date_Of_User_Added;
	
	//Registration Process
	//Circular Linked List
	//Author : Yaser Imtiyaz Ahmed Shaikh
	R * NewMember = (R*)malloc(1 * sizeof (R));
	NewMember->ID=ID;																															//ID
	strcpy(NewMember->Name,array[count].Name);																		//Name
	strcpy(NewMember->Gender,array[count].Gender);																//Gender
	strcpy(NewMember->Phone,array[count].Phone);																	//Phone
	strcpy(NewMember->Email,array[count].Email);																	//Email
	strcpy(NewMember->Address,array[count].Address);															//Address
	strcpy(NewMember->City,array[count].City);																		//City
	strcpy(NewMember->State,array[count].State);																	//State
	strcpy(NewMember->Password,array[count].Password);														//Password
	strcpy(NewMember->CPassword,array[count].CPassword);													//Confirm Password
	strcpy(NewMember->Date_Of_User_Added,array[count].Date_Of_User_Added);				//User Added Date
	if(head == NULL)
	{
		head=NewMember;
		tail=NewMember;
		NewMember->Next=head;
		printf("\n\033[1;32mREGISTERED SUCCESSFULLY\033[0m");
	}
	else //Search For Duplicates //Author : Edphil Burce Cardozo
	{
    ptr=head;
		ptr=ptr->Next;
		if(strcmp(ptr->Email, array[count].Email) == 0) //0->Valid
		{ 
			printf("\n\033[1;33mACCOUNT WITH THIS EMAIL ALREADY EXISTS : ⚠\033[0m");
		}
		else
		{
			tail->Next=NewMember;
			tail=NewMember;
			tail->Next=head;
			printf("\n\033[1;32mREGISTERED SUCCESSFULLY\033[0m");
		}
	}
	ID++;
  return count;
}
	
//Displaying Data : Admin Use
//Author : Yaser Imtiyaz Ahmed Shaikh
void Display_Registration()
{  
   current = head;  
   if(head == NULL)
   {  
    printf("\033[1;33mMESSAGE ⚠\033[0m : No one Has Registered\n");  
   }  
   else
   {  
    do
      {
      	printf("\nThe Name : %s ", current->Name);
      	printf("\nThe Gender : %s ",current->Gender);
      	printf("\nThe Address : %s ", current->Address);
      	printf("\nThe City : %s ", current->City);
      	printf("\nThe State : %s ", current->State); 
				printf("\n%s ",current->Date_Of_User_Added);
      	printf("\n\n");     	  
      	current = current->Next;  
      }
      while(current != head) ;
    
     }
}

//Registration Details : Display Personal Details Of User
//Author : Yaser Imtiyaz Ahmed Shaikh
void ViewMydata_Registration()
{  
	if(head == NULL)
	{  
		printf("\n\033[1;33mMESSAGE ⚠\033[0m : No one Has Registered\n");  
	}  
	else
	{  
		printf("\nThe Registration ID : %d ", ptr->ID); 
		printf("\nThe Name : %s ", ptr->Name);
		printf("\nThe Gender : %s ", ptr->Gender);
		printf("\nThe Phone : %s ", ptr->Phone);
		printf("\nThe Email Address : %s ", ptr->Email);
		printf("\nThe Address : %s ", ptr->Address);
		printf("\nThe City : %s ", ptr->City);
		printf("\nThe State : %s ", ptr->State); 
		printf("\nThe Password: %s ", ptr->Password); 
		printf("\n%s ",ptr->Date_Of_User_Added);
		uni_user_id= ptr->ID;	
		strcpy(uni_name,ptr->Name);
		strcpy(uni_email,ptr->Email);
		strcpy(uni_phone,ptr->Phone);
		printf("\n\n");     	  
		printf("\n");  
	}  
} 


//Login Process
//Author : Edphil Burce Cardozo
int R_login(R  array[],int count)
{
	printf("USER LOGIN");
	
	//Email
	printf("\nEnter the Email : ");
	scanf("%s",array[count].Email);
	while(strlen(array[count].Email)>20)
	{
		printf("Array Size is exceeding \033[1;31mMax[20]\033[0m.\nPlease Enter The Email : ");
		scanf("%s",array[count].Email);
	}
	
	//Password
	printf("Enter the Password : ");
	scanf("%s",array[count].Password);
	while(strlen(array[count].Password)>12)
	{
		printf("Array Size is exceeding \033[1;31mMax[12]\033[0m.\nPlease Enter The Password : ");
		scanf("%s",array[count].Password);
	}
		
	//Check Is User is Exists or Not
	search_user = search_Email(array[count].Email,array[count].Password);
	return count;
}

//Login Search :  Search If Email Exists or Not
//Author : Edphil Burce Cardozo 
R * search_Email(char key[20],char key1[20])
{
	int flag=1;  
	ptr = head;   
	if(ptr == NULL)  
	{  
		printf("\033[1;31mInvalid details\033[0m");
		return NULL;
	}  
	else  
	{   
		if(strcmp(head->Email, key) == 0 )  
		{  
			if(strcmp(head->Password, key1) == 0 )  
			{
				//printf("The User Id : %d",head->ID);
				uni_user_id=head->ID;
				strcpy(uni_name,head->Name);
				strcpy(uni_email,ptr->Email);
				strcpy(uni_phone,ptr->Phone);
				printf("\033[1;32mLogin Successful\033[0m");
				User_Menu();
				flag=0;  
			}
		}  
		else   
		{  
			while (ptr->Next != head)  
			{  
				ptr = ptr -> Next; 
				if(strcmp(ptr->Email, key) == 0 )  
				{  
					if(strcmp(ptr->Password, key1) == 0 )  
					{
						//printf("The User Id : %d",ptr->ID);
						uni_user_id=ptr->ID;
						strcpy(uni_name,ptr->Name);
						strcpy(uni_email,ptr->Email);
						strcpy(uni_phone,ptr->Phone);
						printf("\033[0;32mLogin Successful\033[0m");
						User_Menu();  
						flag=0;  
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
			printf("\033[1;31mInvalid details\033[0m");
			User(); 
			return 0;  
		}  
	} 
}     



//Register Delete : Delete Element from Circular Linked List
//Author :  Yaser Imtiyaz Ahmed Shaikh
R * De_Registration()
{
	int i,count;
	R *prev,*cur;

	if (head == NULL)
	{
			printf("\033[0;33mNot Registered ⚠ .\033[0m\n");
			return NULL;
	}

	count = 0;
	cur   = head;
	prev  = cur;

	// Find node before head node
	while (prev->Next != head)
	{
			prev = prev->Next;
			count++;
	}

	// Iterate till first node
	i = 0;
	while (i <= count)
	{
			if (cur->ID == ptr->ID)
			{
					// Link prev node with next node of current
					if (cur->Next != cur)
							prev->Next = cur->Next;
					else
							prev->Next = NULL;

					// Adjust head node if needed
					if (cur == head)
							head = prev->Next;

					// Delete current node
					free(cur);

					// Move current node ahead
					if (prev != NULL)
							cur = prev->Next;
					else
							cur = NULL;
			}
			else
			{
					prev = cur;
					cur  = cur->Next;
			}
i++;
	}
}
