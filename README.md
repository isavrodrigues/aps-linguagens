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

## Flex e Bison

A linguagem foi implementada usando Flex e Bison:

- **Flex** gera o analisador léxico, que identifica tokens como variáveis, números e comandos.
- **Bison** gera o analisador sintático, que interpreta a estrutura do programa baseada na gramática.

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
  // Registro de pilotos e equipes
  driver MaxV;
  driver ChecoP;
  team RedBull[MaxV,ChecoP];
  
  driver LewisH;
  driver GeorgeR;
  team Mercedes[LewisH,GeorgeR];

  // Variáveis de corrida
  fuelLoad : int;
  tyreWear : int;
  raceLaps : int;
  safetycar : bool;
  
  // Inicialização
  fuelLoad = 100;
  tyreWear = 0;
  raceLaps = 5;
  safetycar = false;
  
  // Tempos de volta
  sector1 : lapTime;
  sector2 : lapTime;
  sector3 : lapTime;
  bestLap : lapTime;
  
  sector1 = 28000;
  sector2 = 32000;
  sector3 = 30000;
  bestLap = 999999;
  
  // Simulação de corrida
  forLap(1..raceLaps) {
    // Cálculo do melhor tempo
    bestLap = min(bestLap, sector1 + sector2 + sector3);
    
    // Desgaste e consumo
    tyreWear = tyreWear + 3;
    fuelLoad = fuelLoad - 2;
    
    // Safety car aleatório (simulado)
    ifPit(tyreWear > 20 && !safetycar) {
      safetycar = true;
      radio("Safety car deployed!");
    }
    
    // Pontuações
    addPoint(MaxV, 25);
    addPoint(ChecoP, 18);
    addPoint(LewisH, 15);
    addPoint(GeorgeR, 12);
    
    // Pit stop estratégico
    ifPit(tyreWear > 15) {
      pitStop();
      tyreWear = 0;
      fuelLoad = fuelLoad + 50;
      radio("Box box box - pit stop complete");
    } elsePit {
      pushLap();
      radio("Push now, push now");
    }
  }
chequeredFlag
```



## Estrutura do Repositório

```
APS-Linguagens/
├── .vscode/             # Configurações do VS Code
├── exemplos/            # Scripts de exemplo (.pod)
│   ├── championship.pod
│   ├── exemplo.pod
│   ├── monaco_race.pod
│   ├── safety_car.pod
│   └── wet_race.pod
├── slides/              # Apresentação em PDF
│   └── podium.pdf
├── src/                 # Código-fonte e build
│   ├── podium.l         # Flex (scanner)
│   ├── podium.y         # Bison (parser)
│   ├── lex.yy.c         # Scanner gerado
│   ├── lex.yy.o         # Objeto do scanner
│   ├── podium.tab.c     # Parser gerado
│   ├── podium.tab.h     # Cabeçalhos do parser
│   ├── podium.tab.o     # Objeto do parser
│   ├── podium_ast.h     # Definição da AST
│   ├── podium_ast.c     # Construção/manipulação da AST
│   ├── podium_ast.o     # Objeto da AST
│   ├── podium_llvm.h    # Interface de simulação LLVM
│   ├── podium_llvm.c    # Implementação de simulação LLVM
│   ├── podium_llvm.o    # Objeto de simulação LLVM
│   ├── main.c           # Ponto de entrada (fonte)
│   ├── main.o           # Objeto do main
│   └── podium           # Executável
├── .gitignore           # Arquivo de exclusões
└── README.md            # Documento principal
```



## Como Compilar (MACOS)

No diretório `src/`, execute:

```bash
flex podium.l
bison -d podium.y

clang -c lex.yy.c

clang -c podium.tab.c

clang -c podium_ast.c

clang -c podium_llvm.c

clang -c main.c

clang -o podium main.o lex.yy.o podium.tab.o podium_ast.o podium_llvm.o
```

Isso gera o executável `src/podium`.

## Como Executar

Dentro de `src/`, rode:

```bash
./podium ../exemplos/championship.pod
```

Ou qualquer outro script em `exemplos/`.


## Apresentação
Em `slides/podium.pdf` está a apresentação com Motivação, Características e Exemplo.


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










