#include "Employee.h"

Employee* employee_new()
{

	Employee *auxEmployee = (Employee*) malloc(sizeof(Employee));
	if (auxEmployee != NULL)
	{
		auxEmployee->id = 0;
		strcpy(auxEmployee->nombre, "");
		auxEmployee->horasTrabajadas = 0;
		auxEmployee->sueldo = 0;
	}

	return auxEmployee;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr)
{

	Employee *auxEmployee = employee_new();

	if (auxEmployee != NULL)
	{
		if (!(employee_setId(auxEmployee, atoi(idStr))
				&& employee_setNombre(auxEmployee, nombreStr)
				&& employee_setHorasTrabajadas(auxEmployee,
						atoi(horasTrabajadasStr))
				&& employee_setSueldo(auxEmployee, atoi(sueldoStr))))
		{
			free(auxEmployee);
			auxEmployee = NULL;
		}

	}

	return auxEmployee;
}

int employee_delete(Employee *this)
{
	int todoOk = 0;

	if (this != NULL)
	{
		free(this);
		todoOk = 1;
	}

	return todoOk;
}

int employee_setId(Employee *this, int id)
{
	int todoOk = 0;

	if (this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}

	return todoOk;
}

int employee_getId(Employee *this, int *id)
{
	int todoOk = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}

	return todoOk;
}

int employee_getMaxId(LinkedList *pArrayListEmployee)
{
	int maxId = 0;
	int idActual;
	int tam;
	int flag = 0;
	Employee *auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idActual);
			if (!flag || maxId < idActual)
			{
				maxId = idActual;
				flag = 1;
			}
		}
		auxEmployee = NULL;
	}
	return maxId;
}

int employee_setNombre(Employee *this, char *nombre)
{
	int todoOk = 0;

	if (this != NULL && nombre != NULL && strlen(nombre)<128)
	{
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}
	return todoOk;
}

int employee_getNombre(Employee *this, char *nombre)
{
	int todoOk = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}

	return todoOk;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int todoOk = 0;

	if (this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk = 1;
	}

	return todoOk;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
	int todoOk = 0;

	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		todoOk = 1;
	}

	return todoOk;
}

int employee_setSueldo(Employee *this, int sueldo)
{
	int todoOk = 0;

	if (this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		todoOk = 1;
	}

	return todoOk;
}

int employee_getSueldo(Employee *this, int *sueldo)
{
	int todoOk = 0;

	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		todoOk = 1;
	}
	return todoOk;
}

void employee_mostrarEmpleado(Employee* employee)
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if (employee != NULL && employee_getId(employee, &id)
			&& employee_getNombre(employee, nombre)
			&& employee_getHorasTrabajadas(employee, &horasTrabajadas)
			&& employee_getSueldo(employee, &sueldo))
	{
	printf("|%4d  | %-20s|        %4d        |     $%-10d|\n", id,
											nombre,
											horasTrabajadas,
											sueldo);
	}

}

int employee_compareById(void *employee1, void *employee2)
{
	int todoOk = 0;

	Employee *auxEmployee1 = NULL;
	Employee *auxEmployee2 = NULL;

	if (employee1 != NULL && employee2 != NULL)
	{
		auxEmployee1 = employee1;
		auxEmployee2 = employee2;

		if (auxEmployee1->id < auxEmployee2->id)
		{
			todoOk = 1;
		}
		auxEmployee1 = NULL;
		auxEmployee2 = NULL;
	}
	return todoOk;
}

int employee_compareByName(void *employee1, void *employee2)
{
	int todoOk = 0;
	char nombre1[128];
	char nombre2[128];

	Employee *auxEmployee1 = NULL;
	Employee *auxEmployee2 = NULL;

	if (employee1 != NULL && employee2 != NULL)
	{
		auxEmployee1 = employee1;
		auxEmployee2 = employee2;

		employee_getNombre(auxEmployee1, nombre1);
		employee_getNombre(auxEmployee2, nombre2);

		todoOk = strcmp(nombre1, nombre2);

		auxEmployee1 = NULL;
		auxEmployee2 = NULL;
	}

	return todoOk;
}

int employee_compareByHours(void *employee1, void *employee2)
{
	int todoOk = 0;

	Employee *auxEmployee1 = NULL;
	Employee *auxEmployee2 = NULL;

	if (employee1 != NULL && employee2 != NULL)
	{
		auxEmployee1 = employee1;
		auxEmployee2 = employee2;

		if (auxEmployee1->horasTrabajadas < auxEmployee2->horasTrabajadas)
		{
			todoOk = 1;
		}
		else
		{
			if(auxEmployee1->horasTrabajadas > auxEmployee2->horasTrabajadas)
			{
			todoOk= -1;
			}
		}

		auxEmployee1 = NULL;
		auxEmployee2 = NULL;
	}
	return todoOk;
}

int employee_compareBySalary(void *employee1, void *employee2)
{
	int todoOk = 0;

	Employee *auxEmployee1 = NULL;
	Employee *auxEmployee2 = NULL;

	if (employee1 != NULL && employee2 != NULL)
	{
		auxEmployee1 = employee1;
		auxEmployee2 = employee2;

		if (auxEmployee1->sueldo < auxEmployee2->sueldo)
		{
			todoOk = 1;
		}else
		{
			if(auxEmployee1->sueldo > auxEmployee2->sueldo)
			{
			todoOk= -1;
			}
		}

		auxEmployee1 = NULL;
		auxEmployee2 = NULL;
	}
	return todoOk;
}

Employee* employee_getNewEmployee(LinkedList* pArrayListEmployee)
{
	Employee *auxEmpleado = NULL;

		int nextId;
		char nombre[128];
		int horasTrabajadas;
		int sueldo;

		char horasTrabajadasStr[10];
		char sueldoStr[10];
		char nextIdStr[10];

		if(pArrayListEmployee!=NULL)
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
		}

		return auxEmpleado;
}

