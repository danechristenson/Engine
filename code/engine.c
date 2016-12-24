#include <SDL.h>
#include <stdio.h>


 const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main (int argc, char* args[])
{
    //window to render to
    SDL_Window* window = NULL;
    
    // surface within the window
    SDL_Surface* screenSurface = NULL;
    
    // Initialize
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not be initialized SDL_ERROR: %s\n", SDL_GetError());
}
else
{ 
    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // Get window surface
        screenSurface = SDL_GetWindowSurface(window);
        
        // Fill surface white
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
        
        // Update the window
        SDL_UpdateWindowSurface(window);
        
        // Wait 2 seconds
        SDL_Delay(2000);
    }
}

// Destroy window
SDL_DestroyWindow(window);

// Quit SDL subsystems
SDL_Quit();

return 0;
}