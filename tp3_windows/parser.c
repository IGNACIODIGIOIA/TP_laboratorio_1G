#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	char auxId[51];
	    char auxNombre[51];
	    char auxHoras[51];
	    char auxSueldo[51];
	    int retorno = 0;
	    int flagOnce = 1;
	    Employee* pEmpleado;

	    if(pFile!=NULL)
	    {
	        while(!feof(pFile))
	        {
	            if(flagOnce)
	            {
	                flagOnce=0;
	                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
	            }
	            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

	            pEmpleado = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);

	            if(pEmpleado != NULL)
	            {
	                retorno = 1;
	                ll_add(pArrayListEmployee,pEmpleado);
	            }
	        }
	    }

	    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno= 0;
	    int id;
	    char idStr[10];
	    char nombre[128];
	    int horasTrabajadas;
	    char horasTrabStr[64];
	    int sueldo;
	    char sueldoStr[64];
	    int datosLeidos=0;
	    Employee* pEmpleado=NULL;


	    if(pFile!=NULL && pArrayListEmployee !=NULL)
	    {
	        rewind(pFile);
	        while(!feof(pFile))
	        {
	            datosLeidos =  fread(&id,sizeof(int),1,pFile);
	            datosLeidos =(fread(nombre,sizeof(char),128,pFile))+datosLeidos;
	            datosLeidos =(fread(&sueldo,sizeof(int),1,pFile))+datosLeidos;
	            datosLeidos=(fread(&horasTrabajadas,sizeof(int),1,pFile))+datosLeidos;
	            sprintf(idStr,"%d",id);
	            sprintf(horasTrabStr,"%d",horasTrabajadas);
	            sprintf(sueldoStr,"%d",sueldo);

	            if(datosLeidos==131)
	            {
	                pEmpleado = employee_newParametros(idStr,nombre,horasTrabStr,sueldoStr);
	                ll_add(pArrayListEmployee,pEmpleado);
	            }

	        }
	        retorno = 1;
	    }
	    return retorno;
}
