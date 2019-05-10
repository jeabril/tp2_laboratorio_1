#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define SIZE 1000
#define LLENO 1
#define VACIO -1




void Menu(sEmployee arrayEmployee[])
{

    int option;
    int indice;
    char seguir;
    int flag=0;




    do
    {
        system("color F5");

        printf("                         ***  >>>MENU DE OPCIONES<<<  ***\n\n\n");

        printf("                            __________________________\n");
        printf("                           |                          |\n");
        printf("                           | 1_ ALTA    2_ BAJA       |\n");
        printf("                           |                          |\n");
        printf("                           |                          |\n");
        printf("                           | 3_ MODIFICAR 4_ INFORMAR |\n");
        printf("                           |                          |\n");
        printf("                           |__________________________|\n");


        printf(" \n\nElija una opcion: ");
        scanf("%d", &option);
        system("cls");
        switch(option)
        {
        case 1:
            flag=1;
            indice=ArraySpace(arrayEmployee,SIZE);
            if(indice!=VACIO)
            {
                addEmployees(arrayEmployee, SIZE,indice);
            }
            else
            {
                printf("No hay espacio\n");
            }
            break;


        case 2:
             if(flag==0)
            {

                printf("Usted debe cargar al empleado primero\n");

            }
            else
            {
                printEmployees(arrayEmployee,SIZE);
                printf(" \n                  ***   >>> DAR DE BAJA A EMPLEADOS <<<   ***\n\n");
                removeEmployee(arrayEmployee,SIZE);
            }


            break;


        case 3:
             if(flag==0)
            {
                printf("Usted debe cargar al empleado primero\n");
            }
            else
            {
                printEmployees(arrayEmployee,SIZE);
                printf(" \n                  ***   >>> MODIFICAR EMPLEADOS <<<   ***\n\n");
                modifyEmployee(arrayEmployee,SIZE);

            }

            break;


        case 4:
            if(flag==0)
            {

                printf("Usted debe cargar al empleado primero");

            }
            else
            {
                sortEmployeeByLastName(arrayEmployee,SIZE);
                sortEmployeeBySector(arrayEmployee,SIZE);
                AverageSalaryAndHighestSalary(arrayEmployee,SIZE);

            }

            break;
        }
        printf("\nDesea volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }
    while(seguir =='s');

}
int findEmployeeById(sEmployee arrayEmployee[],int size)
{
    int i ;
    for( i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==VACIO)
        {
            arrayEmployee[i].id=i+1;
            break;
        }

    }
    return i;
}

void initEmployees(sEmployee arrayEmployee[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arrayEmployee[i].isEmpty=VACIO;
    }

}
int ArraySpace(sEmployee arrayEmployee[],int size)
{
    int aux=VACIO;
    int i;

    for(i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void addEmployees(sEmployee arrayEmployee[],int size,int i)
{

    int n;
    int a;
    int flagName=0;
    int flagLastName=0;
    char salary;
    char sector;



    printf(" \n                  ***   >>> DAR DE ALTA A EMPLEADOS <<<   ***\n\n");


    printf("ID es:%d",findEmployeeById(arrayEmployee,SIZE));

    printf("\nIngrese nombre: ");



    do
    {
        flagName= 0;
        fflush(stdin);
        gets(arrayEmployee[i].name);
        for(n=0; n<strlen(arrayEmployee[i].name); n++)
        {
            if((arrayEmployee[i].name[n] < 'a' || arrayEmployee[i].name[n] > 'z') &&
                    (arrayEmployee[i].name[n] < 'A' || arrayEmployee[i].name[n] > 'Z'))
            {
                printf("Error, el nombre solamente puede ir compuesto por letras.  Reingrese nombre: ");
                flagName = LLENO;
                break;
            }
        }
    }
    while(flagName);

    printf("\nIngrese apellido: ");
    do
    {
        flagLastName= 0;
        fflush(stdin);
        gets(arrayEmployee[i].lastName);
        for(a=0; a<strlen(arrayEmployee[i].lastName); a++)
        {
            if((arrayEmployee[i].lastName[a] < 'a' || arrayEmployee[i].lastName[a] > 'z') &&
                    (arrayEmployee[i].lastName[a] < 'A' || arrayEmployee[i].lastName[a] > 'Z'))
            {
                printf("ERROR, el apellido solamente puede ir compuesto por letras. Reingrese apellido: ");
                flagLastName = LLENO;
                break;
            }
        }
    }
    while(flagLastName);


    printf("\nIngrese salario: ");
    scanf("%f", & arrayEmployee[i].salary);

    while(arrayEmployee[i].salary<0)
    {
        printf("\nERROR. Reingrese salario: ");
        scanf("%f", & arrayEmployee[i].salary);

    }

    printf("\nIngrese sector: ");
    scanf("%d", & arrayEmployee[i].sector);
    while(arrayEmployee[i].sector<0)
    {
        printf("\nERROR.Reingrese sector: ");
        scanf("%d", & arrayEmployee[i].sector);

    }

    arrayEmployee[i].isEmpty=LLENO;
}


void removeEmployee(sEmployee arrayEmployee[],int size)
{

    int flag=0;
    int aceptar1;
    int auxId2;


    printf("\nIngrese el ID que desea dar de baja: ");
    scanf("%d", & auxId2);

    for(int i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty!=VACIO && auxId2==arrayEmployee[i].id)
        {
            flag=1;
            printf("\nDesea dar de baja a este empleado?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este empleado.\n");
                arrayEmployee[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nPrecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe ID ingresalo nuevamente\n");
    }
}





void modifyEmployee(sEmployee arrayEmployee[],int size)
{



    int aceptar2;
    int i;
    int auxId;
    int flag =0;
    char modify;
    int flagName2=0;
    int flagLastName2=0;


    printf("\nIngrese el ID que desea modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty!=VACIO && auxId==arrayEmployee[i].id)
        {
            do
            {
                system("cls");
                printf("                            ______________\n");
                printf("                           |              |\n");
                printf("                           |  5_ NOMBRE   |\n");
                printf("                           |              |\n");
                printf("                           |  6_ APELLIDO |\n");
                printf("                           |              |\n");
                printf("                           |  7_ SALARIO  |\n");
                printf("                           |              |\n");
                printf("                           |  8_ SECTOR   |\n");
                printf("                           |              |\n");
                printf("                           |______________|\n");

                printf("\nQue desea modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 5:
                    printf("Ingrese un nuevo nombre: ");
                    do
                    {
                        flagName2= 0;
                        fflush(stdin);
                        gets(arrayEmployee[i].name);
                        for(int n=0; n<strlen(arrayEmployee[i].name); n++)
                        {
                            if((arrayEmployee[i].name[n] < 'a' || arrayEmployee[i].name[n] > 'z') &&
                                    (arrayEmployee[i].name[n] < 'A' || arrayEmployee[i].name[n] > 'Z'))
                            {
                                printf("\nERROR. Reingrese nuevo nombre: ");
                                flagName2 = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagName2);
                    break;

                case 6:
                    printf("\nIngrese nuevo apellido: ");
                    do
                    {
                        flagLastName2= 0;
                        fflush(stdin);
                        gets(arrayEmployee[i].lastName);
                        for(int a=0; a<strlen(arrayEmployee[i].lastName); a++)
                        {
                            if((arrayEmployee[i].lastName[a] < 'a' || arrayEmployee[i].lastName[a] > 'z') &&
                                    (arrayEmployee[i].lastName[a] < 'A' || arrayEmployee[i].lastName[a] > 'Z'))
                            {
                                printf("\nERROR. Reingrese nuevo apellido: ");
                                flagLastName2 = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagLastName2);
                    break;

                case 7:
                    printf("\nIngrese nuevo salario: ");
                    scanf("%f", & arrayEmployee[i].salary);
                    while(arrayEmployee[i].salary<0)
                    {
                        printf("\nERROR. Reingrese nuevo salario: ");
                        scanf("%f", & arrayEmployee[i].salary);

                    }
                    break;

                case 8:
                    printf("\nIngrese nuevo sector: ");
                    scanf("%d", & arrayEmployee[i].sector);
                    while(arrayEmployee[i].sector<0)
                    {
                        printf("\nERROR. Reingrese nuevo sector: ");
                        scanf("%d", & arrayEmployee[i].sector);

                    }
                    break;

                }
                printf("\nDesea modificar otro campo?\ns/para continuar n/para salir\n");
                modify=getch();
                system("cls");
            }
            while(modify=='s');


            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe ID ingresalo nuevamente\n");
    }
}

void sortEmployeeByLastName( sEmployee arrayEmployee[], int size)
{
    int i;
    int j;
    sEmployee aux;
    printf("  Ordenado alfabeticamente por apellido:\n\n");
    for(i=0; i< size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(stricmp(arrayEmployee[i].lastName,arrayEmployee[j].lastName)>0)
            {
                aux=arrayEmployee[i];
                arrayEmployee[i]=arrayEmployee[j];
                arrayEmployee[j]=aux;

            }
        }
    }
    for (i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].salary,arrayEmployee[i].sector);
        }

    }

}
void sortEmployeeBySector( sEmployee arrayEmployee[], int size)
{
    int i;
    int j;
    sEmployee aux2;
    printf("\n  Ordenado alfabeticamente por sector:\n\n");
    for(i=0; i< size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arrayEmployee[i].sector>arrayEmployee[j].sector)
            {
                aux2=arrayEmployee[i];
                arrayEmployee[i]=arrayEmployee[j];
                arrayEmployee[j]=aux2;

            }
        }
    }
    for (i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmployee[i].name,arrayEmployee[i].lastName,arrayEmployee[i].salary,arrayEmployee[i].sector);
        }

    }
}
void AverageSalaryAndHighestSalary(sEmployee arrayEmployee[],int size)
{
    int i;
    float acum=0;
    float promedio;
    float contador=0;
    int contDePromedio=0;
    for(i=0; i<size; i++)
    {
        acum=acum+arrayEmployee[i].salary;
        if(arrayEmployee[i].isEmpty==LLENO)
        {
            contador++;
        }

    }

    promedio= (float) acum/contador;
    if(arrayEmployee[i].isEmpty>promedio)
    {
        contDePromedio++;
    }
    printf("\n  El salario total es:%.2f y el promedio es:%.2f\n\n",acum,promedio);
    printf("\n  los empleados que superaron el salario son:%d\n\n",contDePromedio);
}
void printEmployees(sEmployee arrayEmployee[],int size)
{
    for(int i=0; i<size; i++)
    {
        if(arrayEmployee[i].isEmpty==LLENO)
        {

            printf("id:%d  nombre:%s  apellido:%s\n\n",arrayEmployee[i].id,arrayEmployee[i].name,arrayEmployee[i].lastName);
        }
    }

}

