/*
 * informes.c
 *
 *  Created on: May 15, 2021
 *      Author: caami
 */

#include "informes.h"


int listarEmpleadosOrdenados(employee *list, int len){
	int ret=-1;

	if(list!=NULL && len>0){
		ret=0;
		sortEmployees(list, len, 1);
		printEmployees(list, len);
	}

	return ret;

}

int total_promedio_salario(employee *list, int len, float *promedio, float *total){
	int ret=-1;
	int i;
	int contEmployees=0;
	float contSalary=0;


	if(list!=NULL && len>0 && promedio!=NULL && total!=NULL){
		ret=0;
		for(i=0; i<len; i++){

			if(list[i].isEmpty==0){
				contEmployees++;
				contSalary+=list[i].salary;
			}
		}

		*promedio=contSalary/contEmployees;
		*total=contSalary;
	}
	return ret;
}


int printEmployeesByPosicion(employee* list, int len, int posicion){

	int ret=-1;
	char desc[LEN_STR];
		if(list!=NULL && len>0){
			ret=0;

			getDescSector(list[posicion].sector, desc, LEN_STR);

			printf("%-9d %-13s %-15s %-15.2f %s\n", list[posicion].id, list[posicion].name,
													list[posicion].lastName, list[posicion].salary,
													desc);
		}
		return ret;
}


/*
 *
 * return -1: ERROR
 * return 0: el empleado no supera el salario promedio
 * return 1: el empleado supera el salario promedio
 */
int superaSalarioPromedio(employee *list, int leng, int posicion, float promedio){

	int ret=-1;

	if(list!=NULL && leng>0){
		ret=0;

		if(list[posicion].salary>promedio){
			ret=1;
		}
	}
	return ret;
}


int printSalarios(employee *list, int leng){

	int ret=-1;
	float prom;
	float total;
	int i;

		if(list!=NULL && leng>0){
			ret=0;
			total_promedio_salario(list, leng, &prom, &total);
			printf("Total de los salarios= $ %.2f\nSalario promedio= $ %.2f\n", total, prom);
			printf("Empleados que superan el salario promedio:\n");
			printf("Id        Nombre        Apellido        Salario        Sector\n");

			for(i=0; i<leng; i++){
				if(list[i].isEmpty==1){
					continue;
				}
				else{
					if(superaSalarioPromedio(list, leng, i, prom)){
						printEmployeesByPosicion(list, leng, i);
					}
				}
			}
		}
		return ret;
}

