#include <string.h>
#include "datawarehouse.h"



char nombres[10][20] = {
    "Juan",
    "Pedro",
    "Sofia",
    "Miguel",
    "Valentina",
    "Camila",
    "Andres",
    "Luis",
    "Diego",
    "Analia"
};

char sexos[10] = {'m', 'm', 'f', 'm', 'f', 'f', 'f' , 'm', 'm', 'f'};

int edades[10] = {23,21,28,32,45,29,39,23,28,27};

float altura[10] = {1.65,1.67,1.9,1.78,1.75,1.7,1.65,1.71,1.69, 1.68};

int idLocalidades[10]={1001, 1002, 1000, 1001, 1001, 1003, 1004, 1002, 1004, 1001};



int hardcodearPersonas(ePersona lista[], int tam, int cant, int* pId)
{

    int todoOk = 0;

    if(lista != NULL && tam > 0 && cant > 0 && pId != NULL)
    {


        int contador = -1;
        if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
        {
            contador = 0;
            for(int i=0; i < cant; i++)
            {
                lista[i].id = *pId;
                (*pId)++;
                strcpy(lista[i].nombre, nombres[i]);
                lista[i].sexo = sexos[i];
                lista[i].edad = edades[i];
                lista[i].altura = altura[i];
                lista[i].idLocalidad = idLocalidades[i];
                lista[i].isEmpty = 0;
                contador++;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}


