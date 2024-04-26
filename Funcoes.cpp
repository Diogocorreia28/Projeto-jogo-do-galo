#include "Funcoes.h"
#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
using namespace std;

Funcoes::Funcoes()
{

}

Funcoes::~Funcoes()
{

}

int Funcoes::menu_dificuldades(){
    cout << "Escolha a sua dificuldade\n\n" << endl;
    cout << "1-elementar\n" << "2-básico\n" << "3-médio\n" << endl;
    cout << "Dificuldade-";
    cin >> dificuldade;

     int opçao_dificuldade;
    /*basicamente cada dificuldade*/
    switch(dificuldade){
                            case(1):        /*computador joga aleatoriamente perdendo maior parte das vezes*/
                                    opçao_dificuldade=1;
                                    
                            break;
                            case(2):        /*computador ganhar na jogada corrente usando a estratégia greddy */
                                    opçao_dificuldade=2;
                            break;
                            case(3):        /*o computador ganha na jogada corrente, não sendo possível faz empate*/
                                    opçao_dificuldade=3;
                            break;

    }
return opçao_dificuldade;


}

int Funcoes::menu(){
    cout << "\nPor favor escolha uma das várias opções;\n"<< endl;

do{
    cout << "1-Iniciar jogo\n" << "2-Escolher quem inicia primeiro o jogo\n" << "3-Modo de funcionamento\n" << "4-Sair\n" 
         << endl;

    cout << "Opção:";
    cin >> opcao;
}while(opcao<1 || opcao >4);
do{
    switch(opcao){

        case(1):        /* inicia o jogo,aleatorio quem joga primeiro,criar função iniciar jogo */

        return 1;
        break;
        
        case(2):        /*  escolher contra quem quer jogar ou player ou pc*/

        return 2;
        break;
        
        case(3):        /*  apagar o histórico de jogadas*/
        
        return 3;
        break;
        
        case(4):        /*  fechar jogo*/

        return 4;
        break;
        
 
    }
    }while(opcao>5 || opcao<0);
}

int Funcoes::verificafimdojogo(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Vitória" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Vitória" << endl;
            return 9;
        }
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Vitória" << endl;
        return 9;
    }

    
}

int Funcoes::verificafimdojogo_computador(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Derrota" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Derrota" << endl;
            return 9;
        }

        
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Derrota" << endl;
        return 9;
    }
}

void Funcoes::jogada_computador(char matriz_de_jogo[3][3],int &linha,int &coluna){

        linha = rand()%(2-0+1);
        coluna = rand()%(2-0+1); 
}

void Funcoes::colocar_valor(char matriz_de_jogo[3][3],int linha,int coluna){
   matriz_de_jogo[linha][coluna]='x';
}

void Funcoes::colocar_valor_computador(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='0';
                        
}

void Funcoes::printmatriz(char matriz_de_jogo[3][3],int i){
   
    if(i == 0){

    cout << setw(4) << "0"  << " |" << setw(2) << "1"  << " |"    << setw(2) << "2"  << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "0"     << "|"  << setw(2) << " " << " |"  << setw(2) <<  " "    << " |" << setw(2) << " "  << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "1"     << "|"  << setw(2) << " " << " |"  << setw(2) << " "   << " |" << setw(2) << " "   << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "2"     << "|"  << setw(2) << " " << " |"  << setw(2) <<   " "   << " |" << setw(2) <<  " "   << endl;
    
    }

    if(i != 0){
    cout << setw(4) << "0"  << " |"    << setw(2) << "1" << " |"    << setw(2) << "2"  << endl;
    cout << setw(2) << "-|" << setw(3) << "---"   << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "0"     << "|"  << setw(2) << matriz_de_jogo[0][0]      << " |"<< setw(2) <<  matriz_de_jogo[0][1]     << " |" << setw(2) << matriz_de_jogo[0][2]    << endl;
    cout << setw(2) << "-|" << setw(3) << "---"   << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "1"     << "|"  << setw(2) << matriz_de_jogo[1][0]       << " |"<< setw(2) << matriz_de_jogo[1][1]       << " |" << setw(2) << matriz_de_jogo[1][2]    << endl;
    cout << setw(2) << "-|" << setw(3) << "---"   << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "2"     << "|"  << setw(2) << matriz_de_jogo[2][0]       << " |"<< setw(2) <<   matriz_de_jogo[2][1]     << " |" << setw(2) <<  matriz_de_jogo[2][2]    << endl;
   

}
} 

bool Funcoes::verificarposicaoDisponivel(char matriz_de_jogo[3][3],int l, int c) {


    return ((c >= 0 && c <= 2 && l >= 0 && l <= 2 ) && matriz_de_jogo[l][c] != 'x' && matriz_de_jogo[l][c] != '0');
}

void Funcoes::obtercoordenada(int &c,int &l){
    
    do{
        cout << "Insira um numero para a linha" << endl;
        cin >> l;
        
    }while(l != 0 && l != 1 && l != 2);

     do{
        cout << "Insira um numero para a coluna" << endl;
        cin >> c;
        
    }while(c != 0 && c != 1 && c != 2);

}

void Funcoes::quem_joga_primeiro(int &p){
    
    cout << "\nQuem pretende que comece a jogar?" << endl;
    cout << "1-Eu ou 2-Computador ou 3-aleatório" << endl;
    do{
        cin >> p;
    }while(p<1 && p>3);

    if(p == 3){

        p = rand()%2;
    }

}

void Funcoes::numero_jogada(int &n){
        
        cout << "\nJogada:" << n << endl;
        n++;
}

void Funcoes::tirar_valores(char matriz_de_jogo[3][3]){
 //limpar linhas
    int c=0;
    for(c;c<3;c++){
        
        matriz_de_jogo[0][c] =' ';
        matriz_de_jogo[1][c] =' ';
        matriz_de_jogo[2][c] =' ';


    }
}

void Funcoes::jogada_nivel2(char matriz_de_jogo[3][3],int &linha,int &coluna){
    x=0;
    //para ele tentar ganhar
    for(int i = 0;i<3;i++){

        for(int k = 0;k<3;k++){
             if(matriz_de_jogo[0][k] == '0' && matriz_de_jogo[1][k] == '0' && matriz_de_jogo[2][k] == ' '){
               linha=2;
               coluna=k;
               x=1;
           

             }if(matriz_de_jogo[0][k] == '0' && matriz_de_jogo[2][k] == '0' && matriz_de_jogo[1][k] == ' '){
                linha=1;
                coluna=k;
                x=1;
            
             }if(matriz_de_jogo[1][k] == '0' && matriz_de_jogo[2][k] == '0' && matriz_de_jogo[0][k] == ' '){
                linha=0;
                coluna=k;
                x=1;
              
             }

             if(matriz_de_jogo[i][0] == '0' && matriz_de_jogo[i][1] == '0' && matriz_de_jogo[i][2] == ' '){
                linha=i;
                coluna=2;
                x=1;
            
             }if(matriz_de_jogo[i][0] == '0' && matriz_de_jogo[i][2] == '0' && matriz_de_jogo[i][1] == ' '){
                linha=i;
                coluna=1;
                x=1;
              
             }if(matriz_de_jogo[i][1] == '0' && matriz_de_jogo[i][2] == '0' && matriz_de_jogo[i][0] == ' '){
                linha=i;
                coluna=0;
                x=1;
               

             }if(matriz_de_jogo[0][0] == '0' && matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][2] == ' '){
                linha=2;
                coluna=2;
                x=1;
   

             }if(matriz_de_jogo[0][0] == '0' && matriz_de_jogo[2][2] == '0' && matriz_de_jogo[1][1] == ' '){
               
                linha=1;
                coluna=1;
                x=1;

             }if(matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][2] == '0' && matriz_de_jogo[0][0] == ' '){
                
                linha=0;
                coluna=0;
                x=1;

             }if(matriz_de_jogo[0][2] == '0' && matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][0] == ' '){
                linha=2;
                coluna=0;
                x=1;
   
             }if(matriz_de_jogo[0][2] == '0' && matriz_de_jogo[2][0] == '0' && matriz_de_jogo[1][1] == ' '){
                linha=1;
                coluna=1;
                x=1;
  
             }if(matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][0] == '0' && matriz_de_jogo[0][2] == ' '){
                linha=0;
                coluna=2;
                x=1;
             }
             //quando não se verifica ele tem de jogar random
             if(x == 0){
            linha = rand()%(2-0+1);
            coluna = rand()%(2-0+1); 
           }
        }
    }
} 

void Funcoes::jogada_nivel3(char matriz_de_jogo[3][3],int &linha,int &coluna){
   x=0;
    for(int i = 0;i<3;i++){
       
        for(int k = 0;k<3;k++){// Joga para ganhar
              if(matriz_de_jogo[0][k] == '0' && matriz_de_jogo[1][k] == '0' && matriz_de_jogo[2][k] == ' '){
               linha=2;
               coluna=k;
                x=2;
                

             }if(matriz_de_jogo[0][k] == '0' && matriz_de_jogo[2][k] == '0' && matriz_de_jogo[1][k] == ' '){
                linha=1;
                coluna=k;
                 x=2;
                
             }if(matriz_de_jogo[1][k] == '0' && matriz_de_jogo[2][k] == '0' && matriz_de_jogo[0][k] == ' '){
                linha=0;
                coluna=k;
                 x=2;
                
             }

             if(matriz_de_jogo[i][0] == '0' && matriz_de_jogo[i][1] == '0' && matriz_de_jogo[i][2] == ' '){
                linha=i;
                coluna=2;
                 x=2;
                
             }if(matriz_de_jogo[i][0] == '0' && matriz_de_jogo[i][2] == '0' && matriz_de_jogo[i][1] == ' '){
                linha=i;
                coluna=1;
                 x=2;
                
             }if(matriz_de_jogo[i][1] == '0' && matriz_de_jogo[i][2] == '0' && matriz_de_jogo[i][0] == ' '){
                linha=i;
                coluna=0;
                 x=2;
                

             }if(matriz_de_jogo[0][0] == '0' && matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][2] == ' '){
                linha=2;
                coluna=2;
                 x=2;
                

             }if(matriz_de_jogo[0][0] == '0' && matriz_de_jogo[2][2] == '0' && matriz_de_jogo[1][1] == ' '){
               
                linha=1;
                coluna=1;
                 x=2;
                
             }if(matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][2] == '0' && matriz_de_jogo[0][0] == ' '){
                
                linha=0;
                coluna=0;
                 x=2;
                
             }if(matriz_de_jogo[0][2] == '0' && matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][0] == ' '){
                linha=2;
                coluna=0;
                 x=2;
                
             }if(matriz_de_jogo[0][2] == '0' && matriz_de_jogo[2][0] == '0' && matriz_de_jogo[1][1] == ' '){
                linha=1;
                coluna=1;
                 x=2;
                
             }if(matriz_de_jogo[1][1] == '0' && matriz_de_jogo[2][0] == '0' && matriz_de_jogo[0][2] == ' '){
                linha=0;
                coluna=2;
                 x=2;
                
             }
        }
        if(x==2){
                return;
        }
for(int i = 0;i<3;i++){
       
        for(int k = 0;k<3;k++){//
            // Joga para empate
             if(matriz_de_jogo[0][k] == 'x' && matriz_de_jogo[1][k] == 'x' && matriz_de_jogo[2][k] == ' '){
                linha=2;
                coluna=k;
                 x=1;
                
             
             }if(matriz_de_jogo[0][k] == 'x' && matriz_de_jogo[2][k] == 'x' && matriz_de_jogo[1][k] == ' '){
                linha=1;
                coluna=k;
                 x=1;
                
             }if(matriz_de_jogo[1][k] == 'x' && matriz_de_jogo[2][k] == 'x' && matriz_de_jogo[0][k] == ' '){
                linha=0;
                coluna=k;
                 x=1;
                
             }
 
             if(matriz_de_jogo[i][0] == 'x' && matriz_de_jogo[i][1] == 'x' && matriz_de_jogo[i][2] == ' '){
                linha=i;
                coluna=2;
                 x=1;
                
             }if(matriz_de_jogo[i][0] == 'x' && matriz_de_jogo[i][2] == 'x' && matriz_de_jogo[i][1] == ' '){
                linha=i;
                coluna=1;
                 x=1;
             }if(matriz_de_jogo[i][1] == 'x' && matriz_de_jogo[i][2] == 'x' && matriz_de_jogo[i][0] == ' '){
                linha=i;
                coluna=0;
                 x=1;
             
             }if(matriz_de_jogo[0][0] == 'x' && matriz_de_jogo[1][1] == 'x' && matriz_de_jogo[2][2] == ' '){
                linha=2;
                coluna=2;
                 x=1;
             
             }if(matriz_de_jogo[0][0] == 'x' && matriz_de_jogo[2][2] == 'x' && matriz_de_jogo[1][1] == ' '){
                linha=1;
                coluna=1;
                 x=1;
             }if(matriz_de_jogo[1][1] == 'x' && matriz_de_jogo[2][2] == 'x' && matriz_de_jogo[0][0] == ' '){
                linha=0;
                coluna=0;
                 x=1;
             }if(matriz_de_jogo[0][2] == 'x' && matriz_de_jogo[1][1] == 'x' && matriz_de_jogo[2][0] == ' '){
                linha=2;
                coluna=0;
                 x=1;
             }if(matriz_de_jogo[0][2] == 'x' && matriz_de_jogo[2][0] == 'x' && matriz_de_jogo[1][1] == ' '){
                linha=1;
                coluna=1;
                 x=1;
             }if(matriz_de_jogo[1][1] == 'x' && matriz_de_jogo[2][0] == 'x' && matriz_de_jogo[0][2] == ' '){
                linha=0;
                coluna=2;
                 x=1;
             }
        }

             //quando nâo se verifica ele tem de jogar random
             if(x == 0){
            linha = rand()%(2-0+1);
            coluna = rand()%(2-0+1); 
             }
        }
    }
}
