#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

typedef struct{
	//Animation
	SDL_Texture** p_animm;
	SDL_Texture** idle_anim;
	int size_idle_anim;
	SDL_Texture** run_anim;
	int size_run_anim;

	SDL_Rect pos;
	SDL_Renderer* p_renderer;
	SDL_bool is_display;

}Player;

//Construceur
Player* player_create(SDL_Renderer* renderer);
//Destructeur
void player_destroy(Player* player);

//Display
int player_display(void* ptr);

#endif
