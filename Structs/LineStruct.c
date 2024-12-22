#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\LineStruct.h"

void PrintLine(Line *line){
    No *aux = line->fisrtElement;
    printf("\t------------------------------------\n\t");
    while (aux)
    {
        printf("%f",aux->vehicle.reactionTime);
        aux = aux->next;
    }
    printf("\n\t------------------------------------\n");
}

void CrateLine(Line *line){
    line->fisrtElement = NULL;
    line->lastElement = NULL;
    line->leght = 0;
}

void InsertCarInEndOfLine(Line *line,Vehicles newVehicle){
    No *newNo = malloc(sizeof(No));
    if(newNo){
        newNo->vehicle = newVehicle;
        newNo->next = NULL;
        if(line->fisrtElement == NULL){
            line->fisrtElement = newNo;
            line->lastElement = newNo;
        }  
        else{        
           line->lastElement->next = newNo;
           line->lastElement = newNo;
        }

      line->leght++;
    }else{
        printf("\n\n Erro de Alocacao de Memoria");
    }
}

No* RemoveCarFirstElementInLine(Line *line){
    No *removeCar = NULL;
    if(line->fisrtElement){
        removeCar = line->fisrtElement;
        line->fisrtElement = removeCar->next;
        line->leght--;
    }
    else
        printf("fila vazia");
    return removeCar;
}
