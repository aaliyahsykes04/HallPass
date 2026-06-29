#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
//this loads the SDL3 so I can use the tools


int main(int argc, char* argv[])
//this is where the game starts once the player presses play
// int means that the function will return an integer value, and main is the name of the function. The parameters argc and argv are used to pass command-line arguments to the program.
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
	//this starts up SDL3 and tells it where I want to use the video system (the screen)
	// kinda like how you have to turn on the tv before you can watch it, you have to turn on SDL3 before you can use it

    // Create the window
    SDL_Window* window = SDL_CreateWindow("Hall Pass", 800, 600, 0);
	//creates the came wibdow on the screen with the title "Hall Pass" and a size of 800x600 pixels
        // SDL_Window hold the window 
		// * means it stores the address of the window in memory, so we can use it later to refer to the window
		// 800, 600 is the width and height of the window in pixels
		// 0 is the flags parameter, which we don't need to use right now, so we just set it to 0

    // Create the renderer (this is what draws things on screen)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	// SDL_Renderer is a painter that draws things on the window. Every time I want to draw something I have to call the renderer to do it. The renderer is created with the window as a parameter, so it knows where to draw things.

    // This variable controls when the game loop stops
    bool running = true;
    // the bool is a data type that can only be true or false. 
	// When running is true the game keeps running, when it is false the game stops.
  


    // THE GAME LOOP
    while (running)
    {
        // --- STEP 1: CHECK INPUT ---
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        // SDL_Event a container that hold whatever happened 
        // SDL_PollEvent check if ther are any new events waiting 
		// SDL_Event_Quit this means the user clicked to close the window, so if they close the window we set running to false so the game loop stops and the game ends

        // --- STEP 2: UPDATE ---
        // (we'll add game logic here later)

        // --- STEP 3: DRAW ---
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
    // SDL_SetRenderDrawColor sets the color to dark grey the numbers are ( Red, Green, Blue, Alpha -255 means fully visible)
    // SDL_RenderClear paints the whole screen with that color
    // SDL_RenderPresent shows everything on screen. This makes everything that I drew appear. 

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// when the loop ends this cleans everything up properly
//SDL_DestroyRenderer destroys the renderer and frees up the memory it was using
//SDL_DestroyWindow destroys the window and frees up the memory it was using
//SDL_Quit shuts down SDL3 and cleans up any resources it was using
// return 0; means the program ended successfully. If there was an error, we would return a different number to indicate that something went wrong.