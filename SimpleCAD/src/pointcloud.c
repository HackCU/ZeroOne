typedef struct PointCloud
{
	Point3D* data;
	unsigned int length;
	unsigned int MAX_LENGTH;
	
	Point3D* center;
}
PointCloud;

/************
*			*
* Init		*
*			*
************/
PointCloud* initPointCloud()
{
	PointCloud* cloud;
	
	 cloud = malloc(sizeof(PointCloud));
	
	if(NULL == cloud )
	{
		log_error(POINTCLOUD_INIT_ERROR);
		return NULL;
	}
	
	cloud->data	  = NULL;
	cloud->length = 0;
	cloud->MAX_LENGTH  = ~0;
	
	cloud->center = initPoint();
	
	return cloud;
}

/************
*			*
* Helpers	*
*			*
************/
bool setPointCloudData(PointCloud* cloud, Point3D* target, int length)
{
	if(cloud == 0 || target == 0)return false;
	
	cloud->data = target;
	cloud->length = length;
	
	return true;
}

/************
*			*
* Clean up	*
*			*
************/

void pointcloud_clean_up(PointCloud* cloud)
{
	int i;
	for(i = 0; i < cloud->length; i++)
	{
		point_clean_up(&(cloud->data[i]));
	}
	
	free(&(cloud->length));
	free(&(cloud->MAX_LENGTH));
	free(&cloud);
}
