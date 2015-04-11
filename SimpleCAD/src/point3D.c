typedef struct Point3D
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}
Point3D;

/************
*			*
* Init		*
*			*
*************/
Point3D* initPoint()
{
	Point3D* point;
	
	point = malloc(sizeof(Point3D));
	
	if(NULL == point )
	{
		log_error(POINT_INIT_ERROR);
		return NULL;
	}
	
	point->x = 0;
	point->y = 0;
	point->z = 0;
	
	return point;
}

/************
*			*
* Clean up	*
*			*
************/
void point_clean_up(Point3D* point)
{
	free(point);
}
