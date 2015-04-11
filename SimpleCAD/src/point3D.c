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

/************
*			*
* Helpers	*
*			*
*************/

bool negatePoint(Point3D* point)
{
	if(point == NULL) return false;
	
	point->x *= -1;
	point->y *= -1;
	point->z *= -1;
	
	return true;
}

bool addPoints(Point3D* a, Point3D* b)
{
	if(a == NULL || b == NULL) return false;
	
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	
	return true;
}

#define DISASSEMBLE Point3D* intermediate = initPoint();\
														\
					addPoint(intermediate, point); 		\
					negatePoint(origin);				\
					addPoints(intermediate, origin);
					
					

#define ASSEMBLE 	negatePoint(origin);				\
														\
					addPoints(intermediate,origin);		\
														\
					point->x = intermediate->x;			\
					point->y = intermediate->y;			\
					point->z = intermediate->z;			\
														\
					point_clean_up(intermediate);

bool scalePoint(Point3D* point, GLfloat amount, Point3D* origin)
{
	if(point == NULL || origin == NULL) return false;
	
	/****************
	*		  C		* Find scaled AB
	*	  _/*		* Disassemble: 	CB = AB - AC
	*  A*	|		*
	*	 \	|		* CB = scale CB
	*	  \ |		*
	*	   \|		* Assemble: 	AB = CB - AB
	*		*B		*
	****************/
	
	//disassemble
	DISASSEMBLE
	
	//scale
	intermediate->x *= amount;
	intermediate->y *= amount;
	intermediate->z *= amount;
	
	//assemble
	ASSEMBLE
	
	return true;
}

bool rotatePointOnXAxis(Point3D* point, GLuint degrees, Point3D* origin)
{
	if(point == NULL || origin == NULL) return false;
	
	/****************
	*		  C		* Find scaled AB
	*	  _/*		* Disassemble: 	CB = AB - AC
	*  A*	|		*
	*	 \	|		* CB = rotate CB
	*	  \ |		*
	*	   \|		* Assemble: 	AB = CB - AB
	*		*B		*
	****************/
		
	GLfloat radians = degrees/180*M_PI;
	
	//disassemble
	DISASSEMBLE
	
	//rotate
		//get unit vector x component
		GLfloat distance = sqrt(pow(intermediate->y,2)+pow(intermediate->z,2));
		
		GLfloat unit_x = intermediate->y/distance;
		
		//calculate initial angle
		GLfloat beta = acos(unit_x);
		
		//calculate final point
		intermediate->y = cos(beta+radians)/(cos(beta)/unit_x);
		intermediate->z = sin(beta+radians)/(cos(beta)/unit_x);
	
	//assemble
	ASSEMBLE
	
	return true;
}

bool rotatePointOnYAxis(Point3D* point, double degrees, Point3D* origin)
{
	if(point == NULL || origin == NULL) return false;
	
	/****************
	*		  C		* Find scaled AB
	*	  _/*		* Disassemble: 	CB = AB - AC
	*  A*	|		*
	*	 \	|		* CB = rotate CB
	*	  \ |		*
	*	   \|		* Assemble: 	AB = CB - AB
	*		*B		*
	****************/
	
	GLfloat radians = degrees/180*M_PI;
	
	//disassemble
	DISASSEMBLE
	
	//rotate
		//get unit vector x component
		GLfloat distance = sqrt(pow(intermediate->x,2)+pow(intermediate->z,2));
		
		GLfloat unit_x = intermediate->x/distance;
		
		//calculate initial angle
		GLfloat beta = acos(unit_x);
		
		//calculate final point
		intermediate->x = cos(beta+radians)/(cos(beta)/unit_x);
		intermediate->z = sin(beta+radians)/(cos(beta)/unit_x);
	
	//assemble
	ASSEMBLE
	
	return true;
}

bool rotatePointOnZAxis(Point3D* point, double degrees, Point3D* origin)
{
	if(point == NULL || origin == NULL) return false;
	
	/****************
	*		  C		* Find scaled AB
	*	  _/*		* Disassemble: 	CB = AB - AC
	*  A*	|		*
	*	 \	|		* CB = rotate CB
	*	  \ |		*
	*	   \|		* Assemble: 	AB = CB - AB
	*		*B		*
	****************/
	
	GLfloat radians = degrees/180*M_PI;
	
	//disassemble
	DISASSEMBLE
	
	//rotate
		//get unit vector x component
		GLfloat distance = sqrt(pow(intermediate->x,2)+pow(intermediate->y,2));
		
		GLfloat unit_x = intermediate->x/distance;
		
		//calculate initial angle
		GLfloat beta = acos(unit_x);
		
		//calculate final point
		intermediate->x = cos(beta+radians)/(cos(beta)/unit_x);
		intermediate->y = sin(beta+radians)/(cos(beta)/unit_x);
	
	//assemble
	ASSEMBLE
	
	return true;
}

bool setPointValues(Point3D* point, GLfloat x, GLfloat y, GLfloat z)
{
	if(point == NULL) return false;
	
	point->x = x;
	point->y = y;
	point->z = z;
	
	return true;
}
