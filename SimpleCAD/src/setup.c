start_logger();

if(SDL_Init(SDL_INIT_EVERYTHING ^ SDL_INIT_HAPTIC) < 0)
{
	printf("Could not initialize SDL:\n %s",SDL_GetError());
	return 1;
}

SDL_DisplayMode displayMode;
SDL_GetDesktopDisplayMode(0, &displayMode);
float width = 3*displayMode.w/4;
float height = 3*displayMode.h/4;

//Create window
SDL_Window* window = SDL_CreateWindow( PRODUCT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_OPENGL);

if(!window)
{
	printf("Could not initialize window.\n");
	return 1;
}

//ODE setup
/*
Create a dynamics world.
Create bodies in the dynamics world.
Set the state (position etc) of all bodies.
Create joints in the dynamics world.
Attach the joints to the bodies.
Set the parameters of all joints.
Create a collision world and collision geometry objects, as necessary.
Create a joint group to hold the contact joints.
*/

SDL_GLContext gl = SDL_GL_CreateContext(window);

#include "setup_gl.c"

#include "load_objects.c"
