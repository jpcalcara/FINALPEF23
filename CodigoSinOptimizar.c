#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 5
#define N 5

void ProductoX(int numero);
double Factorial (int n);


int main()
{
int numero1 = 1000, numero2 = 5000, i = 0, resultado;
int *p1=malloc(sizeof(int)), *p2; /*declaración de los punteros */
int a, b, c;
double resultFac;

printf("\n**** MENU DE OPCIONES **** \n" );
printf( "\n   1. Calcula la suma de pares hasta el 10000");
printf( "\n   2. Calcula el cubo (1-100)");
printf( "\n   3. Producto por 100 (1-100)");
printf( "\n   4. Calcula Fibonacci (0-1000)");
printf( "\n   5. Calcula factorial (1-100)");
printf( "\n   6. Numeros (1-100) en una matriz");
printf( "\n   7. Calcula suma usando punteros");
printf( "\n   8. Recorre arreglo y matriz por medio de punteros");

    do
    {i++;
    switch ( i )
    {

    case 1:	resultado = sumar();
    printf( "\n   " );
    printf( "\nSuma total: %d \n", resultado );
    break;

   case 2:
   printf( "\nCubo del 1 al 100.\n" );
   for ( resultado = 1 ; resultado <= 100 ; resultado++ )
   {
      printf( "Cubo de %d: %.f  \n",resultado , pow( resultado, 3 ) );
   }
   break;

   case 3:
   resultado = 100;
   ProductoX(resultado);
   break;

   case 4:
   printf( "\n   " );
   printf( "\nFibonacci del 0-1000.\n" );
   for (int o = 0; o <= 1000; o++)
   {
    resultado = Fibonacci(o);
    printf("Fibonacci de %d:  %d \n",o , resultado);
   }

   case 5:
   printf( "\nFactorial (1-100).\n" );
   for (int fac = 0; fac <= 100; fac++)
   {
    resultFac = Factorial(fac);
    printf("Factorial de %d:  %lf \n",fac , resultFac);
   }
   break;

   case 6:
   printf( "\nNumeros (1-100) en una matriz \n");
   int x,y, numerosTabla[10][10];

   for (x=0;x<10;x++)
   {
    for (y=0;y<10;y++)
    {
     numerosTabla[x][y]=(x*10)+1+y;
    }

   }

   for (x=0;x<10;x++)
   {
    for (y=0;y<10;y++)
    {
    printf("%d ",numerosTabla[x][y]);
    }
    printf("\n");				}
    break;

    case 7:
    printf( "\nCalcular suma usando punteros\n");

   a= 300;

   b= 1500;

   c= a + b;

   printf("Suma sin punteros -> %d +% d = %d\n", a, b, c);

   p1= &a;

   p2= &b;

   printf("Suma con punteros -> *p1 + *p2 = %d\n", *p1+*p2);


   case 8:
   printf( "\nRecorrer arreglo y matriz por medio de punteros \n");
   int x2[5][5], y2[5] = {1,2,3,4,5};

   int f=0,cc=0, res;


   for(f=0; f< M; f++)
   {
   for(cc=0; cc<N; cc++)
   {
   printf("2 *(x+ %d)+%d)=", f,cc);
    }

   }
   printf("-MATRIZ: \n");

   for(f=0; f<M; f++)

   for(cc=0; cc<N; cc++)

   printf("%d", *(*(x2+f)+cc));

   printf("\n-VECTOR: \n");

   for(f=0; f<M; f++)
   printf("%d", *(y2+f));
   printf("\n");
   };
   } while ( i != 8 );
 return 0;
}

int sumar (){
    int x,cont,sum,i,t[10000];

    i=0;
    sum=0;
    for (x=1;x<=10000;x++)
    {
     cont=0;
     if (x%2==0)
     {
      t[i]=x;
      i++;
     }
    }
    for (x=0;x<i;x++)
    {sum=sum+t[x];
 }

    return sum;
}

double Factorial (int n) {
    double f = 1;
    if (n < 0)
        f = 0;
    else if (n > 1)
        for (int i = 2; i <= n; i++)
            f *= i;
    return f;
}

int Fibonacci (int n) {
    int f = 1, anterior = 1, actual = 1;
    if (n < 0)
        f = -1;
    else if (n > 2)
        for (int i = 3; i <= n; i++) {
            f = anterior + actual;
            anterior = actual;
            actual = f;
        }
    return f;
}



void ProductoX(int numero){
    printf( "\n   " );
    int i;
    printf( "\nProducto por %d es:\n", numero );
    for ( i = 1 ; i <= 100 ; i++ )
    printf( "\n   %d * %d = %d", i, numero, i * numero );
}