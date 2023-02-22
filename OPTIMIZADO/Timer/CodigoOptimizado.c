#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 10

int sumar();

void cubos();

void ProductoX(int numero);

double Factorial(int n);

int Fibonacci(int n);

void sumaDePunteros();

void matrizX();

void arrayMatrizDePunteros();

void quickSort(int *arr, int low, int high, int n);

int OrMatriz(int n);

int i, j, n = 50;

 
// Definición de la estructura del nodo
typedef struct node {
    
	int value;
	    
	struct node *left;
	    
	struct node *right;
} Node;

 
Node * root = NULL;

Node * createNode(int value);

Node * insertNode(Node * root, int value);

void preorden(Node * root);

void inOrderTraversal(Node * root);

void postorden(Node * root);

int arbolBinario();

void liberarArbol(Node * root);
 
 
int main() {
	
	clock_t start= clock();
 
	int resultado;
	    
	double resultFac;
	    
	printf("\n**** MENU DE OPCIONES **** \n");
	    
	printf("\n1. Calcula la suma de pares hasta el 10000");
	    
	printf("\n2. Calcula el cubo (1-10000)");
	    
	printf("\n3. Producto por 100 (1-10000)");
	    
	printf("\n4. Calcula Fibonacci (0-10000)");
	    
	printf("\n5. Calcula factorial (1-10000)");
	    
	printf("\n6. Numeros (1-100) en una matriz");
	    
	printf("\n7. Calcula suma usando punteros");
	    
	printf("\n8. Recorre arreglo y matriz por medio de punteros");
	    
	printf("\n9. Ordenamiento de matrices");
	    
	printf("\n10.Arbol binario y sus recorridos");
	    
	resultado = sumar();
	    
	printf("\n\nSuma total: %d \n", resultado);
	    
	printf("\n*****************************");
	    
	cubos();
	    
	resultado = 100;
	    
	ProductoX(resultado);
	    
	printf("\n*****************************");
	    
	printf("\n\nFibonacci del 0-10000.\n");
	    
	for (int o = 0; o <= 10000; o++) {
		
		resultado = Fibonacci(o);
			
		printf("Fibonacci de %d:  %d \n", o, resultado);	    
	} 
	
	printf("\n*****************************");
	    
	printf("\nFactorial (1-10000).\n");
	    
	for (int fac = 0; fac <= 10000; fac++) {
		
		resultFac = Factorial(fac);
			
		printf("Factorial de %d:  %lf \n", fac, resultFac);	    
	} 
	
	printf("\n*****************************");
	    
	printf("\n\nNumeros (1-100) en una matriz\n\n");
	    
	matrizX();
	    
	printf("\n*****************************");
	    
	printf("\n\nCalcular suma usando punteros\n\n");
	    
	sumaDePunteros();
	    
	printf("\n*****************************");
	    
	printf("\n\nRecorrer arreglo y matriz por medio de punteros \n\n ");
	    
	arrayMatrizDePunteros();
	    
	printf("\n*****************************");
	    
	printf("\n\nOrdenamiento de Matrices \n");
	    
	OrMatriz(n);
	    
	printf("\n*****************************");
	    
	printf("\n\nArbol binario y sus recorridos \n");
	    
	arbolBinario();
	    
	printf("\n*****************************");
	
	
printf( "Tiempo de procesamiento: %f\n", ( ( double )clock() - start) / CLOCKS_PER_SEC );

	return 0;
}

int sumar(){

	int x, sum, i, tabla[10000];
	    
	i = 0;
	    
	sum = 0;
	    
	for (x = 1; x <= 10000; x++){
		
		if (x % 2 == 0){
		
			tabla[i] = x;
			i++;   
		}	
	}
	 
	for (x = 0; x < i; x++){

		sum = sum + tabla[x];		
	}
	   
	return sum;
}

void cubos(){

	int resultado;
	    
	printf("\n   ");
	    
	for (resultado = 1; resultado <= 10000; resultado++) {
		
		printf("\nCubo de %d: %.f  \n", resultado, pow(resultado, 3));	    
	}
}

void ProductoX(int numero)
{
	printf("\n   ");
	    
	int i;
	    
	printf("\n\nProducto por %d es:\n", numero);
	    
	for (i = 1; i <= 10000; i++) {
		
		printf("\n   %d * %d = %d", i, numero, i * numero);    
	}
}
 
int Fibonacci(int n){

	int f = 1, anterior = 1, actual = 1;
	    
	if (n > 2)
		
	for (int i = 3; i <= n; i++) {
		    
		f = anterior + actual;
		    
		anterior = actual;
		    
		actual = f;	
	}
	
	return f;
}
 
double Factorial(int n){

    	double f = 1;
	    
	 if (n > 1) {
		
		for (int i = 2; i <= n; i++) {
		    
			f *= i;    
		} 
	}
	return f;
}

void matrizX(){

	int x, y, numerosTabla[10][10];
	     
	for (x = 0; x < 10; x++) {
		
		for (y = 0; y < 10; y++) {
		    
			numerosTabla[x][y] = (x * 10) + 1 + y;	
		}
	}
	    
	for (x = 0; x < 10; x++) {
		
		for (y = 0; y < 10; y++) {
		    
			printf("%d ", numerosTabla[x][y]);	
		}	
	printf("\n");
    
	}
}

void sumaDePunteros(){

    int *p1 = NULL;
    int *p2 = NULL;
    int a, b, c;

    a = 4775;
    b = 4561;
    c = a + b;

    printf("-Suma sin punteros -> %d + %d = %d\n", a, b, c);

    p1 = (int*) malloc(sizeof(int));
    p2 = (int*) malloc(sizeof(int));
    
    *p1 = a;
    *p2 = b;

    printf("-Suma con punteros -> *p1 + *p2 = %d\n", *p1 + *p2);

    if (p1 != NULL) {
        free(p1);
        p1 = NULL;
    }

    if (p2 != NULL) {
        free(p2);
        p2 = NULL;
    }
} 
 
void arrayMatrizDePunteros()
{
	int x2[10][10], y2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	    
	int f = 0, cc = 0;
	    
	for (f = 0; f < M; f++) {
		
		for (cc = 0; cc < N; cc++) {
		//Importante inicializar si no genera errores
		x2[f][cc] = (f + 1) * (cc + 1); 
		   
		printf("2 *(x+ %d)+%d)=", f, cc);
		
		}    
	}
	    
	printf("\n\n\n-MATRIZ  \n");
	    
	for (f = 0; f < M; f++) {
		
		for (cc = 0; cc < N; cc++) {
		    
		printf("%d", *(*(x2 + f) + cc));
		
		}    
	}
	    
	printf("\n\n\n-VECTOR: \n");
	    
	for (f = 0; f < M; f++) {
		
		printf("%d", *(y2 + f));   
	}
}

void quickSort(int *arr, int low, int high, int n)
{
	int i = low;
	    
	int j = high;
	    
	int pivot = arr[(low + high) / 2];
	    
	while (i <= j) {
		
		while (arr[i] < pivot) {
		    
			i++;
		}
		
		while (arr[j] > pivot) {
		    
			j--;
		
		}
		
		if (i <= j) {
		    
			int temp = arr[i];
		    
			arr[i] = arr[j];
		    
			arr[j] = temp;
		    
			i++;
		    
			j--;	
		}   
	} 
	 
	if (low < j) {
		
		quickSort(arr, low, j, n);    
	}
	    
	if (i < high) {
		
		quickSort(arr, i, high, n);    
	}
}

int OrMatriz(int n)
{ 
	int *matriz = (int *) malloc(n * n * sizeof(int));	// Asignación de memoria
	
	//Se deja este IF por motivos que si Matriz es null puedo ocurrir corrupcion de memoria
	if (matriz == NULL) {	
	
		printf("Error al asignar memoria.\n");
		return 1;    
	} 
	// Inicialización de la matriz con números aleatorios
	for (i = 0; i < n; i++) {
		
		for (j = 0; j < n; j++) {
		    
			matriz[i * n + j] = rand() % 10000;
		}    
	}
	  
	// Ordenamiento de la matriz con QuickSort
	quickSort(matriz, 0, n * n - 1, n);
	    
	// Impresión de la matriz ordenada
	printf("\nMatriz ordenada:\n");
	    
	for (i = 0; i < n; i++) {
		
		for (j = 0; j < n; j++) {
		    
			printf("%d ", matriz[i * n + j]);	
		}
		
		printf("\n");    
	}
	    
	free(matriz);// Liberación de memoria
	return 0;
}

// Función para crear un nuevo nodo
Node * createNode(int value){
    
	Node * newNode = (Node *) malloc(sizeof(Node));
    
    	//Se deja este IF por motivos que si Node es null puedo ocurrir corrupcion de memoria
	if (newNode == NULL) {
		
		printf("No se pudo asignar memoria");
			
		exit(1);    
	}
	    
	newNode->value = value;
	    
	newNode->left = NULL;
	    
	newNode->right = NULL;
	    
	return newNode;
}
 
// Función para insertar un nodo en el árbol
Node * insertNode(Node * root, int value){

	if (root == NULL) {
		
		return createNode(value);    
	}
	    
	if (value < root->value) {
		
		root->left = insertNode(root->left, value);    
	} else if (value > root->value) {	
		root->right = insertNode(root->right, value);  
		}
	return root;
}
 
// Función para recorrer el árbol en orden
void inOrderTraversal(Node * root){
    
	if (root != NULL) {
		
		inOrderTraversal(root->left);
			
		printf("%d ", root->value);
			
		inOrderTraversal(root->right);
	    
	}

}

void postorden(Node * root){
    
	if (root != NULL) {
		
		postorden(root->left);
			
		postorden(root->right);
			
		printf("%d ", root->value);
	    
	}
}

void preorden(Node * root){
    
	if (root != NULL) {
		
		printf("%d ", root->value);
			
		preorden(root->left);
			
		preorden(root->right);
	}
}
 
int arbolBinario(){

	// Insertar 50000 nodos aleatorios en el árbol
	for (int i = 0; i < 50000; i++) {
	
		int value = rand() % 50000;
		
		root = insertNode(root, value);    
	} 
 
	// Recorrer el árbol en orden e imprimir los valores de los nodos
	printf("\n\n\nRecorrido en orden del árbol:\n\n");
	    
	inOrderTraversal(root);
    
	printf("\n\n\nRecorrido en preorden del árbol:\n\n");
    
	preorden(root);
    
	printf("\n\n\nRecorrido en post del árbol:\n\n");
    
	postorden(root);
    
	printf("\n");
    
	//free(root);
	// Liberar la memoria asignada dinámicamente
	liberarArbol(root);
	    
	return 0;
}

void liberarArbol(Node * root) {

    if (root == NULL) {
        return;
    }

    liberarArbol(root->left);
    liberarArbol(root->right);
    free(root);
}
