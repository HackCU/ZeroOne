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


/************
*			*
* Clean up	*
*			*
************/
bool internal_object_clean_up(Object3D* object, bool isRecursive)
{
	if(object == NULL) return false;
	
	if(isRecursive)
		recursive_pointcloud_clean_up(object->cloud);
		
	recursive_triangle_list_clean_up(object->list);
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
