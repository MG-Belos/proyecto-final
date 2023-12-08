/*****************************************************************************************************************
    UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO
    FACULTAD DE ESTUDIOS SUPERIORES -ARAGON-

    Computadoras y programacion.
    (c) Ernesto Peñaloza Romero 2015

    Quiso decir: Programa principal de la aplicacion de la distancia de Levenstein.

    NO MODIFIQUE ESTE ARCHIVO

******************************************************************************************************************/

#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <stdlib.h>
#include <ctype.h>
#define TAMTOKEN 50
#define NUMPALABRAS 100
#define LONGITUD 32

char abecedario[LONGITUD + 7] = "abcdefghijklmnñopqrstuvwxyzáéíóú";

//Funciones publicas del proyecto
/*****************************************************************************************************************
    DICCIONARIO: Esta funcion crea el diccionario completo
    char *	szNombre				:	Nombre del archivo de donde se sacaran las palabras del diccionario
    char	szPalabras[][TAMTOKEN]	:	Arreglo con las palabras completas del diccionario
    int		iEstadisticas[]			:	Arreglo con el numero de veces que aparecen las palabras en el diccionario
    int &	iNumElementos			:	Numero de elementos en el diccionario
******************************************************************************************************************/

void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos);
void ClonaPalabras(char* szPalabraLeida, char szPalabrasSugeridas[][TAMTOKEN], int& iNumSugeridas);
void ListaCandidatas(char szPalabrasSugeridas[][TAMTOKEN], int iNumSugeridas, char szPalabras[][TAMTOKEN], int iEstadisticas[], int iNumElementos, char szListaFinal[][TAMTOKEN], int iPeso[], int& iNumLista);

int main()
{
    char szPalabrasDicc[NUMPALABRAS][TAMTOKEN];
    int iEstadisticas[NUMPALABRAS];
    int iNumPalabrasDicc;

    char szPalabraLeida[TAMTOKEN];
    char szPalabrasSugeridas[NUMPALABRAS * 100][TAMTOKEN];
    int iNumSugeridas;

    char szListaFinal[NUMPALABRAS * 100][TAMTOKEN];
    int iPeso[NUMPALABRAS * 100];
    int iNumLista;

    // Cargar diccionario
    Diccionario("diccionario.txt", szPalabrasDicc, iEstadisticas, iNumPalabrasDicc);

    // Leer palabra
    scanf_s("%s", szPalabraLeida, sizeof(szPalabraLeida));

    // Clonar palabras
    ClonaPalabras(szPalabraLeida, szPalabrasSugeridas, iNumSugeridas);

    // Obtener lista de candidatas ordenadas por peso
    ListaCandidatas(szPalabrasSugeridas, iNumSugeridas, szPalabrasDicc, iEstadisticas, iNumPalabrasDicc, szListaFinal, iPeso, iNumLista);

    // Mostrar sugerencias
    for (int i = 0; i < iNumLista; i++) {
        printf("%s - Peso: %d\n", szListaFinal[i], iPeso[i]);
    }

    return 0;
}
