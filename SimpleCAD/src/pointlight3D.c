typedef struct PointLight3D
{
	Point3D* position;
}
PointLight3D;

/************
*			*
*Init		*
*			*
************/
PointLight3D* initPointLight()
{
	PointLight3D* light;
	
	light = malloc(sizeof(PointLight3D));
	
	if(NULL == light)
	{
		log_error(LIGHTPOINT_INIT_ERROR);
		return NULL;
	}
	
	light->position = initPoint();
	
	return light;
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
bool pointlight_clean_up(PointLight3D* light)
{
	if(light == NULL) return false;
	
	point_clean_up(light->position);
	free(light);
	
	return true;
}
