#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include "screen.h"
#include "food.h"
#include "snake.h"

using namespace std;

int main(int argc, char* argv[]) {
    initWindow();

    SDL_Event event; bool quit = false;

    SNAKE snake;
    snake.initSnake();

    FOOD food;
    food.generateFood();
    
    while (!quit) {
        while (SDL_PollEvent( &event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_UP) snake.changeDirection(UP);
                else if (event.key.keysym.sym == SDLK_DOWN) snake.changeDirection(DOWN);
                else if (event.key.keysym.sym == SDLK_LEFT) snake.changeDirection(LEFT);
                else if (event.key.keysym.sym == SDLK_RIGHT) snake.changeDirection(RIGHT);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (snake.isDied()) {
            quit = true;
            break;
        }

        if (snake.nextCell() == pair<int,int> (food.x, food.y)) snake.appendSnake();
        else snake.moveSnake();

        while (1) {
            bool needChange = 0;

            for (int i = 0; i < snake.snakeLength; ++i)
                if (snake.snakeBody[i].first == food.x && snake.snakeBody[i].second == food.y) {
                    needChange = 1;
                    break;
                }
            
            if (needChange) food.generateFood();
            else break;
        }
        
        food.printFood();
        snake.printSnake();
        
        SDL_RenderPresent(renderer);

        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}