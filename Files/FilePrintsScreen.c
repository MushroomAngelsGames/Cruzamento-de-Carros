#include <stdio.h>
#include "..\Headers\FilePrintsScreen.h"

int PrintScreenHeaderApp(){

    printf("\n------------------------------------------------------------------------------------------\n");
    printf("| Simulador de Transito - St - Version 0.0.1                                             |\n");
    printf("| Developer by: Luiz Felipe da Silva Marian                                              |\n");
    printf("| All Rights Reserved Mushroom Angels Games | 2018-2023                                  |");
    printf("\n------------------------------------------------------------------------------------------\n");

    return 0;
}

void PrintScreenHeaderAppInit(){
   
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("| Inicializacao do Sistema de Simulacoes                                                 |\n");
    printf("| E necessario informar os dados da simulacao.                                           |");
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("\n\n");
}

void ForceNotice(char* labelErro){
    printf("\n\n------------------------------------------------------------------------------------------\n");
    printf(labelErro);
    printf("\n------------------------------------------------------------------------------------------\n\n");
}

void ForceNoticeSecondMode(char* labelErro){
    printf("\n------------------------------------------------------------------------------------------\n");
    printf(labelErro);
    printf("\n------------------------------------------------------------------------------------------\n");
}

void ForceNoticeThirdMode(char* labelErro){
    printf("------------------------------------------------------------------------------------------\n");
    printf(labelErro);
    printf("\n------------------------------------------------------------------------------------------\n");
}

int CheckAnyValueFromInput(){
    char valueFinal;
    scanf("%c",&valueFinal);
    return 0;
}

int GetIntFromInput(char* labelNoticeGet){
    int getInt;
    int checkReturn = -1;
    char world;
    do{
        if(checkReturn == 0) ForceNotice("(ERRO) Digite Apenas Numeros Inteiros");
        printf(labelNoticeGet);
        checkReturn = scanf("%d",&getInt);
      
        do
        {
            world = getchar();
        } while (world != '\n');
    
    } while (checkReturn == 0);
 
    return getInt;
}

float GetFloatFromInput(char* labelNoticeGet){
    float getfloat;
    int checkReturn = -1;
    char world;
    do{
        if(checkReturn == 0) ForceNotice("(ERRO) Digite Apenas Numeros Inteiros");
        printf(labelNoticeGet);
        checkReturn = scanf("%f",&getfloat);
      
        do
        {
            world = getchar();
        } while (world != '\n');
    
    } while (checkReturn == 0);
 

    return getfloat;
}