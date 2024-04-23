#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // Ajout de cet en-tête pour la fonction time
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"


void initialiser_objet(objet *chouka) {
	chouka->afficher_objet=NULL;
	chouka->afficher_objet=IMG_Load("s1.png");

	chouka->pos_objet.x=1000;
	chouka->pos_objet.y=0;
}
void afficher_objet(objet *chouka, SDL_Surface *ecran, hero evan) {
    // Position horizontale fixe
    chouka->pos_objet.x = (rand() % 1200); 

    // Génération aléatoire de la position verticale
    if (chouka->pos_objet.y == 0) {
        srand(time(NULL)); 
        chouka->pos_objet.y = (rand() % 600); // Position aléatoire sur l'axe y
    }

    // Vérifie si l'objet est dans la zone visible et ajuste sa position
    if (chouka->pos_objet.y < 600 && evan.pos_hero2.x <= 300) {
        if (evan.heromoved == 1 && evan.pos_hero2.x == 300) {
            chouka->pos_objet.x -= 5;
        } else if (evan.heromoved == 2) {
            chouka->pos_objet.x += 5;
        }
        chouka->pos_objet.y += 5;
    } else {
        // Réinitialisation de la position verticale si l'objet sort de la zone visible
        chouka->pos_objet.y = (rand() % 600);
    }

    // Affiche l'objet si la position du héros est suffisamment avancée
    if (evan.pos_hero2.x > 100) {
        SDL_BlitSurface(chouka->afficher_objet, NULL, ecran, &(chouka->pos_objet));
    } else if (evan.pos_hero2.x > 300) {
        chouka->afficher_objet = NULL;
    }
}

