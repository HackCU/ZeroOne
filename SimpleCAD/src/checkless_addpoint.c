//first see if we can fill up a hole
if(temp_cloud->data_has_holes)
{
	int i;
	for(i = 0;i < temp_cloud->length; i++)
	{
		if(temp_cloud->data[i] == NULL)
		{
			temp_cloud->data[i] = cloud->data[i];
		}
		else
		{
			if(i == temp_cloud->length-1) temp_cloud->data_has_holes = false;
		}
	}
}
//else just add at the end
else
{
	//dont check anything, just add		
	temp_cloud->data[temp_cloud->length] = cloud->data[i];
	temp_cloud->length++;
}

if(cloud->data[i] == NULL)temp_cloud->data_has_holes = true;
