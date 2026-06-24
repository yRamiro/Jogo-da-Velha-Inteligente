#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#include<windows.h> 

char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
int i, j, dificuldade, vitoria = 0;


void imprimir_tabuleiro(); 
void jogada_user();
void jogada_computador(); 
void condicao_de_vitoria();

int main() { 
    int escolha, i, j;
    char tabuleiro[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int lance = 1; 

printf("--Bem-vindo ao Jogo da Velha!-- \n"); 
    do {
    printf("Selecione sua opcao: \n1 - Jogar\n2 - Como jogar?\n3 - Sair\n");
    scanf("%d", &escolha); 
    while (escolha > 3 || escolha < 0) {
        printf("Por favor escolha uma opcao valida! \n"); 
        printf("Selecione sua opcao: \n1 - Jogar\n2 - Como jogar?\n3 - Sair\n");
        scanf("%d", &escolha); 
    }
        switch(escolha) {
        case 1: 
            printf("Escolha a dificuldade do computador:\n1 - Facil\n2 - Medio\n3 - Dificil\n");
            scanf("%d", &dificuldade);
            system("cls");
            imprimir_tabuleiro();
            for (lance = 1; lance <= 10;) { 
            printf("Sua vez... \n"); 
            jogada_user(); 
            lance++;
            if (lance > 5) {
                condicao_de_vitoria(); 
                if (vitoria == 1)
            break;
            }   
            printf("\n");
         if (lance >= 9) 
            break;
            imprimir_tabuleiro(); 
            printf("Vez do computador... \n"); 
            Sleep(2000);
            jogada_computador(); 
            imprimir_tabuleiro();
            if (lance > 5) {
                condicao_de_vitoria(); }
            lance++;
                if (vitoria == 1) 
                break;
        }
    
        if (vitoria == 1) { 
        system("cls");
        imprimir_tabuleiro();
        if (lance % 2 == 0) 
        printf("Fim de jogo, o usuario venceu! \n"); 
        if (lance % 2 != 0)
        printf("Fim de jogo, o computador venceu! \n");
        }
    
    if (lance >= 9 && vitoria == 0) {
        system("cls");
        imprimir_tabuleiro();
        printf("Deu velha! \n"); }  
    return 0;
    break; 

case 2:
printf("O objetivo do jogo consiste em formar uma \"linha\" com apenas um carectere (X ou O), seja essa linha diagonal, horizontal ou vertical! \n");
printf("As casas sao numeradas de 1 a 9, quando for a sua vez, basta digitar em qual casa deseja jogar. \n");
for (i = 0; i < 3; i++) { 
    for ( j = 0; j < 3; j++) {
        if (j != 2) 
        printf(" %d |", tabuleiro[i][j]);
        else 
        printf(" %d ", tabuleiro[i][j]); 
    }
    printf("\n");
    if (i <2) { 
        printf("-----------"); 
    }
    printf("\n");
} 
Sleep(3000);
for (i = 3; i >= 1; i--) {
    printf("Voltando ao menu em %d... \n", i);
    Sleep(1000);
}
printf("\n");    
break;
} 
} while (escolha != 3); 
if (escolha == 3)
printf("Ate mais! \n"); 
return 0;
}     

void imprimir_tabuleiro() { 
 for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
           if (j != 2)
            printf(" %c |", tabuleiro[i][j]);
           else 
            printf(" %c ", tabuleiro[i][j]);
           }
        printf("\n");
        if (i < 2) {
        printf("-----------");
        }
        printf("\n");
    }
}

void jogada_user() { 
    srand(time(NULL)); 
    int casa;
    do {
    printf("Em qual casa deseja jogar? ");
    scanf("%d", &casa);
    i = (casa - 1) / 3; 
    j = (casa - 1) % 3;
    } while (tabuleiro[i][j] != ' ');
    tabuleiro[i][j] = 'X';  
} 


void jogada_computador() { 
    srand(time(NULL)); 
    int casa, jogou = 0; 
     
    if (dificuldade == 1) { // dificuldade facil (joga aleatoriamente)
        srand(time(NULL)); 
    int casa; 
    do {
    casa = rand() % 9 + 1;
    i = (casa - 1) / 3; 
    j = (casa - 1) % 3;
    } while (tabuleiro[i][j] != ' '); 
    tabuleiro[i][j] = 'O';
    }

    if (dificuldade == 2) { // dificuldade media (se tiver a oportunidade, irá ganhar o jogo)
    // LINHA 1
    if (tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[0][2] == 'O' && tabuleiro[0][1] == ' ') { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    } 
    if (tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1; 
    }
    // LINHA 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[1][0] == ' ') { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1; 
    }
     if (tabuleiro[1][0] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == ' ') { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
    // LINHA 3 
    if (tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[2][1] == ' ') { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // COLUNA 1 
    if (tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[1][0] == ' ') { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
    // COLUNA 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[0][1] == ' ') { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == ' ') { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
    // COLUNA 3 
     if (tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[1][2] == ' ') { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 1 
     if (tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
    if (jogou != 1) {
     do {
    casa = rand() % 9 + 1;
    i = (casa - 1) / 3; 
    j = (casa - 1) % 3;
    } while (tabuleiro[i][j] != ' '); 
    tabuleiro[i][j] = 'O';
    }
    }
    
    if (dificuldade == 3) { // dificuldade dificl (atrapalha o usuario e ganha o jogo)
    // LINHA 1
    jogou = 0;
    if (tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[0][2] == 'O' && tabuleiro[0][1] == ' ') { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    } 
    if (tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1; 
    }
    // LINHA 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[1][0] == ' ') { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1; 
    }
     if (tabuleiro[1][0] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == ' ') { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
    // LINHA 3 
    if (tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[2][1] == ' ') { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // COLUNA 1 
    if (tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[1][0] == ' ') { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
    // COLUNA 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[0][1] == ' ') { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == ' ') { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
    // COLUNA 3 
     if (tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[1][2] == ' ') { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 1 
     if (tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[0][0] == ' ') { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[2][2] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == ' ') { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 2 
    if (tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][2] == ' ') { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[1][1] == ' ') { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == ' ') { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
        if (tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' && tabuleiro[0][0] == ' ' && jogou != 1) { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[0][2] == 'X' && tabuleiro[0][1] == ' ' && jogou != 1) { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    } 
    if (tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == ' ' && jogou != 1) { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1; 
    }
    // LINHA 2 
    if (tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[1][0] == ' ' && jogou != 1) { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1; 
    }
     if (tabuleiro[1][0] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[1][1] == ' ' && jogou != 1) { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == ' ' && jogou != 1) { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
    // LINHA 3 
    if (tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[2][0] == ' ' && jogou != 1) { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[2][1] == ' ' && jogou != 1) { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == ' ' && jogou != 1) { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // COLUNA 1 
    if (tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[0][0] == ' ' && jogou != 1) { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[1][0] == ' ' && jogou != 1) { 
        tabuleiro[1][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == ' ' && jogou != 1) { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
    // COLUNA 2 
    if (tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[0][1] == ' ' && jogou != 1) { 
        tabuleiro[0][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[1][1] == ' ' && jogou != 1) { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == ' ' && jogou != 1) { 
        tabuleiro[2][1] = 'O'; 
        jogou = 1;
    }
    // COLUNA 3 
     if (tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[0][2] == ' ' && jogou != 1) { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[1][2] == ' ' && jogou != 1) { 
        tabuleiro[1][2] = 'O'; 
        jogou = 1;
    }
     if (tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == ' ' && jogou != 1) { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 1 
     if (tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[0][0] == ' ' && jogou != 1) { 
        tabuleiro[0][0] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[2][2] == 'X' && tabuleiro[1][1] == ' ' && jogou != 1) { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == ' ' && jogou != 1) { 
        tabuleiro[2][2] = 'O'; 
        jogou = 1;
    }
    // DIAGONAL 2 
    if (tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[0][2] == ' ' && jogou != 1) { 
        tabuleiro[0][2] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[1][1] == ' ' && jogou != 1) { 
        tabuleiro[1][1] = 'O'; 
        jogou = 1;
    }
    if (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == ' ' && jogou != 1) { 
        tabuleiro[2][0] = 'O'; 
        jogou = 1;
    }
    if (jogou != 1) {
     do {
    casa = rand() % 9 + 1;
    i = (casa - 1) / 3; 
    j = (casa - 1) % 3;
    } while (tabuleiro[i][j] != ' '); 
    tabuleiro[i][j] = 'O';
    }
    }
}

void condicao_de_vitoria() { 
    if (tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][1] == tabuleiro[0][2] && tabuleiro[0][0] != ' ') { 
        vitoria = 1; }
    if (tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[1][2] && tabuleiro[1][0] != ' ') {
        vitoria = 1;}
    if (tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][1] == tabuleiro[2][2] && tabuleiro[2][0] != ' ') {
        vitoria = 1; }
    if (tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[1][0] == tabuleiro[2][0] && tabuleiro[0][0] != ' ') {
        vitoria = 1; }
    if (tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][1] && tabuleiro[0][1] != ' ') {
        vitoria = 1; }
    if (tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[1][2] == tabuleiro[2][2] && tabuleiro[0][2] != ' ') {
        vitoria = 1; }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        vitoria = 1; }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        vitoria = 1; }
}