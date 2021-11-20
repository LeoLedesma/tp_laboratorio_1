#include "menu.h"

int menuOpciones()
{
	int opcion;
	system("cls");

	printf(	"                    ***    ABM EMPLEADOS EN GRUPO LEDESMA S.A    *** 	\n");
	printf(	"-----------------------------------------------------------------------------------------\n");
	printf("  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("  2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
	printf("  3. Alta de empleado.\n");
	printf("  4. Modificar datos de empleado.\n");
	printf("  5. Baja de empleado.\n");
	printf("  6. Listar empleados.\n");
	printf("  7. Ordenar empleados.\n");
	printf("  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("  9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
	printf(" 10. Iniciar testing de funciones Linkedlist.");
	printf(" 11. Salir\n");

	fflush(stdin);
	getInt("Por favor elija una opcion: ",
			"ERROR. Por favor elija una opcion (solo numeros): ", &opcion);

	return opcion;
}

int menuPrincipal(LinkedList *listaEmpleados)
{
	int todoOk = 0;
	int option;
	char salir = 'n';
	int flagLoad = 0;
	int flagSave = 0;
	int flagAdd = 0;
	int confirmation;

	if (listaEmpleados != NULL)
	{
		do
		{
			option = menuOpciones();
			switch (option)
			{
			case 1: //Abrir modo texto
				system("cls");

				if (flagAdd && !flagLoad) //Agrego sin cargar
						{
					printf(
							"Ya se ha realizado la carga de al menos un empleado de manera manual, Es probable que los ID de los nuevos empleados se vean afectados.\n");
					confirmation = getConfirmation("Desea continuar? (s/n): ",
							"ERROR. Desea continuar? (s/n): ");
					if (confirmation == 's') {
						if (controller_loadFromText("data.csv",
								listaEmpleados)==1) {
							flagLoad = 1;
							break;
						}
					}
				}

				if (flagLoad) //Ya cargo
				{
					confirmation =
							getConfirmation(
									"Ya se ha realizado una carga, Es probable que se dupliquen los empleados (s/n): ",
									"ERROR. Ya se ha realizado una carga, Es probable que se dupliquen los empleados. desea hacerlo nuevamente? (s/n): ");
					if (confirmation == 's') {
						if (controller_loadFromText("data.csv",
								listaEmpleados)==1) {
							flagLoad = 1;
						}
					}
				} else {
					if (controller_loadFromText("data.csv", listaEmpleados)==1)
					{
						flagLoad = 1;
					}
				}
				break;
			case 2: //Abrir modo binario
				system("cls");

				if(flagAdd && !flagLoad)
				{
					printf("Ya se ha realizado la carga de al menos un empleado de manera manual, Es probable que los ID de los nuevos empleados se vean afectados.\n");
					confirmation =
								getConfirmation(
										"Desea continuar? (s/n): ",
										"ERROR. Desea continuar? (s/n): ");
						if (confirmation == 's')
						{
							if(controller_loadFromBinary("data.bin", listaEmpleados)==1)
									{
									flagLoad = 1;
									break;
									}
						}
				}

				if (flagLoad)
				{
					confirmation =
							getConfirmation(
									"Ya se ha realizado una carga, Es probable que se dupliquen los empleados (s/n): ",
									"ERROR. Ya se ha realizado una carga, Es probable que se dupliquen los empleados. Desea hacerlo nuevamente? (s/n): ");
					if (confirmation == 's')
					{
						if(controller_loadFromBinary("data.bin", listaEmpleados) == 1)
						{
							flagLoad = 1;
						}
					}
				}
				else
				{
					if (controller_loadFromBinary("data.bin", listaEmpleados)==1)
					{
						flagLoad = 1;
					}
				}
				break;
			case 3: //alta
				system("cls");
				if (controller_addEmployee(listaEmpleados))
				{
					flagAdd = 1;
				}
				break;
			case 4: //modificar
				system("cls");
				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf(	"Primero debe cargar un empleado para poder modificarlo.\n");
				}

				break;
			case 5: //baja
				system("cls");
				if ((flagAdd || flagLoad) && (ll_len(listaEmpleados) > 0))
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un empleado para poder darlo de baja.\n");
				}
				break;
			case 6: //Listar
				system("cls");

				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un empleado para poder listar.\n");
				}
				break;
			case 7: //Ordenar
				system("cls");
				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un empleado para poder ordenar.\n");
				}

				break;
			case 8: //guardar modo texto
				system("cls");
				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_saveAsText("data.csv", listaEmpleados);
					flagSave = 1;
				}
				else
				{
					printf("Primero debe cargar un empleado para guardarlos.\n");
				}

				break;
			case 9: //guardar modo binario;
				system("cls");

				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_saveAsBinary("data.bin", listaEmpleados);
					flagSave = 1;
				}
				else
				{
					printf("Primero debe cargar un empleado para guardarlos.\n");
				}

				break;
			case 10:
					system("cls");
					startTesting(1);  // ll_newLinkedList //usada
					startTesting(2);  // ll_len //usada
					startTesting(3);  // getNode - test_getNode //aplicada
					startTesting(4);  // addNode - test_addNode //aplicada
					startTesting(5);  // ll_add
					startTesting(6);  // ll_get
					startTesting(7);  // ll_set
					startTesting(8);  // ll_remove
					startTesting(9);  // ll_clear
					startTesting(10); // ll_deleteLinkedList
					startTesting(11); // ll_indexOf
					startTesting(12); // ll_isEmpty
					startTesting(13); // ll_push
					startTesting(14); // ll_pop
					startTesting(15); // ll_contains
					startTesting(16); // ll_containsAll
					startTesting(17); // ll_subList
					startTesting(18); // ll_clone
					startTesting(19); // ll_sort
				break;
			case 11: //salir
				system("cls");
				if (((flagAdd && flagLoad) || flagAdd)
						&& ll_len(listaEmpleados) > 0 && !flagSave)
				{
					printf("　　ALERTA!!!!  　　ALERTA!!!!  　　ALERTA!!!!  \n");
					printf("Esta queriendo salir sin guardar los cambios. \n");

				}
				salir = getConfirmation("Esta seguro que desea salir? (s/n): ",
						"ERROR. Esta seguro que desea salir? (s/n): ");

				break;
			default:
				printf("Ingreso una opcion invalida. Vuelva a intentarlo.\n");
				break;
			}

				printf("Presione una tecla para continuar...\n");
				fflush(stdin);
				getchar();
				//system("pause"); //Rompe el pedido de opcion en consola de eclipse.
		} while (salir == 'n');

		todoOk=1;
	}

	return todoOk;
}

void mostrarGraficoEmpleado()
{
	printf(" __________________________________________________________________\n");
	printf("|  ID  |       Nombre        |  Horas trabajadas  |    Salario     |\n");
	printf("|______|_____________________|____________________|________________|\n");
}

int menuOrdenamiento()
{
	int option;

	printf("     ***   ORDENAR EMPLEADOS   ***\n");
	printf("---------------------------------------\n");
	printf("Como desea ordenar a los empleados? \n");

	printf("  1. Por ID\n");
	printf("  2. Por nombre\n");
	printf("  3. Por horas trabajadas\n");
	printf("  4. Por sueldo\n");
	printf("  5. Salir\n\n");

	getInt("Por favor elija una opcion:",
			"ERROR. Por favor elija una opcion (Solo numeros):", &option);
	return option;
}

int menuCriterioOrdenamiento()
{
	int option;
	printf("     ***   ORDENAR EMPLEADOS   ***\n");
	printf("---------------------------------------\n");
	printf("Como desea ordenar a los empleados? \n");
	printf("  1. Ascendente\n");
	printf("  2. Descendente\n");
	getInt("Por favor elija una opcion:",
			"ERROR. Por favor elija una opcion (Solo numeros):", &option);
	option--;

	return option;
}

int menuModificaciones()
{
	int option;
	printf("\n\n   1. Nombre\n");
	printf("   2. Horas trabajadas\n");
	printf("   3. Sueldo\n");
	printf("   4. Volver\n");

	getInt("Por favor elija una opcion: ",
			"ERROR. Por favor elija una opcion (solo numeros): ", &option);
	return option;
}
