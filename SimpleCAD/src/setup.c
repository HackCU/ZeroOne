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

SDL_GLContext gl = SDL_GL_CreateContext(window);

#include "setup_gl.c"

#include "load_objects.c"
