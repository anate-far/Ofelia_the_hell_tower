#ifndef TOOLBASE_H
#define TOOLBASE_H

#include<SDL.h>
#include "player.h"


//gesstion error
void clearRessources(const char *message, SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture);

//Créatioin texture
SDL_Texture* create_texture(SDL_Renderer* renderer, const char* name_img);


//Gestion input
typedef struct{
	SDL_bool key[SDL_NUM_SCANCODES];
	SDL_bool window_is_open;	
}input_keys;


void input_key_init(input_keys* in);
void update_event(input_keys* in, Player* player);

#endif
