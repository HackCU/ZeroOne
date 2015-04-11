#include <stdio.h>

#ifdef _WIN32
	#include <SDL2/SDL.h>
	#include <gl/gl.h>
#endif

#ifndef _WIN32
	#include "SDL.h"
#endif

#include "default_strings.c"
#include "definitions.c"
#include "logger.c"

//3D Helpers
#include "perspective.c"

#include "point3D.c"
#include "triangle3D.c"
#include "pointlight3d.c"
#include "camera.c"

#include "pointcloud.c"
#include "trianglelist.c"
#include "object3D.c"
#include "objectlist.c"

