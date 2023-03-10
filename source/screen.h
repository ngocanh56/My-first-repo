#include <bits/stdc++.h>
#include <SDL2/SDL.h>

using namespace std;

const int boardWidth = 50;
const int boardHeight = 33;
const int SCREEN_WIDTH = 1850;
const int SCREEN_HEIGHT = 1016;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Renderer* renderer;

void initWindow() {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return;
    }
    
    // Create window
    window = SDL_CreateWindow("Snake", 74 , 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return;
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    //Update the surface
    SDL_UpdateWindowSurface(window);

    //Create renderer
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void drawPoint(int x, int y, int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void drawLine(int x, int y, int z, int t, int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawLine(renderer, x, y, z, t);
}

void drawRectangle(int x, int y, int z, int t, int r, int g, int b, int a) {
    SDL_Rect fillRect = {x, y, z, t};
    SDL_SetRenderDrawColor( renderer, r, g, b, a);        
    SDL_RenderFillRect(renderer, &fillRect);
}