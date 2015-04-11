//Setup camera
glViewport(0, 0, (GLsizei) width, (GLsizei) height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
perspective(60.0, (GLfloat) 800/(GLfloat) 600, 1.0, 30.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

Camera* camera = initCamera();

camera->position->z = 5.0;
