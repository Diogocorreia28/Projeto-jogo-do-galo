#ifndef FUNCOES_H
#define FUNCOES_H
#include <string>
#pragma once

using namespace std;

class Funcoes{
 
protected:
    //das funções
    int dificuldade;
    int opcao;
    int x;
    int opçao_dificuldade;
    int colocar_canto;
    

     



public:
    //usadas no main
    int opçaomenu_jogo,i_jogo=0,dificuldade_main;
    int coluna_main,linha_main;
    int j_main,r_main=1;
    string confirmar_main;
    char x_main=' ',y=' ',z=' ',w=' ',s=' ',d=' ',a=' ',b=' ',c=' ';
    char matriz_de_jogo[3][3] = {{x_main,y,z},
                                 {a,b,c},
                                 {w,d,s}
    };

    int contador_nivel4=0;

         string linha;
    const int Maxjogos=10;
    int numeroJogos=0;
    string resultado_main;

    struct Jogo {
    string resultado;
     
    }jogo[10];


     
    char matriz_de_jogo_sec[9][3][3] ;
    
    int i_matriz=0;

   
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
    
    void colocar_valor2(char matriz_de_jogo[3][3],int linha,int coluna);

    int  verificafimdojogo2(char matriz_de_jogo[3][3]);

    void jogadorVSjogador();

    void jogada_nivel4(char matriz_de_jogo[3][3],int &linha,int &coluna,int &contador_nivel4);

    void executavel_nivel4();

    int menuDificuldadesPC();

    void computadorVScomputador();

    void jogadaComputador2(char matriz_de_jogo[3][3],int &linha,int &coluna);

    int  verificafimdojogo_computador2(char matriz_de_jogo[3][3]);

    int  verificafimdojogo_computador1(char matriz_de_jogo[3][3]);

    void colocar_valor_computador1(char matriz_de_jogo[3][3],int linha,int coluna);

    void colocar_valor_computador2(char matriz_de_jogo[3][3],int linha,int coluna);

    void computador2_jogada_nivel2(char matriz_de_jogo[3][3],int &linha,int &coluna);

    void computador2_jogada_nivel3(char matriz_de_jogo[3][3],int &linha,int &coluna);

    void computador2_jogada_nivel4(char matriz_de_jogo[3][3],int &linha,int &coluna);
    

    //matrizes direita

    void matriz_de_jogo1(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo2(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo3(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo4(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo5(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo6(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo7(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo8(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void matriz_de_jogo9(char matriz_de_jogo[3][3],char matriz_de_jogo_sec[9][3][3]);

    void imprimeMatrizes(char matriz_de_jogo_sec[9][3][3],int &i,char matriz_de_jogo[3][3]);



};

class top10   : public Funcoes{
   
    public:

        //top 10
    void salvarJogos(const Jogo jogos[], int numeroJogos);

    void carregarJogos(Jogo jogos[], int& numeroJogos);

    void registrarJogo(Jogo jogos[], int& numeroJogos, const string &resultado);

    void mostrarTop10(const Jogo jogos[], int numeroJogos);
};


#endif
