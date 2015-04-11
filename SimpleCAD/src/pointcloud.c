typedef struct PointCloud
{
	Point3D** data;
	unsigned int length;
	unsigned int MAX_SIZE;

	bool data_has_holes;
	
	Point3D* center;
}
PointCloud;

/************
*			*
* Init		*
*			*
************/

PointCloud* initPointCloudWithSize(unsigned int target_length)
{
	//create cloud to return
	PointCloud* cloud;
	
	cloud = calloc(target_length,sizeof(PointCloud));
	
	if(NULL == cloud )
	{
		log_error(POINTCLOUD_INIT_ERROR);
		return NULL;
	}
	/*********************/
	
	cloud->data	  = NULL;
	cloud->length = 0;
	cloud->MAX_SIZE = target_length;
	
	cloud->data_has_holes = false;
	
	cloud->center = initPoint();
	
	return cloud;
}

PointCloud* initPointCloud()
{
	return initPointCloudWithSize(1);
}

/************
*			*
* Clean up	*
*			*
************/

bool internal_pointcloud_clean_up(PointCloud* cloud, bool isRecursive)
{
	if(cloud == NULL) return false;
	
	if(isRecursive)
	{
		int i;
		for(i = 0; i < cloud->length; i++)
		{
			point_clean_up(cloud->data[i]);
		}
	}
	
	free(&(cloud->length));
	free(&(cloud->MAX_SIZE));
	free(cloud);
	
	return true;
}

bool pointcloud_clean_up(PointCloud* cloud)
{
	return internal_pointcloud_clean_up(cloud, false);
}

bool recursive_pointcloud_clean_up(PointCloud* cloud)
{
	return internal_pointcloud_clean_up(cloud, true);
}

/************
*			*
* Helpers	*
*			*
************/
bool resizePointCloud(PointCloud* cloud, unsigned int target_length)
{
	if(cloud == NULL || target_length == 0) return false;

	//get right size	
	unsigned int right_size = 1;
	while(target_length > right_size) {right_size*=2;}
	
	//create the cloud with right size where the data will be copied to
	PointCloud* temp_cloud = initPointCloudWithSize(right_size);
	
	//copy the data
	unsigned int i;
	for(i = 0; (i < right_size)&&(i<cloud->length); i++)
	{
		#include "checkless_addpoint.c"
	}
	
	//if we are cutting short, clean up the tail points
	if(cloud->length > temp_cloud->length)
	{
		for(i = temp_cloud->length; i < cloud->length; i++)
		{
			point_clean_up( cloud->data[i] );
		}
	}
	
	//do the final assignment and clean up temporary cloud
	cloud->data = temp_cloud->data;
	cloud->length = temp_cloud->length;
	cloud->MAX_SIZE = temp_cloud->MAX_SIZE;
	
	cloud->data_has_holes = temp_cloud->data_has_holes;
	
	pointcloud_clean_up(temp_cloud);
	
	return true;
}

bool internal_removePointFromCloud(PointCloud* cloud, unsigned int index, bool isRecursive)
{
	if(cloud == NULL || index >= cloud->length) return false;
	
	if(isRecursive)
		point_clean_up(cloud->data[index]);
	
	if(index == cloud->length-1)
	{
		cloud->length--;
	}
	else
	{
		cloud->data[index] = NULL;
		cloud->data_has_holes = true;
	}
	
	return true;
}

bool recursive_removePointFromCloud(PointCloud* cloud, unsigned int index)
{
	return internal_removePointFromCloud(cloud, index, true);
}

bool removePointFromCloud(PointCloud* cloud, unsigned int index)
{
	return internal_removePointFromCloud(cloud, index, false);
}

bool addPointToCloud(PointCloud* cloud, Point3D* target)
{
	if(cloud == NULL ) return false;
	
	//first see if we can fill up a hole
	if(cloud->data_has_holes)
	{
		int i;
		for(i = 0;i < cloud->length; i++)
		{
			if(cloud->data[i] == NULL)
			{
				cloud->data[i] = target;
			}
			else
			{
				if(i == cloud->length-1) cloud->data_has_holes = false;
			}
		}
	}
	//else just add at the end
	else
	{
		//check if there is enough space and resize if necessary
		if(cloud->length+1 > cloud->MAX_SIZE) resizePointCloud(cloud,cloud->length+1);
		
		cloud->data[cloud->length] = target;
		cloud->length++;
	}
	
	if(target == NULL)cloud->data_has_holes = true;
	
	return true;
}

bool addPointCopyToCloud(PointCloud* cloud, Point3D* target)
{
	Point3D* point = initPoint();
	
	point->x = target->x;
	point->y = target->y;
	point->z = target->z;
	
	if(!addPointToCloud(cloud, point))
		point_clean_up(point);
}

bool calculateCloudCenter(PointCloud* cloud)
{
	if(cloud == NULL) return false;
	
	//calculate
	
	return true;
}
