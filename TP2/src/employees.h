/*
 * employees.h
 *
 *  Created on: May 10, 2021
 *      Author: caami
 */

#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_



#define LEN_STR 20
#define QTY_EMPLOYEES 1000

typedef struct{
	int id;
	char name[LEN_STR];
	char lastName[LEN_STR];
	float salary;
	int sector;
	int isEmpty; //1: estructura libre 0:ocupada
}employee;


#include "getsDatos.h"





/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);



/*
 * \brief Itera por el array de tipo cliente hasta que encuentra la primera posicion libre
 * \param employee* array
 * \param int leng
 * \param posicionLibre: Puntero al espacio de memoria donde se dejara la primera posicion libre
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int buscarLibre(employee array[], int leng, int *posicionLibre);

int ingresarValores(char *nombre, char *apellido, int lenArray,
float *salario, int *sector);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(employee* list, int len,int id);




/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee* list, int length);




/** \brief Permite al usuario modificar los valores de un empleado
 *
 * \param list Employee*
 * \param len int
 *
 * \return Retorna -1 si ERROR (No se encontro el empleado, len invalido o puntero nulo) o 0 si EXITO
 */
int modificarEmployee(employee *list, int len);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(employee* list, int len, int id);




/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(employee* list, int len, int order);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int printEmployees(employee* list, int len);




/** \Permite al usuario ingresar valores y los guarda en la direccion de memoria apuntada
 *
 * \param char *nombre
 * \param char *apellido
 * \param int lenArray
 * \param float *salario
 * \param int *sector
 *
 * \return Retorna -1 si ERROR (Puntero nulo o lenArray invalido) o 0 si EXITO
 */
int ingresarValores(char *nombre, char *apellido, int lenArray,
float *salario, int *sector);


/** \brief Ordena el array de empleados por apellido y sector de forma ascendente
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int ordenarArrayAscendente(employee* list, int len);



/** \brief Ordena el array de empleados por apellido y sector de forma descendente
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int ordenarArrayDescendente(employee* list, int len);


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee* list, int len);


/** \brief Imprime el contenido de la posicion pasada por parametro del array de tipo employee
 *
 * \param list Employee*
 * \param int len
 * \param int posicion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int printEmployeesByPosicion(employee* list, int len, int posicion);



/* \brief Itera por el array hasta encontrar un empleado de alta (isEmpty==0)
 * \param employee* array
 * \param int leng
 * \return Retorna -1 si ERROR, 0 si no hay empleados de alta, 1 si hay al menos un empleado de alta
 */
int hayEmpleadosdeAlta(employee* array, int leng);



/* \brief Copia en la direccion del puntero la descripcion correspondiente al numero que le
 * paso por parametro
 * \param int nSector
 * \param char *desc
 * \param int len
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int getDescSector(int nSector, char *desc, int len);


/*
 * Imprime los sectores con su numero y nombre
 */
void listarSector(void);


/*
 * \brief permite al usuario ingresar un numero de id y si esta de alta (isEmpty==0) en el array de
 * tipo employee, guarda el id en la direccion apunta por pResultado
 * \param employee *list
 * \param int len
 * \param int *pResultado
 * \param char *mensaje
 * \param char* mensajeError
 * \param int reintentos
 * return Retorna -1 si ERROR o 0 si EXITO
 */
int getIdEmployee(employee *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos);




#endif /* EMPLOYEES_H_ */
