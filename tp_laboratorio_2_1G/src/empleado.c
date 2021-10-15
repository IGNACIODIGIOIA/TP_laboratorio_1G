
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"


int emp_printEmpleado(Empleado* list,int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		respuesta = 0;
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty != 1)
			{
				printf("Id: %8d- %8s - %8s - Salario: %8.2f Sector: %8d\n",	list[i].id,
																		list[i].name,
																		list[i].lastName,
																		list[i].salary,
																		list[i].sector);
			}
		}
	}
	return respuesta;
}


int emp_initEmpleado(Empleado* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return respuesta;
}


int emp_addEmpleadoForzada(Empleado* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice)
{
	int respuesta = -1;
	Empleado bufferEmployee;

	if(list != NULL && len > 0 && id != NULL && name != NULL && lastName != NULL && salary >= 0 && sector >=0 && indice >=0)
	{
			strncpy(bufferEmployee.name,name,NAME_LEN);
			strncpy(bufferEmployee.lastName,lastName,LASTNAME_LEN);
			respuesta = 0;
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			bufferEmployee.isEmpty = 0;
			bufferEmployee.id = *id;
			list[indice] = bufferEmployee;
			(*id)++;
	}
	return respuesta;
}





int emp_addEmpleado(Empleado* list,int len, int indice, int* id)
{
	int respuesta = -1;
	Empleado bufferEmployee;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmployee.lastName,LASTNAME_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nSalario?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"Ingrese sector\n","Sector incorrecto\n",0,100,2)==0)
		{
			respuesta = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[indice] = bufferEmployee;
			(*id)++;
		}
	}
	return respuesta;
}


int emp_modificarArray(Empleado* list,int len, int indice)
{
	int respuesta = -1;
	Empleado auxiliar;
	int opcion;
	if(list != NULL && len > 0 && indice < len)
	{
	do
	{
		if(!utn_getNumero(&opcion, "\nIngrese el valor que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n", "Opcion incorrecta\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre empleado:\n", "Valor inválido\n", 2);
				strncpy(list[indice].name,auxiliar.name, NAME_LEN);
				printf("El nombre se modificó correctamente\n");
				break;
			case 2:
				utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Valor inválido\n", 2);
				strncpy(list[indice].lastName,auxiliar.lastName, LASTNAME_LEN);
				printf("El apellido se modificó correctamente\n");
				break;
			case 3:
				utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Valor inválido\n", 0, 100000, 2);
				list[indice].salary = auxiliar.salary;
				printf("El salario se modificó correctamente\n");
				break;
			case 4:
				utn_getNumero(&auxiliar.sector, "Ingrese sector:\n", "Valor inválido\n", 0, 10, 2);
				list[indice].sector = auxiliar.sector;
				printf("El sector se modificó correctamente\n");
				break;
			}
			respuesta = 0;
			list[indice].isEmpty = 0;

		}
	}while(opcion !=5);

	}

	return respuesta;
}

int emp_removeEmpleado(Empleado* list, int len, int id)
{
	int respuesta = -1;
	int auxIndice;
	if(list != NULL && len > 0 && id < len)
	{
		auxIndice = emp_findEmpleadoById(list, len, id);
		respuesta = 0;
		list[auxIndice].isEmpty = 1;
	}
	return respuesta;
}


int emp_findEmpleadoById(Empleado* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].id==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}




int emp_getEmptyIndex(Empleado* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


int emp_sortEmpleado(Empleado* list, int len, int order)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Empleado auxiliar;
	int auxiliarCmp;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if(	 (auxiliarCmp > 0 && order == 1) ||
					(auxiliarCmp == 0 && list[i].sector < list[i+1].sector && order == 1) )
				{
					flagSwap = 1;


					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]= auxiliar;
				}
				if(	 (auxiliarCmp < 0 && order == 0) ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector && order == 0) )
				{
					flagSwap = 1;
					auxiliar = list[i+1];
					list[i+1] = list[i];
					list[i]= auxiliar;
				}
			}
			len--;
		}while(flagSwap);
	}
	return respuesta;
}




int emp_promediarSalarios(Empleado* list, int len, float* promedioSalario)
{
    int retorno=-1;
    int i;
    float sumaSalarios=0;
    int contador=0;
    float AuxSalarios;
    if(list!= NULL && len>=0 && promedioSalario != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
            	sumaSalarios = sumaSalarios + list[i].salary;
                contador++;
            }
        }
        AuxSalarios = sumaSalarios / contador;
        retorno = sumaSalarios;
        *promedioSalario = AuxSalarios;
    }
    return retorno;
}




int emp_imprimirEmpleadosSuperanPromedio(Empleado* list, int len)
{
    int retorno=-1;
    int i;
    float auxPromedio;
    if(list != NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
        	emp_promediarSalarios(list, len, &auxPromedio);
            if(list[i].isEmpty==0 && list[i].salary >= auxPromedio)
            {
            	printf("Id: %8d- %8s - %8s - Salario: %8.2f Sector: %8d\n",	list[i].id,
																			list[i].name,
																			list[i].lastName,
																			list[i].salary,
																			list[i].sector);
            	retorno =0;
            }
        }
    }
    return retorno;
}


