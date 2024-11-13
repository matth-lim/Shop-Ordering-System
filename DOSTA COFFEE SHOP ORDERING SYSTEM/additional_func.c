#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "additional_func.h"

// To combine a string and a character
void str_cont(char* string, char c) 
{
	int len = strlen(string);
	string[len] = c;
	string[len + 1] = '\0';
}

// To replace a line in a specific file
void replace_line_file(char* filename, char* replace_line, int line)
{
	FILE* file, *temp;
	char temp_filename[100]; 
	char buffer[100];
	strcpy(temp_filename, "temp_");
	strcat(temp_filename, filename);
	file = fopen(filename, "r");
	temp = fopen(temp_filename, "w");
	if (file == NULL)
		exit(0);
	if (temp == NULL)
		exit(0);
	int cont_reading = 1;
	int current_line = 1;
	do
	{
		fgets(buffer, 100, file);
		if (feof(file))
			cont_reading = 0;
		else if (current_line == line)
			fputs(replace_line, temp);
		else 
			fputs(buffer, temp);
		current_line++;
	} while (cont_reading);
	fclose(file);
	fclose(temp);
	remove(filename);
	rename(temp_filename, filename);
}

// To check whether your string exist in the database or not
int check_first_element_dup(char* filename, char* name,int initial_line, int line_interval)
{
	FILE* pfile = fopen(filename, "r");
	if (pfile == NULL)
		exit(0);
	char buffer[255];
	int i = line_interval;
	for (int y = 1; y < initial_line; y++)
		fgets(buffer, 255, pfile);
	while (fgets(buffer, 255, pfile))
	{
		if (i % line_interval == 0)
		{
			if (strcmp(name, buffer) == 0)
			{
				fclose(pfile);
				return 1;
			}
		}
		i++;
	}
	fclose(pfile);
	return 0;
}

// To get the line number of a string
int get_line_num(char* filename, char* name, int initial_line, int line_interval)
{
	FILE* pfile = fopen(filename, "r");
	if (pfile == NULL)
		exit(0);
	char buffer[255];
	int line_num = initial_line;
	int i = line_interval;
	for (int y = 1; y < initial_line; y++)
		fgets(buffer, 255, pfile);
	while (fgets(buffer, 255, pfile))
	{
		if (i % line_interval == 0)
		{
			if (strcmp(name, buffer) == 0)
				break;
		}
		line_num++;
		i++;
	}
	fclose(pfile);
	return line_num;
}

// Check if the string contains all digit or not
int check_valid_digit(char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len - 1; i++)
	{
		if (isdigit(string[i]) == 0)
			return 1;
	}
	return 0;
}

// Check if the price is valid or not
int check_valid_price(char* string)
{
	if (string[0] != '$')
		return 1;
	int len = strlen(string);
	for (int i = 1; i < len - 1; i++)
	{
		if (isdigit(string[i]) == 0)
			return 1;
	}
	return 0;
}

// To remove a substring from a string
void remove_substring(char* string, char* sub) 
{
	char* match;
	int len = strlen(sub);
	while (1)
	{
		if (strstr(string, sub))
		{
			match = strstr(string, sub);
			*match = '\0';
			strcat(string, match + len);
		}
		else
			break;
	}
}