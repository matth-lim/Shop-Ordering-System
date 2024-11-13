#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "staff_func.h"
#include "additional_func.h"

// Staff login to access the staff system
void staff_login()
{
	char username[100];
	char password[100];
	printf("\t*****Staff Login*****\n");
	printf("\nEnter your username: ");
	fgets(username, 100, stdin);
	printf("Enter your password: ");
	fgets(password, 100, stdin);
	if (check_first_element_dup("staff.txt", username, 1, 2) && check_first_element_dup("staff.txt", password, 2, 2))
	{
		system("cls");
		staff_menu();
	}
	else
	{
		printf("Invalid username or password! Press Enter to return to menu.....");
		fgets(username, 100, stdin);
		system("cls");
		start();
	}
}

// Staff main menu after successful login
void staff_menu()
{
	printf("\t*****Staff Menu*****\n");
	printf("\n1. Create staff account");
	printf("\n2. Add new menu item");
	printf("\n3. Update menu item");
	printf("\n4. Create customer account");
	printf("\n5. Search customer order");
	printf("\n6. Return to main menu");
	printf("\n7. Exit");
	printf("\nSelect a choice: ");
	char choice[100];
	fgets(choice, 100, stdin);
	if (choice[0] == '1' && choice[1] == '\n')
	{
		system("cls");
		create_acc();
	}
	else if (choice[0] == '2' && choice[1] == '\n')
	{
		system("cls");
		add_new_item();
	}
	else if (choice[0] == '3' && choice[1] == '\n')
	{
		system("cls");
		update_item();
	}
	else if (choice[0] == '4' && choice[1] == '\n')
	{
		system("cls");
		create_cus_acc();
	}
	else if (choice[0] == '5' && choice[1] == '\n')
	{
		system("cls");
		search_cus_order();
	}
	else if (choice[0] == '6' && choice[1] == '\n')
	{
		system("cls");
		start();
	}
	else if (choice[0] == '7' && choice[1] == '\n')
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

// Create a new account for staff
void create_acc()
{
	char username[100];
	char password[100];
	printf("\t*****Register Account*****\n");
	printf("\nEnter your username: ");
	fgets(username, 100, stdin);
	while (check_first_element_dup("staff.txt", username, 1, 2))
	{
		printf("Username used! Enter another username: ");
		fgets(username, 100, stdin);
	}
	printf("Enter your password: ");
	fgets(password, 100, stdin);
	FILE* pfile = fopen("staff.txt", "a");
	if (pfile == NULL)
		exit(0);
	fprintf(pfile, username);
	fprintf(pfile, password);
	fclose(pfile);
	printf("Account created successfully. Press Enter to return to menu.....");
	fgets(username, 100, stdin);
	system("cls");
	staff_menu();
}

// Add a new item/product in the menu
void add_new_item()
{
	struct item {
		char name[100];
		char price[100];
		char id[100];
	} item1;
	printf("\t*****Add New Menu Item*****\n");
	printf("\nEnter item's ID: ");
	fgets(item1.id, 100, stdin);
	while (check_first_element_dup("menu_item.txt", item1.id, 1, 3))
	{
		printf("Item ID already existed! Enter another item ID: ");
		fgets(item1.id, 100, stdin);
	}
	printf("Enter item's name: ");
	fgets(item1.name, 100, stdin);
	while (check_first_element_dup("menu_item.txt", item1.name, 2 ,3))
	{
		printf("Item name already existed! Enter another item's name: ");
		fgets(item1.name, 100, stdin);
	}
	printf("Enter item's price ($ only): ");
	fgets(item1.price, 100, stdin);
	while (check_valid_price(item1.price))
	{
		printf("Invalid price! Enter price again: ");
		fgets(item1.price, 100, stdin);
	}
	FILE* pfile = fopen("menu_item.txt", "a");
	if (pfile == NULL)
		exit(0);
	fprintf(pfile, item1.id);
	fprintf(pfile, item1.name);
	fprintf(pfile, item1.price);
	fclose(pfile);
	printf("Item added successfully. Press Enter to return to menu.....");
	fgets(item1.name, 100, stdin);
	system("cls");
	staff_menu();
}

// Update an exisiting item/product in the menu
void update_item()
{
	struct new_item {
		char name[100];
		char price[100];
		char id[100];
	} new_item1;
	char item_id[100];
	printf("\t*****Update Item*****\n");
	printf("\nEnter the item's ID that you want to update: ");
	fgets(item_id, 100, stdin);
	if (check_first_element_dup("menu_item.txt", item_id, 1, 3))
	{
		printf("\nEnter the item's new ID: ");
		fgets(new_item1.id, 100, stdin);
		while (check_first_element_dup("menu_item.txt", new_item1.id, 1, 3))
		{
			printf("Item ID already existed! Enter another item ID: ");
			fgets(new_item1.id, 100, stdin);
		}
		printf("Enter the item's new name: ");
		fgets(new_item1.name, 100, stdin);
		while (check_first_element_dup("menu_item.txt", new_item1.name, 2, 3))
		{
			printf("Item name already existed! Enter another item's name: ");
			fgets(new_item1.name, 100, stdin);
		}
		printf("Enter the item's new price ($ only): ");
		fgets(new_item1.price, 100, stdin);
		while (check_valid_price(new_item1.price))
		{
			printf("Invalid price! Enter price again: ");
			fgets(new_item1.price, 100, stdin);
		}
		int line_num = get_line_num("menu_item.txt", item_id, 1, 3);
		replace_line_file("menu_item.txt", new_item1.id, line_num);
		replace_line_file("menu_item.txt", new_item1.name, line_num + 1);
		replace_line_file("menu_item.txt", new_item1.price, line_num + 2);
		printf("\nItem updated successfully! Press Enter to return to menu.....");
		fgets(item_id, 100, stdin);
	}
	else
	{
		printf("\nInvalid item ID! Press Enter to return to menu.....");
		fgets(item_id, 100, stdin);
	}
	system("cls");
	staff_menu();
}

// Create a new customer account
void create_cus_acc()
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
	staff_menu();
}

// Search for customer orders through their username
void search_cus_order()
{
	char username[100];
	printf("\t*****Search Customer Order*****\n");
	printf("\nEnter the customer's username: ");
	fgets(username, 100, stdin);
	if (check_first_element_dup("customer.txt", username, 1, 6))
	{
		int line_num = get_line_num("customer.txt", username, 1, 6);
		FILE* pfile = fopen("customer.txt", "r");
		if (pfile == NULL)
			exit(0);
		char buffer[255];
		for (int i = 0; i < line_num + 5; i++)
		{
			fgets(buffer, 255, pfile);
		}
		username[strcspn(username, "\n")] = 0;
		buffer[strcspn(buffer, "\n")] = 0;
		printf("%s ordered: [%s]\n",username, buffer);
		printf("\nPress Enter to return to menu.....");
		fgets(username, 100, stdin);
	}
	else
	{
		printf("\nInvalid username! Press Enter to return to menu.....");
		fgets(username, 100, stdin);
	}
	system("cls");
	staff_menu();
}