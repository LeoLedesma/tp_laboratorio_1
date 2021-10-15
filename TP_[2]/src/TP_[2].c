#include "ArrayEmployees.h"


int main()
{
    setbuf(stdout, NULL);
    system("mode con cols=230 lines=1500 ");

    int nextId = 1;

    int todoOk;

    char confirmarSalir = 'n';

    int banderaAlta = 0;

    Employee lista[SIZE_LIST] = {{1, "Leonel", "Ledesma", 15000, 1, 0}, {2, "Micaelaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "Schlemender", 18000, 1, 0}, {3, "Juan Carlos", "Ballestreti", 18000, 3, 0}};

    initEmployees(lista, SIZE_LIST);

    lista[0].isEmpty = 0;
    lista[1].isEmpty = 0;
    lista[2].isEmpty = 0;
    banderaAlta = 1;

    do
    {
    	 system("cls");
    	printf("--------------------------------\n");
        printf("     *** ABM Empleados ***\n");
        printf("--------------------------------\n");

        fflush(stdin);
        switch(menuEmployees())
        {
        case 0:
        	confirmarSalir = getConfirmation("Seguro que quiere salir? (s/n", "ERROR. Ingreso caracter invalido. Seguro que quiere salir? (s/n)");

            break;
        case 1:
        	todoOk = getDataEmployee(lista, SIZE_LIST, nextId);
        	if(todoOk==0)
        	{
        		nextId++;
        		banderaAlta=TRUE;
        	}

            break;

        case 2:
            if(banderaAlta==TRUE)
            {
            	todoOk = modifyEmployee(lista, SIZE_LIST, SIZE_STRING);
            	if(todoOk==-1)
				{
            		printf("Ocurrio un error. Por favor intente nuevamente");
				}else
				{
					printf("Empleado modificado correctamente.");
				}
            }else
            {
            	printf("Primero debe dar de alta al menos un empleado para modificar.\n");
            }

            break;
        case 3:
            if(banderaAlta==TRUE)
            {
            	if(!offEmployee(lista, SIZE_LIST))
            		{
            		printf("Ocurrio un error. Por favor intente nuevamente");
            		}
            }else
            {
                printf("Primero debe dar de alta al menos un empleado para dar de baja.\n");
            }

            break;
        case 4:
            if(banderaAlta==TRUE)
            {
            	menuPrintEmployees(lista, SIZE_LIST);
            	/*ordenado = sortEmployees(lista, SIZE_LIST, 0);

            	if(ordenado==0)
            	{
            		printEmployees(lista, SIZE_LIST);
					//Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
					printf("\n\nEl monto total de salarios es: $%.2f.\n", totalSalaryEmployees(lista, SIZE_LIST));
					printf("El promedio de los salarios es $%.2f.\n", getMedianSalaryEmployees(lista, SIZE_LIST));
					printf("La cantidad de empleados que superan el salario promedio es de: %d.\n", getEmployeesUpMedianSalary(lista, SIZE_LIST));
            	}else
            	{
            		printf("Ocurrio un error.");
            	}

            	 	 */
            }
            else
            {
            	printf("Primero debe dar de alta al menos un empleado para informar.");
            }
            break;

        default:
            printf("Opcion invalida, a continuacion elija una opcion correcta.\n");
            break;

        }

        system("pause");
        fflush(stdin);
    }while(confirmarSalir=='n');

    return 0;
}



