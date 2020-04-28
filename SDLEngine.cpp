
#include <iostream>
#include <cmath>

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL.h>
#undef main

#include <Box2D/Box2D.h>
#undef main

#define WIDTH 1280
#define HEIGHT 1024
#define CX WIDTH/2
#define CY HEIGHT/2

int main() {

  int running = 1;      //Assuming everything will go fine, this well keep as 1.

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *sprite = NULL;
  int w, h;

  float countA = 0.0;
  float countB = 0.4;
  float countC = 1.1;

  b2Vec2 gravity(0.0f, -10.0f);
  b2World myWorld = b2World(gravity);

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("ERR: Failed to initialize SDL: %s\n", SDL_GetError());
    running = 0;
  }
  window = SDL_CreateWindow("Title goes here", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
      printf("ERR: Renderer failed.\n", SDL_GetError());
      running = 0;
  }
    
  sprite = IMG_LoadTexture(renderer, "images/sprite.png");
  if (sprite == NULL) {
      printf("ERR: Imageload failed: %s\n", SDL_GetError());
      running = 0;
  }
  
  SDL_QueryTexture(sprite, NULL, NULL, &w, &h);
  SDL_Rect texr;

  SDL_Event event;

  while (running) {

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT: {
        running = 0;
        break;
        }
      }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
      printf("Escape is pressed.\n");
      running = 0;
    }

    SDL_SetRenderDrawColor(renderer, 30, 40, 50, 255);
    SDL_RenderClear(renderer);

    countA = countA + 0.03;
    if (countA > M_PI * 2) {
        countA = countA - M_PI * 2;
    }

    countB = countB + 0.027;
    if (countB > M_PI * 2) {
        countB = countB - M_PI * 2;
    }

    countC = countC + 0.043;
    if (countC > M_PI * 2) {
        countC = countC - M_PI * 2;
    }


    for (int i = 0; i < 512; i++) {
        float f = (i / 100.0);
        texr.x = int( CX + 200 * ( sin( countA + f ) + sin( countB + f ) + sin(countC + f) ) );
        texr.y = int( CY + 200 * ( cos( countA + f ) + sin( countB + f ) + sin(countC + f) ) );
        texr.w = w * 2;
        texr.h = h * 2;

        // SDL_RenderCopy(renderer, sprite, NULL, &texr);
        double angle = f + countA * 360.0;
        SDL_RenderCopyEx(renderer, sprite, NULL, &texr, angle, NULL, SDL_FLIP_NONE);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(25);
  }

  SDL_DestroyTexture(sprite);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}
