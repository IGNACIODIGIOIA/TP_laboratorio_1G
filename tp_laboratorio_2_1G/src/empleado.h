

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define NAME_LEN 50
#define LASTNAME_LEN 20

typedef struct
{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Empleado;

int emp_imprimir(Empleado* auxProducto);
int emp_initEmpleado(Empleado* array,int limite);
int emp_addEmpleado(Empleado* list,int len, int indice, int* id);
int emp_addEmpleadoForzada(Empleado* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice);
int emp_getEmptyIndex(Empleado* array,int limite);
int emp_printEmpleado(Empleado* list,int length);
int emp_findEmpleadoById(Empleado* list, int len, int id);
int emp_modificarArray(Empleado* array,int limite, int indice);
int emp_removeEmpleado(Empleado* array,int limite, int indice);
int emp_sortEmpleado(Empleado* list, int len, int order);
int emp_promediarSalarios(Empleado* list, int len, float* promedioSalario);
int emp_imprimirEmpleadosSuperanPromedio(Empleado* list, int len);


#endif /* EMPLEADO_H_ */

