#include "..\Headers\FileGetSettigs.h"
#include "..\Headers\FilePrintsScreen.h"
#include "..\GlobalVariables.c"

int GetFromUserValuesNeedToConfigureSimulation(){
    
    PrintScreenHeaderAppInit();
    globalSettings.NumberOfWaysInSimulationLine = GetIntFromInput("Quantidade de Vias para Mesma Rotatoria :");
    globalSettings.NumberSimuationForScenary = GetIntFromInput("Quantidade de Simulacoes por Cenario :");
    globalSettings.MinNumerOfVehicles = GetIntFromInput("Quantidade Minima de Veiculos que Trafegam em 1 Via :");
    globalSettings.MaxNumerOfVehicles = GetIntFromInput("Quantidade Maxima de Veiculos que Trafegam em 1 Via :");
    globalSettings.timeNeededTheCarCompletTheRoundAbout = GetIntFromInput("Tempo necessario para os carros concluirem a Rotatoria em S :");
    globalSettings.percentIsBus = GetFloatFromInput("Porcentagem de Onibus :");
    globalSettings.percentIsCar = GetFloatFromInput("Porcentagem de Veiculos :");

    ForceNotice("Configure as Caracteristicas de Reacao");

    globalSettings.constTimeReactionTimePriorityDriver = GetFloatFromInput("Tempo de Reacao do Motorista Prioritario :");
    globalSettings.minReactionTimeSimpleDriver = GetFloatFromInput("Tempo Minimo de Reacao do Motorista Simples :");
    globalSettings.maxReactionTimeSimpleDriver = GetFloatFromInput("Tempo Maximo de Reacao do Motorista Simples :");

    ForceNotice("Configure Tempo de Espera em Colisoes");

    globalSettings.probabilityOfNormalVehiclesCollision = GetFloatFromInput("Probabilidade de Haver Colisao :");
    globalSettings.percentColosionWhenHaveTrafficLightVehicles = GetFloatFromInput("Probabilidade de Haver Colisao se Houver Semafaro:");
    globalSettings.percentMinTimeIncreaseWhenHaveCollision = GetFloatFromInput("Porcentagem Minima de Espera na Colisao :");
    globalSettings.percentMaxTimeIncreaseWhenHaveCollision = GetFloatFromInput("Porcentagem Maxima de Espera na Colisao :");

    ForceNotice("Configure Veiculos Prioritarios");
    globalSettings.percentIsPriorityVehicles = GetFloatFromInput("Probabilidade de Veiculos Prioritarios :");
    globalSettings.percentMinTimeIncreaseWhenHavePriorityCar = GetFloatFromInput("Porcentagem Minima do Aumento do Tempo de Espera se Houver Prioridade :");
    globalSettings.percentMaxTimeIncreaseWhenHavePriorityCar = GetFloatFromInput("Porcentagem Maxima do Aumento do Tempo de Espera se Houver Prioridade :");

    ForceNotice("Todos os Valores Importantes Foram Definidos!");
    ForceNoticeSecondMode("Precione Qualquer Botao Para Criar o Ambiente de Simulacao");
    CheckAnyValueFromInput("start");
    return 0;
}