#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "segundabiblioteca.h"



int cargarDescripcionLocalidad(eLocalidad localidades[],int tam,int idLocalidad, char descripcion[])
{

    int todoOk = 0;
    int flag = 1;

    if(localidades != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for(int i=0; i < tam; i++)
        {
            if(localidades[i].id == idLocalidad)
                {
                    strcpy(descripcion, localidades[i]. descripcion);
                    flag = 0;
                    break;
                }

        }


        if(flag)
        {
            todoOk = -1;
        }

    }

    return todoOk;

}

int mostrarLocalidades(eLocalidad localidades[], int tam)
{
    int todoOk = 0;

    if(localidades != NULL && tam > 0)
    {
        system("cls");
        printf("   ID       Localidad\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %02d      %-10s  \n", localidades[i].id, localidades[i].descripcion);

        }
        todoOk = 1;

    }

    return todoOk;
}

int validarIdLocalidad(int id, eLocalidad localidades[], int tam)
{
    int todoOk = 0;

    if(localidades != NULL && tam > 0 && id > 0)
    {

        for(int i=0; i < tam; i++)
        {
            if(localidades[i].id == id)
                {
                    todoOk = 1;
                    break;
                }

        }

    }

    return todoOk;
}

//informes ------------------------------------------------------------------------

