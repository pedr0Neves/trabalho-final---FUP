#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

//biblioteca de funções utilizadas

#include "acesso.h"
#include "geral.h"

#define clear system("cls");

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//funções utilizadas da parte jogavel

void moldura();
void inimigo_1();
void inimigo_2();
void inimigo_3();
void inimigo_4();
void inimigo_5();
void inimigo_6();
void inimigo_7();
void jogar();

int main(void)
{
    char acao, nome_jogador[10];
    int apagar, cont, cont2 = 0, placar;

    moldura();
    gotoxy(23,10);
    printf("aperte [ENTER] para comecar\n");
    acao = getch();

    while(acao != 's'){
        clear;
        moldura();
        gotoxy(24,12);
        printf("aperte [z] para entrar no login\n");
        gotoxy(24,14);
        printf("aperte [c] para criar um login\n");
        gotoxy(24,16);
        printf("aperte [s] para sair\n");
        acao = getch();

        if(acao == 'c'){
            jogador = criar_login(jogador,&cont2);
        } else if(acao == 'z'){
            int confirmador = 0;
            fazer_login(&confirmador,&cont2,nome_jogador);

            if(confirmador == 2){
                printf("login errado.\n");
                confirmador = 0;
                acao = getch();
                clear;
            }else if(confirmador == 1){
                while(acao != 's'){
                    clear;
                    moldura();
                    gotoxy(25,8);
                    printf("aperte [w] comecar a jogar\n");
                    gotoxy(19,10);
                    printf("aperte [a] para ir para o ranking geral\n");
                    gotoxy(21,12);
                    printf("aperte [d] para deletar um ranking\n");
                    gotoxy(28,14);
                    printf("aperte [s] para sair\n");
                    gotoxy(35,20);
                    printf("escolha: ");
                    acao = getch();

                    if(acao == 'w'){
                        clear;
                        jogar(&placar);
                        score = adiciona_score(score,&cont,nome_jogador,placar);
                    } else if(acao == 'd'){
                        clear;
                        score = remover_score(score,&cont,&apagar);
                    } else if(acao == 'a'){
                        clear;
                        imprimir_score(score,&cont);
                    }
                }
            } else {
               continue; 
            }
        }
    }

    free(jogador);
    free(score);

    return 0;
}

void moldura()
{
    for(int i = 2; i <= 79; i++){
        gotoxy(i,1);
        printf("=");
    }
    for(int i = 2; i <= 79; i++){
        gotoxy(i,25);
        printf("=");
    }
    for(int i = 2; i <= 24; i++){
        gotoxy(1,i);
        printf("[");
    }
    for(int i = 2; i <= 24; i++){
        gotoxy(80,i);
        printf("]");
    }

    gotoxy(1,1);
    printf("*");
    gotoxy(80,25);
    printf("*");
    gotoxy(1,25);
    printf("*");
    gotoxy(80,1);
    printf("*");
}

void inimigo_1()
{
    gotoxy(10,5);
    printf("8");
    gotoxy(10,6);
    printf("8");
    gotoxy(11,5);
    printf("8");
    gotoxy(11,6);
    printf("8");
    gotoxy(12,5);
    printf("8");
    gotoxy(12,6);
    printf("8");
}

void inimigo_2()
{
    gotoxy(20,5);
    printf("8");
    gotoxy(20,6);
    printf("8");
    gotoxy(21,5);
    printf("8");
    gotoxy(21,6);
    printf("8");
    gotoxy(22,5);
    printf("8");
    gotoxy(22,6);
    printf("8");
}

void inimigo_3()
{
    gotoxy(30,5);
    printf("8");
    gotoxy(30,6);
    printf("8");
    gotoxy(31,5);
    printf("8");
    gotoxy(31,6);
    printf("8");
    gotoxy(32,5);
    printf("8");
    gotoxy(32,6);
    printf("8");
}

void inimigo_4()
{
    gotoxy(40,5);
    printf("8");
    gotoxy(40,6);
    printf("8");
    gotoxy(41,5);
    printf("8");
    gotoxy(41,6);
    printf("8");
    gotoxy(42,5);
    printf("8");
    gotoxy(42,6);
    printf("8");
}

void inimigo_5()
{
    gotoxy(50,5);
    printf("8");
    gotoxy(50,6);
    printf("8");
    gotoxy(51,5);
    printf("8");
    gotoxy(51,6);
    printf("8");
    gotoxy(52,5);
    printf("8");
    gotoxy(52,6);
    printf("8");
}

void inimigo_6()
{
    gotoxy(60,5);
    printf("8");
    gotoxy(60,6);
    printf("8");
    gotoxy(61,5);
    printf("8");
    gotoxy(61,6);
    printf("8");
    gotoxy(62,5);
    printf("8");
    gotoxy(62,6);
    printf("8");
}

void inimigo_7()
{
    gotoxy(70,5);
    printf("8");
    gotoxy(70,6);
    printf("8");
    gotoxy(71,5);
    printf("8");
    gotoxy(71,6);
    printf("8");
    gotoxy(72,5);
    printf("8");
    gotoxy(72,6);
    printf("8");
}

int PosiX = 40;
int TiroY = 19;
int tiro_inimigoY[7];
int tiro_inimigoX[7];
int tiro_inimigo[7];

void jogar(int *placar)
{
    char acao;
    int tempo = 0;
    int Tiro = 0;
    int TiroX = 0;
    *placar = 0;

    int inimigo1 = 1;
    int inimigo2 = 1;
    int inimigo3 = 1;
    int inimigo4 = 1;
    int inimigo5 = 1;
    int inimigo6 = 1;
    int inimigo7 = 1;

    while(acao != '1'){

        while(!kbhit()){
            clear;

            gotoxy(PosiX, 20);
            printf("U");
            gotoxy(70,3);
            printf("score: %d", *placar);
            tempo++;

            if(inimigo1 == 1){
                inimigo_1();

                if(tempo % 2 == 0 && tiro_inimigo[0] == 0){
                    tiro_inimigo[0] = 1;
                    tiro_inimigoX[0] = 11;
                    tiro_inimigoY[0] = 7;
                    gotoxy(tiro_inimigoX[0],tiro_inimigoY[0]);
                    printf("!");
                }
            }
            if(((TiroX == 10) || (TiroX == 11) || (TiroX == 12)) && TiroY == 6 && inimigo1 == 1){
                inimigo1 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo2 == 1){
                inimigo_2();

                if(tempo % 7 == 0 && tiro_inimigo[1] == 0){
                    tiro_inimigo[1] = 1;
                    tiro_inimigoX[1] = 21;
                    tiro_inimigoY[1] = 7;
                    gotoxy(tiro_inimigoX[1],tiro_inimigoY[1]);
                    printf("!");
                }
            }
            if(((TiroX == 20) || (TiroX == 21) || (TiroX == 22)) && TiroY == 6 && inimigo2 == 1){
                inimigo2 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo3 == 1){
                inimigo_3();

                if(tempo % 3 == 0 && tiro_inimigo[2] == 0){
                    tiro_inimigo[2] = 1;
                    tiro_inimigoX[2] = 31;
                    tiro_inimigoY[2] = 7;
                    gotoxy(tiro_inimigoX[2],tiro_inimigoY[2]);
                    printf("!");
                }
            }
            if(((TiroX == 30) || (TiroX == 31) || (TiroX == 32)) && TiroY == 6 && inimigo3 == 1){
                inimigo3 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo4 == 1){
                inimigo_4();

                if(tempo % 5 == 0 && tiro_inimigo[3] == 0){
                    tiro_inimigo[3] = 1;
                    tiro_inimigoX[3] = 41;
                    tiro_inimigoY[3] = 7;
                    gotoxy(tiro_inimigoX[3],tiro_inimigoY[3]);
                    printf("!");
                }
            }
            if(((TiroX == 40) || (TiroX == 41) || (TiroX == 42)) && TiroY == 6 && inimigo4 == 1){
                inimigo4 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo5 == 1){
                inimigo_5();

                if(tempo % 11 == 0 && tiro_inimigo[4] == 0){
                    tiro_inimigo[4] = 1;
                    tiro_inimigoX[4] = 51;
                    tiro_inimigoY[4] = 7;
                    gotoxy(tiro_inimigoX[4],tiro_inimigoY[4]);
                    printf("!");
                }
            }
            if(((TiroX == 50) || (TiroX == 51) || (TiroX == 52)) && TiroY == 6 && inimigo5 == 1){
                inimigo5 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo6 == 1){
                inimigo_6();

                if(tempo % 13 == 0 && tiro_inimigo[5] == 0){
                    tiro_inimigo[5] = 1;
                    tiro_inimigoX[5] = 61;
                    tiro_inimigoY[5] = 7;
                    gotoxy(tiro_inimigoX[5],tiro_inimigoY[5]);
                    printf("!");
                }
            }
            if(((TiroX == 60) || (TiroX == 61) || (TiroX == 62)) && TiroY == 6 && inimigo6 == 1){
                inimigo6 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            if(inimigo7 == 1){
                inimigo_7();

                if(tempo % 9 == 0 && tiro_inimigo[6] == 0){
                    tiro_inimigo[6] = 1;
                    tiro_inimigoX[6] = 71;
                    gotoxy(tiro_inimigoX[6],tiro_inimigoY[6]);
                    tiro_inimigoY[6] = 7;
                    printf("!");
                }
            }
            if(((TiroX == 70) || (TiroX == 71) || (TiroX == 72)) && TiroY == 6 && inimigo7 == 1){
                inimigo7 = 0; (*placar)++; Tiro = 0; TiroX = 0; TiroY = 0;
            }

            for(int i = 0; i < 7; i++){
                if(tiro_inimigo[i] == 1){
                    gotoxy(tiro_inimigoX[i],tiro_inimigoY[i]);
                    printf("!");
                    tiro_inimigoY[i]++;
                }
                if(tiro_inimigoY[i] == 25){
                    tiro_inimigo[i] = 0; //caso não acerte o jogador;
                }
            }

            if(Tiro == 1){
            gotoxy(TiroX,TiroY);
            printf("*");
            TiroY = TiroY - 1;
            }
            if(TiroY == 2){
                Tiro = 0; // caso não acerte nenhum inimigo
            }

            if(inimigo1 == 0 && inimigo2 == 0 && inimigo3 == 0 && inimigo4 == 0 && inimigo5 == 0 && inimigo6 == 0 && inimigo7 == 0){
                inimigo1 = 1;
                inimigo2 = 1;
                inimigo3 = 1;
                inimigo4 = 1;
                inimigo5 = 1;
                inimigo6 = 1;
                inimigo7 = 1;

                Sleep(2);
            }

            for(int i = 0; i < 7; i++){
                if(tiro_inimigoY[i] == 20 && tiro_inimigoX[i] == PosiX){
                clear;
                gotoxy(40,12);
                printf("[ VOCE MORREU ]");
                gotoxy(30,14);
                printf("[ APERTE QUALQUER TECLA PARA COMECAR ]");
                acao = getch();
                
                return;
                }
            }
            
            moldura();
        }

        acao = getch();

        if(acao == 'a'){
            PosiX--;
            if(PosiX == 1){
                PosiX++;
            }
        } else if (acao == 'd'){
            PosiX++;
            if(PosiX == 80){
                PosiX--;
            }
        } else if(acao == 't'){
            Tiro = 1;
            TiroX = PosiX;
            gotoxy(TiroX,TiroY);
            printf("*");
            TiroY = 19;
        }
    }
}
