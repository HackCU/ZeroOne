typedef struct Triangle3D
{
	GLuint a;
	GLuint b;
	GLuint c;
	
	Point3D* normal;
}
Triangle3D;

/************
*			*
* Init		*
*			*
*************/

Triangle3D* initTriangleWithValues(GLuint a, GLuint b, GLuint c)
{
	Triangle3D* triangle;
	
	triangle = malloc(sizeof(Triangle3D));
	
	if(NULL == triangle )
	{
		log_error(TRIANGLE_INIT_ERROR);
		return NULL;
	}
	
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	
	return triangle;
}

Triangle3D* initTriangle()
{
	return initTriangleWithValues(0,0,0);
}

/************
*			*
* Helpers	*
*			*
*************/
bool flipTriangle(Triangle3D* triangle)
{
	if(triangle == 0) return false;
	
	GLint intermediate;
	intermediate = triangle->a;
	
	triangle->a = triangle->b;
	triangle->b = intermediate;
	
	negatePoint(triangle->normal);
	
	return true;
}

bool calculateNormal(Triangle3D* triangle)
{
	if(triangle == NULL) return false;
	
	//calculate
	
	return true;
}

/************
*			*
* Clean up	*
*			*
************/
bool triangle_clean_up(Triangle3D* triangle)
{
	if(triangle == NULL) return false;
	
	free(&(triangle->a));
	free(&(triangle->b));
	free(&(triangle->c));
	point_clean_up(triangle->normal);
	free(triangle);
	
	return true;
}
