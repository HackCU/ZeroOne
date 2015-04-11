typedef enum mouse_3D_usage{regular, projected}mouse_3D_usage;

typedef struct Mouse3D
{
	Point3D* position;
	mouse_3D_usage usage;
}
Mouse3D;

/************
*			*
*Init		*
*			*
************/
Mouse3D* init3DMouse()
{
	Mouse3D* mouse;
	
	mouse = malloc(sizeof(Mouse3D));
	
	if(NULL == mouse)
	{
		log_error(MOUSE3D_INIT_ERROR);
		return NULL;
	}
	
	mouse->position = initPoint();
	mouse->usage = regular;
	
	return mouse;
}

/************
*			*
*Helpers	*
*			*
************/


/************
*			*
*Clean up	*
*			*
************/
bool mouse3d_clean_up(Mouse3D* mouse)
{
	if(mouse == NULL) return false;
	
	free(mouse);
	
	return true;
}
