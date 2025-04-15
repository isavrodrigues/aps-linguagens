# F1Ling – Linguagem de Programação de Fórmula 1

**F1Ling** é uma linguagem de programação temática inspirada no mundo da Fórmula 1.

## Características

- **Temática F1:** Palavras-chave inspiradas em corridas e estratégias, como `polePosition`, `checkered`, `driver`, `lap`, entre outras.
- **Estruturas Básicas:** Suporte a declaração de variáveis, atribuições, condicionais e laços de repetição.
- **Operação com Inteiros:** Todas as operações utilizam números inteiros (ex.: tempos de volta, velocidades, pontos, etc.).


## Especificação EBNF

```
Program       := "polePosition" CommandList "checkered"

(Uma lista de comandos, onde zero ou mais comandos podem ocorrer *)
CommandList   := { Command }

( Cada comando pode ser uma declaração, atribuição, impressão, condicional ou loop *)
Command       := Declaration 
                | Assignment 
                | Print 
                | Conditional 
                | Loop

(Declaração de variável: exemplo "driver maxSpeed drives int;")
Declaration   := "driver" Identifier "drives" Type ";"  

(Atribuição de valor: exemplo "maxSpeed updates maxSpeed + 10;")
Assignment    := Identifier "updates" Expression ";"  

(Impressão de valor: exemplo "radio( maxSpeed );")
Print         := "radio" "(" Expression ")" ";"  

(Estrutura condicional: exemplo "ifOvertake(maxSpeed > 150) { ... } elseOvertake { ... }" )
Conditional   := "ifOvertake" "(" Condition ")" Block [ "elseOvertake" Block ]  

(Estrutura de repetição: exemplo "lap(maxSpeed < 250) { ... }" )
Loop          := "lap" "(" Condition ")" Block  

(Bloco de comandos delimitado por chaves)
Block         := "{" CommandList "}"  

(Condição relacional: exemplo "maxSpeed > 150" )
Condition     := Expression RelationalOp Expression

(Expressão aritmética com operadores de adição e subtração)
Expression    ::= Term { ("+" | "-") Term }

(Termo aritmético que utiliza multiplicação e divisão)
Term          := Factor { ("*" | "/") Factor }

(Fator: número, identificador ou expressão entre parênteses)
Factor         := Number 
                | Identifier 
                | "(" Expression ")"

(Operadores relacionais suportados)
RelationalOp  := ">" | "<" | "==" | "!=" | ">=" | "<="

(Atualmente, apenas o tipo inteiro está disponível)
Type          := "int"

(Identificador: começa com uma letra, seguido por letras, dígitos ou o caractere "_")
Identifier    := Letter { Letter | Digit | "_" }

(Símbolos para letras: qualquer caractere alfabético)
Letter        := "a" | "b" | "c" | ... | "z" | "A" | "B" | "C" | ... | "Z"

(Dígito: números de 0 a 9)
Digit         ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

(Número: opcionalmente negativo e composto por um ou mais dígitos)
Number        := [ "-" ] Digit { Digit }
```

## Exemplo de Programa em F1Ling

```
polePosition
    driver maxSpeed drives int;
    maxSpeed updates 200;

    radio( maxSpeed );

    ifOvertake( maxSpeed > 150 )
    {
        radio( 1 );
    }
    elseOvertake
    {
        radio( 0 );
    }
    
    lap( maxSpeed < 250 )
    {
        maxSpeed updates maxSpeed + 10;
        radio( maxSpeed );
    }
checkered

```

Explicação do exemplo:

O programa inicia com polePosition e termina com checkered.

É declarada a variável maxSpeed do tipo inteiro.

A variável é atualizada e seu valor é exibido por meio da função radio.

Um condicional (ifOvertake) verifica se maxSpeed é superior a 150, executando o bloco correspondente ou o bloco alternativo (elseOvertake).


