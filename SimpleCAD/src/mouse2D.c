typedef struct Mouse2D
{
	double x,y;
}
Mouse2D;

/************
*			*
*Init		*
*			*
************/
Mouse2D* init2DMouse()
{
	Mouse2D* mouse;
	
	mouse = malloc(sizeof(Mouse2D));
	
	if(NULL == mouse)
	{
		log_error(MOUSE2D_INIT_ERROR);
		return NULL;
	}
	
	mouse->x = 0;
	mouse->y = 0;
	
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
bool mouse2d_clean_up(Mouse2D* mouse)
{
	if(mouse == NULL) return false;
	
	free(mouse);
	
	return true;
}
