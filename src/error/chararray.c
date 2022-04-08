#include <stdio.h>
#include <stdlib.h>

#include "chararray.h"



char* str_realoc(char* str, int new_size) 
{
	//alocation d'un nouveau tableau avec la nouvelle taille 
	char* new_str = malloc(sizeof(char) * new_size);

	//Copie du contenue de l'ancien tableau dans le nouveau 
	for(int i = 0; i < new_size; i++)
		new_str[i] = str[i];

	//liberation de la mémoire de l'acien tableau
	free(str);

	//pointeur de l'ancien tableau pointe ver le nouveau 
	return new_str;
}


int size_str(char* str)
{
	int i = 0, value = 0;

	for(i = 0; str[i] != '\0'; i++)
		value++;


	return value;
}

char* concact_str(char* str1, char* str2)
{
	//Alocation d'une novuelle chaine de la taille des deux chaine 
	char* str_final = malloc(sizeof(char) * (size_str(str1) + size_str(str2)));

	//ajour de la première chaine 
	for(int i = 0; i <  size_str(str1); i++)
		str_final[i] = str1[i];
	//ajout de la seconde chaine
	for(int i = size_str(str1); i < (size_str(str1) + size_str(str2)); i++)
	{
		str_final[i] = str2[i - size_str(str1)];
	}

	return str_final;

}
