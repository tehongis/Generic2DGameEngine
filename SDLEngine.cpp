
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#undef main

#include <Box2D/Box2D.h>
#undef main

#define WIDTH 1280
#define HEIGHT 1024

int main() {

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *sprite = NULL;
  int w, h;

  b2Vec2 gravity(0.0f, -10.0f);
  b2World myWorld = b2World(gravity);

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("ERR: Failed to initialize SDL: %s\n", SDL_GetError());
  }
  window = SDL_CreateWindow("Title goes here", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

  renderer = SDL_CreateRenderer(window, -1, 0);

  sprite = IMG_LoadTexture(renderer, "sprite.png");
  SDL_QueryTexture(sprite, NULL, NULL, &w, &h);
  SDL_Rect texr;
  texr.x = WIDTH / 2;
  texr.y = HEIGHT / 2;
  texr.w = w * 2;
  texr.h = h * 2;

  int running = 1;

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

    SDL_RenderCopy(renderer, sprite, NULL, &texr);

    SDL_RenderPresent(renderer);
    SDL_Delay(100);
  }

  SDL_DestroyTexture(sprite);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}
