
#include <iostream>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 

using namespace std;

int main() 
{ 
    cout << "nakki" <<endl;
 
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("ERR: Failed to initialize SDL: %s\n", SDL_GetError()); 
    } 
    SDL_Window* win = SDL_CreateWindow("Title goes here", 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       800, 600, 0); 

    int running = 1;

    // annimation loop 
    while (running) { 
        SDL_Event event; 
  
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
  
            case SDL_QUIT: 
                // handling of close button 
                running = 0; 
                break;   
            } 
        } 
    }

    SDL_Quit();
    return 0; 
} 