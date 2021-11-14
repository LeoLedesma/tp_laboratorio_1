#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaEmpleados = ll_newLinkedList();



    if(listaEmpleados!=NULL)
    {
    		menuPrincipal(listaEmpleados);

    	    ll_deleteLinkedList(listaEmpleados);

    }else
    {
    	printf("Ocurrio un problema al iniciar el programa. Intente libera memoria.!\n");
    }





    return 0;
}

