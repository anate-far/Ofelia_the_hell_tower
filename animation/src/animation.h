#ifndef ANIMATION_H
#define ANIMATION_H

#include "tools_sdl.h"

typedef struct{
	SDL_Texture** m_idle_texture;
	int m_size_idle_tab;
	SDL_Rect pos;
	SDL_Renderer* m_renderer;
	input_keys* m_in;

}Anim;

Anim* anim_init(SDL_Renderer* renderer, input_keys* in, char** name_img, int size_tab_name_img);
void anim_destroy(Anim* anim);

int anim_display(void* ptr);

#endif
