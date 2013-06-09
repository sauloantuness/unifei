#include <stdio.h>
#include <conio.h>

#define CIMA 72
#define DIREITA 77
#define BAIXO 80
#define ESQUERDA 75
#define ENTER 13
#define ESC 27
#define PECA '*'
#define BURACO 'o' 
#define FORA '#' 

void preenche(char m[9][9],int lin,int col,char c){
     int i,j;
     for (i=lin; i<lin+3; i++){
              for (j=col; j<col+3; j++)
                  m[i][j] = c;
     }  
}

void inicializa(char m[9][9]){
     preenche(m,0,0,FORA);
     preenche(m,0,3,PECA);
     preenche(m,0,6,FORA);
     
     preenche(m,3,0,PECA);
     preenche(m,3,3,PECA);
     preenche(m,3,6,PECA);
     
     preenche(m,6,0,FORA);
     preenche(m,6,3,PECA);
     preenche(m,6,6,FORA);
     
     m[4][4] = BURACO;
}

void imprimeChar(int corTexto, int corFundo, char c){
     printf(" ");
     textcolor(corTexto);  
     textbackground(corFundo);
     printf("%c",c);
     textcolor(15);  
     textbackground(0);
}

void imprime(char m[9][9]){
     int i,j;
     for (i=0; i<9; i++){
              for (j=0; j<9; j++){
                  switch(m[i][j]){
                    case BURACO: imprimeChar( 4, 0,BURACO); break;
                    case PECA: imprimeChar(15, 0,PECA); break;
                    case FORA: imprimeChar( 3, 0,FORA);  break;
                  }
              }
              printf("\n");             
     } 
}

void destaca(char m[9][9], int x, int y){
    gotoxy(y*2+1,x+1);
    imprimeChar(4,15,m[x][y]);  
}

void jogada(char m[9][9], int x1, int y1, int x2, int y2){
    
     int x, y;
     
     x = (x1+x2)/2;
     y = (y1+y2)/2;     
     
     m[x1][y1] = BURACO;
     m[x2][y2] = PECA;
     m[x][y]   = BURACO;

}

void verifica(char m[9][9], int x, int y){
     
     int cima=0,baixo=0,esquerda=0,direita=0;
     
     if(m[x][y] != PECA)
         return;
     
     if(x>1){
             if(m[x-1][y] == PECA && m[x-2][y] == BURACO){
                 destaca(m,x-2,y);     
                 cima = 1;
             }
     }
     if(x<7){
             if(m[x+1][y] == PECA && m[x+2][y] == BURACO){
                 destaca(m,x+2,y);     
                 baixo = 1;
             }
     }
     
     if(y>1){
             if(m[x][y-1] == PECA && m[x][y-2] == BURACO){
                 destaca(m,x,y-2);     
                 esquerda = 1;
             }
     }
     if(y<7){
             if(m[x][y+1] == PECA && m[x][y+2] == BURACO){
                 destaca(m,x,y+2);    
                 direita = 1;
             }
     }
     
     if(cima || baixo || esquerda || direita){
         if(getch() == 224){                            
             switch(getch()){
                 case CIMA:      if(cima) jogada(m,x,y,x-2,y); break;
                 case BAIXO:     if(baixo) jogada(m,x,y,x+2,y); break;
                 case ESQUERDA:  if(esquerda) jogada(m,x,y,x,y-2); break;                          
                 case DIREITA:   if(direita) jogada(m,x,y,x,y+2); break;                                                    
             }  
         }
     }
}

void moveCursor(char m[9][9], int pos[2], int movimento){
     switch(movimento){
        case CIMA:     if(pos[0]>0 && m[pos[0]-1][pos[1]] != FORA) pos[0]--; break;
        case BAIXO:    if(pos[0]<8 && m[pos[0]+1][pos[1]] != FORA) pos[0]++; break;
        case ESQUERDA: if(pos[1]>0 && m[pos[0]][pos[1]-1] != FORA) pos[1]--; break;
        case DIREITA:  if(pos[1]<8 && m[pos[0]][pos[1]+1] != FORA) pos[1]++; break;
     }
} 

int main (int argc, char *arvv[]){
    
    char m[9][9];
    int op, pos[] = {4,4};
    
    inicializa(m);
    imprime(m);
    destaca(m,pos[0],pos[1]);

    while(1){
        op = getch();
        if(op == 224){
            switch(getch()){
                case CIMA :     moveCursor(m,pos,CIMA); break;
                case DIREITA :  moveCursor(m,pos,DIREITA); break;
                case BAIXO :    moveCursor(m,pos,BAIXO); break;                                                                     
                case ESQUERDA : moveCursor(m,pos,ESQUERDA); break;                          
            }
        }
        else {
            switch(op){
                case ENTER: verifica(m,pos[0],pos[1]); break;
                case ESC: printf("oi"); break;
            }
        }  
        system("cls");
        imprime(m); 
        destaca(m,pos[0],pos[1]); 
        
    }
    
    system("pause");
    return 0;
}
