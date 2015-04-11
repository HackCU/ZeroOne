/*  Author: Dragos Iarovoi
    Product: Acta Non Verba
    */

/****************
*				*
* Variables		*
*				*
*****************/
#include "variables.c"

/************
*			*
* Includes	*
*			*
*************/

#include "includes.c"

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
