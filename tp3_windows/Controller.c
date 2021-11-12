#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	    int retorno= 0;

	    pArchivo=fopen(path,"r");

	    if(pArchivo != NULL && pArrayListEmployee != NULL)
	    {
	        retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
	        printf("El archivo .csv se leyo correctamente.\n");
	    }
	    fclose(pArchivo);

	    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	    int retorno = 0;

	    pArchivo = fopen(path,"rb");

	    if(pArchivo != NULL && pArrayListEmployee != NULL)
	    {
	        retorno = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
	        printf("El archivo .bin se leyo correctamente.\n");
	    }
	    fclose(pArchivo);

	    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	    int auxID = ll_len(pArrayListEmployee)+1;
	    int retorno = 0;

	    char auxNombre[51];
	    int auxSueldo;
	    int auxHoras;

	    empleado = employee_new();

	    if(ll_len(pArrayListEmployee) == 0)
	    {
	        printf("Primero cargue la lista.\n");
	        return retorno;
	    }

	    else
	    {
	        if(pArrayListEmployee != NULL)
	        {

	            printf("Ingrese nombre: ");
	            gets(auxNombre);

	            //Sueldo
	            utn_getNumero(&auxSueldo, "\n Ingrese sueldo: \n", "\n Ingrese sueldo correctamente", 100, 1000000, 2);
	            //Horas trabajadas
	            utn_getNumero(&auxHoras, "\n Ingrese Horas Trabajadas: \n", "\n Ingrese Horas trabajadas correctamente", 10, 10000, 2);

	            employee_setId(empleado,auxID);
	            employee_setNombre(empleado,auxNombre);
	            employee_setSueldo(empleado,auxSueldo);
	            employee_setHorasTrabajadas(empleado,auxHoras);

	            ll_add(pArrayListEmployee,empleado);

	            auxID++;
	            retorno = 1;
	            printf("El empleado se agrego correctamente.\n");
	        }
	    }

	    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	    int retorno = 0;
	    int encontro = 0;
	    int auxId;
	    int idModify;
	    int option;

	    char auxNombre[51];
	    int auxSueldo;
	    int auxHoras;

	    controller_ListEmployee(pArrayListEmployee);

	    utn_getNumero(&idModify, "\n Ingrese id a Modificar: \n", "\n Ingrese un id Valido", 0, 10000, 2);

	    if(pArrayListEmployee != NULL)
	    {

	        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
	        {
	            empleado = ll_get(pArrayListEmployee,i);
	            employee_getId(empleado,&auxId);

	            if(auxId == idModify)
	            {
	                encontro = i;
	                break;
	            }
	        }

	        if(encontro > 0)
	        {
	        	do{
	        	    						if(!utn_getNumero(	&option,
	        	    								"1. Modificar nombre.\n"
	        	    								"2. Modificar Sueldo.\n"
	        	    								"3. Modificar horas trabajadas.\n"
	        	    								"4. Salir\n",
	        	    								"\nError opcion invalida",1,10,2) )
	        	    							{
	        	        switch(option)
	        	        {
	        	        			case 1:
	        	        				mostrar(empleado);
      					                printf("\nIngrese el nuevo nombre :");
       					                gets(auxNombre);
      					                employee_setNombre(empleado,auxNombre);
       	        					                break;

	        	                    case 2:
	        	                    	 mostrar(empleado);
	        	                    	 utn_getNumero(&auxSueldo, "\n Ingrese sueldo: \n", "\n Ingrese sueldo correctamente", 100, 1000000, 2);
	        	                    	 employee_setSueldo(empleado,auxSueldo);
	        	                    	            break;

	        	                    case 3:
	        	                    	mostrar(empleado);
	        	                    	utn_getNumero(&auxHoras, "\n Ingrese Horas Trabajadas: \n", "\n Ingrese Horas trabajadas correctamente", 10, 10000, 2);
	        	                        employee_setHorasTrabajadas(empleado,auxHoras);
	        	                                    break;
	         		    }
	        	     }
	        	    }while(option != 4);

	            retorno = 1;
	            printf("\nEmpleado modificado correctamente.\n");
	        }
	    }
	    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	    int retorno = 0;
	    int auxId;
	    int idPedido;
	    controller_ListEmployee(pArrayListEmployee);


	    utn_getNumero(&idPedido, "\n Ingresar id del empleado a borrar: \n", "\n Ingrese un id Valido", 0, 10000, 2);

	    if(pArrayListEmployee != NULL)
	    {
	        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
	        {
	            empleado=ll_get(pArrayListEmployee,i);
	            employee_getId(empleado,&auxId);

	            if(auxId == idPedido)
	            {
	                ll_remove(pArrayListEmployee,i);
	                retorno = 1;
	                printf("\nEmpleado borrado correctamente.\n");
	            }
	        }
	    }
	    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	    int retorno = 0;
	    char nombre[50];
	    int id;
	    int sueldo;
	    int horas;

	    if(pArrayListEmployee != NULL)
	    {
	        printf("%s%15s%15s%30s\n","ID","NOMBRE","SUELDO","HORAS DE TRABAJO");

	        for(int i=0; i < ll_len(pArrayListEmployee); i++)
	        {
	            empleado=ll_get(pArrayListEmployee,i);
	            employee_getNombre(empleado,nombre);
	            employee_getId(empleado,&id);
	            employee_getSueldo(empleado,&sueldo);
	            employee_getHorasTrabajadas(empleado,&horas);

	            printf("%d%15s%15d%25d\n",id,nombre,sueldo,horas);
	        }
	        printf("\nCantidad de empleados : %d",ll_len(pArrayListEmployee));
	        retorno = 1;
	    }
	    printf("\nEmpleados listados correctamente.\n");
	    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

	    int retorno = 0;
	    int option;

	    if(pArrayListEmployee != NULL)
	    {do{
			if(!utn_getNumero(	&option,
					"1. Por id.\n"
					"2. Por Nombre.\n"
					"3. Salir. \n\n",
					"\nError opcion invalida",1,3,2) )
				{

	        switch(option)
	        {
	            case 1:
	                ll_sort(pArrayListEmployee,employee_CompareById,1);
	                printf("\nEmpleados ordenados por id.\n");
	                retorno =1;
	                break;

	            case 2:
	                ll_sort(pArrayListEmployee,employee_CompareByName,1);
	                printf("\nEmpleados ordenados por nombre.\n");
	                retorno =1;
	                break;
	        }
				}
	    	}while(option!=3);


	    }
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	 int retorno = 0;
	    Employee * empleado;
	    int id;
	    int sueldo;
	    int horasTrabajadas;

	    char auxId[101];
	    char auxNombre[101];
	    char auxHoras[101];
	    char auxSueldo[101];

	    FILE* pFile=fopen(path,"w");


	    if(pFile!=NULL && pArrayListEmployee !=NULL)
	    {
	        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
	        for(int i= 0; i < ll_len(pArrayListEmployee); i++)
	        {
	            empleado=ll_get(pArrayListEmployee,i);

	            employee_getId(empleado,&id);
	            employee_getNombre(empleado,auxNombre);
	            employee_getSueldo(empleado,&sueldo);
	            employee_getHorasTrabajadas(empleado,&horasTrabajadas);

	            sprintf(auxId, "%d", id);
	            sprintf(auxSueldo,"%d",sueldo);
	            sprintf(auxHoras,"%d",horasTrabajadas);
	            fprintf(pFile,"%s,%s,%s,%s\n",auxId,auxNombre,auxHoras,auxSueldo);
	            printf("%s,%s,%s,%s\n",auxId,auxNombre,auxHoras,auxSueldo);
	        }
	        fclose(pFile);
	        printf("Se guardo correctamente (csv).\n");
	        retorno = 1;
	    }

	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	    FILE* pFile;
	    pFile=fopen(path,"wb");
	    Employee* empleado;

	    if (pFile!= NULL && pArrayListEmployee !=NULL)
	    {
	        for (int i=0; i<ll_len(pArrayListEmployee); i++)
	        {
	            empleado=ll_get(pArrayListEmployee,i);
	            fwrite(empleado,140,1,pFile);
	        }
	        retorno = 1;
	        printf("Se guardo correctamente (bin).\n");
	        fclose(pFile);
	    }
	    return retorno;
}

void mostrar(Employee* empleado)
{
    char nombre[50];
    int id;
    int sueldo;
    int horas;

    employee_getNombre(empleado,nombre);
    employee_getId(empleado,&id);
    employee_getSueldo(empleado,&sueldo);
    employee_getHorasTrabajadas(empleado,&horas);

    printf("%d%15s%15d%25d\n",id,nombre,sueldo,horas);
}
