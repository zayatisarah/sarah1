   /** 
* @file enigme.c 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
/** 
* @brief To initialize the enigme e  . 
* @param e the enigme 
* @return Nothing 
*/ 



void init_enigme(enigme * e)
{      
       SDL_Surface *screen;
       SDL_Surface *imagejeu = NULL;
       SDL_Rect positionecran;
       SDL_Event event;
       screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
       imagejeu=IMG_Load("background.bmp");
       positionecran.x=0;
       positionecran.y=0;
       SDL_BlitSurface(imagejeu,NULL,screen,&positionecran);

	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}
 /** 
* @brief To  afficher the enigme e  . 
 * @param e the enigme 
 * @param  char image
 * @param entier alea 
*/ 
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"%d.jpg",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
 SDL_Flip(screen) ;


 
}
 
/** 
* @brief solution enigme e  . 
* @param char image  
*/  
 int solution_e (char image [])
 {
 	int solution =0 ;
        int A,B,C; 	
 	if(strcmp(image,"1.jpg")==0)
 	{
     solution = 1  ;

 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		solution = 3 ;

       

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		solution = 1;	

 	}
 	return solution;
 } 
/** 
* @brief resolution  . 
* @param running 
* @param run 
*/ 

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
  int a,b,c;
	SDL_WaitEvent(&event);
	if(event.type = SDL_KEYDOWN){
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			   r= 1 ;
			   break ;
			   case  SDLK_b:
			   r= 2 ; 


			   break;
			   case  SDLK_c: 
			   r= 3 ; 
			   break;

			    }

                   }
         
      	
  return r ;
}
   

/** 
* @brief afficher resultat  . 
* @param entier s 
* @param entier resp 
* @param enigme en 
* @return Nothing 
*/ 
 void afficher_resultat (SDL_Surface * screen,int s,int resp,enigme *en)
 {
 
 	if (resp==s)
 	{
 		en->img=IMG_Load("true.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;         
                SDL_Flip(screen);
             
               
 	}
 	else
 	{
 		en->img=IMG_Load("false.jpg");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
                SDL_Flip(screen);

                
 	}
 }
