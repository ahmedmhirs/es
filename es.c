#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>


#include "struct.h"


void initEnnemi(enemy * en)
{
en->mat[1][0]=IMG_Load("rpd1.png");
en->mat[1][1]=IMG_Load("rpd2.png");
en->mat[1][2]=IMG_Load("rpd3.png");
en->mat[1][3]=IMG_Load("rpd1.png");
en->mat[1][4]=IMG_Load("rpd2.png");
en->mat[1][5]=IMG_Load("rpd3.png");
en->mat[1][6]=IMG_Load("rpd1.png");
en->mat[1][7]=IMG_Load("rpd2.png");
en->mat[1][8]=IMG_Load("rpd3.png");
en->mat[1][9]=IMG_Load("rpd1.png");


en->mat[0][0]=IMG_Load("rpg1.png");
en->mat[0][1]=IMG_Load("rpg2.png");
en->mat[0][2]=IMG_Load("rpg3.png");
en->mat[0][3]=IMG_Load("rpg1.png");
en->mat[0][4]=IMG_Load("rpg2.png");
en->mat[0][5]=IMG_Load("rpg3.png");
en->mat[0][6]=IMG_Load("rpg1.png");
en->mat[0][7]=IMG_Load("rpg2.png");
en->mat[0][8]=IMG_Load("rpg3.png");
en->mat[0][9]=IMG_Load("rpg1.png");

en->col=0;
en->dir=0;
en->imgnum=0;
en->posen.x=61;
en->posen.y=462;
en->posen.h=200;
en->posen.w=100;

}



void afficherEnnemi(enemy en, SDL_Surface * screen)
{
SDL_BlitSurface(en.mat[en.dir][en.imgnum],NULL,screen,&en.posen);
}

void animerEnnemi( enemy * en)
{
SDL_Delay(50);
en->imgnum++;
if(en->imgnum>9)
en->imgnum=0;
}

void deplacer_enemy( enemy * en)
{
SDL_Rect posmax;
SDL_Rect posmin;
posmax.x=1000;
posmin.x=1;
if(en->posen.x>posmax.x)
en->dir=1;
if(en->posen.x<posmin.x)
en->dir=0;
if(en->dir==0)
en->posen.x=en->posen.x+5;
if(en->dir==1)
en->posen.x=en->posen.x-5;
}

int collisionBB( SDL_Rect posp, SDL_Rect pose)
{
if((posp.x+posp.w<pose.x)||(posp.x>pose.x+pose.w)||(posp.y+posp.h<pose.y)||(posp.y>pose.y+pose.h))
return 0;//pas de collision//
else
return 1;
}
