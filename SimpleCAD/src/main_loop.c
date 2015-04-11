SDL_Event event;
bool done = false;

while(!done)
{
	SDL_PumpEvents();
	while (SDL_PollEvent(&event))
	{
		#include "handle_events.c"
	}

	//draw frame
	#include "frame_draw.c"
}
