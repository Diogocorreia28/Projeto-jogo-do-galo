/*Pontos a melhorar: classes com ficheiros implementar, o top 10 e fazer aquilo guardar,strings*/



#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
#include "Funcoes.cpp"
#include"Funcoes.h"


using namespace std;


int main(){
    int opçaomenu,i=0,dificuldade;
    int coluna,linha;
    int j,r=1;
    string confirmar;
    string resultado;
    char x=' ',y=' ',z=' ',w=' ',s=' ',d=' ',a=' ',b=' ',c=' ';
    char matriz_de_jogo[3][3] = {{x,y,z},
                                 {a,b,c},
                                 {w,d,s}
    };

   //Falar com professor pois não consigo passar do .h para aqui

    
    string linha_top10;
    const int Maxjogos=10;
    int numeroJogos=0;
    struct Jogo {
    string resultado;
     
}jogo[Maxjogos];

    Funcoes funcoes;
    


    srand((unsigned int)time(NULL)); //plantar a semente 

    cout << "Bem vindo ao jogo do galo " << endl;
    
   
do{
    opçaomenu = funcoes.menu();
        if(opçaomenu == 1) {
            j=1;
            if(j==1 || j==3 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(matriz_de_jogo,i=0);
            
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            funcoes.numero_jogada(r);

            funcoes.printmatriz(matriz_de_jogo,i);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(r);
            funcoes.jogada_computador(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(matriz_de_jogo,linha,coluna);
                        
                       funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            funcoes.printmatriz(matriz_de_jogo,i);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
            }
           

            if(n!=9){
            funcoes.numero_jogada(r);
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

            

            if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
            resultado="Empate";
            funcoes.registrarJogo(jogos,numeroJogos,resultado);
            }
            }
            }
            }
             i=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             r=1;
             funcoes.tirar_valores(matriz_de_jogo);

        }
         //fim do jogo com eu primeiro

        if(opçaomenu == 2){                 /*escolhe contra quem joga*/

        // Tem de haver uma função para escolher quem joga
        // a função vai dar a informação por referencia de quem joga
        funcoes.quem_joga_primeiro(j);

        if(j==1 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(matriz_de_jogo,i=0);
            
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            funcoes.numero_jogada(r);

            funcoes.printmatriz(matriz_de_jogo,i);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(r);
            funcoes.jogada_computador(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(matriz_de_jogo,linha,coluna);
                        
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            funcoes.printmatriz(matriz_de_jogo,i);

            if(funcoes.verificafimdojogo_computador(matriz_de_jogo) == 9){ 
                n=9;
            }
            
              //Função trocar jogador;

           

            if(n != 9){
            funcoes.numero_jogada(r);
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

           if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
              if(n==3){
            cout << "Resultado: Empate" << endl;
            }
            }
            }
             i=0;
             r=1;
            funcoes.tirar_valores(matriz_de_jogo);

        }
         //fim do jogo com eu primeiro

        if(j == 2){
                funcoes.numero_jogada(r);

                funcoes.jogada_computador(matriz_de_jogo,linha,coluna);

                funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

                funcoes.printmatriz(matriz_de_jogo,i=1); 

                cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n\n";
            
                i=1;

            for(int n=0;n<4;n++){  

            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.numero_jogada(r);    

            funcoes.printmatriz(matriz_de_jogo,i);

            if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
            if(n==4){
            cout << "Resultado: Empate" << endl;
            }
             
            
              //trocar jogador
            if(n != 9){
            funcoes.numero_jogada(r);

            funcoes.jogada_computador(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(matriz_de_jogo,linha,coluna);
                        
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

            if(funcoes.verificafimdojogo_computador(matriz_de_jogo)==9){
                
                n=9;

            }

            if(n==3){
            cout << "Resultado: Empate" << endl;
            }
            
           }
         
           }
              
        }

        i=0;
        r=1;
        funcoes.tirar_valores(matriz_de_jogo);

        }

        if(opçaomenu == 3){         /*escolher a dificuldade*/
        //menu_dificuldades(); 

       dificuldade = funcoes.menu_dificuldades();

            switch(dificuldade){

                    case(1):    //começar o jogo em fácil

                         cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(matriz_de_jogo,i=0);
            
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            funcoes.numero_jogada(r);

            funcoes.printmatriz(matriz_de_jogo,i);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(r);
            funcoes.jogada_computador(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(matriz_de_jogo,linha,coluna);
                        
                       funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            funcoes.printmatriz(matriz_de_jogo,i);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
            }
           

            if(n!=9){
            funcoes.numero_jogada(r);
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

            

            if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
            
             if(n==4){
            cout << "Resultado: Empate" << endl;
            }
            }
            }
            
             i=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             r=1;
             funcoes.tirar_valores(matriz_de_jogo);

            break;




                    case(2):    // usa o greedy
                    
                    cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(matriz_de_jogo,i=0);
            
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            funcoes.numero_jogada(r);

            funcoes.printmatriz(matriz_de_jogo,i);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(r);
            funcoes.jogada_nivel2(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_nivel2(matriz_de_jogo,linha,coluna);
                        
                       funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            funcoes.printmatriz(matriz_de_jogo,i);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
            }
           

            if(n!=9){
            funcoes.numero_jogada(r);
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

            

            if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
            }
            }
            }
            
             i=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             r=1;
             funcoes.tirar_valores(matriz_de_jogo);

            break;




                    case(3):    //o computador tenta ganhar ou empatar

            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(matriz_de_jogo,i=0);
            
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            funcoes.numero_jogada(r);

            funcoes.printmatriz(matriz_de_jogo,i);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(r);
            funcoes.jogada_nivel3(matriz_de_jogo,linha,coluna);

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_nivel3(matriz_de_jogo,linha,coluna);
                        
                       funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            funcoes.printmatriz(matriz_de_jogo,i);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
            }
           

            if(n!=9){
            funcoes.numero_jogada(r);
            funcoes.obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(coluna,linha);
                        funcoes.verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            funcoes.colocar_valor(matriz_de_jogo,linha,coluna);
           
            funcoes.printmatriz(matriz_de_jogo,i);

            

            if(funcoes.verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
            }
            }
            }
            
             i=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             r=1;
             funcoes.tirar_valores(matriz_de_jogo);

            break;





            
            }//fecha o switch
        }//fecha opção 3;

         if(opçaomenu == 4){   
                    /*fecha jogo*/
                    //perguntar como resolver o facto dele estar sempre a pedir duas
        cout << "Tem a certeza que quer sair?\n";
       
        int tentativas = 0;
        do {
            if (tentativas > 0) {
                cout << "Por favor, digite 'sim' para sair ou 'nao' para continuar: ";
            }
            while (getchar() != '\n'); // para limpar o buffer
            getline(cin, confirmar);
            tentativas++;
        } while (confirmar != "sim" && confirmar != "nao");

        if(confirmar == "sim"){
            cout << "A sair...";
         
            exit(0);
        }
    
    

}
}while(opçaomenu >= 1 && opçaomenu <=4);
 }

 /* Medidas novas a implementar:
    -O computador jogar contra si mesmo com dificuldades diferentes
    -Nivel avançado,nunca perdende, empata ou ganha(tentar jogar no meio caso não seja possível jogar nas pontas)
    -Implementação de dois jogadores humanos
    -continuação top 10
    -Tabuleiro a ser desenhado à direita (talvez por ficheiros ou manipolação colocando a função)




    Atualizações:
    -Na escolha de quem quer jogar primeiro colocar as dificuldades "ou qual o jogador/agente nos níveis 5 e 6"---
    -
    */
