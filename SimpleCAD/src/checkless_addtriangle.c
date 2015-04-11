//first see if we can fill up a hole
if(temp_list->data_has_holes)
{
	int i;
	for(i = 0;i < temp_list->length; i++)
	{
		if(temp_list->data[i] == NULL)
		{
			temp_list->data[i] = list->data[i];
		}
		else
		{
			if(i == temp_list->length-1) temp_list->data_has_holes = false;
		}
	}
}
//else just add at the end
else
{
	//dont check anything, just add
	temp_list->data[temp_list->length] = list->data[i];
	temp_list->length++;
}

if(list->data[i] == NULL)temp_list->data_has_holes = true;
