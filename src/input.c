#include<SDL.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <SDL_image.h>

#include "input.h"
#include "tools_sdl.h"
#include "constante.h"
#include "player.h"


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
				player->is_live = SDL_FALSE;
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


	//move player
	if(in->key[SDL_SCANCODE_UP])
		player_move(player, UP);
	else if(in->key[SDL_SCANCODE_DOWN])
		player_move(player, DOWN);
	else if (in->key[SDL_SCANCODE_LEFT])
		player_move(player, LEFT);
	else if(in->key[SDL_SCANCODE_RIGHT])
		player_move(player, RIGHT);
	else 
		player_move(player, UNMOVING);

	SDL_Delay(16);
		
	
}
