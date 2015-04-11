typedef struct Triangle3D
{
	GLuint a;
	GLuint b;
	GLuint c;
}
Triangle3D;

/************
*			*
* Init		*
*			*
*************/

Triangle3D* initTriangle()
{
	Triangle3D* triangle;
	
	triangle = malloc(sizeof(Triangle3D));
	
	if(NULL == triangle )
	{
		log_error(TRIANGLE_INIT_ERROR);
		return NULL;
	}
	
	triangle->a = 0;
	triangle->b = 0;
	triangle->c = 0;
	
	return triangle;
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
	
	return true;
}

/************
*			*
* Clean up	*
*			*
************/
void triangle_clean_up(Triangle3D* triangle)
{
	free(&(triangle->a));
	free(&(triangle->b));
	free(&(triangle->c));
	free(triangle);
}
