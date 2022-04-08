#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>

SDL_Texture** create_tab_texture(SDL_Renderer* renderer, char* name_folder);

void animation_loop(SDL_Renderer* renderer, SDL_Texture** tab_animation, int size_tab, SDL_Rect* pos);
#endif
