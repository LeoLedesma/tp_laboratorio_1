#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "modificaciones.h"

int modifyName(Employee* list, int index, char newName[])
{
	int todoOk = 0;

	if(list !=NULL && newName!=NULL)
	{
		strcpy(list[index].name, newName);

		todoOk = 1;
	}


	return todoOk;
}


int modifyLastname(Employee* list, int index, char newLastname[])
{
	int todoOk = 0;
	if(list != NULL && newLastname!=NULL)
		{
		strcpy(list[index].lastName, newLastname);

		todoOk = 1;
		}
	return todoOk;
}
int modifySalary(Employee* list, int index, float newSalary)
{
	int todoOk = 0;
	if(list != NULL)
		{
			list[index].salary = newSalary;
			todoOk = 1;
		}
	return todoOk;
}

int modifySector(Employee* list, int index, int newSector)
{
	int todoOk = 0;
	if(list !=NULL)
		{
			list[index].sector = newSector;
			todoOk = 1;
		}
	return todoOk;
}

int toUpperFirstLetterPhrase(char string [], int len)
{
    int todoOk=0;


    if(string!=NULL && len>0)
    {
        todoOk=1;
        strlwr(string);

        string[0]=toupper(string[0]);

        for(int i = 0; i<len; i++)
        {
            if(string[i] == ' ')
            {
            	string[i+1] = toupper(string[i+1]);
            }
        }
    }

return todoOk;
}

