#define TRIANGLELIST_CLUSTER_SIZE 64

typedef struct TriangleList
{
	Triangle3D* data;
	
	unsigned int length;
	unsigned int MAX_LENGTH;
}
TriangleList;

/************
*			*
* Init		*
*			*
************/
TriangleList* initTriangleList()
{
	TriangleList* list;
	
	list = malloc(sizeof(TriangleList));
	
	if(NULL == list )
	{
		log_error(TRIANGLELIST_INIT_ERROR);
		return NULL;
	}
	
	list->data	  = 0;
	list->length = 0;
	list->MAX_LENGTH  = ~1;
	
	return list;
}

/************
*			*
* Helpers	*
*			*
************/
bool setTriangleData(TriangleList* list, Triangle3D* target, int length)
{
	if(list == 0 || target == 0)return false;
	
	list->data = target;
	list->length = length;
	
	return true;
}

bool addTriangle(TriangleList* list, Triangle3D* target)
{
	
}

/************
*			*
* Clean up	*
*			*
************/
void triangle_list_clean_up(TriangleList* list)
{
	int i;
	for(i = 0; i < list->length; i++)
	{
		triangle_clean_up(&(list->data[i]));
	}
	
	free(&(list->length));
	free(&(list->MAX_LENGTH));
	free(&list);
}
