#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "constante.h"
#include "animation.h" 
#include "filarray.h"


//Constructeur
Player* player_create(SDL_Renderer* renderer)
{
	Player* player = malloc(sizeof(Player));

	//add renderer
	player->p_renderer = renderer;

	//create animation tab
	player->idle_anim = create_tab_texture(player->p_renderer, PLAYER_IMG_IDLE);
	player->run_anim = create_tab_texture(player->p_renderer, PLAYER_IMG_RUN);
	//size tab
	player->size_idle_anim = nb_file_in_folder(PLAYER_IMG_IDLE);
	//player->size_run_anim = nb_file_in_folder(PLAYER_IMG_RUN);
       	//init anim
	player->p_animm = player->idle_anim;	

	//init starter pos
	player->pos.x = PLAYER_START_POS_X;
	player->pos.y = PLAYER_START_POS_Y;
	player->pos.w = PLAYER_SIZE_W;
	player->pos.h = PLAYER_SIZE_H;
	
	//Init bool display player
	player->is_display = SDL_TRUE;

	return player;
}

//Destructeur
void player_destroy(Player* player)
{
	if(player == NULL)
		return;

	//Destruction des texture
	for(int i =0; i < player->size_idle_anim; i++)
		SDL_DestroyTexture(player->idle_anim[i]);
	for(int i = 0; i < player->size_run_anim; i++)
		SDL_DestroyTexture(player->run_anim[i]);

	//Liberation de la structure
	free(player);
}

//Display
int player_display(void* ptr)
{
	Player* player = ptr;

	while(player->is_display)
		animation_loop(player->p_renderer, player->idle_anim, player->size_idle_anim, &player->pos);

	return EXIT_SUCCESS;
}	
