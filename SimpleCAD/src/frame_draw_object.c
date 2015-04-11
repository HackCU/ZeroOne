//repeat for each triangle in object
int f_d_i;
for(f_d_i = 0; f_d_i < object->list->length; f_d_i++)
{
	//reading point from triangle f_d_i
	Point3D* points[3];
	
	points[0] = object->cloud[object->list[f_d_i][0]];
	points[1] = object->cloud[object->list[f_d_i][1]];
	points[2] = object->cloud[object->list[f_d_i][2]];
	
	//render triangle
	glRotatef (theta, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.8, 0.8, 0.8); glVertex3f(points[0]->x, points[0]->y, points[0]->z);
		glColor3f(0.7, 0.7, 0.7); glVertex3f(points[1]->x, points[1]->y, points[1]->z);
		glColor3f(0.6, 0.6, 0.6); glVertex3f(points[2]->x, points[2]->y, points[2]->z);
	glEnd();
}
