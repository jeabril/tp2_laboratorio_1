#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 1000
#include "ArrayEmployee.h"

int main()
{
    sEmployee arrayEmployee[SIZE];
    initEmployees(arrayEmployee,SIZE);
    Menu(arrayEmployee);
    findEmployeeById(arrayEmployee,SIZE);
    return 0;
}
