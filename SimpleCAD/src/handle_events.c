switch (event.type)
{
	case SDL_QUIT:
		done = true;
		break;

	case SDL_KEYDOWN:
		{
			//#include "handle_keyboardEvent.c"
			break;
		}

	case SDL_MOUSEMOTION:
		{
			#include "handle_mouseMotionEvent.c"
			break;
		}

	case SDL_MOUSEBUTTONDOWN:
		{
			#include "handle_mouseButtonEvent.c"
			break;
		}
		
	case SDL_MOUSEWHEEL:
		{
			#include "handle_mouseWheelEvent.c"
			break;
		}
}
