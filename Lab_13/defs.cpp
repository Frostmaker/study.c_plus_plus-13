#include <cstring>
#include <iostream>


const int Max_Length = 256;

int str_cmp(const char* str1, const char* str2)
{
	// Функция сравнения строк

	for (int i = 0; i <= strlen(str1); ++i) {
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}


int word_count(const char* str)
{
	// Функция вычисления количества слов в строке

	int count = 0;
	bool wrd = false;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == ' ' && wrd) {
			wrd = false;
			++count;
		}
		else if (str[i] != ' ' && !wrd)
			wrd = true;
	}
	if (wrd)
		return ++count;
	else
		return count;
}


const char* str_chr(const char* str, char c)
{
	// Поиск первого вхождения заданного символа в строке

	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == c)
			return &str[i];
	}

	return nullptr;
}


void remove_chr(char* str, char c)
{
	// Удаление всех вхождений заданного символа из строки

	char res[Max_Length];
	int j = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] != c) {
			res[j] = str[i];
			++j;
		}
	}
	res[j] = '\0';
	for (int i = 0; i < strlen(str); ++i) {
		str[i] = res[i];
	}
	return;
}


void insert_str(char* str, const char* substr, char c)
{
	// Вставка заданной подстроки в строку после первого вхождения заданного символа

	char res[Max_Length];
	int j = -1;
	int str_len = strlen(str);
	int sub_len = strlen(substr);
	for (int i = 0; i < str_len; ++i) {
		if (str[i] == c) {
			j = i;
			break;
		}
	}

	if (j == -1) {
		throw str;
	}

	for (int i = 0; i <= j; ++i) {
		res[i] = str[i];
	}

	for (int i = 0; i < sub_len; ++i) {
		res[j + 1 + i] = substr[i];
	}
	
	for (int i = j + 1; i <= str_len + sub_len; ++i) {
		res[i + sub_len] = str[i];
	}

	for (int i = 0; i <= str_len + sub_len; ++i) {
		str[i] = res[i];
	}

	return;
}