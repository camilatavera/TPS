/*
 * menu.c
 *
 *  Created on: May 10, 2021
 *      Author: caami
 */


#include "menu.h"
#include "getsDatos.h"


void listadoMenu(void){
	printf("Menu:\n1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n"
			"5. SALIR\n");
}

void submenuInformes(void){
	printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n"
		"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
}

int menu(int *opcionIngresada, employee *array, int leng, int *idEmployee){

	int ret=-1;
	int Aid=*idEmployee;
	char Anombre[LEN_STR];
	char Aapellido[LEN_STR];
	float Asalario;
	int Asector;
	int auxInt;
	//int opcionAuxiliar=opcionIngresada;

	if(array!=NULL && leng>0){

		if(hayEmpleadosdeAlta(array, leng)==0 && *opcionIngresada!=1){
			printf("Error. Primero debes ingresar empleados\n");
			*opcionIngresada=0;
		}

		switch(*opcionIngresada){

			case 1:
				if(ingresarValores(Anombre, Aapellido, LEN_STR, &Asalario, &Asector)==0 &&
					addEmployee(array, leng, Aid, Anombre, Aapellido, Asalario, Asector)==0){
					(*idEmployee)++;
					printf("Se dio de alta exitosamente\n");
				}
				break;
			case 2:
				if(modificarEmployee(array, leng)==0){
					printf("La modificacion se realizo exitosamente\n");
				}
				break;
			case 3:
				printEmployees(array, leng);
				if(getIdEmployee(array, leng, &Aid, "Ingrese el id del empleado\n",
						"Error. ", 25)==0 &&
					removeEmployee(array, leng, Aid)==0){
						printf("Se dio de baja el empleado exitosamente\n");
					}
				break;
			case 4:
				submenuInformes();
				getNumero(&auxInt, "Ingrese 1 o 2\n", "Error. ", 1, 2, 30);
				if(auxInt==1){
					listarEmpleadosOrdenados(array, leng);
				}
				else{
					printSalarios(array, leng);
				}
				break;
			}//cierro switch
		ret=0;
	}
	return ret;
}

