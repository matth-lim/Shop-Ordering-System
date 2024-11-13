#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "additional_func.h"
#include "regis_cus_func.h"

// Registered customer login screen
void regis_cus_login()
{
	char username[100];
	char password[100];
	printf("\t*****Customer Login*****\n");
	printf("\nEnter your username: ");
	fgets(username, 100, stdin);
	printf("Enter your password: ");
	fgets(password, 100, stdin);
	if (check_first_element_dup("customer.txt", username, 1, 6) && check_first_element_dup("customer.txt", password, 2, 6))
	{
		system("cls");
		regis_cus_menu(get_line_num("customer.txt", username, 1, 6));
	}
	else
	{
		printf("Invalid username or password! Press Enter to return to menu.....");
		fgets(username, 100, stdin);
		system("cls");
		start();
	}
}

// Registered customer main menu
void regis_cus_menu(int line_num)
{
	printf("\t*****Registered Customer Menu*****\n");
	printf("\n1. Modify customer details\n2. Place order\n3. Make payment\n4. Cancel order\n5. Return to main menu\n6. Exit");
	printf("\nSelect a choice: ");
	char choice[100];
	fgets(choice, 100, stdin);
	if (choice[0] == '1' && choice[1] == '\n')
	{
		system("cls");
		modify_detail(line_num);
	}
	else if (choice[0] == '2' && choice[1] == '\n')
	{
		system("cls");
		place_order(line_num);
	}
	else if (choice[0] == '3' && choice[1] == '\n')
	{
		system("cls");
		make_payment(line_num);
	}
	else if (choice[0] == '4' && choice[1] == '\n')
	{
		system("cls");
		cancel_order(line_num);
	}
	else if (choice[0] == '5' && choice[1] == '\n')
	{
		system("cls");
		start();
	}
	else if (choice[0] == '6' && choice[1] == '\n')
	{
		system("cls");
		exit(0);
	}
	else
	{
		printf("Invalid input! Press Enter to try again.....");
		fgets(choice, 100, stdin);
		system("cls");
		regis_cus_menu(line_num);
	}
}

// For registered customer to modify their own personal detail
void modify_detail(int line_num)
{
	printf("\t*****Modify Customer detail*****\n");
	printf("\n1. Name\n2. Age\n3. Email address\n4. Username\n5. password");
	printf("\nSelect a choice: ");
	char choice[100];
	fgets(choice, 100, stdin);
	if (choice[0] == '1' && choice[1] == '\n')
	{
		char name[100];
		printf("\nEnter your new name: ");
		fgets(name, 100, stdin);
		replace_line_file("customer.txt", name, line_num + 2);
		printf("Your name has been changed successfully. Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	else if (choice[0] == '2' && choice[1] == '\n')
	{
		char age[100];
		printf("\nEnter your new age: ");
		fgets(age, 100, stdin);
		while (check_valid_digit(age))
		{
			printf("Age is invalid! Enter your age again: ");
			fgets(age, 100, stdin);
		}
		replace_line_file("customer.txt", age, line_num + 3);
		printf("Your age has been changed successfully. Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	else if (choice[0] == '3' && choice[1] == '\n')
	{
		char email_add[100];
		printf("\nEnter your new email address: ");
		fgets(email_add, 100, stdin);
		replace_line_file("customer.txt", email_add, line_num + 4);
		printf("Your email address has been changed successfully. Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	else if (choice[0] == '4' && choice[1] == '\n')
	{
		char username[100];
		printf("\nEnter your new username: ");
		fgets(username, 100, stdin);
		while (check_first_element_dup("customer.txt", username, 1, 6))
		{
			printf("Username is used! Enter another username: ");
			fgets(username, 100, stdin);
		}
		replace_line_file("customer.txt", username, line_num);
		printf("Your username has been changed successfully. Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	else if (choice[0] == '5' && choice[1] == '\n')
	{
		char password[100];
		char re_pass[100];
		printf("Enter your password: ");
		fgets(password, 100, stdin);
		printf("Retype your password: ");
		fgets(re_pass, 100, stdin);
		while (strcmp(password, re_pass) != 0)
		{
			printf("Password do not match!\nEnter your password: ");
			fgets(password, 100, stdin);
			printf("Retype your password: ");
			fgets(re_pass, 100, stdin);
		}
		replace_line_file("customer.txt", password, line_num + 1);
		printf("Your password has been changed successfully. Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	else
	{
		printf("Invalid input! Press Enter to return to menu.....");
		fgets(choice, 100, stdin);
	}
	system("cls");
	regis_cus_menu(line_num);
}

// For registered customer to place order
void place_order(int line_num)
{
	char order[100];
	char all_info[100];
	char buffer[255];
	printf("\t*****Place Order*****\n");
	printf("\nEnter your order: ");
	fgets(order, 100, stdin);
	FILE* pfile = fopen("customer.txt", "r");
	if (pfile == NULL)
		exit(0);
	for (int i = 0; i < line_num + 5; i++)
		fgets(buffer, 255, pfile);
	fclose(pfile);
	buffer[strcspn(buffer, "\n")] = 0;
	order[strcspn(order, "\n")] = 0;
	int duplicate_order = strstr(buffer, order);
	str_cont(order, '\n');
	if (check_first_element_dup("menu_item.txt", order, 2, 3) && duplicate_order == 0)
	{
		order[strcspn(order, "\n")] = 0;
		sprintf(all_info, "%s%s,\n",buffer,order);
		replace_line_file("customer.txt", all_info, line_num + 5);
		printf("Order placed successfully. Press Enter to return to menu.....");
		fgets(order, 100, stdin);
	}
	else
	{
		printf("Invalid order or order has been placed! Press Enter to try again.....");
		fgets(order, 100, stdin);
	}
	system("cls");
	regis_cus_menu(line_num);
}

// For registered customer to make payment
void make_payment(int line_num)
{
	int total = 0;
	char buffer[255];
	char choice[100];
	char creditcard_num[100];
	char exp_date[100];
	char CCV[100];
	printf("\t*****Make Payment*****\n\n");
	FILE* pfile = fopen("customer.txt", "r");
	if (pfile == NULL)
		exit(0);
	for (int i = 0; i < line_num + 5; i++)
		fgets(buffer, 255, pfile);
	fclose(pfile);
	char word[100] = "";
	int len = strlen(buffer);
	for (int i = 0; i < len; i++)
	{
		if (buffer[i] == ',')
		{
			FILE* pfile = fopen("menu_item.txt", "r");
			if (pfile == NULL)
				exit(0);
			str_cont(word, '\n');
			char price[255];
			int line_num = get_line_num("menu_item.txt", word, 2, 3);
			for (int y = 0; y < line_num + 1; y++)
				fgets(price, 255, pfile);
			fclose(pfile);
			word[strcspn(word, "\n")] = 0;
			printf("%s - %s", word, price);
			char* new_price = price + 1;
			total += atoi(new_price);
			memset(word, 0, 100);
			continue;
		}
		str_cont(word, buffer[i]);
	}
	printf("\nTotal price: $%d", total);
	printf("\n\nEnter your credit card number: ");
	fgets(creditcard_num, 100, stdin);
	while (check_valid_digit(creditcard_num))
	{
		printf("Credit card number is invalid! Enter your credit card number again: ");
		fgets(creditcard_num, 100, stdin);
	}
	printf("Enter credit card's expiry date: ");
	fgets(exp_date, 100, stdin);
	printf("Enter credit card's CCV: ");
	fgets(CCV, 100, stdin);
	while (check_valid_digit(CCV))
	{
		printf("CCV is invalid! Enter your CCV again: ");
		fgets(CCV, 100, stdin);
	}
	printf("Thanks for purchase! Do you want a receipt (Y/N): ");
	fgets(choice, 100, stdin);
	if (choice[0] == 'Y' && choice[1] == '\n')
	{
		system("cls");
		gen_receipt(line_num);
	}
	else
	{
		system("cls");
		replace_line_file("customer.txt", "\n", line_num + 5);
		regis_cus_menu(line_num);
	}
}

// For registered custoemr to cancel their order
void cancel_order(int line_num)
{
	char order[100];
	char buffer[100];
	int valid = 0;
	printf("\t*****Cancel Order*****\n");
	printf("\nEnter the order you want to cancel: ");
	fgets(order, 100, stdin);
	order[strcspn(order, "\n")] = 0;
	FILE* pfile = fopen("customer.txt", "r");
	if (pfile == NULL)
		exit(0);
	for (int i = 0; i < line_num + 5; i++)
		fgets(buffer, 255, pfile);
	fclose(pfile);
	char word[100] = "";
	int len = strlen(buffer);
	for (int i = 0; i < len; i++)
	{
		if (buffer[i] == ',')
		{
			if (strcmp(word, order) == 0)
			{
				valid = 1;
				break;
			}
			memset(word, 0, 100);
			continue;
		}
		str_cont(word, buffer[i]);
	}
	if (valid)
	{
		str_cont(order, ',');
		buffer[strcspn(buffer, "\n")] = 0;
		remove_substring(buffer, order);
		str_cont(buffer, '\n');
		replace_line_file("customer.txt", buffer, line_num + 5);
		printf("Order cancelled successfully. Press Enter to return to menu.....");
		fgets(order, 100, stdin);
	}
	else
	{
		printf("Invalid order! Press Enter to try again.....");
		fgets(order, 100, stdin);
	}
	system("cls");
	regis_cus_menu(line_num);
}

// Generete receipt for the register customer
void gen_receipt(int line_num)
{
	int total = 0;
	char name[100];
	char buffer[100];
	char receipt[100] = "";
	printf("\t*****Receipt*****\n\n");
	FILE* cus_file = fopen("customer.txt", "r");
	if (cus_file == NULL)
		exit(0);
	for (int i = 0; i < line_num + 2; i++)
		fgets(name, 255, cus_file);
	name[strcspn(name, "\n")] = 0;
	sprintf(receipt, "DOSTA COFFEE SHOP\n\n%s's receipt\n\n", name);
	strcat(name, ".txt");
	for (int i = 0; i < 3; i++)
		fgets(buffer, 255, cus_file);
	fclose(cus_file);
	char word[100] = "";
	char items[100] = "";
	int len = strlen(buffer);
	for (int i = 0; i < len; i++)
	{
		if (buffer[i] == ',')
		{
			FILE* menu_file = fopen("menu_item.txt", "r");
			if (menu_file == NULL)
				exit(0);
			str_cont(word, '\n');
			char price[255];
			int line_num = get_line_num("menu_item.txt", word, 2, 3);
			for (int y = 0; y < line_num + 1; y++)
				fgets(price, 255, menu_file);
			fclose(menu_file);
			word[strcspn(word, "\n")] = 0;
			sprintf(items, "%s - %s", word, price);
			strcat(receipt, items);
			char* new_price = price + 1;
			total += atoi(new_price);
			memset(word, 0, 100);
			continue;
		}
		str_cont(word, buffer[i]);
	}
	FILE* file = fopen(name, "w");
	if (file == NULL)
		exit(0);
	sprintf(receipt, "%s\nTotal price = $%d\nPaid = $%d\nChange = $0", receipt, total, total);
	fprintf(file, "%s", receipt);
	fclose(file);
	printf("Your receipt is in %s\n", name);
	printf("Press Enter to return to menu.....");
	fgets(name, 100, stdin);
	replace_line_file("customer.txt", "\n", line_num + 5);
	system("cls");
	regis_cus_menu(line_num);
}