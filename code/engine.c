#include <SDL2/SDL.h>
#include <stdio.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Key press surfaces constants
enum KeyPressSurfaces 
{ 
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

// Start SDL and create window
int init();

// loads media
int loadMedia();

//Free media and shutdown SDL
void close();

// Loads the individual image
SDL_Surface* loadSurface(char path[]);

// The window we're rendering to
SDL_Window * gWindow = NULL;

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

// Current displayed image
SDL_Surface* gCurrentSurface = NULL;

// The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


int init()
{
    // Initialization Flag
    int success = 1;
    
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf("SDL could not be Initialized! SDL_ERROR: %s\n", SDL_GetError());
        success = 0;
    }
    else
    {
        //Create Window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf( "Window Could not be created! SDL_Error: %s\n", SDL_GetError());
            success = 0;
        }
        else
        {
            // Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

SDL_Surface* loadSurface(char path[])
{
    // Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if(loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
    }
    
    return loadedSurface;
}


int loadMedia()
{
    // Loading success flag
    int success = 1;
    
    // Load default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("04_keypresses/press.bmp");
    if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf("Failed to load the default image\n");
        success = 0;
    }
    // continues here
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
            // Main loop flag
            int quit = 0;
            
            //Event handler
            SDL_Event e;
            
            // While application is running
            while( !quit)
            {
                // Handle events on the queue
                while (SDL_PollEvent(&e) != 0)
                {
                    // User requests quit
                    if( e.type == SDL_QUIT)
                    {
                        quit = 1;
                    }
                }
                
                // Apply the image
                SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
                
                // Update the surface
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }
    
    // Free resources and close
    close();
    
    return 0;
}
