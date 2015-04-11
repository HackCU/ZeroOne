typedef struct TriangleList
{
	Triangle3D** data;
	
	unsigned int length;
	unsigned int MAX_SIZE;
	
	bool data_has_holes;
}
TriangleList;

/************
*			*
* Init		*
*			*
************/
TriangleList* initTriangleListWithSize(unsigned int target_length)
{	
	//create list to return
	TriangleList* list;
	
	list = calloc(target_length,sizeof(TriangleList));
	
	if(NULL == list )
	{
		log_error(TRIANGLELIST_INIT_ERROR);
		return NULL;
	}
	
	/********************/
	
	list->data	 = NULL;
	list->length = 0;
	list->MAX_SIZE  = target_length;
	
	list->data_has_holes = false;	
	
	return list;
}

TriangleList* initTriangleList()
{
	return initTriangleListWithSize(1);
}

/************
*			*
* Clean up	*
*			*
************/

bool internal_trianglelist_clean_up(TriangleList* list, bool isRecursive)
{
	if(list == NULL) return false;
	
	if(isRecursive)
	{
		int i;
		for(i = 0; i < list->length; i++)
		{
			triangle_clean_up(list->data[i]);
		}
	}

	free(&(list->length));
	free(&(list->MAX_SIZE));
	free(list);
	
	return true;
}

bool trianglelist_clean_up(TriangleList* list)
{	
	return internal_trianglelist_clean_up(list, false);
}

bool recursive_trianglelist_clean_up(TriangleList* list)
{
	return internal_trianglelist_clean_up(list, true);
}

/************
*			*
* Helpers	*
*			*
************/
bool resizeTriangleList(TriangleList* list, unsigned int target_length)
{
	if(list == NULL || target_length == 0) return false;

	//get right size	
	unsigned int right_size = 1;
	while(target_length > right_size) {right_size*=2;}
	
	//create the cloud with right size where the data will be copied to
	TriangleList* temp_list = initTriangleListWithSize(right_size);
	
	//copy the data
	unsigned int i;
	for(i = 0; (i < right_size)&&(i<list->length); i++)
	{		
		#include "checkless_addtriangle.c"
	}
	
	//if we are cutting short, clean up the tail points
	if(list->length > temp_list->length)
	{
		for(i = temp_list->length; i < list->length; i++)
		{
			triangle_clean_up( list->data[i] );
		}
	}
	
	//do the final assignment and clean up temporary list
	list->data = temp_list->data;
	list->length = temp_list->length;
	list->MAX_SIZE = temp_list->MAX_SIZE;
	
	list->data_has_holes = temp_list->data_has_holes;
	
	trianglelist_clean_up(temp_list);
	
	return true;
}

bool internal_removeTriangle(TriangleList* list, unsigned int index, bool isRecursive)
{
	if(list == NULL || index >= list->length) return false;
	
	if(isRecursive)
		triangle_clean_up(list->data[index]);
	
	if(index == list->length-1)
	{
		list->length--;
	}
	else
	{
		list->data[index] = NULL;
		list->data_has_holes = true;
	}
	
	return true;
}

bool recursive_removeTriangle(TriangleList* list, unsigned int index)
{
	return internal_removeTriangle(list, index, true);
}

bool removeTriangle(TriangleList* list, unsigned int index)
{
	return internal_removeTriangle(list, index, false);
}

bool addTriangle(TriangleList* list, Triangle3D* target)
{
	if(list == NULL ) return false;
	
	//first see if we can fill up a hole
	if(list->data_has_holes)
	{
		int i;
		for(i = 0;i < list->length; i++)
		{
			if(list->data[i] == NULL)
			{
				list->data[i] = target;
			}
			else
			{
				if(i == list->length-1) list->data_has_holes = false;
			}
		}
	}
	//else just add at the end
	else
	{
		//check if there is enough space and resize if necessary
		if(list->length+1 > list->MAX_SIZE) resizeTriangleList(list,list->length+1);
		
		list->data[list->length] = target;
		list->length++;
	}
	
	if(target == NULL)list->data_has_holes = true;
	
	return true;
}
