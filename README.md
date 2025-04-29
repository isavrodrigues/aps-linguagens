# Podium

**Podium** é uma linguagem de programação para simulação técnica e estratégica de Fórmula 1.


---

## Equipes & Pilotos Sugeridos

- **Red Bull Racing:** Max Verstappen, Sergio Pérez  
- **Mercedes‑AMG:** Lewis Hamilton, George Russell  
- **Scuderia Ferrari:** Charles Leclerc, Carlos Sainz  
- **McLaren F1 Team:** Lando Norris, Oscar Piastri  
- **Aston Martin:** Fernando Alonso, Lance Stroll

*A pontuação de equipe é sempre a soma dos pontos dos dois pilotos.*

---

## Tipos de Dados

| Tipo      | Descrição                                           |
|-----------|-----------------------------------------------------|
| `int`     | Inteiros (pontos, voltas, carga de combustível)     |
| `bool`    | Flags verdadeiras/falsas (safety car ativo/inativo)|
| `lapTime` | Tempo de volta em milésimos (ex.: 90012)            |

Variáveis de volta pré-definidas:  
```  
sector1 : lapTime;  
sector2 : lapTime;  
sector3 : lapTime;  
```

---

## EBNF da Linguagem

```ebnf
Program       ::= "greenLight" StatementList "chequeredFlag"

StatementList ::= { Statement }

Statement     ::= Declaration
                | Assignment
                | Conditional
                | Loop
                | Command ";"

/// 1. Declarações
Declaration   ::= DriverDecl
                | TeamDecl
                | VarDecl ";"

DriverDecl    ::= "driver" Identifier ";"
TeamDecl      ::= "team" Identifier "[" Identifier "," Identifier "]" ";"
VarDecl       ::= Identifier ":" Type

Type          ::= IDENTIFIER   // int, bool, lapTime

/// 2. Atribuições & Expressões
Assignment    ::= Identifier "=" Expr ";"
Expr          ::= Term { ("+"|"-") Term }
Term          ::= Factor { ("*"|"/") Factor }
Factor        ::= Number | Identifier | "(" Expr ")"

Number        ::= Digit { Digit }
Digit         ::= "0" ... "9"

/// 3. Condicionais de Paddock
Conditional   ::= "ifPit" "(" Condition ")" Block [ "elsePit" Block ]
Condition     ::= Expr RelOp Expr
RelOp         ::= ">" | "<" | "==" | "!=" | ">=" | "<="
Block         ::= "{" StatementList "}"

/// 4. Loops de Volta
Loop          ::= "forLap" "(" Expr ".." Expr ")" Block
                | "whileSC" "(" Condition ")" Block

/// 5. Comandos F1
Command       ::= "pitStop"
                | "pushLap"
                | "radio" "(" Expr ")"
                | "min" "(" Expr "," Expr ")"
                | "max" "(" Expr "," Expr ")"
                | "addPoint" "(" Identifier "," Expr ")"

Identifier    ::= Letter { Letter | Digit | "_" }
Letter        ::= "a" ... "z" | "A" ... "Z"
```

---

## Explicações

- **`forLap(1..N)`**  
  Loop de voltas de 1 até N:
  ```  
  raceLaps : int;
  raceLaps = 58;
  forLap(1..raceLaps) { ... }
  ```
- **Sistema de Pontuação**  
  ```  
  addPoint(Piloto, pontos);
  // Ao final:
  // teamPoints(Equipe) = driverPoints(P1) + driverPoints(P2);
  ```
- **Variáveis de volta**  
  `sector1`, `sector2`, `sector3` devem ser definidas ou atribuídas antes do uso em `bestLap = min(...);`.

---

## Exemplo Completo

```  
greenLight
  // Pilotos e equipes
  driver MaxV;
  driver ChecoP;
  team RedBull[MaxV,ChecoP];

  // Variáveis de corrida
  fuelLoad : int;
  tyreWear : int;
  bestLap  : lapTime;
  sector1  : lapTime;
  sector2  : lapTime;
  sector3  : lapTime;

  fuelLoad = 100;
  tyreWear = 0;
  bestLap  = 999;

  // Simula 58 voltas
  raceLaps : int;
  raceLaps = 58;
  forLap (1..raceLaps) {
    // calcular volta
    bestLap = min(bestLap, sector1 + sector2 + sector3);
    // desgaste e consumo
    tyreWear = tyreWear + 3;
    fuelLoad = fuelLoad - 2;

    // pontuações
    addPoint(MaxV,25);
    addPoint(ChecoP,18);

    // pit stop
    ifPit(tyreWear > 60 || fuelLoad < 20) {
      pitStop();
      tyreWear = 0;
      fuelLoad = fuelLoad + 50;
      radio("Pit done");
    }
  }

  // Pontuação de construtores
  // teamPoints(RedBull) = driverPoints(MaxV) + driverPoints(ChecoP)

chequeredFlag
```



## Fontes e Referências Técnicas

### Fontes Oficiais
As especificações técnicas da linguagem são baseadas em regulamentos e dados reais da F1:


> "As equipes usam o máximo de downforce em Monaco, com ângulos de asa 30% maiores que em outros circuitos"  
> **FIA Technical Report Monaco GP 2023**
 
[Relatório Completo](https://www.fia.com/regulation/category/110)
- Capítulo 3: Aerodinâmica
-  Capítulo 5: Unidade de Potência
- Anexo 6: Especificações de Pneus

### Fontes Não-Oficiais

#### Red Bull RB20 (2024)

> *"O design do RB20 mostra como pequenos ajustes aerodinâmicos geram grandes ganhos"* 

[Análise técnica no YouTube](https://www.youtube.com/watch?v=b2u6DDp4DtE)
- **Aplicações:**
  - Configuração de asas (`aero.frontWing 4`)
  - Estratégia de ERS (`engine.ERS = hotlap`)
  - Pressões de pneus otimizadas


## Flex e Bison

A linguagem foi implementada usando Flex e Bison:

- **Flex** gera o analisador léxico, que identifica tokens como variáveis, números e comandos.
- **Bison** gera o analisador sintático, que interpreta a estrutura do programa baseada na gramática.

o Flex apresenta alguns erros no reconhecimento de tokens, principalmente em comentários e strings.






