/*
 * calculadora.c
 *
 *  Created on: 8 sep. 2020
 *      Author: ignacio
 */


int suma(int a, int b)
{  /*
  * \brief   REALIZA LA SUMA DE A Y B
  * \parametro  A, B. SON LOS NUMEROS INGRESADOS POR EL USUARIO
  * \Return. MUESTRA EL RESULTADO DE LA SUMA
  */

    return a + b;
}



int resta(int a, int b)
{  /*
  * \brief   REALIZA LA RESTA DE A Y B
  * \parametro  A, B. SON LOS NUMEROS INGRESADOS POR EL USUARIO
  * \Return. MUESTRA EL RESULTADO DE LA RESTA
  */

    return a - b;
}



int multiplicacion(int a, int b)
{ /*
  * \brief   REALIZA LA MULTIPLICACION DE A Y B
  * \parametro  A, B. SON LOS NUMEROS INGRESADOS POR EL USUARIO
  * \Return. MUESTRA EL RESULTADO DE LA MULTIPLICACION
  */

    return a * b;
}



float division(float a, float b)
{ /*
  * \brief   REALIZA LA DIVISION DE A Y B
  * \parametro  A, B. SON LOS NUMEROS INFRESADOR POR EL USUARIO
  * \Return. MUESTRA EL RESULTADO DE LA DIVISION
  */

      return a/b;

}



int factorial(int x)
{ /*
  * \brief   REALIZA EL FACTORIAL DE X
  * \parametro  X. NUMERO INGRESADO POR EL USUARIO
  * \Return. MUESTRA EL RESULTADO DEL FACTORIAL
  */
  int respuesta;
  int num;

  respuesta = 1;

  for(num = 1 ; num <= x ; ++num)
  {
    respuesta *= num;
  }

   return respuesta;
}



float getFloat(char mensaje[])
{/*
  * \brief SOLICITA UN NUMERO PARA DEVOLVER UN RESULTADO
  * \parametro mensaje. Es el mensaje a ser mostrado
  * \Return EL NUMERO INGRESADO
  */

    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}


int getInt(char mensaje[])
{/*
  * \brief SOLICITA QUE SEA INGRESADO UN NUMERO
  * \parametro mensaje.
  * \Return LO INGRESADO POR EL USUARIO
  */

    int auxiliar;

    printf("%s", mensaje);
    scanf("%i", &auxiliar);
    return auxiliar;
}


void printSuma(int a, int b)
{/*
  * \brief   NOS BRINDA EL VALOR DE LA SUMA DE A Y B
  * \parametro    A y B. SON NECESARIOS PARA REALIZAR LA SUMA
  */

    printf("\n\nEl resultado de A+B es: %i \n\n\n", suma(a, b));
}


void printResta(int a, int b)
{/*
  * \brief   NOS BRINDA EL VALOR DE LA RESTA DE A Y B
  * \parametro    A y B. SON NECESARIOS PARA REALIZAR LA RESTA
  */

    printf("\n\nEl resultado de A-B es: %i \n\n\n", resta(a, b));
}


void printMultiplicacion(int a, int b)
{/*
  * \brief   NOS BRINDA EL VALOR DE DE LA MULTIPLICACION DE A Y DE B
  * \parametro    A y B. SON NECESARIOS PARA REALIZAR LA MULTIPLICACION
  */

    printf("\n\nEl resultado de A*B es: %i \n\n\n", multiplicacion(a, b));
}


void printDivision(float a, float b)
{/*
  * \brief   NOS BRINDA EL VALOR DE LA DIVISION ENTRE A Y B, PERO SI B es 0,
  * NOS BRINDA POR PANTALLA QUE NO ES POSIBLE REALIZAR LA CUENTA DIVIDIENDO POR 0
  * \parametro    A y B. SON NECESARIOS PARA REALIZAR LA DIVISION
  */
    if(b == 0)
    {
        printf("\nNo es posible dividir por cero. \n\n\n");

    }
    else {

    printf("\n\nEl resultado de A/B es: %.2f \n\n\n", division(a, b));

    }
}


void printFactorial(int a)
{/*
  * \brief   NOS BRINDA EL VALOR DEL FACTORIAL de  A
  * \parametro    SE NECESITA EL VALOR DE "A" PARA REALIZAR EL FACTORIAL
  */

    printf("\n\nEl Factorial de A es: %i ", factorial(a));
}
