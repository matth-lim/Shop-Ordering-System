#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "staff_func.h"
#include "new_cus_func.h"
#include "regis_cus_func.h"
#include "additional_func.h"

// To start the entire program
void start()
{
	printf("\t*****Welcome to Dosta Coffee shop*****\n");
	printf("\n1. Staff\n2. New customer\n3. Registered customer\n4. Exit");
	printf("\nSelect a choice: ");
	char choice[100];
	fgets(choice, 100, stdin);
	if (choice[0] == '1' && choice[1] == '\n')
	{
		system("cls");
		staff_login();
	}
	else if (choice[0] == '2' && choice[1] == '\n')
	{
		system("cls");
		new_cus_menu();
	}
	else if (choice[0] == '3' && choice[1] == '\n')
	{
		system("cls");
		regis_cus_login();
	}
	else if (choice[0] == '4' && choice[1] == '\n')
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid input! Press Enter to try again.....");
		fgets(choice, 100, stdin);
		system("cls");
		start();
	}
}

int main()
{   
	start();
	return 0;                             
}