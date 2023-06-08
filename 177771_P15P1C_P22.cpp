/*
Montejano Briano Uriel 177771
10/05/2022
Laboratorio programación
Programa que imprime una tabla con valores random con un arreglo bidimensional
*/

//Declaración de librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float tabla(float num[][5], int pre[][5]); //Declaración de variables flotantes
void imprimir(float num[][5], char prod[][10], char tipo[][12]); //Declaración de variables void imprimir
void presentacion(float num[][5], char prod[][10], char tipo[][12]); //Declaración de variables void presentacion
void litro(float num[][5], char prod[][10], char tipo[][12]); //Declaración de variables void litro
void promedio(float num[][5], char prod[][10], char tipo[][12]); //Declaración de variables void promedio

main()//Funcion principal
{
	srand(time(NULL)); //Declarar el tiempo con el reloj del sistema RAND
	int pre[6][5]; //Declaracion de arreglo entero
	float num[6][5]; //Declaracion de arreglo flotante
	char prod[6][10]={"Coca","Pepsi","Big", "Seven", "Sprite", "Mirinda"}, tipo[5][12]={"Lata", "500ml", "600ml","1lt", "2lt"}; //Declaracion de varfiable para el borde de la tabla
	tabla(num,pre); //Invoca la funcion tabla
	imprimir(num, prod, tipo); //Invoca la funcion imprimir
	presentacion(num, prod, tipo);//Invoca la funcion presentacion
	litro(num, prod, tipo);//Invoca la funcion imprimir litro
	promedio(num, prod, tipo);//Invoca la funcion imprimir promedio
}

float tabla(float num[][5], int pre[][5]) //Funcion flotante tabla
{
	int a[5]={5,8,9,14,19}, b[5]={10,15,16,21,27}; //Declara funcion de arreglos de numeros en rangos de los precios
	float deci=0;
	
	for(int i=0;i<6;i++) //Contador de i hasta menor que 6 (Filas)
	{
		deci=(1+rand()%10)/10;
		for(int j=0;j<5;j++) //Contador de j hasta menor que 5 (Columnas)
		{
			pre[i][j] = a[j]+rand()%(b[j]-a[j]);//Define el arreglo como aleatorios de los rangos de los precios
			if(pre[i][j]%2==0) //Condicional si el arreglo MOD 2 es = 0
			{
				num[i][j]=pre[i][j];//Define la variable entera como flotante si MOD 2 = 0
			}
			else
			{
				num[i][j]=pre[i][j];//Define la variable entera como flotante
			}
		}
	}	
}



void imprimir(float num[][5], char prod[][10], char tipo[][12]) //Funcion imprimir
{
	for(int i=0;i<6;i++)//Ciclo de i hasta menor que 6
	{
		printf("\t%s\t", tipo[i]);//Impreison borde
	}
	printf("\n");
	
	for(int i=0;i<6;i++)//Ciclo i hasta menor que 6
	{
		printf("%s\t", prod[i]); //Impresion borde
		for(int j=0;j<5;j++)
		{
			printf("%.1f\t\t", num[i][j]); //Impresion de arreglo
		}
		printf("\n");
	}
}

void presentacion(float num[][5], char prod[][10], char tipo[][12]) //Función presentación
{
	int tip, posil=0, posi5=0,posi6=0,posi1=0,posi2=0; //Declaracion de variables tipo entero
	float may=0; //Declaración de variables tipo flotante
	
	//Opciones para elegir en el menú
		printf("\nCual presentacion deseas consultar: \n");
		printf("1.- Lata\n");
		printf("2.- 500ml\n");
		printf("3.- 600ml\n");
		printf("4.- 1lt\n");
		printf("5.- 2lt\n");
		printf("Selecciona una opcion\n");
		scanf("%i",&tip);
		switch(tip)//Realizacion del menú
		{
			case 1: //Caso 1 del menu
				{
					printf("Seleccionaste Lata\n"); 
					may=num[0][0]; //Define a num[0][0] como el dato mayor
					for(int i=0;i<5;i++)//Recorre el i hasta menor al 5 en eje x
					{
						if(num[i][0]>may)//Condicional si numero de 1 en x y Y0 es mayor a mayor
						{
							may=num[i][0]; //Define num[i][0] como el arreglo mayor
							posil=i; //Obtiene la posicion de lata				
						}		
					}
					printf("El producto es del tipo: %s\n", prod[posil]);
					printf("El precio mas caro es de: %.2f\n",may);
				}
				break;
				
			case 2:
				{
					printf("\nSeleccionaste 500ml\n");
					may=num[0][1];//Define a num[0][1] como el dato mayor
					for(int i=0;i<5;i++)//Recorre el i hasta menor al 5 en eje x
					{
						if(num[i][1]>may)
						{
							may=num[i][1];//Define arreglo mayor
							posi5=i;//Obtiene la posicion de 500ml					
						}		
					}
					printf("El producto es del tipo: %s\n", prod[posi5]);
					printf("El precio mas caro es de: %.2f\n",may);
				}
				break;
				
			case 3:printf("Seleccionaste 600ml\n");
				{
					printf("\nSeleccionaste 600ml\n");
					may=num[0][2];//Define a num[0][2] como el dato mayor
					for(int i=0;i<5;i++)//Recorre el i hasta menor al 5 en eje x
					{
						if(num[i][2]>may)
						{
							may=num[i][2];//Define arreglo mayor
							posi6=i;//Obtiene la posicion de 600ml					
						}		
					}
					printf("El producto es del tipo: %s\n", prod[posi6]);
					printf("El precio mas caro es de: %.2f\n",may);
				}
				break;
				
			case 4:
				{
					printf("\nSeleccionaste 1lt\n");
					may=num[0][3];//Define a num[0][3] como el dato mayor
					for(int i=0;i<5;i++)//Recorre el i hasta menor al 5 en eje x
					{
						if(num[i][3]>may)
						{
							may=num[i][3];//Define arreglo mayor
							posi1=i;//Obtiene la posicion de 1lt				
						}		
					}
					printf("El producto es del tipo: %s\n", prod[posi1]);
					printf("El precio mas caro es de: %.2f\n",may);
				}
				break;
				
			case 5:
				{
					printf("\nSeleccionaste 2lt\n");
					may=num[0][4];//Define a num[0][4] como el dato mayor
					for(int i=0;i<5;i++)//Recorre el i hasta menor al 5 en eje x
					{
						if(num[i][4]>may)
						{
							may=num[i][4];//Define arreglo mayor
							posi2=i;//Obtiene la posicion de 2lt				
						}		
					}
					printf("El producto es del tipo: %s\n", prod[posi2]); //Impresion del tipo
					printf("El precio mas caro es de: %.2f\n",may); //Impresion del precio mas caro
				}
				break;
			default: printf("Seleccionaste una opción no valida\n"); //Cualquier otro dato menciona que no es una opcion valida
				break;
		}
}

void litro(float num[][5], char prod[][10], char tipo[][12])//Funcion litro, definir los refrescos mas caros por litro
{
	int car=0, car2=0, pos1=0, pos2=0; //Variables entero
	car=num[0][3]; //Define num[0][3] como el más caro
	for(int i=0;i<5;i++)//Ciclo i hasta menos 5
	{
		if(num[i][3]>car)//Condicional de si num es mayor que el producto mas caro
		{
			car=num[i][3]; //Define a ese precio como el mas caro
			pos1=i; //Obtiene la posicion del producto más caro
		}
	}
	
	for(int j=0;j<5;j++)//Ciclo j hasta menos 5
	{
		if(num[j][3]>car2 and num[j][3]<car)//Condicional si el producto es mas caro que el 2do producto mas marco y menor al primero más caro
		{
				car2=num[j][3]; //Obtiene el segundo precio mas caro
				pos2=j;	//Obtiene la posicion 2
		}
	}
	printf("Refrescos mas caros de 1lt\n");
	printf("%s\n", prod[pos1]); //Primer producto mas caro
	printf("%s\n", prod[pos2]); //Segundo producto mas caro
}

void promedio(float num[][5], char prod[][10], char tipo[][12])//Función promedio
{
    int posi=0; //Variable entero
    float prom[6]={0}, menor=0; //Variables flotantes
    for(int i=0;i<6;i++) //Ciclo i hasta menos 6
    {
        for(int j=0;j<5;j++) //Ciclo i hasta menos 5
        {
            prom[i]=prom[i]+num[i][j];//Suma de todos los precios
        }
    }

    for(int i=0;i<6;i++)//Ciclo i hasta menos 6
    {
        prom[i]=prom[i]/5; //Divide la suma de precios entre 5 para obentener el promedio
    }

    menor=prom[0]; //Define el promedio inicial como el menor
    for(int i=0;i<6;i++)//Ciclo i hasta menos 6
    {
        if(prom[i]<menor)//Condicional si promedio recorrido es menor que menor
        {
        	menor=prom[i]; //Define el promedio menor
            posi=i; //Obtiene la posicion del menor
        }
    }

    printf("\nPromedios: \n");
    for(int j=0;j<6;j++)//Ciclo i hasta menos 6
    {
        printf("%s\t%.1f\n",prod[j],prom[j]);//Imprime los productos con sus respectivos promedios de precios
    }
    printf("\nEl producto mas barato: \n%s", prod[posi]); //Imprime el producto con el promedio más bajo
}
