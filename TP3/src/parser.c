#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	if(pFile!=NULL && pArrayListEmployee!=NULL){

		char id[LEN_STR], nombre[LEN_STR], horas[LEN_STR], sueldo[LEN_STR];
		int flag=0; //lectura fantasma

		do{
			if(fscanf(pFile, "%[^,], %[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo)==4 && flag){

				flag=1;
				Employee* empleadoAux=employee_newParametros(id, nombre, horas, sueldo);
				printf("id: %d    nombre: %s    horas: %d    sueldo: %d \n",
						(*empleadoAux).id, (*empleadoAux).nombre, (*empleadoAux).horasTrabajadas, (*empleadoAux).sueldo);
				ll_add(pArrayListEmployee, empleadoAux);
			}
			flag=1;
		}while(feof(pFile)==0);

	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
