/*
 * informes.h
 *
 *  Created on: May 15, 2021
 *      Author: caami
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "employees.h"

/*
 * \brief llama a una funcion que ordena el array de tipo empleados --> llama a funcion que imprime el
 * array ordenado
 * \param employee *list
 * \param int len
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int listarEmpleadosOrdenados(employee *list, int len);


/*
 * \brief Calcula el promedio y el total de salario en el array de tipo employee y guarda los valores
 * en la direccion de memoria pasada por parametro
 * \param employee *list
 * \param int len
 * \param float *promedio
 * \param float *total
 * \Return retorna -1 si ERROR o 0 si EXITO
 */
int total_promedio_salario(employee *list, int len, float *promedio, float *total);


/*
 * \brief Imprime los valores de la posicion del array pasada por parametro
 * \param employee *list
 * \param int len
 * \param int posicion
 * \Return retorna -1 si ERROR o 0 si EXITO
 */
int printEmployeesByPosicion(employee* list, int len, int posicion);


/*
 * \brief Analiza si el empleado de la posicion del array pasado por pasametro supera el pronedio
 * pasado por parametro
 * \param employee *list
 * \param int leng
 * \param int posicion
 * \param float promedio
 * \Return retorna -1 si ERROR o 0 si el empleado no supera el promedio o 1 si supera el promedio
 */
int superaSalarioPromedio(employee *list, int leng, int posicion, float promedio);




/*
 * \brief Imprime la suma total de salario, el promedio y un listado de empleado que superan el promedio
 * \param employee *list
 * \param int leng
 * \Return retorna -1 si ERROR o 0 si EXITO
 */
int printSalarios(employee *list, int leng);





#endif /* INFORMES_H_ */
