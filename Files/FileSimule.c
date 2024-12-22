#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "..\Headers\FileSimule.h"
#include "..\Headers\FilePrintsScreen.h"
#include "..\Headers\LineStruct.h"
#include "..\GlobalVariables.c"

int GetRandoRoundabout(){
    return rand() % globalSettings.NumberOfWaysInSimulationLine;
}

int GetHasTrafficAccident(){

    if((( 1+ (rand() % globalSettings.NumberOfWaysInSimulationLine))/ 100) <= globalSettings.probabilityOfNormalVehiclesCollision)
        return 1;

    return 0;
}

void Await(){
    int tempo = clock(); 
    while(clock() - tempo < (globalSettings.timeNeededTheCarCompletTheRoundAbout * 1000)){ 
    }
}

void AddTimeAllCars(float Time){
    for (size_t j = 0; j < globalSettings.NumberOfWaysInSimulationLine; j++)
    {
        for (size_t ij = 0; ij < globalEnv.waysHave[j].amountRoadsHave ; ij++)
        {
            No *aux = globalEnv.waysHave[j].roads->fisrtElement;
            while (aux)aux->vehicle.timeWait +=Time; 
        }                    
    }
}

void AddTimeBecauseHaveAccident(){
    for (size_t j = 0; j < globalSettings.NumberOfWaysInSimulationLine; j++)
    {
        for (size_t ij = 0; ij < globalEnv.waysHave[j].amountRoadsHave ; ij++)
        {
            No *aux = globalEnv.waysHave[j].roads->fisrtElement;
            while (aux)
                aux->vehicle.timeWait += aux->vehicle.timeWait * globalSettings.totalPercentTimeIncreaseWhenColision; 
        }                    
    }
}

void SimuleNormal(){
    int totalCarHave = 0;
    float totalTime = 0;
    for (size_t i = 0; i < globalSettings.NumberOfWaysInSimulationLine; i++)
        totalCarHave += globalEnv.waysHave[i].numeOfCarsInWayWhenStart;

    //Verificar se ha Prioridade

    while (totalCarHave > 0)
    {   
        int limitCount = 6;
        int currectWays = GetRandoRoundabout();   
        while (limitCount > 0)
        {
            printf("%d \n",limitCount);
            printf("%d \n", currectWays);
            for (size_t i = 0; i < globalEnv.waysHave[currectWays].amountRoadsHave; i++)
            {
                printf("1");
                float totalInThisTime = 0;
                limitCount -1;
                int hasAccidentWithThisCar = GetHasTrafficAccident();
                No* carRemove = RemoveCarFirstElementInLine(&globalEnv.waysHave[currectWays].roads[i]);
                totalTime += carRemove->vehicle.reactionTime;
                totalInThisTime += totalTime + (globalSettings.timeNeededTheCarCompletTheRoundAbout/1000);
                AddTimeAllCars(totalInThisTime);
                carRemove->vehicle.timeWait += totalInThisTime;
                totalCarHave-1;
                if(hasAccidentWithThisCar)
                    AddTimeBecauseHaveAccident();    

                printf("Way: %d | Roud: %d | Carro: %d | Acidente : %d | Tempo: %.2f | Total Time %0.2f",currectWays,i,carRemove->vehicle.typeVehicles,hasAccidentWithThisCar,totalInThisTime,totalTime);
            }  
            Await();
        }           
    }   
}
