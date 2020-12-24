#pragma once
const int Max_Length = 256;
int str_cmp(const char* str1, const char* str2);
int word_count(const char* str);
const char* str_chr(const char* str, char c);
void remove_chr(char* str, char c);
void insert_str(char* str, const char* substr, char c);