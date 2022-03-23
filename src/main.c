#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "constante.h"
#include "tools_sdl.h"
#include "player.h"

int main(void)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	input_keys in;

	SDL_Init(SDL_INIT_VIDEO);
	input_key_init(&in);

	if(SDL_CreateWindowAndRenderer(SIZE_WINDOW_W, SIZE_WINDOW_H,0, &window, &renderer) != 0)
		fprintf(stderr, "Impossible de creer la fenetre et le rendu\n");
	

	//Création Player
	Player* player = player_create(renderer);

	while(in.window_is_open)
	{
		update_event(&in, player);

		SDL_RenderClear(renderer);

		//Affichage du player
		player_display(player, renderer);
		
		SDL_RenderPresent(renderer);
	}

	//Destruction player
//	player_destroy(player);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;
}
