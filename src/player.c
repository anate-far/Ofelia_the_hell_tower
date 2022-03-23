#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "constante.h"
#include "tools_sdl.h"
#include "player.h"

//Constructeur
Player* player_create(SDL_Renderer* renderer)
{
	//Initialisation de la strcuture
	Player* player = malloc(sizeof(Player));
	if(player == NULL)
	{
		fprintf(stderr, "Impossiblde de crée une struc player\n");
		exit(EXIT_FAILURE);
	}

	//Temporaire
	//Init player texture
	player->m_texture_body = create_texture(renderer,"img/tile001.png");

	//Init player pos
	player->m_pos.x = PLAYER_START_POS_X;
	player->m_pos.y = PLAYER_START_POS_Y;
	player->m_pos.w = PLAYER_SIZE_W;
	player->m_pos.h = PLAYER_SIZE_H;

	//Init speed
	player->m_speed = 3;

	SDL_QueryTexture(player->m_texture_body, NULL, NULL, &player->m_pos.w, &player->m_pos.h);

	return player;

}

//Destructeur
void player_destroy(Player* player)
{
	if(player == NULL)
	{
		fprintf(stderr, "La struct Player est vide\n");
		return;
	}

	//Temporaire
	//desalocation de la texture
	SDL_DestroyTexture(player->m_texture_body);

	//Desalocation de la struct
	free(player);
}

//Affichage player
void player_display(Player* player, SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, player->m_texture_body, NULL, &player->m_pos);
}

//Gestion des déplacement du perssonage
void player_movement(Player* player, int direction)
{
	//Up
	if(direction == 0)
	{
		sprite_move(&player->m_pos, 0, -player->m_speed);
	}
	//Down
	if(direction == 1)
	{
		sprite_move(&player->m_pos, 0, player->m_speed);
	}
	//Left
	if(direction == 2)
	{
		sprite_move(&player->m_pos, -player->m_speed, 0);
	}
	//Up
	if(direction == 3)
	{
		sprite_move(&player->m_pos, player->m_speed, 0);
	}
}

void sprite_move(SDL_Rect* pos, int speed_x, int speed_y)
{
	pos->x += speed_x;
	pos->y += speed_y;
}
