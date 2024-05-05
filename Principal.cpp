/*Pontos a melhorar: classes com ficheiros implementar, o top 10 e fazer aquilo guardar,strings*/



#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
#include "Funcoes.cpp" //uso, pois erro de linkagem entre ficheiros
#include"Funcoes.h"

using namespace std;

int main(){
   

   //Falar com professor pois não consigo passar do .h para aqui

    Funcoes funcoes;
    top10 top_10;
 

    srand((unsigned int)time(NULL)); //plantar a semente 

    cout << "Bem vindo ao jogo do galo " << endl;
    

    //para carregar os valores
    top_10.carregarJogos(funcoes.jogo,funcoes.numeroJogos);
   
do{
    funcoes.opçaomenu_jogo = funcoes.menu();
        if(funcoes.opçaomenu_jogo == 1) {
            funcoes.j_main=1;
            if(funcoes.j_main==1 || funcoes.j_main==3 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0);
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            
            
            funcoes.i_jogo=1;

           funcoes.imprimeMatrizes(funcoes.matriz_de_jogo_sec,funcoes.i_matriz,funcoes.matriz_de_jogo);

            for(int n=0;n<4;n++){
            
            
            funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                       funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            funcoes.imprimeMatrizes(funcoes.matriz_de_jogo_sec,funcoes.i_matriz,funcoes.matriz_de_jogo);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
               
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
           

            if(n!=9){
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
         
           funcoes.imprimeMatrizes(funcoes.matriz_de_jogo_sec,funcoes.i_matriz,funcoes.matriz_de_jogo);

            

            if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 

                n=9;
                      
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
            
               
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            }
            }
            }
            funcoes. i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             funcoes.r_main=1;
             funcoes.tirar_valores(funcoes.matriz_de_jogo);

        }
         //fim do jogo com eu primeiro

        if(funcoes.opçaomenu_jogo == 2){         /*escolhe contra quem joga*/

        // Tem de haver uma função para escolher quem joga
        // a função vai dar a informação por referencia de quem joga
        funcoes.quem_joga_primeiro(funcoes.j_main);

        if(funcoes.j_main==1 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0);
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            
            
            funcoes.i_jogo=1;

            funcoes.numero_jogada(funcoes.r_main);

            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo) == 9){ 
                    
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
                n=9;
            }
            
              //Função trocar jogador;

           

            if(n != 9){
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

           if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 

                n=9;
                    
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
              if(n==3){
            cout << "Resultado: Empate" << endl;
                      
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            }
            }
             funcoes.i_jogo=0;
             funcoes.r_main=1;
            funcoes.tirar_valores(funcoes.matriz_de_jogo);

        }
         //fim do jogo com eu primeiro

        if(funcoes.j_main == 2){
                funcoes.numero_jogada(funcoes.r_main);

                funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

                funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

                funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=1); 

                cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n\n";
            
                funcoes.i_jogo=1;

            for(int n=0;n<4;n++){  

            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.numero_jogada(funcoes.r_main);    

            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 
                n=9;
                      
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            if(n==4){
            cout << "Resultado: Empate" << endl;
                     
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
             
            
              //trocar jogador
            if(n != 9){
            funcoes.numero_jogada(funcoes.r_main);

            funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo)==9){
                
                n=9;
                       
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);

            }

            if(n==3){
            cout << "Resultado: Empate" << endl;
                    
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            
           }
         
           }
              
        }

       funcoes.i_jogo=0;
        funcoes.r_main=1;
        funcoes.tirar_valores(funcoes.matriz_de_jogo);

        }

        if(funcoes.opçaomenu_jogo == 3){         /*Modo de funcionamento*/
        //menu_dificuldades(); 

       funcoes.dificuldade_main = funcoes.menu_dificuldades();

            switch(funcoes.dificuldade_main){

                    case(1):    //começar o jogo em fácil

                         cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0);
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            
            
            funcoes.i_jogo=1;

            funcoes.numero_jogada(funcoes.r_main);

            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                       funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
           

            if(n!=9){
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            

            if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 
                n=9;
                          
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            
             if(n==4){
            cout << "Resultado: Empate" << endl;
                  
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);

            }
            }
            }
            
             funcoes.i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             funcoes.r_main=1;
             funcoes.tirar_valores(funcoes.matriz_de_jogo);

            break;




                    case(2):    // usa o greedy
                    
                    cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0);
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            
            
            funcoes.i_jogo=1;

            funcoes.numero_jogada(funcoes.r_main);

            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.jogada_nivel2(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main );

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_nivel2(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                       funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
                          
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
           

            if(n!=9){
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            

            if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 
                n=9;
                       
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;

                   
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);

            }
            }
            }
            
             funcoes.i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             funcoes.r_main=1;
             funcoes.tirar_valores(funcoes.matriz_de_jogo);

            break;




                    case(3):    //o computador tenta ganhar ou empatar

            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0);
            
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

        funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            
            
            funcoes.i_jogo=1;

            funcoes.numero_jogada(funcoes.r_main);

            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            for(int n=0;n<4;n++){
            
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.jogada_nivel3(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){  //verificar a linha do computador
                        
                        funcoes.jogada_nivel3(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
                        
                       funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor_computador(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);

            
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            
            
              //Função trocar jogador;
            if(funcoes.verificafimdojogo_computador(funcoes.matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
                          
            funcoes.resultado_main="Derrota";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
           

            if(n!=9){
            funcoes.numero_jogada(funcoes.r_main);
            funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main); // Aqui chama a função para obter as coordenadas

            while(funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        funcoes.obtercoordenada(funcoes.coluna_main,funcoes.linha_main);
                        funcoes.verificarposicaoDisponivel(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
            }

            funcoes.colocar_valor(funcoes.matriz_de_jogo,funcoes.linha_main,funcoes.coluna_main);
           
            funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo);

            

            if(funcoes.verificafimdojogo(funcoes.matriz_de_jogo) == 9){ 
                n=9;
          
            funcoes.resultado_main="Vitoria";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
        
            funcoes.resultado_main="Empate";
            top_10.registrarJogo(funcoes.jogo,funcoes.numeroJogos,funcoes.resultado_main);
            top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);
            }
            }
            }
            
             funcoes.i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             funcoes.r_main=1;
             funcoes.tirar_valores(funcoes.matriz_de_jogo);

            break;



            case(4):        //modo avançado
            funcoes.executavel_nivel4();

            break;


            case(5):        //jogador contra jogador

            funcoes.jogadorVSjogador();

            break;

            case(6):       //PC vs PC

            funcoes.computadorVScomputador();



            break;
            
            }//fecha o switch
        }//fecha opção 3;

        if(funcoes.opçaomenu_jogo == 4){           //Mostra top-10
       

                top_10.mostrarTop10(funcoes.jogo,funcoes.numeroJogos);

        }

         if(funcoes.opçaomenu_jogo == 5){   
                    /*fecha jogo*/
                    //perguntar como resolver o facto dele estar sempre a pedir duas
        cout << "Tem a certeza que quer sair?\n";
       
        int tentativas = 0;
        do {
            if (tentativas > 0) {
                cout << "Por favor, digite 'sim' para sair ou 'nao' para continuar: ";
            }
            while (getchar() != '\n'); // para limpar o buffer
            getline(cin, funcoes.confirmar_main);
            tentativas++;
        } while (funcoes.confirmar_main != "sim" && funcoes.confirmar_main != "nao");

        if(funcoes.confirmar_main == "sim"){
            cout << "A sair...";
         
            exit(0);
        }
    
    

}
}while(funcoes.opçaomenu_jogo >= 1 && funcoes.opçaomenu_jogo <=5);
 }



 /* Medidas novas a implementar:
    -O computador jogar contra si mesmo com dificuldades diferentes(d/j)(feito)
    -Nivel avançado,nunca perdende, empata ou ganha(tentar jogar no meio caso não seja possível jogar nas pontas)(feito)
    -Implementação de dois jogadores humanos(feito)
    -continuação top 10(feito)
    -Tabuleiro a ser desenhado à direita (talvez por ficheiros ou manipolação colocando a função)
     criar 10 variaveis para ele ir armazenando as matrizes e depois is mostrando(d/j)




    Atualizações:
    -Na escolha de quem quer jogar primeiro colocar as dificuldades "ou qual o jogador/agente nos níveis 5 e 6"---
    -
    */
