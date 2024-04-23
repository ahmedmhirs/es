#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>

#include "struct.h"

int main(int argc, char *argv[]) {
    SDL_Surface *screen, *background;
    SDL_Event event;
    int running = 1;
    hero evan;
    enemy en;
    objet chouka;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Set up the screen
    screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_image
    if ((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)) != (IMG_INIT_PNG | IMG_INIT_JPG)) {
        fprintf(stderr, "Unable to initialize SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize objects
    initEnnemi(&en);
    initialiser_objet(&chouka);

    // Load background image
    background = IMG_Load("background.png");
    if (!background) {
        fprintf(stderr, "Failed to load background image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Game loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }

        // Game logic and rendering
        animerEnnemi(&en);
        deplacer_enemy(&en);

        // Clear screen and display background
        SDL_BlitSurface(background, NULL, screen, NULL);

        // Display enemy and object
        afficherEnnemi(en, screen);
        afficher_objet(&chouka, screen, evan);
int mouseX, mouseY;
        Uint8 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        // Afficher les coordonnées de la souris dans la console
        printf("Mouse X: %d, Mouse Y: %d\n", mouseX, mouseY);
        // Update the screen
        SDL_Flip(screen);
        SDL_Delay(20);
    }

    // Clean up
    SDL_FreeSurface(chouka.afficher_objet);
    SDL_FreeSurface(background);
    IMG_Quit();
    SDL_Quit();
    return 0;
}

