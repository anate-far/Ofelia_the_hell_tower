#ifndef STRINGARRAY_H
#define STRINGARRAY_H

//Réaloue un pointeur de char (un tableau mais ne fonctionne que si on le fait avec un pointeur et pas un tablau[] )
char* str_realoc(char* str, int new_size); 

//Renvoie la taille d'une chaine de caractère
int size_str(char* str);
char* concact_str(char* str1, char* str2);



#endif
