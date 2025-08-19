//
//  main.cpp
//  eight_ball_pool
//
//  Created by Astijus Karvauskas on 19/08/2025.
//

#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, const char * argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    //SDL_Surface* screenSurface = nullptr;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL FAILED TO INIT." << std::endl;
        return -1;
    }
    else
    {
        window = SDL_CreateWindow("8 BALL POOL",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        
        if (window == NULL)
        {
            std::cout << "WINDOW NOT CREATED.";
            return -1;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            
            if (renderer == NULL)
            {
                std::cout << "RENDERER NOT CREATED" << std::endl;
                return -1;
            }
            
            SDL_SetRenderDrawColor(renderer, 255, 222, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            
            // draw stuff here
            
            SDL_RenderPresent(renderer);
            
            
            SDL_Event e;
            bool quit = false;
            
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
            }
            
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            
            return 0;
        }
    }
}
