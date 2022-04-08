#include <stdio.h>
#include <stdlib.h>

#include "animation.h"
#include "tools_sdl.h"
#include "filarray.h"
#include "chararray.h"


//create texture array for animation
SDL_Texture** create_tab_texture(SDL_Renderer* renderer, char* name_folder)
{
	//créatiion d'un tableau du nom des image
	char** tab_name = tab_file_name(name_folder);
	int size_tab = nb_file_in_folder(name_folder);
	

	//Initialisation du tableau de texture
	SDL_Texture** tab_texture = malloc(sizeof(SDL_Texture*) * size_tab);
	for(int i = 0; i < size_tab; i++)
		tab_texture[i] = create_texture(renderer, tab_name[i]);	

	//Destruction du tableau de nom d'image
	destroy_fillarray(tab_name, size_tab);

	return tab_texture;	
}

//animation loupe
void animation_loop(SDL_Renderer* renderer, SDL_Texture** tab_animation, int size_tab, SDL_Rect* pos)
{
	for(int i = 0; i < size_tab; i++)
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tab_animation[i], NULL, pos);
		SDL_RenderPresent(renderer);
	}
}
