/*
 ============================================================================
 Name        : calculadora_tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : CALCULADORA, Ansi-style
 ============================================================================
 */
/******************************************************************************
* Programa: Calculadora. Trabajo Practico Nº1
*
* Objetivo:
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*      1. Ingresar 1er operando (A=x)
*      2. Ingresar 2do operando (B=y)
*      3. Calcular todas las operaciones:
*       a) Calcular la suma (A+B)
*       b) Calcular la resta (A-B)
*       c) Calcular la division (A/B)
*       d) Calcular la multiplicacion (A*B)
*       e) Calcular el factorial (A!)
*
*      4. Informar resultados
*       a) “El resultado de A+B es: r”
*       b) “El resultado de A-B es: r”
*       c) “El resultado de A/B es: r” o “No es posible dividir por cero”
*       d) “El resultado de A*B es: r”
*       e) “El factorial de A es: r1 y El factorial de B es: r2”
*      5. Salir
*
* Alumno: Ignacio Di Gioia
* Comision: 1ºE
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "calculadora.h"

int main()
{
	setbuf(stdout,NULL);

    char letra;
    int a, b;
    float aF, bF;

    char continuar = 'S';

    printf("  Bienvenido a la Calculadora  ");

    while(continuar == 'S')
    {

       printf("\n\nPara sumar, presiona la letra S ");
       printf("\nPara restar, presiona la letra R ");
       printf("\nPara multiplicar, presiona la letra M ");
       printf("\nPara dividir, presiona la letra D ");
       printf("\nPara obtener el factorial de un numero, presiona la letra F ");

       letra = toupper(getch());

       switch(letra)
       {
           case 'S': a = getInt("\nIngrese el valor de A: ");   b = getInt("\nIngrese el valor de B: ");   printSuma(a, b);   break;

           case 'R': a = getInt("\nIngrese el valor de A: ");   b = getInt("\nIngrese el valor de B: ");   printResta(a, b);  break;

           case 'M': a = getInt("\nIngrese el valor de A: ");   b = getInt("\nIngrese el valor de B: ");   printMultiplicacion(a, b);   break;

           case 'D': aF = getFloat("\nIngrese el valor de A: "); bF = getFloat("\nIngrese el valor de B: "); printDivision(aF , bF);   break;

           case 'F': a = getInt("\nIngrese el valor de A: ");    printFactorial(a) ;   break;

             default: printf("\nLa letra ingresada no es Valida.. \n");
       }

         do{
            printf("\nRealizar otra Operacion?  S/N ");
            fflush(stdin);

            continuar = toupper(getch());

            if(continuar == 'S')
            {

                system("cls");
            }
         } while(continuar != 'S' && continuar != 'N');
    }


    return 0;
}
