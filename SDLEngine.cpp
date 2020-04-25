
#include <iostream>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h> 

using namespace std;

int main() 
{ 
 
    SDL_Window* window;
    SDL_Renderer* renderer;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("ERR: Failed to initialize SDL: %s\n", SDL_GetError()); 
    } 
    window = SDL_CreateWindow("Title goes here", 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       800, 600, 0); 

    renderer = SDL_CreateRenderer(window, -1, 0);

    int running = 1;

    while (running) { 
        SDL_Event event; 
  
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
  
            case SDL_QUIT: 
                running = 0; 
                break;   
            } 

        SDL_SetRenderDrawColor(renderer, 30, 40, 50, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);

        } 
    }

    SDL_Quit();
    return 0; 
} 