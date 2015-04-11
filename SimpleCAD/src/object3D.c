typedef struct Object3D
{	
	PointCloud* cloud;
	TriangleList* list;
	
	char* name;
}
Object3D;

/************
*			*
* Includes	*
*			*
*************/
Object3D* initObject()
{
	Object3D* object;
	
	object = malloc(sizeof(Object3D));
	
	if(NULL == object)
	{
		log_error(OBJECT_INIT_ERROR);
		return NULL;
	}
	
	object->cloud = initPointCloud();
	object->list  = initTriangleList();
	
	object->name = "Nameless";
	
	return object;
}

/************
*			*
* Helpers	*
*			*
*************/

bool moveObject(Object3D* object, Point3D* amount)
{
	if(object == NULL || amount == NULL) return false;
	
	//move center
	object->cloud->center->x += amount->x;
	object->cloud->center->y += amount->y;
	object->cloud->center->z += amount->z;
	
	return true;
}

bool scaleObject(Object3D* object, GLfloat amount, Point3D* origin)
{
	if(object == NULL || origin == NULL) return false;
	
	//scale cloud
	Point3D* intermediate = initPoint();
	int i;
	for(i = 0; i < object->cloud->length; i++)
	{
		
	}
	
	//scale center
	Point3D* center_to_origin = initPoint();
	
	
	return true;
}

bool rotateObjectOnXAxis(Object3D* object, GLuint degrees, Point3D* origin)
{
	if(object == NULL || origin == NULL) return false;
	
	
	
	return true;
}

bool rotateObjectOnYAxis(Object3D* object, double degrees, Point3D* origin)
{
	if(object == NULL || origin == NULL) return false;
	
	
	
	return true;
}

bool rotateObjectOnZAxis(Object3D* object, double degrees, Point3D* origin)
{
	if(object == NULL || origin == NULL) return false;
	
	
	
	return true;
}

/************
*			*
* Clean up	*
*			*
************/
bool internal_object_clean_up(Object3D* object, bool isRecursive)
{
	if(object == NULL) return false;
	
	if(isRecursive)
	{
		recursive_pointcloud_clean_up(object->cloud);
		recursive_triangle_list_clean_up(object->list);
	}
	
	free(object->name);	
	free(object);
	
	return true;
}

bool object_clean_up(Object3D* object)
{
	return internal_object_clean_up(object, false);
}

bool recursive_object_clean_up(Object3D* object)
{
	return internal_object_clean_up(object, true);
}
