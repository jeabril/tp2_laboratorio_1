#ifndef ARRAYEMPLOYEES_H
#define ARRAYEMPLOYEES_H

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployee;

/**\brief muestra las opciones del menu
 *\param ingresa a la opcion que desea que el usuario ejecute
 * \return retorna void
 */
void Menu(sEmployee[]);


/**\brief recorre el array
 *\param incrementa cada vez que se ingresa un empleado
 * \return retorna i
 */
int findEmployeeById(sEmployee[],int);


/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna void
 */
void initEmployees(sEmployee[],int);


/**\brief recorre el array
 *\param Busca VACIO luego lo cambia a LLENO
 * \return retorna aux
 */
int ArraySpace(sEmployee[],int);


/**\brief Ingresa los datos
 *\param validacion de datos
 * \return retorna void
 */
void addEmployees(sEmployee[],int,int);


/**\brief se ingresa id para modificar los datos
 *\param si el id es correcto se modifican los datos, caso contrario sale del programa
 * \return retorna void
 */
void modifyEmployee(sEmployee[],int);


/**\brief se ingresa id para dar de baja a un empleado
 *\param si el id es correcto se da de baja, caso contrario sale del programa
 * \return retorna void
 */
void removeEmployee(sEmployee[],int);


/**\brief recorre el array
 *\param  hace un intercambio de posicion hasta que el apellido quede ordenado
 * \return retorna void
 */
void sortEmployeeByLastName(sEmployee[],int);


/**\brief  recorre el array
 *\param  hace un intercambio de posicion hasta que el sector quede ordenado
 * \return retorna void
 */
void sortEmployeeBySector(sEmployee[],int);


/**\brief  recorre el array
 *\param saca el promedio del salario y que empleado lo supera
 * \return retorna void
 */
void AverageSalaryAndHighestSalary(sEmployee[],int);


/**\brief  recorre el array
 *\param muestra el id,el nombre y el apellido
 * \param los datos son mostrados dentro de modificar y dar de baja
  * \param para que el usuario sepa que id desea modificar o dar de baja
 * \return retorna void
 */
void printEmployees(sEmployee[],int);


#endif

