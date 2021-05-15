
#include "menu.h"


int main(void) {

	setbuf(stdout, NULL);


	int opcionMenu;
	int idEmployeeIncremental=1000;

	employee arrayEmployees[QTY_EMPLOYEES];
	initEmployees(arrayEmployees, QTY_EMPLOYEES); //pongo todos vacios

	do{
		listadoMenu();
		if(getNumero(&opcionMenu, "Ingrese la opcion de menu\n", "Error. ", 1, 5, 30)==0){
			menu(&opcionMenu, arrayEmployees, QTY_EMPLOYEES, &idEmployeeIncremental);
		}
	}while(opcionMenu!=5);



}
