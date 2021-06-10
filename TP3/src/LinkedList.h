/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //USAR
/*
 * creo lista
 * Return puntero a la lista
 */

int ll_len(LinkedList* this); //USAR
/*
 * me dice cuanto mide
 */

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

int ll_add(LinkedList* this, void* pElement); //USAR
/*
 * Incorporar elemento a la lista
 * LinkedList* this: puntero a la lista, que me devolvio el new...
 * void* pElement: El elemento que quiero agregar
 *
 */

void* ll_get(LinkedList* this, int index); //USAR
/*
 * int index: que posicion de la lista queremos obtener
 *
 * Return: puntero a void, que lo vamos a guardar en puntero a empleado.
 *		Employee *pAuxEmpleado
 *		 pAuxEmpleado=(Employee*)ll_get(listaEmpleados, 4)
 *
 */

int ll_set(LinkedList* this, int index,void* pElement);
/*
 * Guardame tal elemento(void* pElement) en tal posicion(int index)
 */

int ll_remove(LinkedList* this,int index); //USAR

int ll_clear(LinkedList* this); //borra todos los elementos de la lista

int ll_deleteLinkedList(LinkedList* this); //USAR
/*
 * borra de memoria la lista
 * primero tengo que hacer un clear
 */

int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);

int ll_push(LinkedList* this, int index, void* pElement);
/*
 * Me permite insertar en alguna posicion de la lista un elemento
 */

void* ll_pop(LinkedList* this,int index); //Lo contrario de push


int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
