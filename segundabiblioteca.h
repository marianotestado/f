#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eLocalidad;


#endif // LOCALIDAD_H_INCLUDED

int cargarDescripcionLocalidad(eLocalidad localidades[],int tam,int idLocalidad, char descripcion[]);
int mostrarLocalidades(eLocalidad localidades[],int tam);
int validarIdLocalidad(int id, eLocalidad localidades[], int tam);

