#include "ArrayEmployees.h"



int menuEmployees()
{

    int opcion;
    fflush(stdin);
    printf("1) Alta de empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja de empleado\n");
    printf("4) Informar\n\n");
    printf("0) Salir\n");
    getInt("Por favor seleccione una opcion: ", "ERROR. seleccione una opcion (solo numeros): " , &opcion);
    fflush(stdin);
    return opcion;
}

int menuPrintEmployees(Employee* list, int len)
{
	int todoOk=-1;
	int opcion;
	char salir;

	int banderaPromedio=FALSE;

	do
	{
	system("cls");

	printf("------------------------------------------------------\n");
	printf("    	     *** Informar Empleados ***\n");
	printf("------------------------------------------------------\n");
	printf("Que quiere mostrar??\n");
	printf("1) Empleados ordenados alfabeticamente de forma ascendente (A-Z).\n");
	printf("2) Empleados ordenados alfabeticamente de forma descendente (Z-A).\n");
	printf("3) Total de salarios y el promedio general.\n");
	printf("4) Cantidad de empleados con salario superior al promedio.\n");
	printf("0) Salir.\n");
	fflush(stdin);
	getInt("Por favor,  elija una opcion: ", "ERROR, elija una opcion (solo numeros", &opcion);


	switch(opcion)
	{
	case 1:
		system("cls");
		sortEmployees(list,len,0);
		todoOk = printEmployees(list, len);
		system("pause");
		break;
	case 2:
		system("cls");
		sortEmployees(list,len,1);
		todoOk = printEmployees(list, len);
		system("pause");
		break;
	case 3:
		system("cls");
		printf("\n\nEl monto total de salarios es: $%.2f.\n", totalSalaryEmployees(list, SIZE_LIST));
		printf("El promedio de los salarios es $%.2f.\n", getMedianSalaryEmployees(list, SIZE_LIST));
		banderaPromedio=TRUE;
		todoOk=1;
		system("pause");
		break;
	case 4:
		if(banderaPromedio==TRUE)
		{

			printf("La cantidad de empleados que superan el salario promedio es de: %d.\n", getEmployeesUpMedianSalary(list, SIZE_LIST));
			system("pause");
		}else
		{
			printf("Primero debe mostrar promedios (opcion 3).\n");
			todoOk=0;
			system("pause");
		}

		break;
	case 0:
		salir = getConfirmation("Seguro que desea salir? (s/n)", "ERROR. Seguro que desea salir? (s/n)");
		salir = tolower(salir);
		if(salir=='s')
		{
			printf("Saliendo al menu principal.\n");
		}
		todoOk=0;
		break;
	default:
		printf("ERROR. No eligio una opcion correcta.\n");
		break;
	}
	}while(salir!='s');

	return todoOk;
}

int getDataEmployee(Employee* list, int len, int nextId)
{
	int todoOk;

	char nombre[SIZE_STRING];
	char apellido[SIZE_STRING];
	float salario;
	int sector;

	int empty;

	empty = findEmpty(list, len);

	if(empty!=-1)
	{
		system("cls");
		printf("----------------------------------------------------------------\n");
		printf("                    *** Alta Empleados ***\n");
		printf("----------------------------------------------------------------\n");


		getString("Por favor ingrese nombre del empleado: ", "ERROR. Ingrese nombre del empleado (no debe contener numeros ni superar los 50 caracteres): ", nombre, SIZE_STRING);
		getString("Por favor ingrese apellido del empleado: ", "ERROR. Ingrese apellido del empleado (no debe contener numeros ni superar los 50 caracteres): ", apellido, SIZE_STRING);
		getFloat("Por favor ingrese el salario del empleado: ", "ERROR. Por favor ingrese un salario valido del empleado: ", &salario);
		getInt("Ingrese sector del empleado: ", "ERROR. Ingrese sector del empleado (solo numeros): ", &sector);
		todoOk = addEmployee(list, len, nextId, nombre, apellido, salario, sector);
		if(todoOk!=0)
			{
				printf("Ocurrio un error al agregar el empleado");
			}else
			{
				printf("Empleado cargado correctamente. Su ID es %d.\n", nextId);
			}

	}else
	{
		printf("No hay mas lugar para cargar empleados.");
	}
        return todoOk;

}




int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int todoOk = -1;
	int index;
	Employee auxiliar;

			if(list!=NULL && len>0 && name!=NULL && lastName!=NULL)
			{
				index = findEmpty(list, len);

				if(index!=-1)
				 {
					  toUpperFirstLetterPhrase(name, strlen(name));
					  toUpperFirstLetterPhrase(lastName, strlen(name));

						auxiliar.id = id;
						strcpy(auxiliar.name, name);
						strcpy(auxiliar.lastName, lastName);
						auxiliar.salary=salary;
						auxiliar.sector=sector;
						auxiliar.isEmpty=FALSE;

						list[index] = auxiliar;

					}

				todoOk=0;
			}
			return todoOk;
}

int printEmploye(Employee list)
{
int todoOk = 0;


if(!list.isEmpty){
printf("|%4d  |%-50s  |%-50s  |$%-21.2f|  %2d    |\n",
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
	int todoOk = -1;


	if(list!=NULL && length>0)
	{

			printf(" ________________________________________________________________________________________________________________________________________________\n");
			printf("|                                                      *** Lista de empleados ***                                                                |\n");
			printf("|________________________________________________________________________________________________________________________________________________|\n");
			printf("|  ID  |                       Nombre                       |                      Apellido                      |       Salario        | Sector |\n");
			printf("|______|____________________________________________________|____________________________________________________|______________________|________|\n");
			for(int i = 0; i< length; i++)
			{
				if(!list[i].isEmpty)
				{
				printEmploye(list[i]);
				}
			}
			printf("|______|____________________________________________________|____________________________________________________|______________________|________|\n");
			todoOk = 1;


	}


return todoOk;
}

int sortEmployees(Employee* list, int len, int order)
{
	int todoOk = -1;
	Employee auxEmployee;

	if(list != NULL && len>0)
	{
		if(order) //descendente
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

					}
				}
			}
			}else //ascendente
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


								}
							}
						}
			}
		todoOk = 0;
	}

	return todoOk;
}

int findEmployeeById(Employee* list, int len, int id)
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

//-----------INFORMACION DE EMPLEADOS--------------
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


//--------------PEDIDO DE DATOS DE EMPLEADOS-----------

int getIdEmployee(Employee* list, int len)

{int index;
int id;

if(list!=NULL && len>0)
{
	getInt("Por favor ingrese el ID del empleado: ", "ERROR. Ingrese el ID del empleado (solo numeros): ", &id);

	index = findEmployeeById(list, len, id);


		while(index == -1)
		{
			getInt("El ID ingresado no fue encontrado. Por favor ingrese nuevamente el ID del empleado: ", "ERROR. Ingrese el ID del empleado (solo numeros): ", &id);
			index = findEmployeeById(list, len, id);
		}

}

	return id;
}

int modifyEmployee(Employee* list, int len, int lenName)
{

	int todoOk = -1;
	int printOk;
	int confirmarId;
	int opcion = 0;
	int id;
	int indice;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	Employee auxEmployee[1];
	initEmployees(auxEmployee, 1);

	if(list!=NULL && len>0)
	{
	do
	{
	system("cls");
	printf("--------------------------------\n");
	printf("     *** Modificar empleado ***\n");
	printf("--------------------------------\n");

	id = getIdEmployee(list, len);
	indice = findEmployeeById(list, len, id);

	auxEmployee[0] = list[indice];

	printOk = printEmployees(auxEmployee, 1);

	if(printOk==1)
	{
		confirmarId = getConfirmation("Los datos del empleado son los correctos? s/n: ", "ERROR. Los datos del empleado son los correctos? s/n: ");
		confirmarId = tolower(confirmarId);
	}
	else
	{
		printf("Ocurrio un error.");
	}



	}while(confirmarId=='n');

	fflush(stdin);
	do
	{
			system("cls");
			printf("--------------------------------\n");
			printf("     *** Modificar empleado ***\n");
			printf("--------------------------------\n");

			printf("Que desea modificar de: \n");

			printEmployees(auxEmployee, 1);

			printf("\n1. Nombre.\n");
			printf("2. Apellido.\n");
			printf("3. Salario.\n");
			printf("4. Sector.\n");
			printf("0. Salir.\n");

			fflush(stdin);
			getInt("Por favor, elija una opcion: ","ERROR. Por favor, elija una opcion (solo numeros): ", &opcion);

			switch(opcion)
			{
			case 1:

				getString("Por favor ingrese el nombre del empleado: ", "ERROR. Ingrese nuevamente nombre del empleado", nombre, lenName);

				if(modifyName(list, indice, nombre))
				{
					printf("Nombre modificado con exito.\n");
					todoOk = 1;
				}
				else
				{
					printf("Ocurrio un error al modificar el nombre. Intente nuevamente.\n");
				}

				break;
			case 2:

				getString("Por favor ingrese el apellido del empleado: ", "ERROR. Ingrese nuevamente apellido del empleado", apellido, lenName);
				printf("apellido: %s", apellido);
				if(modifyLastname(list, indice, apellido))
				{
					printf("Apellido modificado con exito.\n");
					todoOk = 1;
				}
				else
				{
					printf("Ocurrio un error al modificar el apellido. Intente nuevamente.\n");
				}

				break;
			case 3:
				getFloat("Por favor ingrese el nuevo salario del empleado: ", "ERROR. Por favor ingrese el nuevo salario del empleado: ", &salario);
				if(modifySalary(list, indice, salario))
				{
					printf("Salario modificado con exito.\n");
					todoOk = 1;
				}
				else
				{
					printf("Ocurrio un error al modificar el nombre. Intente nuevamente.\n");
				}

				break;
			case 4:
				getInt("Por favor ingrese el nuevo sector del empleado: ", "ERROR. Por favor ingrese el nuevo sector del empleado: ", &sector);
				if(modifySector(list, indice, sector))
				{
					printf("Sector modificado con exito.\n");
					todoOk = 1;
				}
				else
				{
					printf("Ocurrio un error al modificar el sector. Intente nuevamente\n");
				}

				break;
			case 0:
				todoOk = 0;
				printf("Saliendo al menu principal.\n");
				break;
			default:
				opcion = -1;
				printf("ERROR. Elija una opcion correcta.\n");
				system("pause");
				break;
			}

		}while(opcion==-1);
	}

	return todoOk;
}

//------------MODIFICACIONES DE EMPLEADOS

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


int offEmployee(Employee* list, int len)
{
	system("cls");
	char confirmar;
	int idPedido;

	int indice;
	int todoOk = 0;
	int removidoExitoso;
	Employee auxEmployee[1];
	initEmployees(auxEmployee, 1);

	printf("--------------------------------\n");
	printf("     *** Baja de empleados ***\n");
	printf("--------------------------------\n");

	if(list!=NULL && len>0)
	{

	do{
	idPedido = getIdEmployee(list, len);
	indice = findEmployeeById(list, len, idPedido);

	if(indice!=-1)
	{

		auxEmployee[0] = list[indice];

		printEmployees(auxEmployee, 1);

			fflush(stdin);
		confirmar = getConfirmation("Los datos del empleado son los correctos? s/n: ", "ERROR. Los datos del empleado son los correctos? s/n: ");
		confirmar = tolower(confirmar);

	}else
	{
		printf("Ocurrio un error. Intente nuevamente");
	}

	}while(confirmar!='s');


	removidoExitoso = removeEmployee(list, len, idPedido);
	if(removidoExitoso==0)
	{
		todoOk = 1;
		printf("Empleado dado de baja con exito.\n");
	}

	}

return todoOk;
}

int modifyName(Employee* list, int index, char newName[])
{
	int todoOk = 0;
		if(list != NULL && newName!=NULL)
			{
			toUpperFirstLetterPhrase(newName, strlen(newName));
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
		toUpperFirstLetterPhrase(newLastname, strlen(newLastname));
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

int findEmpty(Employee* lista, int tam)
{
    int indice = -1;

    if(lista!=NULL && tam>0)
    {

       for (int i = 0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }

        }
}
return indice;
}

