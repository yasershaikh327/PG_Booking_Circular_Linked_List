//Author :  Yaser Imtiyaz Ahmed Shaikh
#include "Data_Structure_structure.h"
#include <stdlib.h>
#include <stdio.h>

//Menu
void menu(int Mode)
{
	//Switch Modes
	switch(Mode)
	{
		case 1:
		Admin();
		break;
		
		case 2:
		User();
		break;
		
		case 3:
		Owner();
		break;
		
		case 4:
		printf("\033[1;33mExiting\033[0m\n");
		exit(0);
		break;

		default:
		printf("\033[1;31mInvalid Choice\033[0m\n");
	}
}


