#ifndef PLAYER_H
#define PLAYER_H

typedef struct 
{
	//Temporaire le temps de faire des test et d'ajouter des animation
	SDL_Texture* m_texture_body;
	SDL_Rect m_pos;
	int m_speed;
}Player;

//Constructeur
Player* player_create(SDL_Renderer* renderer);
//Destructeur
void player_destroy(Player* player);

//affichage du joueur
void player_display(Player* player, SDL_Renderer* renderer);

//Mouvemnt player
void player_movement(Player* player, int direction);
void sprite_move(SDL_Rect* pos, int speed_x, int speed_y);

#endif
