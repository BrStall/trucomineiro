#include <iostream>
#include <time.h> /// time
#include <stdlib.h> /// srand
#include <unistd.h> /// usleep
#include <locale.h> /// definição de configuração local (para usar nos caracteres especiais)
using namespace std;

                                    /*************************************/
                                    /*************************************/
                                    /*** TRUCO BY STALL E BRUNO DANIEL ***/
                                    /*************************************/
                                    /*************************************/

void Menu()
{
    setlocale(LC_ALL, "");
    int opcao;
    char pronto;
    cout << "Olá! Seja bem vindo ao remake de um TRUCO. \n Feito por: BRUNA STALL E BRUNO DANIEL." << endl;
    cout << "Comece escolhendo uma opção: " << endl;
    cout << "\n\n 1 - Iniciar \n 2 - Ajuda \n 3 - Tabela de valores (cartas) \n 4 - Sair\n\n";
    cin >> opcao;
    switch(opcao)
    {
    case 1:
        break;
    case 2:
        cout << "\n\nCada jogador recebe três cartas. O primeiro jogador escolhe uma carta para ser jogada. Seu oponente ";
        cout << "escolhe uma carta para jogar (não necessariamente para ganhar a rodada). O vencedor da rodada joga uma ";
        cout << "nova carta, iniciando uma nova rodada. A partida é vencida por quem ganhar duas rodadas. Em caso de empate, ";
        cout << "a vitória da partida é do jogador que venceu a primeira rodada. Cada partida vencida conta três pontos ao ";
        cout << "jogador vencedor. O jogo termina quando um dos jogadores atinge 15 pontos.\n";
        cout << "\nPronto para jogar? (s/n) ";
        cin >> pronto;
        if (pronto == 's')
        {
            break;
        }
        else system("cls");
        Menu();
        break;
    case 3:
        cout << "\nNaipes: \n1 = Paus \n2 = Copas \n3 = Espadas \n4 = Ouros\n";
        cout << "\nCartas: \n8 = Valete \n9 = Dama \n10 = Rei\n";
        cout << "\nPronto para jogar? (s/n) ";
        cin >> pronto;
        if (pronto == 's')
        {
            break;
        }
        else system("cls");
        Menu();
        break;
    }
}

int verificaValor(int valor)
{
    while (valor == 0)
    {
        valor = rand()%4;
    }
    return valor;
}

int main()
{
    system("color 03f");
    Menu();
    usleep(500000);
    system("cls");

    int cartasJum[3], cartasPc[3], naipeJum[3], naipePc[3], valorX, j = 1, opcao, cartaJogada;
    int naipePcJogado, cartaPcJogada, naipeJogado, cartaViradaValor;
    string naipe[5], aux, aux2; /** aux é pra usar no switch **/
    float valoresCartas[10] = {3, 2, 1, 10, 9, 8, 7, 6, 5, 4};
    float valoresNaipes[4] = {0, 1, 2, 3};

    srand (time(NULL));
    for (int i = 0; i < 3; i++) /** Sorteando as cartas para o jogador **/
    {
        valorX = rand()%10+1;
        cartasJum[i] = valorX;
    }


    for (int i = 0; i < 3; i++) /** Sorteando as cartas para o computador **/
    {
        valorX = rand()%10+1;
        cartasPc[i] = valorX;
    }

    for (int i = 0; i < 3; i++) /** Sorteando o naipe das cartas do jogador **/
    {
        valorX = rand()%4;
        naipeJum[i] = valorX;

        switch(naipeJum[i])
        {
        case 0:
            naipe[i] = "paus";
            break;
        case 1:
            naipe[i] = "copas";
            break;
        case 2:
            naipe[i] = "espadas";
            break;
        case 3:
            naipe[i] = "ouros";
            break;
        }
    }

    cartaViradaValor = rand()%4;
    if (cartaViradaValor == 0)
    {
        verificaValor(cartaViradaValor);
    }

    cout << "\nCarta virada: " << cartaViradaValor << " de " << aux2;
    cout << "\nSuas cartas são: " << endl;
    for (int i = 0; i < 3; i++) /** Mostrando as cartas **/
    {
        cout << "\n" << j << " - " <<  cartasJum[i] << " de " << naipe[i];
        j+=1;
    }

    cout << "\n\nInforme qual das 3 cartas você quer jogar: ";
    cin >> opcao;

    cout << "\nVez do PC jogar...";
    usleep(900000);

    cartaPcJogada = rand()%10;
    if (cartaPcJogada == 0)
    {
        verificaValor(cartaPcJogada);
    }
    naipePcJogado = rand()%4;
    switch(naipePcJogado)
        {
        case 0:
            aux = "paus";
            break;
        case 1:
            aux = "copas";
            break;
        case 2:
            aux = "espadas";
            break;
        case 3:
            aux = "ouros";
            break;
        }

    cout << "\nPC jogou " << cartaPcJogada << " de " << aux;
}
