#include<SDL.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <SDL_image.h>

#include "tools_sdl.h"
#include "player.h"
#include "constante.h"

//Gestion error
void clearRessources(const char *message, SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture)
{
	if(texture != NULL)
	{
		SDL_DestroyTexture(texture);
	}

	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	if( window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	if(message != NULL)
	{
		SDL_Log("Error : %s > %s\n", message, SDL_GetError());
	}
	SDL_Quit();
	exit(EXIT_FAILURE);

}


//Création texture
SDL_Texture* create_texture(SDL_Renderer* renderer, const char* name_img)
{
	SDL_Surface* img = IMG_Load(name_img);
	if(name_img == NULL)
		fprintf(stderr,"ERROR <set_texture> : Impossible de charger l image %s\n", name_img);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);
	if(texture == NULL)
		fprintf(stderr,"Error <set_texture> : Impossible de charger la texture de l'image %s\n", name_img);

	SDL_FreeSurface(img);
	

	return texture;
}



//Gestion input
void input_key_init(input_keys* in)
{
	for(int i = 0; i <= SDL_NUM_SCANCODES; i++)
		in->key[i] = SDL_FALSE;
	in->window_is_open = SDL_TRUE;	
}


void update_event(input_keys* in, Player* player)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				in->window_is_open = SDL_FALSE;
				break;
			
			case SDL_KEYDOWN:
				in->key[event.key.keysym.scancode] = SDL_TRUE;
				break;
			case SDL_KEYUP:
				in->key[event.key.keysym.scancode] = SDL_FALSE;
				break;

		}

	}
	//quit
	if(in->key[SDL_SCANCODE_ESCAPE])
		in->window_is_open = SDL_FALSE;

	//Player movement
	if(in->key[SDL_SCANCODE_UP])
		player_movement(player, UP);	

	if(in->key[SDL_SCANCODE_DOWN])
		player_movement(player, DOWN);

	if(in->key[SDL_SCANCODE_LEFT])
		player_movement(player, LEFT);
	
	if(in->key[SDL_SCANCODE_RIGHT])
		player_movement(player, RIGHT);

	SDL_Delay(16);
		
	
}
