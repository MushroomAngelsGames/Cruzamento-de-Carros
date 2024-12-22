#ifndef LINE_STRUCT_H_DEFINEDED
#define LINE_STRUCT_H_DEFINEDED
#include "..\Structs\VehiclesStruct.c"

typedef struct no
{
    Vehicles vehicle;
    struct no *next; 
}No;

typedef struct LineStruct
{
    No *fisrtElement;
    No *lastElement;
    int leght;

}Line;


void PrintLine(Line *line);
void CrateLine(Line *line);
void InsertCarInEndOfLine(Line *line,Vehicles newVehicle);
No* RemoveCarFirstElementInLine(Line *line);


#endif