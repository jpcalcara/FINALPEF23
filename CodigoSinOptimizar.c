#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 10
#define N 10

void ProductoX(int numero);
double Factorial(int n);
int sumar();
int Fibonacci(int n); 
int n, i, j, temp;
int OrMatriz(int n);
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node* root = NULL;
Node* createNode(int value);
Node* insertNode(Node* root, int value);
void preOrderTraversal(Node* root);
void inOrderTraversal(Node* root);
void postOrderTraversal(Node* root);

int main() 
 { 
int numero1 = 1000, numero2 = 5000, i = 0, resultado;
    
int *p1 = (int *)malloc(sizeof(int)), *p2;	/*declaración de los punteros */
    
int a, b, c;
    
double resultFac;

printf("\n**** MENU DE OPCIONES **** \n");
    
printf("\n   1. Calcula la suma de pares hasta el 10000");
    
printf("\n   2. Calcula el cubo (1-10000)");
    
printf("\n   3. Producto por 100 (1-10000)");
    
printf("\n   4. Calcula Fibonacci (0-10000)");
    
printf("\n   5. Calcula factorial (1-10000)");
    
printf("\n   6. Numeros (1-100) en una matriz");
    
printf("\n   7. Calcula suma usando punteros");
    
printf("\n   8. Recorre arreglo y matriz por medio de punteros");

printf("\n   9. Ordenamiento de Matrices");

printf("\n   10. Arbol binario y sus recorridos");
 
    do
	
 {
	i++;
	
switch (i)
	    
 {
	
 
case 1:
	    resultado = sumar();
	    
printf("\n   ");
	    
printf("\nSuma total: %d \n", resultado);
	    
break;
	
 
case 2:
	    
printf("\nCubo del 1 al 10000.\n");
	    
for (resultado = 1; resultado <= 10000; resultado++)
		
 {
		
printf("Cubo de %d: %.f  \n", resultado,
			pow(resultado, 3));
		
}
	    
break;
	
 
case 3:
	    
resultado = 100;
	    
ProductoX(resultado);
	    
break;
	
 
case 4:
	    
printf("\n   ");
	    
printf("\nFibonacci del 0-10000.\n");
	    
for (int o = 0; o <= 10000; o++)
		
 {
		
resultado = Fibonacci(o);
		
printf("Fibonacci de %d:  %d \n", o, resultado);
	
} 
 
case 5:
	    
printf("\nFactorial (1-10000).\n");
	    
for (int fac = 0; fac <= 10000; fac++)
		
 {
		
resultFac = Factorial(fac);
		
printf("Factorial de %d:  %lf \n", fac, resultFac);
		
} 
break;
	
 
case 6:
	    
printf("\nNumeros (1-100) en una matriz \n");
	    
int x, y, numerosTabla[10][10];
	    
 
for (x = 0; x < 10; x++)
		
 {
		
for (y = 0; y < 10; y++)
		    
 {
		    
numerosTabla[x][y] = (x * 10) + 1 + y;
		    
}
		
 
}
	    
 
for (x = 0; x < 10; x++)
		
 {
		
for (y = 0; y < 10; y++)
		    
 {
		    
printf("%d ", numerosTabla[x][y]);
		    
}
		
printf("\n");
		}
	    
break;
	
 
case 7:
	    
printf("\nCalcular suma usando punteros\n");
	    
 
a = 300;
	    
 
b = 1500;
	    
 
c = a + b;
	    
 
printf("Suma sin punteros -> %d +% d = %d\n", a, b, c);
	    
 
p1 = &a;
	    
 
p2 = &b;
	    
 
printf("Suma con punteros -> *p1 + *p2 = %d\n", *p1 + *p2);
	
 
 
case 8:
{ 	    
printf("\nRecorrer arreglo y matriz por medio de punteros \n");
	    
int x2[10][10], y2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	    
 
int f = 0, cc = 0, res;
	    
 
 
for (f = 0; f < M; f++)
		
 {
		
for (cc = 0; cc < N; cc++)
		    
 {
		    
printf("2 *(x+ %d)+%d)=", f, cc);
		    
}
		
 
}
	    
printf("-MATRIZ: \n");
	    
 
for (f = 0; f < M; f++)
		
 
for (cc = 0; cc < N; cc++)
		    
 
printf("%d", *(*(x2 + f) + cc));
	    
 
printf("\n-VECTOR: \n");
	    
 
for (f = 0; f < M; f++)
		
printf("%d", *(y2 + f));
	    
printf("\n");
}

case 9:
printf("Ingrese el tamaño de la matriz: ");
scanf("%d", &n);
OrMatriz(n);

case 10:
for (int i = 0; i < 50000; i++) {
        int value = rand() % 50000;
        root = insertNode(root, value);
    }

printf("Recorrido en preorden: ");
preOrderTraversal(root);
printf("\n");

printf("Recorrido en orden: ");
inOrderTraversal(root);
printf("\n");

printf("Recorrido en postorden: ");
postOrderTraversal(root);
printf("\n");
	    
}; //switch
    
} //do

while (i != 10);    
return 0;

}//main


 
int sumar()
{
    
int x, cont, sum, i, t[50000];
    
 
i = 0;
    
sum = 0;
    
for (x = 1; x <= 50000; x++)
	
 {
	
cont = 0;
	
if (x % 2 == 0)
	    
 {
	    
t[i] = x;
	    
i++;
	    
}
	
}
    
for (x = 0; x < i; x++)
	
 {
	sum = sum + t[x];
	
}
    
 
return sum;

}


 
double Factorial(int n)
{
    
double f = 1;
    
if (n < 0)
	
f = 0;
    
    else if (n > 1)
	
for (int i = 2; i <= n; i++)
	    
f *= i;
    
return f;

}


 
int Fibonacci(int n)
{
    
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

void ProductoX(int numero)
{
    
printf("\n   ");
    
int i;
    
printf("\nProducto por %d es:\n", numero);
    
for (i = 1; i <= 10000; i++)
	
printf("\n   %d * %d = %d", i, numero, i * numero);

}

int OrMatriz(int n){
	int *matriz = (int*) malloc(n * n * sizeof(int)); // Asignación de memoria
    // Inicialización de la matriz con números aleatorios
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i * n + j] = rand() % 10000;
        }
    }

    // Ordenamiento de la matriz con algoritmo de burbuja
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (matriz[j * n + j] > matriz[(j + 1) * n + (j + 1)]) {
                temp = matriz[j * n + j];
                matriz[j * n + j] = matriz[(j + 1) * n + (j + 1)];
                matriz[(j + 1) * n + (j + 1)] = temp;
            }
        }
    }

    // Impresión de la matriz ordenada
    printf("\nMatriz ordenada:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }
	return 0;
}

// Función para crear un nuevo nodo
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función para insertar un nodo en el árbol
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    Node* current = root;
    while (current != NULL) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = createNode(value);
                return root;
            }
            current = current->left;
        } else if (value > current->value) {
            if (current->right == NULL) {
                current->right = createNode(value);
                return root;
            }
            current = current->right;
        } else {
            return root;
        }
    }

    return root;
}

// Función para recorrer el árbol en orden
void inOrderTraversal(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->value);

        current = current->right;
    }
}

// Función para recorrer el árbol en preorden
void preOrderTraversal(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;

    stack[++top] = current;
    while (top != -1) {
        current = stack[top--];
        printf("%d ", current->value);

        if (current->right != NULL) {
            stack[++top] = current->right;
        }

        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

// Función para recorrer el árbol en postorden
void postOrderTraversal(Node* root) {
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;
    Node* current = root;

    stack1[++top1] = current;
    while (top1 != -1) {
        current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }

        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    while (top2 != -1) {
        current = stack2[top2--];
        printf("%d ", current->value);
    }
}
