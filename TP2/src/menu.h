/*
 * menu.h
 *
 *  Created on: May 10, 2021
 *      Author: caami
 */

#ifndef MENU_H_
#define MENU_H_


#include "informes.h"



/*
 * Imprime las opciones del menu
 */
void listadoMenu(void);

/*
 * Imprime las opciones del submenu de informes
 */
void submenuInformes(void);


/*
 * \brief valida la opcion de menu pasada por parametro. Si se da de alta un usuario, incrementa
 * el id en la posicion de memoria
 * \param int *opcionIngresada
 * \param employee *array
 * \param int leng
 * \param int *idEmployee
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int menu(int *opcionIngresada, employee *array, int leng, int *idEmployee);

#endif /* MENU_H_ */
