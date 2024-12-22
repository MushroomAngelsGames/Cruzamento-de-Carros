#include <stdio.h>
#include ".\Headers\FileGetSettigs.h"
#include ".\Headers\FileCreateEnv.h"
#include ".\Headers\FilePrintsScreen.h"
#include ".\Headers\FileSimule.h"

void SimuleEnviromentNormal(){
    ConfigureWays(2);
    ConfigureTypeCar();
    AlocMemoryRouds();
    InicializeRoads();
    CreateCarsForNormal();
    SimuleNormal();
}

int main()
{
   
    if(PrintScreenHeaderApp()) return 1;
    if(GetFromUserValuesNeedToConfigureSimulation()) return 1;
    SimuleEnviromentNormal();
    
    return 0;
}