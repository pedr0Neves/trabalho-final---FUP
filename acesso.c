#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "acesso.h"

#define clear system("cls");

acesso *jogador;

acesso jogador_novo()
{
    acesso novo;

    printf("digite aqui o nome do save: ");
    scanf("%s", novo.nome);
    printf("\n\n");
    printf("digite aqui sua senha: ");
    scanf("%s", novo.senha);

    return novo;
}

void erro_login()
{
    FILE *login = fopen("login.txt","w");
    fclose(login);
}

void ler_login(int *cont2)
{
    FILE *login;

    int n;
    char nome[10], senha[10];

    login = fopen("login.txt","r");
    if(login == 0){
        erro_login();
    }

    *cont2 = 0;
    while((fscanf(login, "%d\n%s\n%s\n", &n, nome, senha)) == 3){
        (*cont2)++;
    }

    fclose(login);
}

acesso* criar_save(acesso *jogador, int *cont2, acesso novo)
{
    ler_login(&*cont2);
    FILE *login;

    login = fopen("login.txt","a");
    if(login == 0){
        printf("ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }

    jogador = (acesso*) realloc(jogador, (*cont2 + 1) * sizeof(acesso));
    if(jogador == 0){
        printf("ERRO.");
        exit(1);
    }

    novo.n = *cont2 + 1;
    jogador[*cont2] = novo;
    
    fprintf(login, "%d\n%s\n%s\n", jogador[*cont2].n, jogador[*cont2].nome, jogador[*cont2].senha);

    (*cont2)++;

    fclose(login);
    return jogador;
}

acesso* deletar_save(acesso *jogador, int *cont2, int *save)
{
    int num;
    char nome[10], senha[10];

    ler_login(&*cont2);
    FILE *login;

    jogador = (acesso*) realloc(jogador, (*cont2) * sizeof(acesso));

    if(*cont2 == 0){
        printf("nao existe nenhum save para deletar\n");
        getch();
        jogador = criar_login(jogador,&*cont2);
    }

    login = fopen("login.txt","r");
    for(int j = 0; j < *cont2; j++){
        fscanf(login, "%d\n%s\n%s\n", &num, nome, senha);
        printf("[ %d ] - %s\n\n", num, nome);
    }
    fclose(login);
    
    printf("deseja deletar qual save?\n");
    printf("save: ");
    scanf("%d", &*save);

    login = fopen("login.txt","r");
    for(int j = 0; j < *cont2; j++){
        fscanf(login, "%d\n%s\n%s\n", &jogador[j].n, jogador[j].nome, jogador[j].senha);
    }
    fclose(login);

    for(int i = 0; i < *cont2; i++){
        if(jogador[i].n == *save){

            jogador[*cont2 - 1].n = jogador[i].n;
            jogador[i] = jogador[*cont2 - 1];

            if(*cont2 - 1 == 0){
                jogador = (acesso*) realloc(jogador, 1 * sizeof(acesso));
            } else {
                jogador = (acesso*) realloc(jogador, (*cont2 - 1) * sizeof(acesso));
                if(jogador == 0){
                    printf("ERRO");
                    exit(1);
                }
            }

            (*cont2)--;

            login = fopen("login.txt","w");
            for(int j = 0; j < *cont2; j++){
                fprintf(login, "%d\n%s\n%s\n", jogador[j].n, jogador[j].nome, jogador[j].senha);
            }
            fclose(login);
            break;
        }
    }

    return jogador;
}

acesso* criar_login(acesso *jogador, int *cont2)
{
    FILE *login;
    char acao, nome[10], senha[10];
    (void) acao;
    int save;

    while(acao != 's'){
        clear;

        ler_login(&*cont2);

        login = fopen("login.txt","r");

        printf("se deseja criar um save, aperte [c]. \n");
        printf("se deseja deletar um save, aperte [d]. \n");
        printf("se deseja voltar para o menu, aperte [s]. \n");
        printf("\n");
        while((fscanf(login, "%d\n%s\n%s\n", &save, nome, senha)) == 3){
            printf("[ %d ] - %s\n\n", save, nome);
        }
        printf("selecione: ");
        acao = getch();

        fclose(login);

        clear;

        if(acao == 'c'){
            acesso novo = jogador_novo();
            jogador = criar_save(jogador, &*cont2, novo);
        } else if(acao == 'd'){
            jogador = deletar_save(jogador, &*cont2, &save);
        } else {
            continue;
        }
    }

    return jogador;
}

void fazer_login(int *confirmador, int *cont2, char nome_jogador[])
{
    clear;

    int save, numero;
    char usuario_senha[10], nome[10], senha[10];

    ler_login(&*cont2);

    FILE *login;
    login = fopen("login.txt","r");

    if(*cont2 == 0){
        printf("nao existe nenhum save salvo.\n");
        getch();
        return;
    }

    printf("escolha o save para entrar.\n");
    printf("\n");
    while((fscanf(login, "%d\n%s\n%s\n", &save, nome, senha)) == 3){
        printf("[ %d ] - %s\n\n", save, nome);
    }
    printf("selecione: ");
    scanf("%d", &numero);
    printf("\n\n");

    fclose(login);

    printf("Digite sua senha: ");
    scanf("%s", usuario_senha);
    clear;

    login = fopen("login.txt","r");
    while((fscanf(login, "%d\n%s\n%s\n", &save, nome, senha)) == 3){
        if(numero == save){
            if(strcmp(usuario_senha,senha) == 0){
                *confirmador = 1;
                strcpy(nome_jogador,nome);
                break;
            } else {
                *confirmador = 2;
            } 
        }
    }

    fclose(login);
    clear;
}