//OpenGL code

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glPushMatrix ();
	//relative camera movements
	glTranslatef(-camera->position->x, -camera->position->y, -camera->position->z);
	
	//now draw everything
	glRotatef (theta, 0.0f, 0.0f, 1.0f);
		glBegin(GL_TRIANGLES);
			//draw all objects
			glColor3f(1.0, 0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0); glVertex3f( 1.0,  1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0); glVertex3f(-1.0,  1.0, 0.0);
			
			glColor3f(1.0, 1.0, 1.0); glVertex3f( 1.0,  1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0); glVertex3f(-1.0, -1.0, 0.0);
			glColor3f(1.0, 1.0, 1.0); glVertex3f( 1.0, -1.0, 0.0);
		glEnd();
glPopMatrix ();

theta += 0.05f;

SDL_GL_SwapWindow(window);

//SDL_Delay( 1 );


