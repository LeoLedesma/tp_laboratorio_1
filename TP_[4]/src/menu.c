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
	printf("  5. Insertar un nuevo empleado en una posicion.\n");
	printf("  6. Baja de empleado.\n");
	printf("  7. Listar empleados.\n");
	printf("  8. Ordenar empleados.\n");
	printf("  9. Crear sublista de empleados en un rango.\n");
	printf(" 10. Comparar lista de empleados y sublista.\n");
	printf(" 11. Eliminar todos los empleados de sublista.\n");
	printf(" 12. Validar si la lista esta vacia.\n");
	printf(" 13. Clonar lista.\n");
	printf(" 13. Mover empleado.\n");
	printf(" 15. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf(" 16. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
	printf(" 17. Iniciar testing de funciones Linkedlist.\n");

	printf(" 18. Salir\n");

	fflush(stdin);
	getInt("Por favor elija una opcion: ",
			"ERROR. Por favor elija una opcion (solo numeros): ", &opcion);

	return opcion;
}

int menuPrincipal(LinkedList *listaEmpleados, LinkedList *sublistaEmpleados, LinkedList* listaClonada)
{
	int todoOk = 0;
	int option;
	char salir = 'n';
	int flagLoad = 0;
	int flagSave = 0;
	int flagAdd = 0;
	int flagSublist = 0;
	int flagClonada = 0;
	int confirmation;
	int auxInt;

	LinkedList* listaSeleccionada = NULL;
	LinkedList* listaSeleccionada2 = NULL;

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
			case 5: //Insertar un nuevo empleado en una posicion.
				system("cls");
				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 0)
				{
					controller_addEmployeeIndex(listaEmpleados);
				}
				else
				{
					printf(	"Primero debe cargar un empleado para utilizar esta opcion.\n");
				}

				break;
			case 6: //baja
				system("cls");

				listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);



				if(listaSeleccionada!=NULL)
				{
					if ((flagAdd || flagLoad) && (ll_len(listaSeleccionada) > 0))
					{
						controller_removeEmployee(listaSeleccionada);
					}
					else
					{
						printf("Primero debe cargar un empleado para poder darlo de baja.\n");
					}
				}else
				{
					printf("Es probable que la lista no haya sido creada.\n");
				}

				break;
			case 7: //Listar
				system("cls");
				listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);


				if(listaSeleccionada!=NULL)
				{

					if (ll_len(listaSeleccionada) > 0)
					{
						controller_ListEmployee(listaSeleccionada);
					}
					else
					{
						printf("Primero debe cargar un empleado para poder listar.\n");
					}
				}else
				{
					printf("Es probable que la lista no haya sido creada.\n");
				}
				break;
			case 8: //Ordenar
				system("cls");
				listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);

				if(listaSeleccionada!=NULL)
				{
					if ((flagAdd || flagLoad) && ll_len(listaSeleccionada) > 0)
					{
						controller_sortEmployee(listaSeleccionada);
					}
					else
					{
						printf("Primero debe cargar un empleado para poder ordenar.\n");
					}
				}else
				{
					printf("Es probable que la lista no haya sido creada.\n");
				}

				break;
			case 9: //Crear sublista de empleados en un rango.
				if ((flagAdd || flagLoad) && ll_len(listaEmpleados) > 2)
				{
					sublistaEmpleados = controller_createSubList(listaEmpleados);

						if(sublistaEmpleados!=NULL)
						{
							printf("La lista no es null\n");
							flagSublist = 1;
						}else
							{
							printf("la lista es null\n");
							}
				}
				else
				{
					printf("Primero debe cargar al menos dos empleado para poder crear una sublista.\n");
				}
				break;
			case 10: //Comparar lista de empleados y sublista.
				system("cls");
				if ((flagAdd || flagLoad) || flagSublist || flagClonada)
				{
					listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);
					listaSeleccionada2 = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);

					if(listaSeleccionada!=NULL && listaSeleccionada2!=NULL)
					{

						if(listaSeleccionada!=listaSeleccionada2)
						{
							auxInt = ll_containsAll(listaSeleccionada, listaSeleccionada2);

							if(auxInt==1)
							{
								printf("Las listas son iguales.\n");
							}
							else if (!auxInt)
							{
								printf("Las listas no son iguales.\n");
							}
						}else
						{
							printf("No se puede comparar una lista entre si.\n");
						}
					}else
					{
						printf("Es probable que la lista no haya sido creada.\n");
					}

				}
				else
				{
					printf("Primero debe tener cargadas las listas seleccionadas\n");
				}


				break;
			case 11: //Eliminar todos los empleados de sublista.


				if(!ll_isEmpty(sublistaEmpleados))
				{
					ll_clear(sublistaEmpleados);
				}else
				{
					printf("La lista ya esta vacia.\n");
				}

				break;
			case 12: //Validar si la lista esta vacia.

				if(!ll_isEmpty(sublistaEmpleados))
				{
					printf("La lista NO esta vacia.\n");
				}else
				{
					printf("La lista ya esta vacia.\n");
				}

				break;
			case 13://mover empleado

				printf("Por favor seleccione la lista de origen.\n");
				listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);
				printf("Por favor seleccione la lista de destino.\n");
				listaSeleccionada2 = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);

				if(listaSeleccionada!=NULL && listaSeleccionada2!=NULL && listaSeleccionada!=listaSeleccionada2)
				{
					controller_moveEmployee(listaSeleccionada, listaSeleccionada2);

				}


				break;

			case 14://clonas lista
				listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);
				if(!ll_isEmpty(listaSeleccionada))
					{
						ll_clone(listaSeleccionada);
					}
				break;

			case 15: //guardar modo texto
				system("cls");
				if ((flagAdd || flagLoad) || flagClonada || flagSublist)
				{
					listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);

					controller_saveAsText("data.csv", listaSeleccionada);
					flagSave = 1;
				}
				else
				{
					printf("Primero debe cargar un empleado para guardarlos.\n");
				}

				break;
			case 16: //guardar modo binario;
				system("cls");

				if ((flagAdd || flagLoad) || flagClonada || flagSublist)
				{
					listaSeleccionada = controller_getList(listaEmpleados, sublistaEmpleados, listaClonada);

					controller_saveAsBinary("data.bin", listaSeleccionada);
					flagSave = 1;
				}
				else
				{
					printf("Primero debe cargar un empleado para guardarlos.\n");
				}

				break;
			case 17:
				system("cls");
				/*startTesting(1);  // ll_newLinkedList //usada
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
				startTesting(19); // ll_sort*/
				break;
			case 18: //salir
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
