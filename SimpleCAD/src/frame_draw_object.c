//get center
Point3D* center = initPoint();
addPoints(center,object->cloud->center);

//repeat for each triangle in object
Point3D* 	points[3];
GLuint 		indices[3];

int i;
for(i = 0; i < object->list->length; i++)
{
	//reading points from triangle i
	indices[0] = object->list->data[i]->a;
	indices[1] = object->list->data[i]->b;
	indices[2] = object->list->data[i]->c;
	
	if(indices[0] >= object->cloud->length)break;
	if(indices[1] >= object->cloud->length)break;
	if(indices[2] >= object->cloud->length)break;
	
	points[0] = object->cloud->data[indices[0]]; addPoints(points[0],center);
	points[1] = object->cloud->data[indices[1]]; addPoints(points[1],center);
	points[2] = object->cloud->data[indices[2]]; addPoints(points[2],center);
	
	//render triangle
	glRotatef (theta, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.8, 0.8, 0.8); glVertex3f(points[0]->x, points[0]->y, points[0]->z);
		glColor3f(0.7, 0.7, 0.7); glVertex3f(points[1]->x, points[1]->y, points[1]->z);
		glColor3f(0.6, 0.6, 0.6); glVertex3f(points[2]->x, points[2]->y, points[2]->z);
	glEnd();
}
