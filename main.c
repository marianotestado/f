#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "primerbiblioteca.h"
#include "datawarehouse.h"
#include "segundabiblioteca.h"


#define TAM 10
#define TAM_LOC 5








int main()
{

    char seguir = 's';
    int nextId = 20000;
    ePersona lista[TAM];

    eLocalidad localidades[TAM_LOC] = {
        {1000,"Avellaneda"},
        {1001,"Bernal"},
        {1002,"Quilmes"},
        {1003,"Lanus"},
        {1004,"Sarandi"},

    };

    if( !inicializarPersonas(lista, TAM))
    {
        printf("Problema al inicializar.\n");
    }

    hardcodearPersonas(lista, TAM, 5, &nextId);

    do
    {
        switch(menu())
        {
            case 1:
                if(!altaPersona(lista,TAM,&nextId, localidades, TAM_LOC))
                {
                    printf("No se pudo realizar el alta.\n");
                }
                else
                {
                    printf("Alta Exitosa.\n");
                }
                break;
            case 2:
                if(!bajaPersona(lista, TAM, localidades, TAM_LOC))
                {
                    printf("No se pudo realizar la baja.");
                }
                else
                {
                    printf("Baja Exitosa.\n");
                }

                break;
            case 3:
                if(!modificarPersona(lista, TAM, localidades, TAM_LOC))
                {
                    printf("No se pudo realizar la modificacion.");
                }
                else
                {
                    printf("Modificacion Exitosa.\n");
                }
                break;
            case 4:
                if(!ordenarPersonas(lista, TAM))
                {
                    printf("No se pudo realizar el ordenamiento.");
                }
                else
                {
                    printf("Ordenamiento exitoso.\n");
                }
                break;
            case 5:
                mostrarPersonas(lista, TAM, localidades, TAM_LOC);
                break;

            case 6:
                mostrarMujeres(lista, TAM, localidades, TAM_LOC);
                break;

            case 7:
                mostrarLocalidades(localidades, TAM_LOC);
                break;

            case 8:
                mostrarPersonasLocalidad(lista, TAM, localidades, TAM_LOC);
                break;

            case 9:
                mostrarPersonasAllLocalidades(lista, TAM, localidades, TAM_LOC);
                break;

            case 10:
                mostrarNombreVaronMasEdad(lista, TAM);
                break;

            case 11:
                mostrarCantPersonasLocalidad(lista, TAM, localidades, TAM_LOC);
                break;

            case 12:
                localidadMenosHabitada(lista, TAM, localidades, TAM_LOC);
                break;

            case 13:
                mostrarPromedioAlturaLocalidad(lista, TAM, localidades, TAM_LOC);
                break;


            case 20:
                confirmaSalida(&seguir);
                break;

            default:
                printf("Opcion Invalida!!!\n");


        }
        system("pause");

    }while(seguir == 's');


    return 0;
}

/*int validarIdCarrera(int id, eCarrera carreras[], int tam);
{

    int esValido = 0;
    if(carreras != NULL && id > 0 && tam >0)
    {
        for(int=0; i < tam; i++)
        {
            if(carreras[i].id == id)
            {
                esValido = 1;
                break;
            }
        }

    }

    return esValido;

}  */

