//OpenGL code

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glPushMatrix ();
	//relative camera movements
	glTranslatef(-camera->position->x, -camera->position->y, -camera->position->z);
	glRotatef   (30.0, 1.0f, 1.0f, 1.0f);
	
	//now draw everything
	{
		//draw all objects
		Object3D* object;	
		//loop through objects
		
		{
			//set object
			object = cube;
			
			//draw object
			#include "frame_draw_object.c"
		}
	}
	
	//draw UI
	{
		//draw cube guide in top-right
		
		
		//draw cursor
		
		
	}
		
glPopMatrix ();

theta += 0.05f;

SDL_GL_SwapWindow(window);

//SDL_Delay( 1 );


