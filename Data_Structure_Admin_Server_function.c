#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>	
#include "Data_Structure_structure.h"
int count;

//Declaring head and tail pointer as null and I have declared it once because I will Be using In The entire Program.  
//Author :  Yaser Imtiyaz Ahmed Shaikh
A * head2=NULL;
A * tail2=NULL;
A * search_Admin_user=NULL;
A * ptrs=NULL;

//Insertion
//Author :  Yaser Imtiyaz Ahmed Shaikh
int admin_insertion(A  array1[],int count)
{
	//Declaring Variables To Store The Data From Client into Server
	//Author :  Yaser Imtiyaz Ahmed Shaikh
	A * Admin_Username;
	A * Admin_Password;

	//Username and Password Stored Here
	//Circular Linked List
	//Author :  Yaser Imtiyaz Ahmed Shaikh
	A * NewAdmin = (A*)malloc(1 * sizeof (A));
	strcpy(NewAdmin->Admin_Username,"Admin");					//Username
	strcpy(NewAdmin->Admin_Password,"Ankola@327");		//Password

	if(head2 == NULL)
	{
		head2=NewAdmin;
		tail2=NewAdmin;
		NewAdmin->Direction=head2;
	}
	return count;
}

//Login Search :  Search If Admin Username Exists or Not 
//Author : Edphil Burce Cardozo
A * search_Username_Admin(char key[20],char key1[20])
{
	if(head2 == NULL)
		return NULL;
	else
	{
		ptrs =head2;
		ptrs=ptrs->Direction;
		while(ptrs != NULL)
		{
			if(strcmp(ptrs->Admin_Username, key) == 0 && strcmp(ptrs->Admin_Password, key1) == 0 )//&& (ptr->ID==ID-1)) //0->Valid
			{ 
				printf("\033[1;32mLogin Successful\033[0m");
			
			}
			else
			{
			printf("\033[1;31mInvalid details\033[0m\n");
			Admin();
			}
			return ptrs;
		}
		return NULL;
	}
}
 
