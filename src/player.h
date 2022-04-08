#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

typedef struct{
	SDL_Renderer* p_renderer;
	//managment area
	int towards;
	//display animation
	SDL_Texture* texture_display;
	int nb_tab_texture;
       	SDL_bool is_live;
	//animation
	SDL_Texture** up;
	SDL_Texture** down;
	SDL_Texture** left;
	SDL_Texture** right;
	SDL_Texture* unmoving;
	SDL_Rect pos;
}Player;

//builder and destructive
Player* player_create(SDL_Renderer* renderer);
void player_destroy(Player* player);

//display
void player_display(Player* player);

//movement
void player_move(Player* player, int _towards);
int player_animation(void* _player);

#endif
