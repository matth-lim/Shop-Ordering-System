#pragma once

void str_cont(char* string, char c);
void replace_line_file(char* filename, char* replace_line, int line);
int check_first_element_dup(char* filename, char* name, int initial_line, int line_interval);
int get_line_num(char* filename, char* name, int initial_line, int line_interval);
int check_valid_digit(char* string);
int check_valid_price(char* string);
void remove_substring(char* string, char* sub);