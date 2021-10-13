#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "entradas.h"
#include "modificaciones.h"

#define TRUE 1
#define FALSE 0
#define SIZE_LIST 1000 //max 1000
#define SIZE_STRING 51


int main()
{
    setbuf(stdout, NULL);

    int nextId = 1;
    char nombre[SIZE_STRING];
    char apellido[SIZE_STRING];
    float salario;
    int sector;

    int buscarId;
    int indice;
    char confirmar = 'n';
    char confirmarSalir = 'n';
    int opcion = -1;

    int banderaAlta = 0;

    Employee lista[SIZE_LIST];// = {{1, "Leonel", "Ledesma", 15000, 1, 0}, {2, "Micaelaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "schlemender", 18000, 1, 0}, {3, "Juan Carlos", "Ballestreti", 18000, 3, 0}};

    initEmployees(lista, SIZE_LIST);

    /*lista[0].isEmpty=FALSE;
    lista[1].isEmpty=FALSE;
    lista[2].isEmpty=FALSE;
    banderaAlta=1;*/

    do
    {
    	 system("cls");
    	printf("--------------------------------\n");
        printf("     *** ABM Empleados ***\n");
        printf("--------------------------------\n");

        fflush(stdin);
        switch(menuOpciones())
        {
        case 0:

            printf("Seguro que quiere salir? (s/n)");
            fflush(stdin);
            scanf("%c", &confirmarSalir);
            confirmarSalir = tolower(confirmarSalir);

            while(confirmarSalir!='s' && confirmarSalir != 'n')
            {
                printf("ERROR. Ingreso caracter invalido.\n");
                printf("Seguro que quiere salir? (s/n)");
                fflush(stdin);
                scanf("%c", &confirmarSalir);
                confirmarSalir = tolower(confirmarSalir);
            }
            break;
        case 1:
            system("cls");
            printf("--------------------------------\n");
            printf("     *** Alta Empleados ***\n");
            printf("--------------------------------\n");


            getString("Por favor ingrese nombre del empleado: ", "ERROR. Ingrese nombre del empleado (no debe contener numeros ni superar los 50 caracteres): ", nombre, SIZE_STRING);
            getString("Por favor ingrese apellido del empleado: ", "ERROR. Ingrese apellido del empleado (no debe contener numeros ni superar los 50 caracteres): ", apellido, SIZE_STRING);
            getFloat("Por favor ingrese el salario del empleado: ", "ERROR. Por favor ingrese un salario valido del empleado: ", &salario);
            getInt("Ingrese sector del empleado: ", "ERROR. Ingrese sector del empleado (solo numeros): ", &sector);
            addEmployee(lista, SIZE_LIST, nextId, nombre, apellido, salario, sector);


            banderaAlta=TRUE;
            nextId++;

            break;

        case 2:
            if(banderaAlta==TRUE)
            {
                system("cls");
                confirmar = 'n';
                opcion = -1;
                printf("--------------------------------\n");
                printf("     *** Modificar empleado ***\n");
                printf("--------------------------------\n");


                while(confirmar=='n')
                {

                    getInt("Por favor ingrese el ID del empleado a modificar: ", "ERROR. Ingrese el ID del empleado a modificar (solo numeros): ", &buscarId);
                    printf("El id es: %d", buscarId);
                    indice = findEmployeeById(lista, SIZE_LIST, buscarId);

                    while(indice == -1)
                    {
                        getInt("El ID ingresado no fue encontrado. Por favor ingrese nuevamente el ID del empleado a modificar: ", "ERROR. Ingrese el ID del empleado a modificar (solo numeros): ", &buscarId);
                        indice = findEmployeeById(lista, SIZE_LIST, buscarId);
                    }


                    printf("Id\tNombre\tApellido    Salario\tSector\t\n");
                    printEmploye(lista[indice]);

                    printf("Los datos del empleado son los correctos? s/n: ");
                    fflush(stdin);
                    confirmar = getc(stdin);
                    confirmar = tolower(confirmar);

                    while(confirmar!='s' && confirmar!='n')
                    {
                        printf("ERROR. Los datos del empleado son los correctos? s/n: ");
                        fflush(stdin);
                        confirmar = getc(stdin);

                        confirmar = tolower(confirmar);

                    }

                    fflush(stdin);
                    if(confirmar=='s')
                    {
                        while(opcion== -1)
                        {
                        	system("cls");
                            printf("--------------------------------\n");
                            printf("     *** Modificar empleado ***\n");
                            printf("--------------------------------\n");

                            printf("Que desea modificar de: \n");
                            printf("Id\tNombre\tApellido    Salario\tSector\t\n");
                            printEmploye(lista[indice]);

                            //Nombre o Apellido	o Salario o Sector
                            printf("1. Nombre.\n");
                            printf("2. Apellido.\n");
                            printf("3. Salario.\n");
                            printf("4. Sector.\n");
                            printf("0. Salir.\n");

                            fflush(stdin);
                            getInt("Por favor,  elija una opcion: ","ERROR. Por favor,  elija una opcion (solo numeros): ", &opcion);

                            switch(opcion)
                            {
                            case 1:
                                getString("Por favor ingrese el nombre del empleado: ", "ERROR. Ingrese nuevamente nombre del empleado", nombre, SIZE_STRING);

                                if(modifyName(lista, indice, nombre))
                                {
                                    printf("Nombre modificado con exito.\n");
                                }
                                else
                                {
                                    printf("Ocurrio un error al modificar el nombre. Intente nuevamente");
                                }
                                break;
                            case 2:
                                getString("Por favor ingrese el apellido del empleado: ", "ERROR. Ingrese nuevamente apellido del empleado", apellido, SIZE_STRING);
                                if(modifyLastname(lista, indice, apellido))
                                {
                                    printf("Apellido modificado con exito.\n");
                                }
                                else
                                {
                                    printf("Ocurrio un error al modificar el apellido. Intente nuevamente");
                                }
                                break;
                            case 3:
                                getFloat("Por favor ingrese el nuevo salario del empleado: ", "ERROR. Por favor ingrese el nuevo salario del empleado: ", &salario);
                                if(modifySalary(lista, indice, salario))
                                {
                                    printf("Salario modificado con exito.\n");
                                }
                                else
                                {
                                    printf("Ocurrio un error al modificar el nombre. Intente nuevamente");
                                }
                                break;
                            case 4:
                                getInt("Por favor ingrese el nuevo sector del empleado: ", "ERROR. Por favor ingrese el nuevo sector del empleado: ", &sector);
                                if(modifySector(lista, indice, sector))
                                {
                                    printf("Sector modificado con exito.\n");
                                }
                                else
                                {
                                    printf("Ocurrio un error al modificar el sector. Intente nuevamente");
                                }

                                break;
                            case 0:
                                printf("Saliendo al menu principal.\n");
                                break;
                            default:
                                opcion = -1;
                                printf("ERROR. Elija una opcion correcta.");
                                break;


                            }
                        }




                    }




                }



            }else
            {
            	printf("Primero debe dar de alta al menos un empleado para modificar.\n");
            }
            break;
        case 3:
            if(banderaAlta==TRUE)
            {
                system("cls");
                confirmar = 'n';
                opcion = -1;
                printf("--------------------------------\n");
                printf("     *** Baja de empleados ***\n");
                printf("--------------------------------\n");


                while(confirmar=='n')
                {

                    getInt("Por favor ingrese el ID del empleado a dar de baja: ", "ERROR. Ingrese el ID del empleado a dar de baja (solo numeros): ", &buscarId);
                    indice = findEmployeeById(lista, SIZE_LIST, buscarId);

                    while(indice == -1)
                    {
                        getInt("El ID ingresado no fue encontrado. Por favor ingrese nuevamente el ID del empleado a dar de baja: ", "ERROR. Ingrese el ID del empleado a dar de baja (solo numeros): ", &buscarId);
                        indice = findEmployeeById(lista, SIZE_LIST, buscarId);
                    }


                    printf("Id\tNombre\tApellido    Salario\tSector\t\n");
                    printEmploye(lista[indice]);

                    printf("Los datos del empleado son los correctos? s/n: ");
                    fflush(stdin);
                    confirmar = getc(stdin);
                    confirmar = tolower(confirmar);

                    while(confirmar!='s' && confirmar!='n')
                    {
                        printf("ERROR. Los datos del empleado son los correctos? s/n: ");
                        fflush(stdin);
                        confirmar = getc(stdin);

                        confirmar = tolower(confirmar);

                    }

                    fflush(stdin);
                    if(confirmar=='s')
                    {

                        removeEmployee(lista, SIZE_LIST, buscarId);
                        printf("Empleado dado de baja con exito.\n");
                    }
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
            	system("cls");
                printEmployees(lista, SIZE_LIST);
                //Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
                printf("\n\nEl monto total de salarios es: $%.2f.\n", totalSalaryEmployees(lista, SIZE_LIST));
                printf("El promedio de los salarios es $%.2f.\n", getMedianSalaryEmployees(lista, SIZE_LIST));
                printf("La cantidad de empleados que superan el salario promedio es de: %d.\n", getEmployeesUpMedianSalary(lista, SIZE_LIST));
            }
            else
            {
            	printf("Primero debe dar de alta al menos un empleado para informar.");
            }
            break;

        default:
            printf("Opcion invalida, a continuacion elija una opcion correcta.\n");
            //confirmarSalir
            break;

        }




        system("pause");
        fflush(stdin);
    }
    while(confirmarSalir=='n');

    return 0;
}



int validarCaracter(char valor, char a, char b)
{
    int todoOk=0;

    if(valor==a || valor==b)
    {
        todoOk = 1;
    }

    return todoOk;
}
