#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief
 * crea un nuevo empleado
 * @return devuelve el empleado
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief
 * crea un nuevo empleado
 * @param idStr id que asignar al empleado
 * @param nombreStr nombre que asignar al empleado
 * @param horasTrabajadasStr horas de trabajo que asignar al empleado
 * @param sueldoStr sueldo que asignar al empleado
 * @return devuelve el empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @fn int employee_delete(Employee*)
 * @brief
 * borra un empleado
 * @param empleado a borrar
 * @return 0 si borró, -1 si no
 */
int employee_delete(Employee* this);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief
 * setea un id a un empleado
 * @param this empleado al que se le asigna el id
 * @param id id a asignar
 * @return 0 si funcionó, -1 si no
 */
int employee_setId(Employee* this,int id);
/**
 * @fn int employee_getId(Employee*, int*)
 * @brief
 * consigue el id de un empleado
 * @param this empleado del que conseguir el id
 * @param id variable en la que retornar el id
 * @return -1 si no se consiguió, 0 si si
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief
 * setear nombre a un empleado
 * @param this empleado al que asignar el nombre
 * @param nombre , nombre a asignar
 * @return devuelve 0 si fue exitoso, -1 si no
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn char employee_getNombre*(Employee*)
 * @brief
 * consigue el nombre de un empleado
 * @param this empleado del cual obtener el nombre
 * @return devuelve el nombre del empleado
 */
char* employee_getNombre(Employee* this);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief
 * setea las horas de trabajo de un empleado
 * @param this empleado al cual setear horas
 * @param horasTrabajadas horas a setear
 * @return 0 si seteó, -1 si no
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief
 * obtener las horas que trabajó un empleado
 * @param this empleado del cual obtener horas
 * @param horasTrabajadas guardar y devolver las horas que trabajó
 * @return 0 si consiguió el dato, -1 si no
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief
 * setear el sueldo de un empleado
 * @param this empleado al que setear el sueldo
 * @param sueldo sueldo a setear
 * @return 0 si seteó, -1 si no
 */
int employee_setSueldo(Employee* this,int sueldo);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief
 * cponsigue el sueldo de un empleado
 * @param this empleado del cual obtener el sueldo
 * @param sueldo guardar y devolver el sueldo obtenido
 * @return 0 si consiguió el dato, -1 si no
 */
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * @fn int employee_CompareById(void*, void*)
 * @brief
 * compara dos empleados segun su id
 * @param primer empleado
 * @param segundo empleado
 * @return devuelve -1 o 1 segun el criterio
 */
int employee_CompareById(void*, void*);
/**
 * @fn int employee_CompareByNombre(void*, void*)
 * @brief
 * compara dos empleados segun su nombre
 * @param primer empleado
 * @param segundo empleado
 * @return devuelve -1 o 1 segun el criterio
 */

int employee_CompareByNombre(void*, void*);

/**
 * @fn int employee_CompareByHorasTrabajadas(void*, void*)
 * @brief
 * compara dos empleados segun sus horas trabajadas
 * @param primer empleado
 * @param segundo empleado
 * @return devuelve -1 o 1 segun el criterio
 */
int employee_CompareByHorasTrabajadas(void*, void*);

/**
 * @fn int employee_CompareBySueldo(void*, void*)
 * @brief
 * compara dos empleados segun su sueldo
 * @param primer empleado
 * @param segundo empleado
 * @return devuelve -1 o 1 segun el criterio
 */
int employee_CompareBySueldo(void*, void*);

#endif // employee_H_INCLUDED
