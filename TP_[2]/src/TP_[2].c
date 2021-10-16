#include "ArrayEmployees.h"


int main()
{
    setbuf(stdout, NULL);
    system("mode con cols=230 lines=1500 ");

    int nextId = 1;

    int todoOk;

    char confirmarSalir = 'n';

    int banderaAlta = 0;

    Employee lista[SIZE_LIST];

    initEmployees(lista, SIZE_LIST);


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
            confirmarSalir = getConfirmation("Seguro que quiere salir? (s/n): ", "ERROR. Ingreso caracter invalido. Seguro que quiere salir? (s/n): ");

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
                    printf("Ocurrio un error. Por favor intente nuevamente\n");
                }
                else if (todoOk==0)
                {
                    printf("No se modifico ningun empleado.\n");
                }
                else
                {
                    printf("Empleado modificado correctamente.\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta al menos un empleado para modificar.\n");
            }

            break;
        case 3:
            if(banderaAlta==TRUE)
            {
                todoOk = offEmployee(lista, SIZE_LIST);
                if(todoOk==-1)
                {
                    printf("Ocurrio un error. Por favor intente nuevamente.\n");
                }
                else if(todoOk==0)
                {
                    printf("No se dio de baja ningun empleado.\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta al menos un empleado para dar de baja.\n");
            }

            break;
        case 4:
            if(banderaAlta==TRUE)
            {
                menuPrintEmployees(lista, SIZE_LIST);
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
    }
    while(confirmarSalir=='n');

    return 0;
}
