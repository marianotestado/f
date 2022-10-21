#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "primerbiblioteca.h"


int menu()
{
    int opcion;
    system("cls");
    printf("         ABM Personas      \n\n");
    printf("1- Alta Persona\n");
    printf("2- Baja Persona\n");
    printf("3- Modificar Persona\n");
    printf("4- Ordenar Persona\n");
    printf("5- Listar Persona\n");
    printf("6- Listar Mujeres\n");
    printf("7- Listar Localidades\n");
    printf("8- Mostrar personas de una localidad\n");
    printf("9- Listar Personas de cada localidad.\n");
    printf("10- Listar veron con mas edad.\n");
    printf("11- Listar cant. de personas en cada localidad.\n");
    printf("20- Salir\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int inicializarPersonas(ePersona lista[], int tam)
{

    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;



}

int buscarLibre(ePersona lista[], int tam)
{
    int indice = -1;
    for(int i=0 ; i < tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice = i;
            break;
        }
    }

    return indice;



}

int altaPersona(ePersona lista[], int tam, int* pId, eLocalidad localidades[], int tamLoc)
{


    int todoOk = 0;
    int indice;
    ePersona auxPersona;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("         Alta Persona       \n\n");

        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("No hay lugar.");
        }
        else
        {

            auxPersona.id = *pId;
            (*pId)++;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxPersona.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxPersona.sexo);
            printf("Ingrese edad: ");
            scanf("%d", &auxPersona.edad);
            printf("Ingrese altura: ");
            fflush(stdin);
            scanf("%f", &auxPersona.altura);

            mostrarLocalidades(localidades, tamLoc);
            printf("Ingrese id localidad: ");
            scanf("%d", &auxPersona.idLocalidad);

            while(!validarIdLocalidad(auxPersona.idLocalidad, localidades, tamLoc))
            {
                mostrarLocalidades(localidades, tamLoc);
                printf("Ingrese id localidad valida: ");
                scanf("%d", &auxPersona.idLocalidad);
            }


            auxPersona.isEmpty = 0;

            lista[indice] = auxPersona;

            todoOk = 1;

        }


        todoOk = 1;
    }

    return todoOk;


}

void mostrarPersona(ePersona p, eLocalidad localidades[], int tam)
{

    char descLocalidad[20];

    if(cargarDescripcionLocalidad(localidades, tam, p.idLocalidad, descLocalidad)==1)
    {
        printf("  %02d     %-10s  %c       %02d     %.2f         %10s \n", p.id,
                                           p.nombre,
                                           p.sexo,
                                           p.edad,
                                           p.altura,
                                           descLocalidad);
    }




}


int mostrarPersonas(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{

    int flag = 1;
    int todoOk = 0;


    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Lista de Personas    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Nombre      Sexo    Edad   Altura    Localidad\n\n");
        printf("---------------------------------------------------------------\n");

        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarPersona(lista[i], localidades, tamLoc);
                flag = 0;
            }

        }

        if(flag)
        {
            printf("No hay personas para mostrar.\n");
        }

        todoOk = 1;
    }

    return todoOk;


}

int bajaPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        mostrarPersonas(lista, tam, localidades, tamLoc);
        printf("-------------------------------------------------\n");
        printf("     Baja Persona     ");
        printf("|  Ingrese ID: ");
         scanf("%d", &id);
        printf("-------------------------------------------------\n");




        indice = buscarPersonaId(lista, tam, id);

        if(indice == -1)
        {
            printf("El id: %d no esta en el sistema.\n", id);
        }
        else
        {
            mostrarPersona(lista[indice], localidades, tamLoc);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("baja cancelada por el ususario.\n");
            }
        }

    }

    return todoOk;

}

int buscarPersonaId(ePersona lista[], int tam, int id)
{
    int indice = -1;
    for(int i=0 ; i < tam; i++)
    {
        if(!lista[i].isEmpty && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

int modificarPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char auxNombre[20];
    char auxSexo;
    int auxEdad;
    float auxAltura;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("     Modificar Persona     \n\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = buscarPersonaId(lista, tam, id);

        if(indice == -1)
        {
            printf("El id: %d no esta en el sistema.\n", id);
        }
        else
        {
            mostrarPersona(lista[indice],localidades, tamLoc);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                    strcpy(lista[indice].nombre, auxNombre);
                    break;
                case 2:
                    printf("Ingrese nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &auxSexo);
                    lista[indice].sexo = auxSexo;
                    break;

                case 3:
                    printf("Ingrese nueva edad: ");
                    fflush(stdin);
                    scanf("%d", &auxEdad);
                    lista[indice].edad = auxEdad;
                    break;
                case 4:
                    printf("Ingrese nueva altura: ");
                    fflush(stdin);
                    scanf("%f", &auxAltura);
                    lista[indice].altura = auxAltura;
                    break;
                case 5:
                    break;
                default:
                    printf("Opcion Invalida.\n");



                }
                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada.\n");
            }
        }

    }

    return todoOk;
}

int confirmaSalida(char* r)
{

    int respuesta = 0;
    char salir;


    if(r != NULL)
    {
        printf("Desea continuar? (s/n)\n");
        fflush(stdin);
        salir = tolower(getchar());
        if(salir == 'n' || salir == 'N')
        {
            *r = 'n';

        }


        respuesta = 1;

    }
    return respuesta;

}

int menuModificacion()
{
    int opcion;
    printf("         Que desea modificar?     \n");
    printf("----------------------------------\n\n");
    printf("1-Nombre\n");
    printf("2-Sexo\n");
    printf("3-Edad\n");
    printf("4-Altura\n");
    printf("5-Salir\n");

    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int ordenarPersonas(ePersona lista[], int tam)
{

    int todoOk= 0;
    ePersona auxPersona;

    if(lista != NULL && tam > 0)
    {

        for(int i=0; i < tam; i++)
        {
            for(int j=i+1; j < tam; j++)
            {
                if((lista[i].sexo > lista[j].sexo) ||
                   (lista[i].sexo == lista[j].sexo &&
                    strcmp(lista[i].nombre, lista[j].nombre) > 0
                    )
                   )
                {
                    auxPersona = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxPersona;
                }

            }
        }


        todoOk =1;
    }

    return todoOk;
}

int mostrarMujeres(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{

    int flag = 1;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Lista de Mujeres    \n");
        printf("---------------------------------------------------------------\n");
        printf("  ID       Nombre      Sexo    Edad   Altura    Localidad\n\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
            {
                if(!lista[i].isEmpty && lista[i].sexo == 'f')
                {
                    mostrarPersona(lista[i],localidades, tamLoc);;
                    flag = 0;
                }


            }

        }

        if(flag)
        {
            printf("No hay mujeres para mostrar.\n");
        }

        todoOk = 1;
    }

    return todoOk;


}

int mostrarPersonasIdLocalidad(int id,ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{

    int flag = 1;
    int todoOk = 0;

    if(id > 0 && lista != NULL && tam>0 && localidades != NULL && tamLoc > 0)
    {


        printf("---------------------------------------------------------------\n");
        printf("  ID       Nombre      Sexo    Edad   Altura    Localidad\n\n");
        printf("---------------------------------------------------------------\n");
        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
                {
                    if(!lista[i].isEmpty && id == lista[i].idLocalidad)
                    {
                        mostrarPersona(lista[i],localidades, tamLoc);;
                        flag = 0;
                    }
                }

        }

        if(flag)
        {
            printf("\nNo hay personas de esa localidad.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}

int mostrarPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{


    int idLocalidad;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Personas de una localidad    \n");

        mostrarLocalidades(localidades, tamLoc);
        printf("Ingrese id localidad: ");
        scanf("%d", &idLocalidad);

        while(!validarIdLocalidad(idLocalidad, localidades, tamLoc))
        {
            mostrarLocalidades(localidades, tamLoc);
            printf("Ingrese id localidad valida: ");
            scanf("%d", &idLocalidad);
        }
        system("cls");
        mostrarPersonasIdLocalidad(idLocalidad, lista, tam, localidades, tamLoc);

        todoOk = 1;
    }

    return todoOk;


}

int mostrarPersonasAllLocalidades(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{


    int todoOk = 0;

    system("cls");
    printf("Personas de cada localidad   \n");
    if(lista != NULL && tam > 0)
    {

        for(int i=0; i < tamLoc; i++ )
        {
            printf("---------------------------------------------------------------\n");
            printf("%10s                              \n", localidades[i].descripcion);
            mostrarPersonasIdLocalidad(localidades[i].id, lista, tam, localidades, tamLoc);
        }

        todoOk = 1;
    }

    return todoOk;



}

int mostrarNombreVaronMasEdad(ePersona lista[], int tam)
{
    int todoOk = 0;
    int mayorEdad;
    int mayorNombre[20];
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].sexo == 'm')
            {
                if(flag || lista[i].edad > mayorEdad)
                {
                    mayorEdad = lista[i].edad;
                    strcpy(mayorNombre, lista[i].nombre);
                    flag = 0;
                }
            }
        }

        system("cls");
        printf("Hombre con mayor edad :\n");
        printf("%s con %d anios.\n", mayorNombre, mayorEdad);
        fflush(stdin);


        todoOk = 1;
    }

    return todoOk;
}

int mostrarCantPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    int todoOk = 0;
    int contador;

    if(lista != NULL && tam > 0 && localidades != NULL && tamLoc > 0)
    {
        system("cls");
        printf("      Cantidad de personas de cada localidad.\n");
        printf("================================================\n\n");
        for(int i=0; i < tamLoc; i++)
        {
            printf("Localidad: %s\n", localidades[i].descripcion);
            contador = 0;
            for(int j=0; j < tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idLocalidad == localidades[i].id)
                {
                    contador++;
                }

            }
            printf("Cantidad: %d\n\n", contador);
        }
        todoOk = 1;
    }
    return todoOk;
}


localidadMenosHabitada(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    int todoOk = 0;
    int contadores[tamLoc];
    int menor;
    char menorLoc[20];

    for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {

                contadores[i] = 0;
            }
        }


    if(lista != NULL && tam > 0 && localidades != NULL && tamLoc > 0)
    {
        system("cls");
        printf("      Localidad menos habitada.\n");
        printf("================================================\n\n");
        for(int i=0; i < tamLoc; i++)
        {
            for(int j=0; j < tam ; j++)
            {
                if(!lista[j].isEmpty && lista[j].idLocalidad == localidades[i].id)
                {
                    contadores[i]++;
                }

            }


        }
        for(int i=0; i<tamLoc ; i++)
            {
                if(i==0 || contadores[i] < menor)
                {
                    menor = contadores[i];
                }
            }
            for(int i=0; i<tamLoc ; i++)
            {
                if(contadores[i] == menor)
                {
                    printf("%s con %d cantidad de habitantes.\n",localidades[i].descripcion, contadores[i]);
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPromedioAlturaLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{


    int idLocalidad;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        printf("                      Promedio de altura de una localidad    \n");

        mostrarLocalidades(localidades, tamLoc);
        printf("Ingrese id localidad: ");
        scanf("%d", &idLocalidad);

        while(!validarIdLocalidad(idLocalidad, localidades, tamLoc))
        {
            mostrarLocalidades(localidades, tamLoc);
            printf("Ingrese id localidad valida: ");
            scanf("%d", &idLocalidad);
        }
        system("cls");
        mostrarPromedioAlturaIdLocalidad(idLocalidad, lista, tam, localidades, tamLoc);


        todoOk = 1;
    }

    return todoOk;


}

int mostrarPromedioAlturaIdLocalidad(int id,ePersona lista[], int tam, eLocalidad localidades[], int tamLoc)
{
    char descLocalidad[20];
    int contador = 0;
    float acumAlturas = 0;
    int todoOk = 0;
    float promedio;

    if(id > 0 && lista != NULL && tam>0 && localidades != NULL && tamLoc > 0)
    {
        for(int i=0; i < tam ; i++)
        {
            if(!lista[i].isEmpty)
                {
                    if(!lista[i].isEmpty && lista[i].idLocalidad == id)
                    {
                        acumAlturas += lista[i].altura;
                        contador++;
                    }
                }

        }

        cargarDescripcionLocalidad(localidades,tamLoc,id, descLocalidad);

        if(!contador)
        {

            printf("\nNo hay personas en %s.\n", descLocalidad);
        }
        else
        {
            promedio = acumAlturas / contador;
            printf("Promedio Edad en %s :   %.2f\n", descLocalidad, promedio);
        }
        todoOk = 1;
    }

    return todoOk;
}
