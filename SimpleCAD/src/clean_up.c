//Close the window, clean-up and exit the program.

//ODE Physics
/*
Destroy the dynamics and collision worlds.
*/

//OpenGL context
SDL_GL_DeleteContext(gl);

//SDL
SDL_DestroyWindow(window);
SDL_Quit();

//Logger
stop_logger();
