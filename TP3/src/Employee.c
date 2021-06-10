
#include "Employee.h"

int employee_setId(Employee* this,int id){

	int ret=-1;
	if(this!=NULL && id>0){
		this->id=id;
		ret=0;
	}
	return ret;
}

int employee_setNombre(Employee* this,char* nombre){
	int ret=-1;
	if(this!=NULL && nombre!=NULL){
			strncpy(this->nombre, nombre, LEN_STR);
			ret=0;
	}
		return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

	int ret=-1;
		if(this!=NULL && horasTrabajadas>0){
				this->horasTrabajadas=horasTrabajadas;
				ret=0;
		}
		return ret;
}

int employee_setSueldo(Employee* this,int sueldo){

	int ret=-1;
	if(this!=NULL && sueldo>0){
		this->sueldo=sueldo;
		ret=0;
	}
	return ret;
}


Employee* employee_new(){
	Employee* nuevoEmpleado;
	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
	return nuevoEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

	//int ret=-1;
	Employee* pEmpleado=NULL;

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL ){
		pEmpleado=(Employee*)malloc(sizeof(Employee));

		if(pEmpleado!=NULL){
			//validar qeu todos los set devuelvan0
			employee_setId(pEmpleado, atoi(idStr));
			//pEmpleado->id=atoi(idStr);
			employee_setNombre(pEmpleado, nombreStr);
			//strncpy(pEmpleado->nombre, nombreStr, 128);
			employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
			//pEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);

			employee_setSueldo(pEmpleado, atoi(sueldoStr));
			//pEmpleado->sueldo=atoi(sueldoStr);


		}
	}
	return pEmpleado;
}








