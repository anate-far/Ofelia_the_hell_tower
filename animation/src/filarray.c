#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "filarray.h"
#include "chararray.h"
#include "string.h"

//fonctiont pour avoir le nombre de fichier
int nb_file_in_folder(char* name_folder)
{
	int nb_folder = 0;
	//ouverture du dossier
	DIR* folder = opendir(name_folder);

	if(folder != NULL)
	{
		//gestion du dossier
		struct dirent* s_folder;
		
		//boucle pour lire le dossier
		while((s_folder = readdir(folder)) != NULL)
		{	
			//On ne compte pas les fichier chaché
			if(s_folder->d_name[0] != '.')
				nb_folder ++;
		}
	}
	else
		fprintf(stderr, "Imposible d'ouvrir le fichier %s\n", name_folder);

	
	closedir(folder);
	return nb_folder;
}

//Retoure le plus grand nombre de caractère de fichier
int max_size_file_in_folder(char* name_folder)
{
	int size = 0;
	DIR* folder = opendir(name_folder);

	if(folder != NULL)
	{
		struct dirent* s_folder;

		while((s_folder = readdir(folder)) != NULL)
		{
			if(s_folder->d_name[0] != '.')
			{
				if(size_str(s_folder->d_name) > size)
					size = size_str(s_folder->d_name);
			}
		}

	}
	else
		fprintf(stderr, "Imposible d'ouvrir le fichier %s\n", name_folder);

	
	closedir(folder);
	return size;
}

//Retourne un tableau avec le chemin d'un fichier depuis le dossier mis en parametre
char** tab_file_name(char* name_folder)
{
	//Variable tableau
	int size_tab = nb_file_in_folder(name_folder);
	int size_name_folder = 0;
	char** tab = malloc (sizeof(char*) * size_tab);
	int i = 0;
	//Variable dossier
	DIR* folder = opendir(name_folder);

	//taille de la chaine du nom du dossier
	size_name_folder = size_str(name_folder);

	//Allocation des case du tableau 
	for(int i = 0; i < size_tab; i++)
		tab[i] = malloc(sizeof(char) * size_name_folder);
	

	//Parcour du dossier pour récuperer les noms de fichier
	if(folder != NULL)
	{
		//gestion du dossier
		struct dirent* s_folder;
		
		//boucle pour lire le dossier
		i = 0;
		while((s_folder = readdir(folder)) != NULL)
		{	
			//On ne compte pas les fichier chaché
			if(s_folder->d_name[0] != '.')
			{
				//On réaloue la case du tableau pour contenir la taille du nom du dossier + celui du fichier
				tab[i] = str_realoc(tab[i], size_name_folder + size_str(s_folder->d_name));

				tab[i] = concact_str(name_folder, s_folder->d_name);
				i ++;
			}
		}

	}
	else
		fprintf(stderr, "Imposible d'ouvrir le fichier %s\n", name_folder);


	closedir(folder);

	//On trie le tableau dans l'ordre alphabétique
	str_alphabetical_order(tab, size_tab);

	return tab;
}

void destroy_fillarray(char* name_folder, char** tab)
{
	int size_tab = nb_file_in_folder(name_folder);

	//libération des cases du tableau
	for(int i = 0; i < size_tab; i++)
		free(tab[i]);
	free(tab);

}

//trie un tableau dans l'ordre alphabétique
static int string_compar(const void* str1, const void* str2)
{
	return strcmp(* (char* const*) str1, * (char* const*) str2);
}

void str_alphabetical_order(char** tab, int size_tab)
{
	qsort(tab, size_tab, sizeof(char*), string_compar);
}


