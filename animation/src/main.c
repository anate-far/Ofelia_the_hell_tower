#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "constante.h"
#include "tools_sdl.h"
#include "animation.h"
#include "filarray.h"
#include "chararray.h"

int main(void)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	input_keys in;

	SDL_Init(SDL_INIT_VIDEO);
	input_key_init(&in);

	if(SDL_CreateWindowAndRenderer(SIZE_WINDOW_W, SIZE_WINDOW_H,0, &window, &renderer) != 0)
		fprintf(stderr, "Impossible de creer la fenetre et le rendu\n");

	//création tab str_img	
	char** tab = tab_file_name("img/cube/");
	int size_tab_name_img = nb_file_in_folder("img/cube/");

		
	//Initialisation de la struct d'animation 
	Anim* anim = anim_init(renderer, &in, tab, size_tab_name_img);
	
	//Création du thread d'animation
	SDL_Thread* t_animation;
	t_animation = SDL_CreateThread(anim_display, "Animation", anim);

	while(in.window_is_open)
	{
		update_event(&in);


		//SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}


	anim_destroy(anim);

	destroy_fillarray("img/run/",tab); 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;
}
