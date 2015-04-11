//OpenGL setup
glClearColor (0.2f, 0.2f, 0.2f, 0.0f);
glEnable(GL_DEPTH_TEST);
glEnable(GL_CULL_FACE);
glEnable(GL_BLEND);
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

#include "setup_camera.c"
