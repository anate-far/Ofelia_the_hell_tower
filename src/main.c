#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "constante.h"
#include "tools_sdl.h"
#include "player.h"
#include "input.h"

int main(void)
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	input_keys in;

	SDL_Init(SDL_INIT_VIDEO);
	input_key_init(&in);

	if(SDL_CreateWindowAndRenderer(SIZE_WINDOW_W, SIZE_WINDOW_H,0, &window, &renderer) != 0)
		fprintf(stderr, "Impossible de creer la fenetre et le rendu\n");

	//Create Player
	Player* player = player_create(renderer);
	//Create thread animation player
	SDL_Thread* t_animation;
	t_animation = SDL_CreateThread(player_animation, "player_animation", player);

	while(in.window_is_open)
	{
		update_event(&in, player);

		SDL_RenderClear(renderer);

		//Display player
		player_display(player);
		
		SDL_RenderPresent(renderer);
	}
	

	//Destroy Player
	player_destroy(player);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;
}
