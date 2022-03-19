#ifndef FILLARRAY_H
#define FILLARRAY_H

//Retourne le nombre de fichier dans un dossier
int nb_file_in_folder(char* name_folder);

//Retourne le nom de fichier le plus grand
int max_size_file_in_folder(char* name_folder);

//Création d'un tableau de nom de fichier (NE PAS OUBLIER LE '/'  A LA FIN DU NOM DU FICHIER)
char** tab_file_name(char* name_folder);
//Libere le tableau de char** allouer
void destroy_fillarray(char* name_folder, char** tab);

//Trie dans l'ordre alphabétique un tableau de chaine de caractère
static int string_compar(const void* p1, const void* str2);
void str_alphabetical_order(char** tab, int size_tab);


#endif
