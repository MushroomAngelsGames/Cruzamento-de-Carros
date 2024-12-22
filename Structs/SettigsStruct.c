typedef struct SettigsStruct
{
    //Os valore deverão ser atribuidos ao inico do software, pois deixar o simulador mais flexivel para as mudanção de variaveis.

    //Configurar Simulação
    int NumberOfWaysInSimulationLine;
    int NumberSimuationForScenary;
    int MaxNumerOfVehicles;
    int MinNumerOfVehicles;
    float timeNeededTheCarCompletTheRoundAbout;
    float percentIsBus;
    float percentIsCar;
    float percentIsPriorityVehicles;
   
    //Guardar Tempos de reação dos motorista
    float constTimeReactionTimePriorityDriver;
    float minReactionTimeSimpleDriver;
    float maxReactionTimeSimpleDriver;
    float constTimeReactionBusDriver;

    //Guardar Variação de Porcentagem de Aumento do tempo de espera quando há veiculos colididos.
    float probabilityOfNormalVehiclesCollision;
    float percentMinTimeIncreaseWhenHaveCollision;
    float percentMaxTimeIncreaseWhenHaveCollision;
    float percentColosionWhenHaveTrafficLightVehicles;

    //Guardar Variação de Porcentagem de Aumento do tempo de espera quando há veiculos Prioritarios.
    float percentMinTimeIncreaseWhenHavePriorityCar;
    float percentMaxTimeIncreaseWhenHavePriorityCar;

    int totalPercentTimeIncreaseWhenHavePriorityCar;
    int totalPercentTimeIncreaseWhenColision;
    int totalVeicles;
    int totalIsBus;
    int totalIsCar;
    int totalIsCarPriority; 

} Settings;
