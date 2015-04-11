typedef struct Object3D
{	
	PointCloud* cloud;
	TriangleList* list;
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
	
	if(NULL == object )
	{
		log_error(OBJECT_INIT_ERROR);
		return NULL;
	}
	
	object->cloud = initPointCloud();
	object->list  = initTriangleList();
	
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
void object_clean_up(Object3D* object)
{
	triangle_list_clean_up(object->list);	
	free(object);
}

void recursive_object_clean_up(Object3D* object)
{
	pointcloud_clean_up(object->cloud);
	
	object_clean_up(object);
}
