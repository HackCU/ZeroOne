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

Point3D* initPointWithValues(GLfloat x, GLfloat y, GLfloat z)
{
	Point3D* point;
	
	point = malloc(sizeof(Point3D));
	
	if(NULL == point )
	{
		log_error(POINT_INIT_ERROR);
		return NULL;
	}
	
	point->x = x;
	point->y = y;
	point->z = z;
	
	return point;
}

bool setPointValues(Point3D* point, GLfloat x, GLfloat y, GLfloat z)
{
	if(point == NULL) return false;
	
	point->x = x;
	point->y = y;
	point->z = z;
	
	return true;
}

bool negatePoint(Point3D* point)
{
	if(point == NULL) return false;
	
	point->x *= -1;
	point->y *= -1;
	point->z *= -1;
	
	return true;
}

/************
*			*
* Clean up	*
*			*
************/
bool point_clean_up(Point3D* point)
{
	if(point == NULL) return false;
	
	free(point);
	
	return true;
}
