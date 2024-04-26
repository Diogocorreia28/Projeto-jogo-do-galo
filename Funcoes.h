#ifndef FUNCOES_H
#define FUNCOES_H

#pragma once

class Funcoes{


public:

 int dificuldade;
    int opcao;
    int x;

    Funcoes();
    ~Funcoes();

    int menu_dificuldades();

    int menu();

    int verificafimdojogo(char matriz_de_jogo[3][3]);

    int verificafimdojogo_computador(char matriz_de_jogo[3][3]);

    void jogada_computador(char matriz_de_jogo[3][3],int &linha,int &coluna);

    void colocar_valor(char matriz_de_jogo[3][3],int linha,int coluna);

    void colocar_valor_computador(char matriz_de_jogo[3][3],int linha,int coluna);

    void printmatriz(char matriz_de_jogo[3][3],int i);

    bool verificarposicaoDisponivel(char matriz_de_jogo[3][3],int l, int c);

    void obtercoordenada(int &c,int &l);

    void quem_joga_primeiro(int &p);

    void numero_jogada(int &n);

    void tirar_valores(char matriz_de_jogo[3][3]);

    void jogada_nivel2(char matriz_de_jogo[3][3],int &linha,int &coluna);

    void jogada_nivel3(char matriz_de_jogo[3][3],int &linha,int &coluna);
};

#endif