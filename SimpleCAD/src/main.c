/*  Author: Dragos Iarovoi
    Product: Acta Non Verba
    */

/************
*			*
* Includes	*
*			*
*************/

#include "includes.c"

/****************
*				*
* Variables		*
*				*
*****************/
#include "global_variables.c"

/************
*			*
* Main		*
*			*
*************/
int main(int argc, char** argv)
{
	#include "setup.c"
	
	//Main Loop
		#include "main_loop.c"
	
	#include "clean_up.c"
	
	return 0;
}
