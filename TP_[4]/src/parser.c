#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int cant;
	Employee* auxEmployee;
	char* id = (char*) malloc(sizeof(char)*10);
	char* nombre = (char*) malloc(sizeof(char)*128);
	char* horasTrabajadas = (char*) malloc(sizeof(char)*10);
	char* sueldo = (char*) malloc(sizeof(char)*10);
	int nextId;
	char nextIdStr[10];

	if(pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);

		nextId = employee_getMaxId(pArrayListEmployee) + 1;

		while(!feof(pFile))
		{
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,horasTrabajadas,sueldo);

			if(cant<4)
			{
				break;
			}

			itoa(nextId, nextIdStr, 10);

			auxEmployee = employee_newParametros(nextIdStr, nombre, horasTrabajadas, sueldo);
			nextId++;

			if(auxEmployee!=NULL)
			{
				ll_add(pArrayListEmployee, auxEmployee);
				todoOk=1;
			}
		}
		fclose(pFile);
	}
return todoOk;
}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	Employee *auxEmployee = NULL;

	if (pArrayListEmployee != NULL && pFile != NULL)
	{
		while (!feof(pFile))
		{
			auxEmployee = employee_new();
			fread(auxEmployee, sizeof(Employee), 1, pFile);

			if (feof(pFile))
			{
				break;
			}

			ll_add(pArrayListEmployee, auxEmployee);
		}
		todoOk = 1;
		fclose(pFile);
	}

	return todoOk;
}
