#ifndef STRUCT_H
#define STRUCT_H

#include <SDL/SDL.h>

// Structure for the hero character
typedef struct {
    SDL_Surface *sprite;       // Surface for the hero's sprite
    SDL_Rect pos_hero2;        // Rectangle for hero's position and size
    int heromoved;             // Movement flag (0: still, 1: moving left, 2: moving right)
} hero;

// Structure for enemies
typedef struct {
    SDL_Surface *mat[2][10];   // Matrix of sprites for animation
    SDL_Rect posen;            // Position and size of the enemy
    int dir;                   // Direction of movement (0: right, 1: left)
    int imgnum;                // Current frame of animation
    int col;                   // Collision flag
} enemy;

// Structure for objects (like chouka)
typedef struct {
    SDL_Surface *afficher_objet;   // Surface to display the object
    SDL_Rect pos_objet;            // Rectangle for object's position and size
} objet;

#endif // STRUCT_H

