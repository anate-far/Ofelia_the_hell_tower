#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#include "player.h"
#include "tools_sdl.h"
#include "constante.h"

//builder and destructive
Player* player_create(SDL_Renderer* renderer)
{
	Player* player = malloc(sizeof(Player));
	
	//Initi renderer
	player->p_renderer =  renderer;

	//Init tab texture;
	player->up = malloc(sizeof(SDL_Texture*) * NB_IMG_ANIMATION);	
	player->down = malloc(sizeof(SDL_Texture*) * NB_IMG_ANIMATION);	
	player->left = malloc(sizeof(SDL_Texture*) * NB_IMG_ANIMATION);	
	player->right = malloc(sizeof(SDL_Texture*) * NB_IMG_ANIMATION);	
	//Init texture
	player->up[0] = create_texture(renderer, "img/player/tile010.png");
	player->up[1] = create_texture(renderer, "img/player/tile009.png");
	player->up[2] = create_texture(renderer, "img/player/tile010.png");
	player->up[3] = create_texture(renderer, "img/player/tile011.png");
	player->down[0] = create_texture(renderer, "img/player/tile001.png");
	player->down[1] = create_texture(renderer, "img/player/tile000.png");
	player->down[2] = create_texture(renderer, "img/player/tile001.png");
	player->down[3] = create_texture(renderer, "img/player/tile002.png");
	player->left[0] = create_texture(renderer, "img/player/tile004.png");
	player->left[1] = create_texture(renderer, "img/player/tile003.png");
	player->left[2] = create_texture(renderer, "img/player/tile004.png");
	player->left[3] = create_texture(renderer, "img/player/tile005.png");
	player->right[0] = create_texture(renderer, "img/player/tile007.png");
	player->right[1] = create_texture(renderer, "img/player/tile006.png");
	player->right[2] = create_texture(renderer, "img/player/tile007.png");
	player->right[3] = create_texture(renderer, "img/player/tile008.png");
	player->unmoving = create_texture(renderer, "img/player/tile001.png");
	//texture_display
	player->nb_tab_texture = 0;
	player->texture_display = player->up[player->nb_tab_texture];
	player->is_live = SDL_TRUE;

	//init pos
	player->pos.x = PLAYER_START_POS_X;
	player->pos.y = PLAYER_START_POS_Y;
	player->pos.w = PLAYER_SIZE_W;
	player->pos.h = PLAYER_SIZE_H;

	return player;
}
void player_destroy(Player* player)
{
	//destructive texture
	for(int i = 0; i < NB_IMG_ANIMATION; i++)
		SDL_DestroyTexture(player->up[i]);
	//destructive tab
	free(player->up);

	//destructive struct player
	free(player);
}

//display
void player_display(Player* player)
{
	SDL_RenderCopy(player->p_renderer, player->texture_display, NULL, &player->pos);
}

void player_move(Player* player, int _towards)
{
	if(_towards == UP)
	{
		//Animation I change this varible for the thread animation
		player->towards = UP;
		//Movement
		player->pos.y -= PLAYER_SPEED;

	}
	else if(_towards == DOWN)
	{
		//Animation
		player->towards = DOWN;
		//Movement
		player->pos.y += PLAYER_SPEED;
	}
	else if(_towards == LEFT)
	{
		//Animation
		player->towards = LEFT;
		//Movement 
		player->pos.x -= PLAYER_SPEED;
	}
	else if(_towards == RIGHT)
	{
		//Animation 
		player->towards = RIGHT;
		//Movement 
		player->pos.x += PLAYER_SPEED;
	}
	else
		player->towards = UNMOVING; 
}

int player_animation(void* _player)
{
	Player* player = _player;
	while(player->is_live)
	{
		//Up
		if(player->towards == UP)
		{
			if((player->nb_tab_texture < 0) || (player->nb_tab_texture >= 4))
				player->nb_tab_texture = 0;
			player->texture_display = player->up[player->nb_tab_texture];
			SDL_Delay(PLAYER_SPEED_ANIMATION);
			player->nb_tab_texture++;

		}
		//Down
		else if(player->towards == DOWN)
		{
			if((player->nb_tab_texture < 0) || (player->nb_tab_texture >= 4))
				player->nb_tab_texture = 0;
			player->texture_display = player->down[player->nb_tab_texture];
			SDL_Delay(PLAYER_SPEED_ANIMATION);
			player->nb_tab_texture++;

		}
		//Left
		else if(player->towards == LEFT)
		{
			if((player->nb_tab_texture < 0) || (player->nb_tab_texture >= 4))
				player->nb_tab_texture = 0;
			player->texture_display = player->left[player->nb_tab_texture];
			SDL_Delay(PLAYER_SPEED_ANIMATION);
			player->nb_tab_texture++;

		}
		//Right
		else if(player->towards == RIGHT)
		{
			if((player->nb_tab_texture < 0) || (player->nb_tab_texture >= 4))
				player->nb_tab_texture = 0;
			player->texture_display = player->right[player->nb_tab_texture];
			SDL_Delay(PLAYER_SPEED_ANIMATION);
			player->nb_tab_texture++;

		}
		//Unmoving
		else if (player->towards == UNMOVING)
		{	
			player->texture_display = player->unmoving;
		}

	}


	return EXIT_SUCCESS;
}
