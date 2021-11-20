#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna (0) si ocurrio un error al abrir el archivo, (1) si cargo exitosamente y (2) si hubo problema al cargar empleados.
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	char confirmation;
	int flag = 0;

	FILE *pFile = fopen(path, "r");

	if (pFile == NULL && path!=NULL)
	{
		confirmation = getConfirmation(
				"Archivo inexistente! Desea crear uno nuevo? (s/n): ",
				"ERROR. Archivo inexistente! Desea crear uno nuevo? (s/n): ");
		if (confirmation == 's')
		{
			pFile = fopen(path, "w");
			fclose(pFile);
			flag = 1;
		}
	}

	if (pFile != NULL && !flag && pArrayListEmployee)
	{
		if (parser_EmployeeFromText(pFile, pArrayListEmployee))
		{
			if(ll_len(pArrayListEmployee)>0)
			{
			printf("Empleados cargados con exito!\n");
			todoOk = 1;
			}else
			{
				printf("No habia empleados que cargar!\n");
				todoOk = 2;
			}
		}
		else
		{
			printf("Ocurrio un error al cargar los empleados!\n");
			todoOk = 2;
		}
		fclose(pFile);

	}

	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna (0) si ocurrio un error al abrir el archivo, (1) si cargo exitosamente y (2) si hubo problema al cargar empleados.
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{

	int todoOk = 0;
	char confirmation;
	int flag = 0;

	FILE *pFile = fopen(path, "rb");

	if (pFile == NULL && path!=NULL)
	{
		confirmation = getConfirmation(
				"Archivo inexistente! Desea crear uno nuevo? (s/n): ",
				"ERROR. Archivo inexistente! Desea crear uno nuevo? (s/n): ");
		if (confirmation == 's')
		{
			pFile = fopen(path, "wb");
			fclose(pFile);
			flag = 1;
		}
	}

	if (pFile != NULL && !flag && pArrayListEmployee)
	{
		if (parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			if(ll_len(pArrayListEmployee)>0)
			{
				printf("Empleados cargados con exito!\n");
				todoOk = 1;
			}else
			{
				printf("No habia empleados que cargar!\n");
				todoOk = 2;
			}
		}
		else
		{
			printf("Ocurrio un error al cargar los empleados!\n");
			todoOk = 2;
		}
	}
	else
	{
		if(!flag)
		{
			printf("Ocurrio un error al cargar el archivo!\n");
		}
	}

	fclose(pFile);

	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna (0) si ocurrio un error o no se agrego ningun empleado y (1) si se agrego un empleado.
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	Employee *auxEmpleado = NULL;

	int nextId;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	char horasTrabajadasStr[10];
	char sueldoStr[10];
	char nextIdStr[10];

	if (pArrayListEmployee != NULL)
	{
		printf("      *** ALTA DE EMPLEADO ***\n");
		printf("-----------------------------------\n");

		getString("Por favor ingrese el nombre del empleado: ",
				"ERROR. Por favor ingrese el nombre del empleado (Solo letras): ",
				nombre, 127);
		toUpperFirstLetterPhrase(nombre, sizeof(nombre));

		getInt("Por favor ingrese las horas trabajadas: ",
				"Por favor ingrese las horas trabajadas (solo numeros): ",
				&horasTrabajadas);

		itoa(horasTrabajadas, horasTrabajadasStr, 10);

		getInt("Por favor ingrese el sueldo: ",
				"ERROR.Por favor ingrese el sueldo (solo numeros): ", &sueldo);

		itoa(sueldo, sueldoStr, 10);

		nextId = employee_getMaxId(pArrayListEmployee) + 1;
		itoa(nextId, nextIdStr, 10);

		auxEmpleado = employee_newParametros(nextIdStr, nombre,
				horasTrabajadasStr, sueldoStr);

		if (auxEmpleado != NULL)
		{
			ll_add(pArrayListEmployee, auxEmpleado);
			printf("Empleado dado de alta con exito!!\n");
			todoOk = 1;

			auxEmpleado = NULL;
		}
		else
		{
			printf("Ocurrio un error al cargar el empleado. Intente nuevamente\n");
		}

	}

	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna (0) si ocurrio un error o no se modifico ningun empleado y (1) si se modifico un empleado.
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	int flag = 0;
	int indice;
	int idIngresado;
	int opcion;
	char nombre[128];
	int auxInt;
	char salir = 's';

	Employee* auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		printf("    ***    Modificacion de empleados    ***\n");
		printf("------------------------------------------------\n\n");
		controller_ListEmployee(pArrayListEmployee);

		getInt("Ingrese el ID del empleado que desea modificar: ",
				"ERROR. Ingrese el ID del empleado que desea modificar (solo numeros): ",
				&idIngresado);

		indice = controller_findEmployeeById(pArrayListEmployee, idIngresado);

		if (indice == -1)
		{
			printf("ERROR. ID inexistente, regresando al menu principal.\n");
		}
		else
		{
			system("cls");
			printf("    ***    Modificacion de empleados    ***\n");
			printf("------------------------------------------------\n\n");

			auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);

			printf("Que desea modificar de: \n");

			mostrarGraficoEmpleado();
			employee_mostrarEmpleado(auxEmployee);
			printf("|______|_____________________|____________________|________________|\n");

			do
			{
				opcion = menuModificaciones();

				switch (opcion)
				{
				case 1:
					getString("Por favor ingrese el nuevo nombre: ",
							"ERROR. Por favor ingrese el nuevo nombre (solo letras): ",
							nombre, 128);
					if(employee_setNombre(auxEmployee, nombre))
					{
						flag = 1;
					}
					break;
				case 2:
					getInt("Por favor ingrese las nuevas horas trabajadas: ",
							"ERROR. Por favor ingrese las nuevas horas trabajadas (Solo numeros): ",
							&auxInt);
					if(employee_setHorasTrabajadas(auxEmployee, auxInt)){
					flag = 1;
					}
					break;
				case 3:
					getInt("Por favor ingrese el nuevo sueldo: ",
							"ERROR. Por favor ingrese el nuevo sueldo (Solo numeros): ",
							&auxInt);
					if(employee_setSueldo(auxEmployee, auxInt))
					{
						flag = 1;
					}
					break;
				case 4:
					salir = getConfirmation(
							"Esta seguro que desea salir? (s/n): ",
							"ERROR. Esta seguro que desea salir? (s/n): ");
					break;
				default:
					printf(
							"Opcion ingresada incorrecta. Intente nuevamente.\n");
					salir = 'n';
					break;

				}
			} while (salir == 'n');

			if (flag)
			{
				if(ll_set(pArrayListEmployee, indice, auxEmployee))
				{
					printf("Empleado modificado con exito!!\n");
				}
			}
			auxEmployee = NULL;
		}
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	int indice;
	int idIngresado;
	char confirmacion;

	Employee* auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		printf("    ***    Baja de empleados    ***\n");
		printf("------------------------------------------------\n\n");
		controller_ListEmployee(pArrayListEmployee);

		getInt("Ingrese el ID del empleado que desea dar de baja: ",
				"ERROR. Ingrese el ID del empleado que dar de baja (solo numeros): ",
				&idIngresado);

		indice = controller_findEmployeeById(pArrayListEmployee, idIngresado);

		if (indice == -1)
		{
			printf("ERROR. ID inexistente, regresando al menu principal.\n");
		}
		else
		{
			system("cls");
			printf("    ***    Baja de empleados    ***\n");
			printf("------------------------------------------------\n\n");

			auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);

			mostrarGraficoEmpleado();
			employee_mostrarEmpleado(auxEmployee);

			confirmacion =
					getConfirmation(
							"Esta seguro que desea eliminar este empleado? (s/n): ",
							"ERROR. Esta seguro que desea eliminar este empleado? (s/n):");

			if (confirmacion == 's')
			{
				if (!ll_remove(pArrayListEmployee, indice))
				{
					printf("Empleado eliminado con exito!!\n");
				}
				else
				{
					printf("Ocurrio un error al eliminar el empleado!!\n");
				}
			}
			else
			{
				printf("Accion cancelada. Saliendo al menu principal");
			}
		}
		auxEmployee = NULL;
	}

	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	Employee* auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		printf(" __________________________________________________________________\n");
		printf("|                  *** Lista de empleados ***                      |\n");
		printf("|__________________________________________________________________|\n");
		printf("|  ID  |       Nombre        |  Horas trabajadas  |    Salario     |\n");
		printf("|______|_____________________|____________________|________________|\n");

		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			employee_mostrarEmpleado((auxEmployee));
		}
		printf("|______|_____________________|____________________|________________|\n");
		todoOk = 1;
		auxEmployee=NULL;

	}

	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	int option;
	char salir = 's';
	int criterio = 1;
	int (*sortEmployee)(void*, void*) = NULL;
	int flag=0;

	if (pArrayListEmployee != NULL)
	{
		do
		{
			option = menuOrdenamiento();

			if (option != 5) //Si la opcion no es salir
			{
				criterio = menuCriterioOrdenamiento();
			}

			switch (option)
			{
			case 1:
				sortEmployee = employee_compareById;
				break;
			case 2:
				sortEmployee = employee_compareByName;
				break;
			case 3:
				sortEmployee = employee_compareByHours;
				break;
			case 4:
				sortEmployee = employee_compareBySalary;
				break;
			case 5:
				salir = getConfirmation("Esta seguro que desea salir? (s/n): ",
						"ERROR. Esta seguro que desea salir? (s/n): ");
				flag=1;
				break;
			}
			if(!flag)
			{
				printf("Ordenando, aguarde un instante...");

				if(!ll_sort(pArrayListEmployee, sortEmployee, criterio))
				{
					system("cls");
					printf("Ordenados con exito!\n\n");
					controller_ListEmployee(pArrayListEmployee);
				}
			}
		} while (salir == 'n');

	}

	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	int cant;
	FILE *fPath = fopen(path, "w");
	Employee *auxEmployee = NULL;

	if (pArrayListEmployee != NULL && fPath != NULL)
	{
		fprintf(fPath, "ID,Nombre,Horas trabajadas,Sueldo\n");

		cant = ll_len(pArrayListEmployee);
		for (int i = 0; i < cant; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			if (auxEmployee != NULL)
			{

				fprintf(fPath, "%d,%s,%d,%d\n", auxEmployee->id,
						auxEmployee->nombre, auxEmployee->horasTrabajadas,
						auxEmployee->sueldo);
			}
		}
		todoOk = 1;
		printf("Archivo guardado con exito!\n");
		fclose(fPath);
		auxEmployee = NULL;
	}
	else
	{
		printf("Ocurrio un error al guardar el archivo!\n");
	}

	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	int todoOk = 0;
	Employee *auxEmployee = NULL;
	FILE *fPath = fopen(path, "wb");
	int cant;
	int flag = 0;

	int tam = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL && fPath != NULL && tam>0)
	{
		for (int i = 0; i < tam; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);

			//printf("%d", i);

			cant = fwrite(auxEmployee, sizeof(Employee), 1, fPath);

			if (cant < 1)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
		{
			printf("Ocurrio un error al guardar el archivo!\n");
		}
		else
		{
			printf("Archivo guardado con exito!\n");
			todoOk=1;
		}

		fclose(fPath);
		fPath = NULL;

	}

	return todoOk;
}

int controller_findEmployeeById(LinkedList *pArrayListEmployee, int id)
{
	int indice = -1;
	Employee *auxEmployee;
	int tam;
	int idActual;
	int cant;

	if (pArrayListEmployee != NULL && id > 0)
	{
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			if (auxEmployee != NULL) //Si existe
			{
				cant = employee_getId(auxEmployee, &idActual);

				if (cant && idActual == id) //Si me devolvio y el id actual es igual al ingresado
				{
					indice = i;
					break;
				}
			}
		}
	}

	return indice;
}
