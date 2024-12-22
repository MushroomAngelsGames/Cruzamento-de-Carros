#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\Headers\FilePrintsScreen.h"
#include "..\Headers\LineStruct.h"
#include "..\GlobalVariables.c"
#include "..\Headers\FileCreateEnv.h"
#include <math.h>

int GetRandoNumbersOfCars(){ 
    int valueDivision = globalSettings.MaxNumerOfVehicles - globalSettings.MinNumerOfVehicles;
    if(valueDivision == 0) valueDivision = 1;
    int value = globalSettings.MinNumerOfVehicles +  rand() % valueDivision;
    return value;
}

void ConfigureWays(int numeOfRouds){
    srand(time(0));
    
    globalEnv.waysHave = malloc( globalSettings.NumberOfWaysInSimulationLine* sizeof(Ways));
    for (size_t i = 0; i < globalSettings.NumberOfWaysInSimulationLine; i++)
    {
        int cars = GetRandoNumbersOfCars();
        globalSettings.totalVeicles += cars;
        globalEnv.waysHave[i].numeOfCarsInWayWhenStart = cars;
        globalEnv.waysHave[i].amountRoadsHave = numeOfRouds;
    }

    ForceNoticeThirdMode(" => Vias Inicializadas..."); 
}

void ConfigureTypeCar(){
    globalSettings.totalPercentTimeIncreaseWhenHavePriorityCar = GetRandoValue(globalSettings.percentMinTimeIncreaseWhenHavePriorityCar,globalSettings.percentMaxTimeIncreaseWhenHavePriorityCar); 
    globalSettings.totalPercentTimeIncreaseWhenColision = GetRandoValue(globalSettings.percentMinTimeIncreaseWhenHaveCollision,globalSettings.percentMaxTimeIncreaseWhenHaveCollision); 
    globalSettings.totalIsBus = round((float)globalSettings.totalVeicles * (float)(globalSettings.percentIsBus/100));
    globalSettings.totalIsCar = round((float)globalSettings.totalVeicles * (float)(globalSettings.percentIsCar/100));
    globalSettings.totalIsCarPriority = round((float)globalSettings.totalIsCar * (float)(globalSettings.percentIsPriorityVehicles/100));
    ForceNoticeThirdMode(" => Probabilidades e Porcetagens Calculadas..."); 
}

void AlocMemoryRouds(){
    for (size_t i = 0; i < globalSettings.NumberOfWaysInSimulationLine; i++)
        globalEnv.waysHave[i].roads = malloc(globalEnv.waysHave[i].amountRoadsHave * sizeof(Line)); 
    ForceNoticeThirdMode(" => Memoria Alocada para Estradas..."); 
}

void InicializeRoads(){
    for (size_t i = 0; i < globalSettings.NumberOfWaysInSimulationLine; i++)
       for (size_t j = 0; j < globalEnv.waysHave[i].amountRoadsHave; j++)
            CrateLine(&globalEnv.waysHave[i].roads[j]);  

    ForceNoticeThirdMode(" => Estradas Incializadas...");
}

float GetRandoValue(float valueMin,float  valueMax){
    return (float)valueMin + (float)(valueMax *  ((float)rand()/RAND_MAX));
}

Vehicles CreateGenerecCar(int typeCar){
  
    Vehicles newVehicle;
    newVehicle.typeVehicles = typeCar;
    switch (typeCar)
    {
        case 0:
            newVehicle.reactionTime = GetRandoValue(globalSettings.minReactionTimeSimpleDriver,globalSettings.maxReactionTimeSimpleDriver);
            break;
        case 1:
             newVehicle.reactionTime = (GetRandoValue(globalSettings.minReactionTimeSimpleDriver,globalSettings.maxReactionTimeSimpleDriver) * 2);
            break;
        case 2:
            newVehicle.reactionTime = globalSettings.constTimeReactionTimePriorityDriver;
            break;

        default:
            break;
    }

    return newVehicle;
}

void CreateCarsForNormal(){
    int carForWays = globalSettings.totalIsCar / globalSettings.NumberOfWaysInSimulationLine;
    int BusForWays = globalSettings.totalIsBus / globalSettings.NumberOfWaysInSimulationLine;
    int carPriorityForWays = globalSettings.totalIsCarPriority / globalSettings.NumberOfWaysInSimulationLine; 

    for (size_t i = 0; i < globalSettings.NumberOfWaysInSimulationLine; i++)
    {     
        for (size_t road = 0; road < globalEnv.waysHave[i].amountRoadsHave; road++)
        {
           
            int carsForRoadInWay = carForWays/globalEnv.waysHave[i].amountRoadsHave;
            for (size_t j = 0; j < carsForRoadInWay; j++){
                InsertCarInEndOfLine(&globalEnv.waysHave[i].roads[road],CreateGenerecCar(0));
            }


            int BusForRoadInWay = BusForWays/globalEnv.waysHave[i].amountRoadsHave;
            for (size_t j = 0; j < BusForRoadInWay; j++)
               InsertCarInEndOfLine(&globalEnv.waysHave[i].roads[road],CreateGenerecCar(1));


            int carPriorityForWays = BusForWays/globalEnv.waysHave[i].amountRoadsHave;
            for (size_t j = 0; j < carPriorityForWays; j++)
                InsertCarInEndOfLine(&globalEnv.waysHave[i].roads[road],CreateGenerecCar(2));

            
        }
    }

    ForceNoticeThirdMode(" => Carros Adcionados nas Estradas da Simulcao");
    
}




