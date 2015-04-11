void perspective(GLfloat fovx, GLfloat aspect, GLfloat zNear, GLfloat zFar)
{
   // This code is based off the MESA source for gluPerspective
   // *NOTE* This assumes GL_PROJECTION is the current matrix

   
   GLfloat xmin, xmax, ymin, ymax;
   GLfloat m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   xmax = zNear * tan(fovx * M_PI / 360.0);
   xmin = -xmax;
   
   ymin = xmin / aspect;
   ymax = xmax / aspect;

   // Set up the projection matrix
   m[0] = (2.0 * zNear) / (xmax - xmin);
   m[4*1+1] = (2.0 * zNear) / (ymax - ymin);
   m[4*2+2] = -(zFar + zNear) / (zFar - zNear);

   m[2] = (xmax + xmin) / (xmax - xmin);
   m[4+2] = (ymax + ymin) / (ymax - ymin);
   m[4*3+2] = -1.0;

   m[4*2+3] = -(2.0 * zFar * zNear) / (zFar - zNear);
   
   // Add to current matrix
   glMultMatrixf(m);
}
