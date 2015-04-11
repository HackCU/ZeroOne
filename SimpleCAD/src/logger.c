#define CAMERA_INIT_ERROR __LINE__
#define TRIANGLE_INIT_ERROR __LINE__
#define TRIANGLELIST_INIT_ERROR __LINE__
#define OBJECT_INIT_ERROR __LINE__
#define POINT_INIT_ERROR __LINE__
#define POINTCLOUD_INIT_ERROR __LINE__


typedef struct log_node
{
	struct log_node* previous;
	int error;
	struct log_node* next;
}
log_node;

typedef struct Logger
{
	log_node* head;
	log_node* tail;
}
Logger;

Logger* logger;

void start_logger()
{
	logger = malloc(sizeof(Logger));
}

/****************
*				*
*Helpers		*
*				*
****************/
void log_error(int error_code)
{
	log_node* node = malloc(sizeof(log_node));
	
	node->error = error_code;
	
	//if first node ever
	if(logger->head == NULL)
	{
		logger->head = node;
		logger->tail = node;
		return;
	}
	
	/****************/
	
	
	node->previous = logger->tail;
	node->next = NULL;
	
	/****************/
	logger->tail->next = node;
	logger->tail = node;
}

int log_getError()
{
	return logger->tail->error;
}

void log_print_out_Error_Codes()
{
	
}

/************
*			*
*Clean up	*
*			*
************/

void stop_logger()
{
	free(logger);
}
