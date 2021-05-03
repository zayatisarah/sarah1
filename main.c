

/** 
* @file main.c 
* @brief Testing Program. 
* @author C-DEMONS 
* @version 0.1 
* @date Apr 01, 2015 
* 
* Testing program for background scrollilng * 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <time.h>

int main()
{

	SDL_Surface *screen;
	enigme  e;
	int s,resp=0,run_init=0,running,alea,run_resp;
	char image[30]="";
	SDL_Event event;

         srand(time(NULL)); // init alea
	 SDL_Init ( SDL_INIT_VIDEO ) ;
	 screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
         run_init=1;
         running=0;
         run_resp=0;

     while(run_init){
      
      SDL_WaitEvent(&event);
	if(event.type = SDL_KEYDOWN){
           
            switch( event.key.keysym.sym )
                {
                      case  SDLK_d:{
                      running=1;
                      generate_afficher ( screen  , image ,&e,&alea) ;
                        
                      }break ; 
                  case SDLK_ESCAPE: 
                  run_init =0 ;
	          break ;
		      
                 }
              }

      while(running){
          s=solution_e (image );
               
			do{
                         run_resp=1;
			resp=resolution (&running,&run_init);

			}while((resp>3 || resp< 1 ) && running != 0) ;


          
           
              afficher_resultat (screen,s,resp,&e) ;
             
                 SDL_Delay(2000);
                  run_resp=0;
                  running=0;
                     //run_init =0 ;
                 

          }
    }
	 
 
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}
