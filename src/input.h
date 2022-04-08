#ifndef INPUT_H
#define INPUT_H

#include "player.h"

//Gestion input
typedef struct{
	SDL_bool key[SDL_NUM_SCANCODES];
	SDL_bool window_is_open;	
}input_keys;



void input_key_init(input_keys* in);
void update_event(input_keys* in, Player* player);

#endif
