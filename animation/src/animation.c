#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#include "animation.h"
#include "tools_sdl.h"
#include "constante.h"

Anim* anim_init(SDL_Renderer* renderer, input_keys* in,char** name_img, int size_tab_name_img)
{
	Anim* anim = malloc(sizeof(Anim));

	anim->m_renderer = renderer;
	anim->m_in = in;

	//Initialisation des image d'idle
	anim->m_idle_texture = malloc(sizeof(SDL_Texture*) * size_tab_name_img);
	for(int i = 0; i < size_tab_name_img; i++)
		anim->m_idle_texture[i] = create_texture(renderer, name_img[i]);
	anim->m_size_idle_tab = size_tab_name_img; 

	//Init pos a 0
	anim->pos.x = 0;
	anim->pos.y = 0; 
	anim->pos.w = SIZE_PLAYER_IDLE_W;
	anim->pos.h = SIZE_PLAYER_IDLE_H;

	SDL_QueryTexture(anim->m_idle_texture[0], NULL, NULL, &anim->pos.w, &anim->pos.h);	

	return anim;
}

void anim_destroy(Anim* anim)
{
	if(anim != NULL)
	{
		//Libération du tableau de texture
		for(int i = 0; i < anim->m_size_idle_tab; i++)
			SDL_DestroyTexture(anim->m_idle_texture[i]);

		free(anim);
	}
}


int anim_display(void* ptr)
{
	Anim* anim = ptr;
	
	while(anim->m_in->window_is_open)
	{
		for(int i = 0; i < anim->m_size_idle_tab; i++)
		{
			SDL_RenderCopy(anim->m_renderer, anim->m_idle_texture[i], NULL, &anim->pos);
			SDL_RenderPresent(anim->m_renderer);
			SDL_Delay(IDLE_DELAY);
			SDL_RenderClear(anim->m_renderer);
		}
	}

	return EXIT_SUCCESS;
}
