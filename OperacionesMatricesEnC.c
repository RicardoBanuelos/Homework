#include <stdio.h>
#include <time.h>
#define ren 20
#define col 20

typedef struct{
	
	int renglones;
	int columnas;
		
}datos_matriz;

datos_matriz capturas[2];

int M1[ren][col];
int M2[ren][col];
int M1_TRAS[ren][col];
int M2_TRAS[ren][col];
int M_SUMA[ren][col];
int M_RESTA[ren][col];
int M_MULTI[ren][col];

void inicializa_matrices();
void imprime_matrices();
void tras_matrices();
void imprime_tras();
int valida_suma_resta();
int valida_multi();
void suma_matriz();
void resta_matriz();
void multi_matriz();
void imprime_suma();
void imprime_resta();
void imprime_multi();

int main()
{
	srand( time (0) );
	
	//captura datos matriz 1
	printf("Programa soporta 20 renglones y columnas.\n\n");
	printf("Renglones matriz 1: ");
	scanf("%d",&capturas[0].renglones);
	printf("Columnas matriz 1: ");
	scanf("%d",&capturas[0].columnas);
	printf("\n");
	//capturamos datos matriz 2
	printf("Renglones matriz 2: ");
	scanf("%d",&capturas[1].renglones);
	printf("Columnas matriz 2: ");
	scanf("%d",&capturas[1].columnas);
	
	if(capturas[0].renglones<=20 && capturas[0].columnas<=20 && capturas[1].renglones<=20 && capturas[1].columnas<=20){
	
	    //inicializamos e imprimimos las  matrices originales
	    inicializa_matrices();
	    imprime_matrices();
	
	    //imprimimos las matrices traspuestas
	    tras_matrices();
        imprime_tras();
	
	    //resultados
	    if(valida_suma_resta()){
		    suma_matriz();
		    resta_matriz();
		    imprime_suma();
		    imprime_resta();
	    }
	    else{
		    printf("\nNo se pueden sumar ni restar\n");
	    }
	    if(valida_multi()){
		    multi_matriz();
		    imprime_multi();
	    }
	    else{
		    printf("\nNo se pueden multiplicar\n");
	    }
   }
   else{
   	printf("\n");
   	if(capturas[0].renglones>20){
   		printf("Los renglones de la matriz 1 exceden las dimensiones establecidas.\n");
	   }
	if(capturas[0].columnas>20){
   		printf("Las columnas de la matriz 1 exceden las dimensiones establecidas.\n");
	   }
	if(capturas[1].renglones>20){
   		printf("Los renglones de la matriz 2 exceden las dimensiones establecidas.\n");
	   }
	if(capturas[1].columnas>20){
   		printf("Los renglones de la matriz 1 exceden las dimensiones establecidas.\n");
	   }
   }
	
}

void inicializa_matrices()
{
	int i, j;
	
	//valores matriz 1
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			M1[i][j] = rand()%10;
		}
	}
	//valores matriz 2
	for(i=0; i<capturas[1].renglones; i++){
		for(j=0; j<capturas[1].columnas; j++){
			M2[i][j] = rand()%10;
		}
	}
}

void imprime_matrices()
{
	int i,j;
	//imprimimos matriz 1
	printf("\nMatriz 1:\n");
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			printf("%d ", M1[i][j]);
		}
		printf("\n");
	}
	
	//imprimimos matriz 2
	printf("\nMatriz 2:\n");
	for(i=0; i<capturas[1].renglones; i++){
		for(j=0; j<capturas[1].columnas; j++){
			printf("%d ", M2[i][j]);
		}
		printf("\n");
	}
	
}

void tras_matrices()
{
	int i,j;
	//traspuesta matriz 1
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			M1_TRAS[j][i] = M1[i][j];
		}
	}
	//traspuesta matriz 2
	for(i=0; i<capturas[1].renglones; i++){
		for(j=0; j<capturas[1].columnas; j++){
			M2_TRAS[j][i] = M2[i][j];
		}
	}
}
void imprime_tras()
{
	int i,j;
	//matriz 1 traspuesta
	printf("\nMatriz 1 traspuesta:\n");
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			printf("%d ",M1_TRAS[i][j]);
		}
		printf("\n");
	}
	//matriz 2 traspuesta
	printf("\nMatriz 2 traspuesta\n");
	for(i=0; i<capturas[1].renglones; i++){
		for(j=0; j<capturas[1].columnas; j++){
			printf("%d ",M2_TRAS[i][j]);
		}
		printf("\n");
	}
}

int valida_suma_resta()
{
	int bandera;
	
	if(capturas[0].renglones==capturas[1].renglones && capturas[0].columnas==capturas[1].columnas){
		bandera = 1;
	}
	else{
		bandera = 0;
	}
	
	return bandera;
}

int valida_multi()
{
	int bandera;
	
	if(capturas[0].columnas==capturas[1].renglones){
		bandera = 1;
	}
	else{
		bandera = 0;
	}
	return bandera;
}

void suma_matriz()
{
	int i, j;
	
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			M_SUMA[i][j] = M1[i][j] + M2[i][j];
		}
	}
}

void resta_matriz()
{
	int i, j;
	
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			M_RESTA[i][j] = M1[i][j] - M2[i][j];
		}
	}
}

void multi_matriz()
{
	int i,j,k;
	
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[1].columnas; j++){
			for(k=0; k<capturas[0].columnas; k++){
				M_MULTI[i][j] = M_MULTI[i][j] + M1[i][k]*M2[k][j];
			}
		}
	}
}

void imprime_suma()
{
	int i, j;
	//imprimimos suma de matriz
	printf("\nMatriz Suma:\n");
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			printf("%d  ", M_SUMA[i][j]);
		}	
		printf("\n");
	}
}

void imprime_resta()
{
	int i, j;
	//imprimimos suma de matriz
	printf("\nMatriz Resta:\n");
	for(i=0; i<capturas[0].renglones; i++){
		for(j=0; j<capturas[0].columnas; j++){
			printf("%d  ", M_RESTA[i][j]);
		}	
		printf("\n");
	}
}

void imprime_multi()
{	
    int i, j;
	//imprimimos multiplicacion de matriz
	printf("\nMatriz Multiplicada:\n");
	for(i=0; i<capturas[1].columnas; i++){
		for(j=0; j<capturas[0].renglones; j++){
			printf("%d   ", M_MULTI[i][j]);
		}
		printf("\n");
	}
}
