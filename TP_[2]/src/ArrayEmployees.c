#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "modificaciones.h"


#define TRUE 1
#define FALSE 0


int initEmployees(Employee* list, int len)
{
	int todoOk = -1;

	if(list!= NULL && len>0)
	{
		todoOk = 0;

		for(int i = 0; i<len; i++)
		{
		list[i].isEmpty = TRUE;
		}

	}

	return todoOk;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)

{
	int todoOk = -1;
	Employee auxiliar;

			if(list!=NULL && len>0 && name!=NULL && lastName!=NULL)
			{
				for(int i = 0; i<len; i++)
				{

				 if(list[i].isEmpty)
				 {
					  toUpperFirstLetterPhrase(name, strlen(name)+1);
					  toUpperFirstLetterPhrase(lastName, strlen(name)+1);

						auxiliar.id = id;
						strcpy(auxiliar.name, name);
						strcpy(auxiliar.lastName, lastName);
						auxiliar.salary=salary;
						auxiliar.sector=sector;
						auxiliar.isEmpty=FALSE;


						list[i] = auxiliar;
						printf("Empleado cargado correctamente. Su ID es %d.\n", id);
						break;
					}

				}

				todoOk=0;
			}
			return todoOk;
}

int printEmploye(Employee list)
{
int todoOk = 0;

if(!list.isEmpty){
printf("|%04d  |%-50s  |%-50s  |$%.2f\t\t|%3d\t|\n",
		list.id,
		list.name,
		list.lastName,
		list.salary,
		list.sector);
}

return todoOk;
}


int printEmployees(Employee* list, int length)
{
	int todoOk = -1;//
	printf(" _______________________________________________________________________________________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t*** Lista de empleados ***\t\t\t\t\t\t\t\t|\n");
	printf("|_______________________________________________________________________________________________________________________________________________|\n");
	printf("|ID    |Nombre\t\t\t\t\t\t    |Apellido\t\t\t\t\t\t |Salario\t\t|Sector\t|\n");
	printf("|______|____________________________________________________|____________________________________________________|______________________|_______|\n");

	if(list!=NULL && length>0)
	{
		sortEmployees(list, length, 1);
		for(int i = 0; i< length; i++)
		{
			if(!list[i].isEmpty)
			{
			printEmploye(list[i]);
			}
		}
		printf("|______|____________________________________________________|____________________________________________________|______________________|_______|\n");
	}


return todoOk;
}

int sortEmployees(Employee* list, int len, int order)
{
	int todoOk = -1;
	Employee auxEmployee;


	if(list != NULL && len>0)
	{
		if(order)
		{
			for(int i = 0; i<len-1; i++)
			{
				for( int j = i+1; j<len; j++)
				{
			if((strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector < list[j].sector)
					|| strcmp(list[i].lastName, list[j].lastName)<0)
					{
						auxEmployee = list[i];
						 list[i] = list[j];
						 list[j] = auxEmployee;

						 todoOk = 0;
					}
				}
			}
		}else
		{
			for(int i = 0; i<len-1; i++)
						{
							for( int j = i+1; j<len; j++)
							{
						if((strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector > list[j].sector)
								|| strcmp(list[i].lastName, list[j].lastName)>0)
								{
									auxEmployee = list[i];
									 list[i] = list[j];
									 list[j] = auxEmployee;

									 todoOk = 0;
								}
							}
						}
		}

	}


	return todoOk;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index = -1;

	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==FALSE)
			{
				index = i;
				break;
			}

		}

	}

	return index;
}

int removeEmployee(Employee* list, int len, int id)
{
	int todoOk = -1;

	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len; i++)
		{
			if(list[i].id==id && list[i].isEmpty==FALSE)
			{
				list[i].isEmpty=TRUE;
				todoOk=0;
			}

		}

	}

	return todoOk;
}

///Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
float totalSalaryEmployees(Employee* list, int len)
{
	float totalSalary = 0;

	if(list!=NULL && len>0)
	{

	for(int i = 0; i<len; i++)
	{
		if(list[i].isEmpty==FALSE)
		{
		totalSalary+= list[i].salary;
		}
	}


	}
	return totalSalary;
}

float getMedianSalaryEmployees(Employee* list, int len)
{
	int medianSalary = 0;
	int totalEmployees = 0;
	if(list!=NULL && len>0)
	{
		for(int i = 0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				totalEmployees++;
			}

		}
	medianSalary = totalSalaryEmployees(list, len)/totalEmployees;

	}
		return medianSalary;
}

int getEmployeesUpMedianSalary(Employee* list, int len)
{
	int employeesUpMedianSalary = 0;
	if(list!=NULL && len>0)
		{


		for(int i = 0; i<len; i++)
		{
			if(list[i].isEmpty==FALSE && list[i].salary>(getMedianSalaryEmployees(list, len)))
			{
				employeesUpMedianSalary++;
			}
		}


		}
		return employeesUpMedianSalary;
}
