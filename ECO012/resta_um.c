#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define LEVEL      1
#define TAM_BLOCO  (LEVEL*2+1)
#define TAM_MATRIZ (TAM_BLOCO*3)

// Peças
#define PAREDE     '#'
#define PECA       '*'
#define VAZIO      'o'

// Teclas
#define DIRECIONAL 224
#define CIMA       72
#define DIREITA    77
#define BAIXO      80
#define ESQUERDA   75
#define ESPACO     32
#define ENTER      13
#define ESC        27

// Cores Conio
#define BLACK         0
#define BLUE          1
#define GREEN         2
#define CYAN          3
#define RED           4
#define MAGENTA       5
#define BROWN         6
#define LIGHTGRAY     7
#define DARKGRAY      8
#define LIGHTBLUE     9
#define LIGHTGREEN   10
#define LIGHTCYAN    11
#define LIGHTRED     12
#define LIGHTMAGENTA 13
#define YELLOW       14
#define WHITE        15

// Cores jogo
#define CORFUNDO            WHITE
#define CORPECA             BLACK
#define CORVAZIO            LIGHTRED
#define CORPAREDE           GREEN
#define CORTEXTODESTAQUE    WHITE
#define CORFUNDODESTAQUE    MAGENTA
#define CORTEXTOJOGADA      WHITE
#define CORFUNDOJOGADA      LIGHTBLUE
#define CORTITULO           BLACK
#define CORCONTEUDO         DARKGRAY

// Variáveis Globais
char m[TAM_MATRIZ][TAM_MATRIZ];
int posLin;
int posCol;
int pontuacao = (TAM_BLOCO*TAM_BLOCO*5-1);
int jogadas   = 0;
int fimDeJogo = 0;

void preencheBloco(int linha, int coluna, char c){

    // Preenche na matriz um quadrado de TAM_BLOCOxTAM_BLOCO com o caractere C
    // tendo como ponto inicial o vértice superior esquerdo o ponto (linha,coluna)

    int i, j;
    for (i=linha; i<linha+TAM_BLOCO; i++){
        for(j=coluna; j<coluna+TAM_BLOCO; j++){
            m[i][j] = c;
        }
    }
    return;
}

void inicializaMatriz(){

    // Preenche a matriz em 9 blocos iguais de TAM_BLOCOxTAM_BLOCO.

    preencheBloco(0,           0,           PAREDE);
    preencheBloco(0,           TAM_BLOCO,   PECA);
    preencheBloco(0,           TAM_BLOCO*2, PAREDE);

    preencheBloco(TAM_BLOCO,   0,           PECA);
    preencheBloco(TAM_BLOCO,   TAM_BLOCO,   PECA);
    preencheBloco(TAM_BLOCO,   TAM_BLOCO*2, PECA);

    preencheBloco(TAM_BLOCO*2, 0,           PAREDE);
    preencheBloco(TAM_BLOCO*2, TAM_BLOCO,   PECA);
    preencheBloco(TAM_BLOCO*2, TAM_BLOCO*2, PAREDE);

    // Preenche com um VAZIO a posição central do tabuleiro

    int centro = (int)TAM_MATRIZ/2;
    m[centro][centro] = VAZIO;

    return;
}

void imprimeChar(char c){

    // Imprime um único caractere na matriz

    switch(c){
        case PAREDE: textcolor(CORPAREDE); break;
        case PECA:   textcolor(CORPECA);   break;
        case VAZIO:  textcolor(CORVAZIO);  break;
     }

     printf(" %c",c);

     return;
}

void imprimeMatriz(){

    // Limpa tela
    system("cls");

    // Imprime a matriz

    int i,j;
    for (i=0; i<TAM_MATRIZ; i++){
        for(j=0; j<TAM_MATRIZ; j++){
            imprimeChar(m[i][j]);
        }
        printf("\n");
    }

    return;
}

void destaca(int lin, int col){

    // Destaca um elemento da matriz m(lin,col)

    int x = (col+1)*2;
    int y = (lin+1);
    
    // Lembrando que gotoxy(x,y) posiciona o cursor como se fosse
    // um ponto em um gráfico
    
    gotoxy(x,y);

    if(posLin != lin || posCol != col){
        textcolor(CORTEXTOJOGADA);
        textbackground(CORFUNDOJOGADA);
    }
    else{
        textbackground(CORFUNDODESTAQUE);
        textcolor(CORTEXTODESTAQUE);
    }

    printf("%c", m[lin][col]);
    textbackground(CORFUNDO);

    return;
}

void moveCursor(int movimento){

    // Verifica se a posição desejada está dentro da matriz e se não tem parede

    switch(movimento){
        case CIMA:     if(posLin > 0            && m[posLin-1][posCol] != PAREDE) posLin--; break;
        case BAIXO:    if(posLin < TAM_MATRIZ-1 && m[posLin+1][posCol] != PAREDE) posLin++; break;
        case ESQUERDA: if(posCol > 0            && m[posLin][posCol-1] != PAREDE) posCol--; break;
        case DIREITA:  if(posCol < TAM_MATRIZ-1 && m[posLin][posCol+1] != PAREDE) posCol++; break;
    }
    return;
}

void jogada(int movimento){

    // Faz a jogada

    jogadas++;
    pontuacao--;

    int posLin1, posCol1;
    int posLin2 = posLin;
    int posCol2 = posCol;

    // Switch que determinará pra onde a PECA que irá comer vai parar

    switch(movimento){
       case CIMA:     posLin2 = posLin - 2; break;
       case BAIXO:    posLin2 = posLin + 2; break;
       case ESQUERDA: posCol2 = posCol - 2; break;
       case DIREITA:  posCol2 = posCol + 2; break;
    }

    // Posição entre a posição inicial e final da peça que irá comer

    posLin1 = (posLin+posLin2)/2;
    posCol1 = (posCol+posCol2)/2;

    m[posLin][posCol]   = VAZIO;  // Posição onde o cursor estava
    m[posLin1][posCol1] = VAZIO;  // Posição que será 'comida'
    m[posLin2][posCol2] = PECA;   // Posição que a PECA que comeu irá parar

    // Movimenta o cursor para posição final da PECA que comeu

    posLin = posLin2;
    posCol = posCol2;

}

void verifica(){

    // Verifica quais das 4 opções são possíveis de jogar.

    int cima=0, baixo=0, esquerda=0, direita=0;

    // Verifica se a posição onde o cursor está é uma PECA

     if(m[posLin][posCol] != PECA)
         return;

     // Verifica jogada para cima

     if(posLin>1 &&                     // Verifica se linhas acima a posição estará na matriz
        m[posLin-1][posCol] == PECA &&  // Verifica se a primeira casa acima é uma PECA
        m[posLin-2][posCol] == VAZIO){  // Verifica se a segunda casa acima é um VAZIO
            destaca(posLin-2,posCol);   // Se satisfazer todas as condições, desta a jogada
            cima = 1;                   // Marca como possível a jogada para cima
     }

     // Verifica jogada para baixo

     if(posLin<7 &&
        m[posLin+1][posCol] == PECA &&
        m[posLin+2][posCol] == VAZIO){
            destaca(posLin+2,posCol);
            baixo = 1;
     }

     // Verifica jogada para esquerda

     if(posCol>1 &&
        m[posLin][posCol-1] == PECA &&
        m[posLin][posCol-2] == VAZIO){
            destaca(posLin,posCol-2);
            esquerda = 1;
     }

     // Verifica jogada para direita

     if(posCol<7 &&
        m[posLin][posCol+1] == PECA &&
        m[posLin][posCol+2] == VAZIO){
            destaca(posLin,posCol+2);
            direita = 1;
     }

     // Verifica se alguma jogada é possível

     if(cima || baixo || esquerda || direita){

        // Se apenas uma jogada está disponível, faz a jogada automaticamente.
        // Se mais de uma está disponível, destaca as opções possíveis
        // e pede ao jogador selecionar uma.

         if(getch() == 224){

             switch(getch()){
                 case CIMA:      if(cima)     jogada(CIMA);     break;
                 case BAIXO:     if(baixo)    jogada(BAIXO);    break;
                 case ESQUERDA:  if(esquerda) jogada(ESQUERDA); break;
                 case DIREITA:   if(direita)  jogada(DIREITA);  break;
             }
         }
     }
}

void imprimeStatus(){

    // Imprime informações do jogo

    int x = (TAM_MATRIZ+1)*2;
    int y = (1);

    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("        RESTA UM");

    gotoxy(x,y++);
    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("PONTUACAO: ");
    textcolor(CORCONTEUDO);
    printf("%d",pontuacao);

    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("JOGADAS:  ");
    textcolor(CORCONTEUDO);
    printf("%3d",jogadas);

    gotoxy(x,y++);
    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("       INSTRUCOES");

    gotoxy(x,y++);
    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf(" SETAS: ");
    textcolor(CORCONTEUDO);
    printf("Movimentam o cursor");

    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf(" ENTER: ");
    textcolor(CORCONTEUDO);
    printf("Faz jogada");

    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("ESPACO: ");
    textcolor(CORCONTEUDO);
    printf("Sugestao de jogada");

    gotoxy(x,y++);
    textcolor(CORTITULO);
    printf("   ESC: ");
    textcolor(CORCONTEUDO);
    printf("Sai do Jogo");

    return;
}

void imprimeFimdejogo(){

    // Imprime mensagem de fim de jogo

    int x = (TAM_MATRIZ+1)*2;
    int y = (13);
    gotoxy(x,y);
    textcolor(LIGHTRED);
    printf("  --  SEM MAIS JOGADAS --");

    return;
}

void sugestao(){

    // Verifica se há opções de jogada

    int lin,col;

    for(lin=0; lin<TAM_MATRIZ; lin++){
        for (col=0; col<TAM_MATRIZ; col++){

            if(m[lin][col] != PECA)
                 continue;

             // Verifica jogada para cima

             if(lin>1 &&                    // Verifica se linhas acima a posição estará na matriz
                m[lin-1][col] == PECA &&    // Verifica se a primeira casa acima é uma PECA
                m[lin-2][col] == VAZIO){    // Verifica se a segunda casa acima é um VAZIO
                    destaca(lin-2,col);     
                    destaca(lin,col);
                    Sleep(500);
                    return;                 
             }

             // Verifica jogada para baixo

             if(lin<7 &&
                m[lin+1][col] == PECA &&
                m[lin+2][col] == VAZIO){
                    destaca(lin,col);
                    destaca(lin+2,col);
                    Sleep(500);
                    return;
             }

             // Verifica jogada para esquerda

             if(col>1 &&
                m[lin][col-1] == PECA &&
                m[lin][col-2] == VAZIO){
                    destaca(lin,col);
                    destaca(lin,col-2);
                    Sleep(500);
                    return;
             }

             // Verifica jogada para direita

             if(col<7 &&
                m[lin][col+1] == PECA &&
                m[lin][col+2] == VAZIO){
                    destaca(lin,col);
                    destaca(lin,col+2);
                    Sleep(500);
                    return;
             }
        }
    }

    fimDeJogo = 1;

    return;
}


int main(int argc, char *argv[]){

    // Inicializa matriz e a posição central do cursor

    textbackground(CORFUNDO);
    inicializaMatriz(m);
    posLin = (int)TAM_MATRIZ/2;
    posCol = (int)TAM_MATRIZ/2;
    int tecla;

    // Inicia a lógica do jogo

    while(1){

        imprimeMatriz(m);
        destaca(posLin,posCol);
        imprimeStatus();
        if(pontuacao == 1)
            imprimeFimdejogo;

        if(fimDeJogo)
            imprimeFimdejogo();


        tecla = getch();

        if(tecla == DIRECIONAL){

            switch(getch()){
                case CIMA:     moveCursor(CIMA);       break;
                case DIREITA:  moveCursor(DIREITA);    break;
                case BAIXO:    moveCursor(BAIXO);      break;
                case ESQUERDA: moveCursor(ESQUERDA);   break;
            }
        }
        else {
            switch(tecla){
                case ENTER:     verifica(); break;
                case ESPACO:    sugestao(); break;
                case ESC:       return;
            }
        }
        gotoxy(TAM_MATRIZ*2+1,TAM_MATRIZ);

    }


    return 0;
}
