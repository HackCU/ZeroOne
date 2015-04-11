typedef struct Camera
{
	Point3D* position;
	Point3D* rotation;
	
	Point3D* lookAt;
	
	Point3D* orbit;
	GLfloat orbitDistance;
}
Camera;

/************
*			*
* Init		*
*			*
*************/
Camera* initCamera()
{
	Camera* camera;

	camera = malloc(sizeof(Camera));
	
	if(NULL == camera )
	{
		log_error(CAMERA_INIT_ERROR);
		return NULL;
	}
	
	camera->position = initPoint();
	camera->rotation = initPoint();
	
	return camera;
}

/************
*			*
* Helpers	*
*			*
************/
//Look At
bool setLookAt(Camera* camera, Point3D* target)
{
	if(target == 0 || camera == 0) return false;
	
	camera->lookAt = target;
	
	return true;
}

void stopLookAt(Camera* camera)
{
	camera->lookAt = NULL;
}

//Orbit
bool setOrbit(Camera* camera, Point3D* target, GLfloat distance)
{
	if(target == 0 || camera == 0) return false;
	
	camera->orbit = target;
	camera->orbitDistance = distance;
	
	return true;
}

void stopOrbit(Camera* camera)
{
	camera->orbit = NULL;
}

/************
*			*
* Clean up	*
*			*
************/
void camera_clean_up(Camera* camera)
{
	free(&(camera->orbitDistance));
	free(camera);
}

void recursive_camera_clean_up(Camera* camera)
{
	point_clean_up(camera->position);
	point_clean_up(camera->rotation);
	point_clean_up(camera->lookAt);
	point_clean_up(camera->orbit);
	
	camera_clean_up(camera);
}
