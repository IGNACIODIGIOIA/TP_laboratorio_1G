/*
 ============================================================================
 Name        : trabajo_practicoN2.c
 Author      : Ignacio Di Gioia
 Version     :
 Copyright   : Your copyright notice
 Description : trabajo_practicoN2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define EMPLEADOS_LEN 100

int main(void) {
	setbuf(stdout,NULL);
	Empleado arrayEmp[EMPLEADOS_LEN];
	//variables
	int opcion;
	int indiceAuxiliar;
	int idEmpleado =0;
	int auxiliarId;
	int auxOrder;
	float promedioSalarios;
	int sumaAuxiliar;
	int i;
//comienzo del array
	if(emp_initEmpleado(arrayEmp, EMPLEADOS_LEN)==0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
//altas forzadas
	emp_addEmpleadoForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "empleado 1", "apellido 1", 15.700, 1, 0);
	emp_addEmpleadoForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "empleado 2", " apellido 2", 17.700, 2, 1);
	emp_addEmpleadoForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "empleado 3", "apellido 3", 13.900, 3, 2);
	do
	{
		if(!utn_getNumero(&opcion, "1.Alta empleado\n2.Modificar empleado\n3.Baja empleado\n4.Informar\n5.Salir\n", "Opcion invalida\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				indiceAuxiliar = emp_getEmptyIndex(arrayEmp, EMPLEADOS_LEN);
				if(indiceAuxiliar >=0)
				{
					if(!emp_addEmpleado(arrayEmp, EMPLEADOS_LEN, indiceAuxiliar, &idEmpleado))
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
					if(arrayEmp[i].isEmpty ==0)
					{
						for(i=0;i<EMPLEADOS_LEN;i++)
						{
						emp_printEmpleado(arrayEmp, EMPLEADOS_LEN);
							if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea modificar\n", "ID incorrecto\n", 0, 10000, 2))
							{
								indiceAuxiliar = emp_findEmpleadoById(arrayEmp, EMPLEADOS_LEN, auxiliarId);
								if(indiceAuxiliar>= 0 && emp_modificarArray(arrayEmp, EMPLEADOS_LEN, indiceAuxiliar)==0)
								{
									printf("Mofificacion realizada con exito\n\n");
								}
								else
								{
									printf("ID no encontrado\n\n");
								}
							}
						}
					}
					else
					{
						printf("\nNo hay clientes cargados\n");
					}
				break;
			case 3:
				if(arrayEmp[i].isEmpty ==0)
				{
					for(i=0;i<EMPLEADOS_LEN;i++)
					{
					emp_printEmpleado(arrayEmp, EMPLEADOS_LEN);
					if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea eliminar\n", "ID incorrecto\n", 0, 10000, 2))
					{
						indiceAuxiliar = emp_findEmpleadoById(arrayEmp, EMPLEADOS_LEN, auxiliarId);
						if(indiceAuxiliar>= 0 && emp_removeEmpleado(arrayEmp, EMPLEADOS_LEN, auxiliarId)==0)
						{
							printf("Eliminacion realizada con exito\n\n");
						}
						else
						{
							printf("ID no encontrado\n\n");
						}
					}
					}
				}
				else
				{
					printf("\nNo hay clientes cargados\n");
				}
				break;
			case 4:
				if(arrayEmp[i].isEmpty ==0)
				{
					for(i=0;i<EMPLEADOS_LEN;i++)
					{
						if(!utn_getNumero(&auxOrder, "Desea imprimir:\n0.Forma Ascendente\n1.Forma descendente\n", "Opcion incorrecta\n", 0, 1, 2))
						{
							emp_sortEmpleado(arrayEmp, EMPLEADOS_LEN, auxOrder);
							printf("\n\nListado por APELLIDO Y SECTOR\n\n");
							emp_printEmpleado(arrayEmp, EMPLEADOS_LEN);
					}
						sumaAuxiliar = emp_promediarSalarios(arrayEmp, EMPLEADOS_LEN, &promedioSalarios);
						printf("\nLa suma total de los salarios es %d y el promedio es %.2f\n", sumaAuxiliar, promedioSalarios);
						printf("\nLos empleados que igual o superan el promedio son:\n");
						emp_imprimirEmpleadosSuperanPromedio(arrayEmp, EMPLEADOS_LEN);
					break;
					}
				}
				else
				{
					printf("\nNo hay clientes cargados\n");
				}
			}
		}
	}while(opcion != 5);
return EXIT_SUCCESS;
}
