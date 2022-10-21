#include "segundabiblioteca.h"

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float altura;
    int idLocalidad;
    int isEmpty;



}ePersona;

#endif // PERSONA_H_INCLUDED

int menu();
int inicializarPersonas(ePersona lista[], int tam);
int buscarLibre(ePersona lista[], int tam);
int altaPersona(ePersona lista[], int tam, int* pId, eLocalidad localidades[], int tamLoc);
void mostrarPersona(ePersona p,eLocalidad localidades[], int tam);
int mostrarPersonas(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int bajaPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int buscarPersonaId(ePersona lista[], int tam, int id);
int modificarPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int confirmaSalida(char* r);
int menuModificacion();
int ordenarPersonas(ePersona lista[], int tam);
//    informes------------------------------------------------------------------------
int mostrarMujeres(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarPersonasIdLocalidad(int id,ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarPersonasAllLocalidades(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarNombreVaronMasEdad(ePersona lista[], int tam);
int mostrarCantPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int localidadMenosHabitada(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int promedioAlturaLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarPromedioAlturaLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
int mostrarPromedioAlturaIdLocalidad(int id,ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);
