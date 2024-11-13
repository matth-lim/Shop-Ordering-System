#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "new_cus_func.h"
#include "additional_func.h"

// New customer main menu
void new_cus_menu()
{
	printf("\t*****New Customer Menu*****\n");
	printf("\n1. Register account\n2. Return to main menu\n3. Exit");
	printf("\nSelect a choice: ");
	char choice[100];
	fgets(choice, 100, stdin);
	if (choice[0] == '1' && choice[1] == '\n')
	{
		system("cls");
		regis_new_cus();
	}
	else if (choice[0] == '2' && choice[1] == '\n')
	{
		system("cls");
		start();
	}
	else if (choice[0] == '3' && choice[1] == '\n')
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid input! Press Enter to try again.....");
		fgets(choice, 100, stdin);
		system("cls");
		staff_menu();
	}
}															

// Registration for new customer
void regis_new_cus()
{
	struct new_cus {
		char name[100];
		char age[100];
		char email_add[100];
		char username[100];
		char password[100];
		char re_pass[100];
	} new_cus1;
	printf("\t*****Register Account*****\n");
	printf("\nEnter your name: ");
	fgets(new_cus1.name, 100, stdin);
	printf("Enter your age: ");
	fgets(new_cus1.age, 100, stdin);
	while (check_valid_digit(new_cus1.age))
	{
		printf("Age is invalid! Enter your age again: ");
		fgets(new_cus1.age, 100, stdin);
	}
	printf("Enter your email address: ");
	fgets(new_cus1.email_add, 100, stdin);
	printf("Enter your username: ");
	fgets(new_cus1.username, 100, stdin);
	while (check_first_element_dup("customer.txt", new_cus1.username, 1, 6))
	{
		printf("Username is used! Enter another username: ");
		fgets(new_cus1.username, 100, stdin);
	}
	printf("Enter your password: ");
	fgets(new_cus1.password, 100, stdin);
	printf("Retype your password: ");
	fgets(new_cus1.re_pass, 100, stdin);
	while (strcmp(new_cus1.password, new_cus1.re_pass) != 0)
	{
		printf("Password do not match!\nEnter your password: ");
		fgets(new_cus1.password, 100, stdin);
		printf("Retype your password: ");
		fgets(new_cus1.re_pass, 100, stdin);
	}
	FILE* pfile = fopen("customer.txt", "a");
	fprintf(pfile, new_cus1.username);
	fprintf(pfile, new_cus1.password);
	fprintf(pfile, new_cus1.name);
	fprintf(pfile, new_cus1.age);
	fprintf(pfile, new_cus1.email_add);
	fprintf(pfile, "\n");
	fclose(pfile);
	printf("Account created successfully! Press enter to return to menu.....");
	fgets(new_cus1.username, 100, stdin);
	system("cls");
	start();
}