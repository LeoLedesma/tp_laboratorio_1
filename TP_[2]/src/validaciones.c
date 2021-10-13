#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

#define TRUE 1
#define FALSE 0

int isString (char string[])
{
	int todoOk = 1;
	int stringTam = strlen(string);

	if(string!=NULL)
	{

		for(int i = 0; i<stringTam; i++)
		{
		if((!isalpha(string[i]) && string[i]!= ' '))
			{

					todoOk = 0;

					break;
			}

		}

	}

	return todoOk;
}


int isFloat(char entrada[]) //15000
{
	int todoOk = 1;
	int banderaPunto = 0;
	int stringTam = strlen(entrada);

	for(int i=0; i<stringTam ; i++)
	{
		if(entrada[i]=='.')
		{
			banderaPunto++;
		}

		if((!isdigit(entrada[i]) && entrada[i]!='.') || banderaPunto>1)
			{
				todoOk = 0;
				break;
			}

	}


	return todoOk;
}


int isInt(char entrada[])
{
    int todoOk = 1;
    int stringTam = strlen(entrada);


    	if (isdigit(entrada[0]) || (entrada[0]= '-' && stringTam > 1))
    	{

			for(int i = 1; i < stringTam; i++)
			{

					if (!isdigit(entrada[i]))
					{
						todoOk = 0;
						break;
					}
			}
    	}else
    	{
    		todoOk = 0;
    	}



    return todoOk;
}



