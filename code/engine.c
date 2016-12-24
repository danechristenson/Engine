#include <SDL.h>
#include <stdio.h>


 const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Start SDL and create window
bool init();

// loads media
bool loadMedia();

//Free media and shutdown SDL
void close();

// The window we're rendering to
SDL_Window * gWindow = NULL;

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


bool init()
{
    // Initialization Flag
    bool success = true;
    
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL could not be Initialized! SDL_ERROR: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create Window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,  /SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf( "Window Could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return sucess;
}

bool loadMedia()
{
    // Loading success flag
    bool success = true;
    
    // Load splash image
    gHelloWorld = SDL_LoadBMP("data/hello_world.bmp");
    if(gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "data/hello_world.bmp", SDL_GetError());
        success == false;
    }
    return sucess;
}

void close()
{
    // Deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    
    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    
    // Quit SDL subsystems
    SDL_Quit();
}

int main (int argc, char* args[])
{
// Start up SDL and create window
    if(!init())
    {
        printf("Failed to initialize\n");
    }
    else
    {
        // Load media
        if(!loadMedia())
        { 
            printf("Failed to load media\n");
        }
        else
        {
            // Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            
            // Update the surface
            SDL_UpdateWindowSurface(gWindow);
            
            //Wait 2 seconds
            SDL_Delay(2000);
        }
    }
    
    // Free resources and close
    close();
    
    return 0;
}