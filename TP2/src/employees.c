/*
 * employees.c
 *
 *  Created on: May 10, 2021
 *      Author: caami
 */


#include "employees.h"



int removeEmployee(employee* list, int len, int id){

	int ret=-1;
	int posId=findEmployeeById(list, len, id);

	if(list!=NULL && len>0){
		if(posId==-1){
			printf("No se encontro el Id");
		}
		else{
			list[posId].isEmpty=1;
			ret=0;
		}
	}
	return ret;
}


int getIdEmployee(employee *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos){

	 int ret=-1;
	 int bufferInt;
	 int i;
	 int flag=1;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0 && flag){
			 reintentos--;
			 printf("%s", mensaje);

			 if(getInt(&bufferInt)==0){

				 for(i=0; i<len; i++){
					 if(list[i].id==bufferInt && list[i].isEmpty==0){

						 *pResultado = bufferInt;
						  ret=0;
						  flag=0;
						  break;
					 }
				 }
					if(flag){
						 fflush(stdin);
						 printf("%s", mensajeError);
					 }
				 }
			 }
		 }

	 return ret;
}




int modificarEmployee(employee *list, int len){
	int ret=-1;
	int id;
	int opcion;
	int auxInt;
	float auxFloat;
	int pos;
	char auxStr[LEN_STR];

	if(list!=NULL && len>0){


		printEmployees(list, len);

		if(getIdEmployee(list, len, &id, "Ingrese el id del empleado\n", "Error. ", 15)==0){
			ret=0;
			pos=findEmployeeById(list, len, id);

			getNumero(&opcion, "Ingrese el numero de lo que quiera modificar \n1. Nombre\n"
					"2. Apellido \n3. Salario \n4. Sector \n", "Error. ", 1, 4, 20);

		switch(opcion){
				case 1:
				if(utn_getString(auxStr, LEN_STR, "Ingrese el nombre nuevo\n",
						"Error. ", 30)==0){

					auxStr[0]=toupper(auxStr[0]);
					strncpy(list[pos].name, auxStr, LEN_STR);
					ret=0;
				}
					break;
				case 2:
					if(utn_getString(auxStr, LEN_STR, "Ingrese el apellido nuevo\n",
								"Error. ", 30)==0){

						auxStr[0]=toupper(auxStr[0]);
						strncpy(list[pos].lastName, auxStr, LEN_STR);
						ret=0;
					}
					break;

				case 3:
					if(getNumeroFloat(&auxFloat, "Ingrese el nuevo salario\n",
										"Error. ", 0, 200000, 30)==0){
						list[pos].salary=auxFloat;
						ret=0;
						}
						break;

				case 4:
					listarSector();
					if(getNumero(&auxInt, "Ingrese el numero del nuevo sector\n",
									"Error. ", 1, 3, 30)==0){
						list[pos].sector=auxInt;
						ret=0;
					}
					break;
				}
			}
			}
			return ret;
}


int findEmployeeById(employee* list, int len,int id){
	int ret =-1;
	int i;

	if(list!=NULL && len>0){

		for(i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].id == id){
				ret=i;
				break;
			}
		}
	}
	return ret; //devuelve -1 o la posicion
}



int initEmployees(employee* list, int len){
	int ret=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0; i<len; i++){
			list[i].isEmpty=1;
		}
		ret=0;
	}
	return ret;
}

int addEmployee(employee* list, int len, int id, char name[],char
lastName[],float salary,int sector){
	int ret=-1;
	int posicion;

	if(list!=NULL && len>0 && name!=NULL && lastName!=NULL
			&& buscarLibre(list, len, &posicion)==0 ){

			list[posicion].id=id;
			strcpy(list[posicion].name, name);
			strcpy(list[posicion].lastName, lastName);
			list[posicion].salary=salary;
			list[posicion].sector=sector;
			list[posicion].isEmpty=0;
			ret=0;
		}
	return ret;
}



int ingresarValores(char *nombre, char *apellido, int lenArray,
float *salario, int *sector){

	int ret=-1;
	int auxInt;
	char auxStr[LEN_STR];
	float auxFloat;


	if(nombre!=NULL && apellido!=NULL && lenArray>0 && salario!=NULL &&
			sector!=NULL){
		ret=0;


		if(utn_getString(auxStr, LEN_STR, "Ingrese el nombre\n", "Error. ", 20)==0){
			auxStr[0]=toupper(auxStr[0]);
			strncpy(nombre, auxStr, LEN_STR);
		}

		if(utn_getString(auxStr, LEN_STR, "Ingrese el apellido\n", "Error. ", 20)==0){
					auxStr[0]=toupper(auxStr[0]);
					strncpy(apellido, auxStr, LEN_STR);
		}

		if(getNumeroFloat(&auxFloat, "Ingrese el salario\n", "Error. ", 0, 200000, 25)==0){
			*salario=auxFloat;
		}

		listarSector();
		if(getNumero(&auxInt, "Ingrese el numero de sector\n", "Error. ", 1, 3, 25)==0){
			*sector=auxInt;
		}

	}
	return ret;
}



int buscarLibre(employee *array, int leng, int *posicionLibre){
	int i;
	int ret=-1;

	if(array!=NULL && leng>0){
		for(i=0; i<leng; i++){
				if(array[i].isEmpty==1){
					*posicionLibre=i;
					ret=0;
					break;
				}
		}
	}
	return ret;
}

//order int [1] indicate UP - [0] indicate DOWN
int sortEmployees(employee* list, int len, int order){
	int ret=-1;

	if(list!=NULL && len>0 && (order==1 || order ==0)){
		ret=0;

		if(order==1){
			ordenarArrayAscendente(list, len);
		}
		else{

			ordenarArrayDescendente(list, len);
		}
	}
	return ret;
}

int ordenarArrayAscendente(employee* list, int len){
	int ret=-1;
	int flagDesordenado=1;
	employee auxEmployee;
	int auxInt, j;

	if(list!=NULL && len>0){
		ret=0;

		while(flagDesordenado){
			flagDesordenado=0;

			for(j=1; j<len; j++){

				if(strcmp(list[j-1].lastName, list[j].lastName)>0){

					auxEmployee=list[j];
					list[j]=list[j-1];
					list[j-1]=auxEmployee;

					flagDesordenado=1;
				}

				else if(strcmp(list[j-1].lastName, list[j].lastName)==0){
											//son iguales

					if (list[j-1].sector > list[j].sector){
						auxInt = list[j].sector;
						list[j].sector = list[j-1].sector;
						list[j-1].sector = auxInt;
						flagDesordenado = 1;
					}
				}

			}
		}


	}
	return ret;
}


int ordenarArrayDescendente(employee* list, int len){
	int ret=-1;
	int flagDesordenado=1;
	employee auxEmployee;
	int auxInt, j;

	if(list!=NULL && len>0){
		ret=0;

		while(flagDesordenado){
			flagDesordenado=0;

			for(j=1; j<len; j++){

				if(strcmp(list[j-1].lastName, list[j].lastName)<0){

					auxEmployee=list[j];
					list[j]=list[j-1];
					list[j-1]=auxEmployee;

					flagDesordenado=1;
				}

				else if(strcmp(list[j-1].lastName, list[j].lastName)==0){
											//son iguales

					if (list[j-1].sector < list[j].sector){
						auxInt = list[j].sector;
						list[j].sector = list[j-1].sector;
						list[j-1].sector = auxInt;
						flagDesordenado = 1;
					}
				}

			}
		}


	}
	return ret;
}

int printEmployees(employee* list, int len){
	int i;
	int ret=-1;
	char descSector[LEN_STR];

	if(list!=NULL && len>0){
		ret=0;
		printf("Id        Nombre        Apellido        Salario        Sector\n");

			for(i=0; i<len; i++){

				if(list[i].isEmpty==0){

					getDescSector(list[i].sector, descSector, LEN_STR);

					printf("%-9d %-13s %-15s %-15.2f %s\n", list[i].id,
															list[i].name, list[i].lastName,
															list[i].salary, descSector);
				}
			}
	}
	return ret;
}






int hayEmpleadosdeAlta(employee* array, int leng){

	int ret=-1;
	int i;
	if(array!=NULL && leng>0){
		ret=0;
		for(i=0; i<leng; i++){
			if(array[i].isEmpty==0){
				ret=1;
				break;
			}
		}
	}
	return ret;
}

int getDescSector(int nSector, char *desc, int len){

	int ret=-1;
	if(nSector>=1 && nSector<=3 && desc!=NULL && len>0){


		ret=0;
		switch(nSector){
		case 1:
			strncpy(desc, "Sistemas", len);
			break;
		case 2:
			strncpy(desc, "RRHH", len);
			break;
		case 3:
			strncpy(desc, "Limpieza", len);
			break;
		}
	}
	return ret;
}

void listarSector(void){
	printf("1.Sistemas   2.RRHH   3.Limpieza\n");
}


