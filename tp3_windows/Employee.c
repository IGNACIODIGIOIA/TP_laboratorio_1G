


#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"
#include <string.h>

/**
 * \brief Reserva un espacio en memoria para guardar un empleado
 * \param Void (No recibe nada en los parametros)
 * \return Retorna un puntero al espacio de memoria donde guardará el empleado
 */
Employee* employee_new(void)
{
	Employee* aux = NULL;
	aux = malloc(sizeof(Employee));
	return aux;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* aux = NULL;
	aux = employee_new();
	if(aux != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(utn_verificarNumerica(idStr, 5) == 0 && utn_verificarNumerica(horasTrabajadasStr, 5) == 0 && utn_verificarNumerica(sueldoStr, 10) == 0)
		{
			if(employee_setId(aux, atoi(idStr)) == 1 &&
				employee_setNombre(aux, nombreStr) == 1 &&
				employee_setHorasTrabajadas(aux, atoi(horasTrabajadasStr)) == 1 &&
				employee_setSueldo(aux, atoi(sueldoStr)) == 1)
			{
				return aux;
			}
			else
			{
				employee_delete(aux);
			}
		}
	}
	return NULL;
}

int employee_setId(Employee* this, int id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_CompareById(Employee* emp1,Employee* emp2)
{
    int retorno = 0;

    if(emp1->id > emp2->id)
    {
        retorno = 1;
    }
    if(emp1->id < emp2->id)
    {
        retorno = -1;
    }
    return retorno;
}

int employee_CompareByName(Employee* emp1, Employee* emp2)
{
    int retorno = 0;

    if(  strcmpi(emp1->nombre, emp2->nombre) > 0)
    {
        retorno = 1;
    }
    if(strcmpi(emp1->nombre,emp2->nombre) < 0)
    {
        retorno = -1;
    }

    return retorno;
}
