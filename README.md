# Podium - Linguagem de Simulação de Fórmula 1

**Podium** é uma linguagem de programação para simulação técnica e estratégica de Fórmula 1.

## Grid Oficial 2025

### Equipes e Pilotos

| Piloto                | Equipe         | Número |
|-----------------------|----------------|--------|
| Max Verstappen        | Red Bull       | 1      |
| Liam Lawson           | Red Bull       | 40     |
| Charles Leclerc       | Ferrari        | 16     |
| Lewis Hamilton        | Ferrari        | 44     |
| George Russell        | Mercedes       | 63     |
| Andrea Kimi Antonelli | Mercedes       | 47     |
| Lando Norris          | McLaren        | 4      |
| Oscar Piastri         | McLaren        | 81     |
| Fernando Alonso       | Aston Martin   | 14     |
| Lance Stroll          | Aston Martin   | 18     |
| Nico Hülkenberg       | Sauber         | 27     |
| Gabriel Bortoleto     | Sauber         | 50     |
| Pierre Gasly          | Alpine         | 10     |
| Jack Doohan           | Alpine         | 88     |
| Oliver Bearman        | Haas           | 87     |
| Esteban Ocon          | Haas           | 31     |
| Alexander Albon       | Williams       | 23     |
| Carlos Sainz          | Williams       | 55     |
| Yuki Tsunoda          | RB             | 22     |
| Isack Hadjar          | RB             | 37     |

### Circuitos da Temporada 2025

| Código | Nome               | País        | Zonas DRS | Voltas |
|--------|--------------------|-------------|-----------|--------|
| MON    | Monaco             | Mônaco      | 1         | 78     |
| SPA    | Spa-Francorchamps  | Bélgica     | 2         | 44     |
| SIL    | Silverstone        | Reino Unido | 3         | 52     |
| BAH    | Bahrain            | Bahrein     | 3         | 57     |
| CAT    | Catalunya          | Espanha     | 2         | 66     |
| ...    |  ...               |   ...       | ...       | ...    |


## Sistema de Competição

### Tipos de Evento

| Código | Tipo                | Pontuação? | Descrição                     |
|--------|----------------------|------------|-------------------------------|
| 1      | Corrida Oficial      | Sim        | Prova principal (50-78 voltas)|
| 2      | Classificação (Pole) | Sim*       | 1 ponto para a pole position  |
| 3      | Sprint Race          | Sim        | Prova curta (≈100km)          |

*Obs: A classificação (Pole) concede apenas 1 ponto adicional ao pole position, além dos pontos da corrida principal.

### Sistema de Pontuação

**Corrida Principal:**
| Posição | Pontos |
|---------|--------|
| 1º      | 25     |
| 2º      | 18     |
| 3º      | 15     |
| 4º      | 12     |
| 5º      | 10     |
| 6º      | 8      |
| 7º      | 6      |
| 8º      | 4      |
| 9º      | 2      |
| 10º     | 1      |

**Sprint Race:**
| Posição | Pontos |
|---------|--------|
| 1º      | 8      |
| 2º      | 7      |
| 3º      | 6      |
| 4º      | 5      |
| 5º      | 4      |
| 6º      | 3      |
| 7º      | 2      |
| 8º      | 1      |

**Bônus:**
- 1 ponto para a volta mais rápida (se finalizar no top 10)
- 1 ponto adicional para o pole position



## Recursos Técnicos

### Aerodinâmica
| Componente       | Valores | Efeito no Desempenho              | Exemplo Monaco |
|------------------|---------|------------------------------------|----------------|
| **Front Wing**   | 1-5     | 1=Plano (menor arrasto)           | 3 (balanço)    |
|                  |         | 5=Inclinado (maior downforce)     |                |
| **Rear Wing**    | 1-5     | 1=Perfil baixo (alta velocidade)  | 2 (foco em reta)|
|                  |         | 5=Alto (melhor tração)            |                |
| **Diffuser**     | 1-5     | 1=Baixo downforce                 | 4 (curvas apertadas)|
|                  |         | 5=Efeito solo máximo              |                |

### Suspensão
| Configuração     | Valores | Impacto                          | Setup Monaco |
|------------------|---------|----------------------------------|--------------|
| **Rigidez**      | soft/medium/hard | soft=mais aderência       | medium       |
| **Altura**       | 25-35mm | Baixa=melhor aerodinâmica        | 30mm         |

### Motor e ERS
| Parâmetro        | Opções          | Uso Típico                     | Qualy Setup |
|------------------|-----------------|--------------------------------|-------------|
| **Modo Motor**   | race/qualy/safety | qualy=potência máxima        | qualy       |
| **ERS**         | defend/overtake/hotlap | hotlap=melhor volta   | hotlap      |
| **Fuel Mix**    | lean/standard/rich | rich=mais potência         | rich        |

### Pneus (Pirelli)
| Composto  | Durabilidade | Temperatura Ótima | PSI Ideal | Uso em Monaco |
|-----------|--------------|--------------------|-----------|---------------|
| **Soft**  | 15-20 voltas | 100-115°C          | 21.5/20.0 | Q3 e início   |
| **Medium**| 25-35 voltas | 95-110°C           | 20.0/18.5 | Estratégia    |
| **Hard**  | 40+ voltas   | 90-105°C           | 18.5/17.0 | Raramente     |

### Sistema Técnico 
- Configurações aerodinâmicas (ângulo de asas, difusor)
- Modos de motor e ERS (qualy, race, defend, overtake)
- Degradação realista de pneus e combustível
- Pacotes técnicos por equipe (aero, motor, chassis)

### Simulação 
- Todos os tipos de sessão (Práticas, Qualy, Sprint, Corrida)
- Condições climáticas dinâmicas (seco, molhado, misto)
- Incidentes realistas (bandeiras, safety car, red flags)
- Sistema de DRS com zonas específicas por circuito

### Gestão Estratégica
- Planejamento de pit stops múltiplos
- Undercut/overcut estratégico
- Comunicação rádio com pilotos
- Ajustes em tempo real durante a corrida

## Exemplo de Configurações por Tipo de Circuito

### 1. Circuitos de Alta Velocidade (Monza)

```
aero {
    frontWing 1;  // Configuração mais plana possível
    rearWing 1;   // Mínimo arrasto aerodinâmico
    diffuser 2;   // Downforce reduzido
}
suspension {
    stiffness: hard;  // Para altas velocidades
    rideHeight: 25mm; // Baixo para melhor aerodinâmica
}
```
### 2.  Circuitos Técnicos (Monaco)

```
aero {
    frontWing 4;  // Máximo downforce para curvas apertadas
    rearWing 3;   // Equilíbrio entre downforce e velocidade na reta
    diffuser 5;   // Efeito solo máximo para aderência em baixas velocidades
    brakeDucts large; // Refrigeração extra para frenagens intensas
}

suspension {
    front: soft;    // Máxima aderência nas curvas de baixa velocidade
    rear: medium;   // Estabilidade na saída de curvas
    rideHeight: 35mm; // Maior altura para absorver irregularidades
}
```

### 3. Circuitos Mistos (Silverstone)

```
aero {
    frontWing 3;  // Equilíbrio downforce/arrasto
    rearWing 2;   // Configuração intermediária
    diffuser 4;   // Downforce moderado
}
suspension {
    stiffness: medium;
    rideHeight: 30mm; // Altura balanceada
}
```


## EBNF 

```ebnf
Program       := "seasonOpening" [Regulations] [Calendar] [Teams] [Drivers] [Circuits] 
                 [CarSetup] CommandList "seasonFinale"

Regulations   := "regulations" "{" [EngineModeRules] [TireRules] [DRSRules] [PitStopRules] "}"
EngineModeRules := "engineModes" "{" ["qualyMode" BoolVal] ["partyMode" BoolVal] 
                   ["fuelFlow" "max" Amount "kg/h"] "}"
TireRules     := "tires" "{" ["compounds" TireList] ["mandatory" TireRequirement] 
                 ["minPitStops" Number] "}"
DRSRules      := "DRS" "{" ["activationLap" Number] ["zones" TrackName Number] 
                 ["detectionPoints" ZoneList] "}"

Calendar      := "schedule" "{" {RaceWeekend} "}"
RaceWeekend   := "event" "(" TrackName "," Date ")" "{" [Practice] [Qualifying] [Sprint] [Race] "}"
Practice      := "practice" SessionName {"," SessionName} ";"
Qualifying    := "qualifying" "Q1" "," "Q2" "," "Q3" ";"
Sprint        := "sprint" [Number "laps"] ";"
Race          := "race" Number "laps" ";"

Teams         := "constructors" "{" {Constructor} "}"
Constructor   := TeamName "fields" "{" DriverPair TechnicalPackage Budget "}"
DriverPair    := "drivers" "(" DriverName "," DriverName ")" ";"
TechnicalPackage := "aero" AeroLevel "engine" EngineLevel "chassis" ChassisLevel ";"
Budget        := "budget" Amount ("million"|"billion") ";"

CarSetup      := "setup" "{" [AeroSetup] [Suspension] [EngineMode] [TireSelection] "}"
AeroSetup     := "aero" "{" "frontWing" FWAngle "rearWing" RWAngle "diffuser" DiffuserSetting "}"
Suspension    := "suspension" "{" "front" SuspensionSetting "rear" SuspensionSetting "}"
EngineMode    := "engine" "{" "mode" EngineModeSetting "ERS" ERSSetting "}"
TireSelection := "tires" "{" "current" TireCompound "stints" TireStintPlan "}"

CommandList   := { Command }
Command       := TelemetryCommand | StrategyCommand | EngineerCommand | RaceControlCommand 
               | Declaration | Assignment | Print | Conditional | Loop

TelemetryCommand := "adjust" AdjustmentType "for" DriverName "to" Value ";"
StrategyCommand := "callPitStop" "(" DriverName "," LapNumber "," TireCompound [,"FuelAdjust"] ")" ";"
EngineerCommand := "radioTo" DriverName ":" Message ";"
RaceControlCommand := "deploy" SafetyCarType | "issuePenalty" "(" DriverName "," PenaltyType ")"

Declaration   := "let" Identifier "be" Type ("=" Expression)? ";"  
Assignment    := Identifier "sets" Expression ";"  
Print         := "teamRadio" "(" Expression ")" ";"  
Conditional   := "ifYellowFlag" "(" Condition ")" Block ["elsePitLane" Block]
Loop          := "whileSafetyCar" "(" Condition ")" Block

RaceSim       := "simulateSession" "(" SessionType "," TrackName "," WeatherConditions ")" 
                 "{" {LapData} [Incidents] [StrategyCall] "}"
LapData       := "lap" LapRange "{" PositionData GapData TireData FuelData DRSData "}"
Incidents     := "incident" "lap" Number "{" "type" IncidentType "driver" DriverName 
                 ["safetyCar" SafetyCarType] "}"

/* Tipos e valores */
Type          := "int" | "float" | "bool" | "string" | "driver" | "team" | "track" 
               | "tire" | "engineMode" | "aeroConfig"
TireCompound  := "Soft" | "Medium" | "Hard" | "Inter" | "Wet"
EngineModeSetting := "race" | "qualy" | "safety" | "save"
ERSSetting    := "defend" | "overtake" | "hotlap" | "recovery"
SafetyCarType := "virtual" | "full" | "none"
PenaltyType   := "time" Amount | "grid" Positions | "driveThrough" | "stopGo"

```

## Exemplo de código 

```
seasonOpening
    regulations {
        engineModes {
            qualyMode allowed true;
            partyMode banned true;
        }
        tires {
            compounds Soft Medium Hard Inter Wet;
            mandatory twoDifferent dry;
        }
    }

    constructors {
        RedBull fields {
            drivers(MaxVerstappen, AndreaKimi);
            aero 95 engine 92 chassis 90;
            budget 150 million;
        }
    }

    setup {
        aero {
            frontWing 3;
            rearWing 2;
        }
        engine {
            mode qualy;
            ERS hotlap;
        }
    }

    simulateSession(Qualifying, Monaco, Dry) {
        lap Q3 {
            MaxVerstappen 1:10.921;
            CharlesLeclerc 1:11.345;
        }
    }
seasonFinale

```

### Sistema de Pontuação

```
let pointsSystem = {
    race: [25, 18, 15, 12, 10, 8, 6, 4, 2, 1],
    sprint: [8, 7, 6, 5, 4, 3, 2, 1],
    fastestLap: 1,
    polePosition: 1
};

```

## Fontes e Referências Técnicas

### Fontes Oficiais
As especificações técnicas da linguagem são baseadas em regulamentos e dados reais da F1:

#### Aerodinâmica
> "As equipes usam o máximo de downforce em Monaco, com ângulos de asa 30% maiores que em outros circuitos"  
> **FIA Technical Report Monaco GP 2023**  
[Relatório Completo](https://www.fia.com/regulation/category/110)
- Capítulo 3: Aerodinâmica
-  Capítulo 5: Unidade de Potência
- Anexo 6: Especificações de Pneus




