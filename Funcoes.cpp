#include "Funcoes.h"
#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
#include<fstream>



using namespace std;

Funcoes::Funcoes()
{

}

Funcoes::~Funcoes()
{

}

int Funcoes::menu_dificuldades(){
    
    do{
       cout << "Escolha o modo de funcionamento\n\n" << endl;
    cout << "1-elementar\n" << "2-básico\n" << "3-médio \n" << "4-avançado\n" << "5-dois jogadores\n" << "6-computador contra computador\n" << endl;
    cout << "Modo-";
             if (!(cin >> dificuldade)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (dificuldade < 1 || dificuldade > 6) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 1 e 6." << endl;
        }
    } while(cin.fail() || dificuldade < 1 || dificuldade > 6);
   
    
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
                            case(4):        //modo avançado
                                    opçao_dificuldade=4;
                            break;
                            case(5):        //jogador contra jogador
                                    opçao_dificuldade=5;
                            break;
                            case(6):        //computador computador
                                    opçao_dificuldade=6;
                            break;

    }
return opçao_dificuldade;


}

int Funcoes::menu(){
    cout << "\nPor favor escolha uma das várias opções;\n"<< endl;

do {
    cout << "1-Iniciar jogo\n" << "2-Escolher quem inicia primeiro o jogo\n" << "3-Modo de funcionamento\n" << "4-Mostrar top 10\n" <<"5-Sair\n"
         << endl;

        cout << "Opção: ";
        if (!(cin >> opcao)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (opcao < 1 || opcao > 5) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 1 e 5." << endl;
        }
    } while(cin.fail() || opcao < 1 || opcao > 5);

    switch(opcao) {
        case 1: /* inicia o jogo,aleatorio quem joga primeiro,criar função iniciar jogo */
            return 1;
            break;
        
        case 2: /*  escolher contra quem quer jogar ou player ou pc*/
            return 2;
            break;
        
        case 3: /*  Dificuldade*/
            return 3;
            break;
        
        case 4: /*  Mostra top 10*/
            return 4;
            break;
        

        case 5: 
                return 5;
                break;//Fecha jogo
        default:
           
            break;
    }
}

int Funcoes::verificafimdojogo(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Vitória\n" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Vitória\n" << endl;
            return 9;
        }
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Vitória\n" << endl;
        return 9;
    }

    
}

int Funcoes::verificafimdojogo_computador(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Derrota\n" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Derrota\n" << endl;
            return 9;
        }

        
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Derrota\n" << endl;
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

int Funcoes::printmatriz(char matriz_de_jogo[3][3],int i){
   
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
        cout << "Insira um número para a linha" << endl;
         if (!(cin >> l)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (l < 0 || l > 2) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 0 e 2." << endl;
        }
    } while(cin.fail() || l < 0 || l > 2);

     do{
        cout << "Insira um numero para a coluna" << endl;
          if (!(cin >> c)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (c < 0 || c > 2) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 0 e 2." << endl;
        }
    } while(cin.fail() || c < 0 || c > 2);

}

void Funcoes::quem_joga_primeiro(int &p){
    
    cout << "\nQuem pretende que comece a jogar?" << endl;
    cout << "1-Eu ou 2-Computador ou 3-Aleatório" << endl;
    do{
           if (!(cin >> p)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (p < 1 || p > 3) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 1 e 3." << endl;
        }
    } while(cin.fail() || p < 1 || p > 5);
        
    

    if(p == 3){

        p = rand()%2;
    }

}

int Funcoes::numero_jogada(int &n){
        
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

void top10::salvarJogos(const Jogo jogos[],int numeroJogos){
    ofstream my_file("Top_10.txt");
    if(my_file.is_open()){
        for(int i=0;i<numeroJogos;i++){
            my_file << jogos[i].resultado << endl;
        }
        my_file.close();
    }else{
        cout << "Erro ao abrir arquivo" << endl;
    }
}

void top10::carregarJogos(Jogo jogos[],int &numeroJogos){
    ifstream my_file("Top_10.txt");

    if(my_file.is_open()){
       
        while(getline(my_file,linha) && numeroJogos<Maxjogos){ //enquanto o getline for verdadeiro logo existem linha para ler e o numero <que o max ele 
            jogos[numeroJogos].resultado=linha;
            numeroJogos++;

        }
        my_file.close();
    }else{
            cout << "Erro ao abrir o ficheiro" << endl;
    }
    }

void top10::registrarJogo(Jogo jogos[], int &numeroJogos, const string &resultado){
    Jogo jogo;
    jogo.resultado=resultado;
        if(numeroJogos< Maxjogos){

            jogos[numeroJogos]=jogo;
            numeroJogos++;
        }else{
            for(int i=0;i<Maxjogos-1;i++){
                jogos[i] = jogos[i+1]; //para ir substiruir os antigos
            }
            jogos[Maxjogos-1]=jogo;
        }
        salvarJogos(jogos,numeroJogos);
}

void top10::mostrarTop10(const Jogo jogos[], int numeroJogos){
        cout << "Top 10 dos ultimos jogos:\n";

        int inicio=max(0,numeroJogos-Maxjogos);
        for(int i=inicio;i<numeroJogos;i++){

            cout << (i-inicio+1)  << "  Resultado:" << jogos[i].resultado<<endl;
        }

}

void Funcoes::colocar_valor2(char matriz_de_jogo[3][3],int linha,int coluna){
       matriz_de_jogo[linha][coluna]='0';
}

int Funcoes::verificafimdojogo2(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: vitoria jogador 2\n" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: vitória jogador 2\n" << endl;
            return 9;
        }
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: vitória jogador 2\n" << endl;
        return 9;
    }

    
}

void Funcoes::jogadorVSjogador(){

    top10 top_10;
            printmatriz(matriz_de_jogo,i_jogo=0);
            
            obtercoordenada(coluna_main,linha_main); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha_main,coluna_main);


            i_jogo=1;

            numero_jogada(r_main);

            printmatriz(matriz_de_jogo,i_jogo);



            for(int n=0;n<4;n++){
            //Jogador-2
                 numero_jogada(r_main);
            obtercoordenada(coluna_main,linha_main); // criar funcao para jogador 2

            while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna_main,linha_main);
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

           colocar_valor2(matriz_de_jogo,linha_main,coluna_main); // criar funcao para jogador 2
           
           printmatriz(matriz_de_jogo,i_jogo);

            if(verificafimdojogo2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
            resultado_main="Vitoria jogador 2";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n!=9){
            numero_jogada(r_main);
            obtercoordenada(coluna_main,linha_main); // Aqui chama a função para obter as coordenadas

            while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna_main,linha_main);
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

            colocar_valor(matriz_de_jogo,linha_main,coluna_main);
           
            printmatriz(matriz_de_jogo,i_jogo);

            

            if(verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
                          
            resultado_main="Vitoria jogador 1";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);
            }
            
             if(n==3){
            cout << "Resultado: Empate jogador Vs jogador" << endl;
                  
            resultado_main="Resultado: Empate jogador Vs jogador";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
        }

        }
        i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
        r_main=1;
        tirar_valores(matriz_de_jogo);

}   

void Funcoes::jogada_nivel4(char matriz_de_jogo[3][3],int &linha,int &coluna,int &contador_nivel4){
     x=0;
     colocar_canto=rand()%(4-0+1);
     
    
           
      
                

    for(int i = 0;i<3;i++){

        if(matriz_de_jogo[1][1]==' ' && contador_nivel4 == 0 ){
            linha=1;
            coluna=1;
            
            return;
        }

       
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
             }//caso ele tente a tática dos cantos
             if(matriz_de_jogo[0][0] == 'x' && matriz_de_jogo[2][2] == 'x' && x!=1){
                linha=1;
                coluna=0;
                x=1;
             }
             if(matriz_de_jogo[0][2] == 'x' && matriz_de_jogo[2][0] == 'x' && x!=1){
                linha=1;
                coluna=0;
                x=1;
             }

               if(matriz_de_jogo[1][1]=='x' && contador_nivel4 == 0 ){

            if(colocar_canto==1){
                linha=0;
                coluna=2;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==2){
                linha=0;
                coluna=0;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==3){
                linha=2;
                coluna=2;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==4){
                linha=2;
                coluna=0;
                contador_nivel4++;
                return;
            }
            }

             if(matriz_de_jogo[1][1] == '0' && x!=1){
         if(colocar_canto==1 && contador_nivel4==0 && (matriz_de_jogo[0][0]=='x' || matriz_de_jogo[2][2]=='x') ){
                linha=0;
                coluna=2;
                
                return;
            }
            if(colocar_canto==2 && contador_nivel4==0 && (matriz_de_jogo[0][2]=='x'|| matriz_de_jogo[2][0]=='x')){
                linha=0;
                coluna=0;
              
                return;
            }
            if(colocar_canto==3 && contador_nivel4==0 && (matriz_de_jogo[0][2]=='x' || matriz_de_jogo[2][0]=='x')){
                linha=2;
                coluna=2;
                
                return;
            }
            if(colocar_canto==4 && contador_nivel4== 0 && (matriz_de_jogo[0][0]=='x' || matriz_de_jogo[2][2]=='x')){
                linha=2;
                coluna=0;
              
                return;
            }
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

void Funcoes::executavel_nivel4(){
    
    top10 top_10;

     cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            printmatriz(matriz_de_jogo,i_jogo=0);
            
            obtercoordenada(coluna_main,linha_main); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha_main,coluna_main);

            
            
            
            i_jogo=1;

            numero_jogada(r_main);

            printmatriz(matriz_de_jogo,i_jogo);

            for(int n=0;n<4;n++){
            
            numero_jogada(r_main);
            jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

            while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);
                        
                       verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

            colocar_valor_computador(matriz_de_jogo,linha_main,coluna_main);

            
            printmatriz(matriz_de_jogo,i_jogo);

            
            
              //Função trocar jogador;
            if(verificafimdojogo_computador(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu
                n=9;
                          
            resultado_main="Derrota";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);
            }
           

            if(n!=9){
            numero_jogada(r_main);
            obtercoordenada(coluna_main,linha_main); // Aqui chama a função para obter as coordenadas

            while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna_main,linha_main);
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

            colocar_valor(matriz_de_jogo,linha_main,coluna_main);
           
            printmatriz(matriz_de_jogo,i_jogo);

            

            if(verificafimdojogo(matriz_de_jogo) == 9){ 
                n=9;
          
            resultado_main="Vitoria";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);
            }
            
             if(n==3){
            cout << "Resultado: Empate" << endl;
        
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);
            }
            }
            }
            
             i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
             r_main=1;
             contador_nivel4=0;
             tirar_valores(matriz_de_jogo);


}
    
int Funcoes::menuDificuldadesPC(){
     do{
       cout << "Escolha o modo de funcionamento\n\n" << endl;
    cout << "1-elementar\n" << "2-básico\n" << "3-médio \n" << "4-avançado\n"  << endl;
    cout << "Modo-";
             if (!(cin >> dificuldade)) {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();            // Limpa o estado de erro do cin
            cin.ignore(100, '\n');  // Limpa o buffer de entrada
        } else if (dificuldade < 1 || dificuldade > 4) {
            cout << "Opção inválida. Por favor, escolha uma opção entre 1 e 4." << endl;
        }
    } while(cin.fail() || dificuldade < 1 || dificuldade > 4);
   
    
    /*basicamente cada dificuldade*/
    switch(dificuldade){
                            case(1):        /*computador joga aleatoriamente perdendo maior parte das vezes*/
                                    return 1;
                                    
                            break;
                            case(2):        /*computador ganhar na jogada corrente usando a estratégia greddy */
                                    return 2;
                            break;
                            case(3):        /*o computador ganha na jogada corrente, não sendo possível faz empate*/
                                    return 3;
                            break;
                            case(4):        //modo avançado
                                    return 4;
                            break;
                           
    }


}

void Funcoes::computadorVScomputador(){

    top10 top_10;
        cout << "Para o Computador 1 'x' " << endl;

            switch(menuDificuldadesPC()){

                case (1):             //fácil
                           
                  cout << "Para o Computador 2 '0' " << endl; 

                                 switch(menuDificuldadesPC()){

                                    case (1):          

                            i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);

                    break;
                
                                    case (2):    


                            i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);


                    break;

                                    case (3):


                            i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);



                    break;

                                    case (4):

  i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_computador(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);





                    break;
            }
                         

                    
                
                case (2):     //Joga apenas para ganhar computador 1

                 cout << "Para o Computador 2 '0'" << endl; 

                        switch(menuDificuldadesPC()){

                                    case (1):             //fácil
                                    
                                     i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);

                    break;
                
                                    case (2):

                                              i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);



                    break;

                                    case (3):

                 i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);





                    break;

                                    case (4):

                                    i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);



                    break;
            }



                    break;

                case (3):          //joga para ganhar e defender

                 cout << "Para o Computador 2'0'" << endl; 

                            switch(menuDificuldadesPC()){

                                    case (1):             //fácil
                           
                                 i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);
                                    

                    break;
                
                                    case (2):

                                              i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);





                    break;

                                    case (3):


                 i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);




                    break;

                                    case (4):

                                  i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);


                    break;
            }




                case (4):          //nunca perde

                 cout << "Para o Computador 2'0'" << endl; 

                            switch(menuDificuldadesPC()){

                                    case (1):             //fácil
                                                            i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogadaComputador2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);
                                    
                           
                                    

                    break;
                
                                    case (2):

                                                                      i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel2(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);




                    break;

                                    case (3):

                                         i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel3(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);




                    break;

                                    case (4):

                                                                 i_jogo=1;

                            numero_jogada(r_main);

                                    jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                                    colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                                    printmatriz(matriz_de_jogo,i_jogo);

                    for(int n=0;n<4;n++){

                        //Parte do computador 2
                    
                        numero_jogada(r_main);

                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);

                     while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        computador2_jogada_nivel4(matriz_de_jogo,linha_main,coluna_main);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }

                        colocar_valor_computador2(matriz_de_jogo,linha_main,coluna_main);

                        printmatriz(matriz_de_jogo,i_jogo);

                    //Começa a fazer as verificações de vencedor

                    if(verificafimdojogo_computador2(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 2\n";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }

            //Passa para o computador 1

                if(n!=9){
                          numero_jogada(r_main);

                          jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);

                while(verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main) != 1){  //verificar a linha do computador
                        
                        jogada_nivel4(matriz_de_jogo,linha_main,coluna_main,contador_nivel4);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha_main,coluna_main);
            }
                        colocar_valor_computador1(matriz_de_jogo,linha_main,coluna_main);

                         printmatriz(matriz_de_jogo,i_jogo);


                if(verificafimdojogo_computador1(matriz_de_jogo) == 9){ //para ele saltar o empate e voltar ao menu

                n=9;


                     
                         resultado_main="Vitoria computador 1\n";
                         top_10.registrarJogo(jogo,numeroJogos,resultado_main);
                         top_10.mostrarTop10(jogo,numeroJogos);
            }


            if(n==3){
            cout << "Resultado: Empate\n" << endl;
                  
            resultado_main="Empate";
            top_10.registrarJogo(jogo,numeroJogos,resultado_main);
            top_10.mostrarTop10(jogo,numeroJogos);

            }
                }
                    }

            i_jogo=0; //para quando o jogo acaba o utilizador se voltar a escolher menu aparece tudo de novo
            r_main=1;
            tirar_valores(matriz_de_jogo);



                    break;
            }


            }

}

void Funcoes::jogadaComputador2(char matriz_de_jogo[3][3],int &linha,int &coluna){

         linha = rand()%(2-0+1);
        coluna = rand()%(2-0+1); 
}

int  Funcoes::verificafimdojogo_computador2(char matriz_de_jogo[3][3]){

     //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Vitoria Computador 2\n" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Vitoria Computador 2\n" << endl;
            return 9;
        }

        
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Vitoria Computador 2\n" << endl;
        return 9;
    }
}

int Funcoes::verificafimdojogo_computador1(char matriz_de_jogo[3][3]){

     //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Vitoria Computador 1\n" << endl;
            return 9;
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Vitoria Computador 1\n" << endl;
            return 9;
        }

        
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Vitoria Computador 1\n" << endl;
        return 9;
    }
}

void Funcoes::colocar_valor_computador1(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='x';
                        
}

void Funcoes::colocar_valor_computador2(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='0';
                        
}

void Funcoes::computador2_jogada_nivel2(char matriz_de_jogo[3][3],int &linha,int &coluna){
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

void Funcoes::computador2_jogada_nivel3(char matriz_de_jogo[3][3],int &linha,int &coluna){

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

void Funcoes::computador2_jogada_nivel4(char matriz_de_jogo[3][3],int &linha,int &coluna){

     x=0;
     colocar_canto=rand()%(4-0+1);
     
    
           
      
                

    for(int i = 0;i<3;i++){

        if(matriz_de_jogo[1][1]==' ' && contador_nivel4 == 0 ){
            linha=1;
            coluna=1;
            
            return;
        }

       
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
             }//caso ele tente a tática dos cantos
             if(matriz_de_jogo[0][0] == 'x' && matriz_de_jogo[2][2] == 'x' && x!=1){
                linha=1;
                coluna=0;
                x=1;
             }
             if(matriz_de_jogo[0][2] == 'x' && matriz_de_jogo[2][0] == 'x' && x!=1){
                linha=1;
                coluna=0;
                x=1;
             }

               if(matriz_de_jogo[1][1]=='x' && contador_nivel4 == 0 ){

            if(colocar_canto==1){
                linha=0;
                coluna=2;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==2){
                linha=0;
                coluna=0;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==3){
                linha=2;
                coluna=2;
                contador_nivel4++;
                return;
            }
            if(colocar_canto==4){
                linha=2;
                coluna=0;
                contador_nivel4++;
                return;
            }
            }

             if(matriz_de_jogo[1][1] == '0' && x!=1){
         if(colocar_canto==1 && contador_nivel4==0 && (matriz_de_jogo[0][0]=='x' || matriz_de_jogo[2][2]=='x') ){
                linha=0;
                coluna=2;
                
                return;
            }
            if(colocar_canto==2 && contador_nivel4==0 && (matriz_de_jogo[0][2]=='x'|| matriz_de_jogo[2][0]=='x')){
                linha=0;
                coluna=0;
              
                return;
            }
            if(colocar_canto==3 && contador_nivel4==0 && (matriz_de_jogo[0][2]=='x' || matriz_de_jogo[2][0]=='x')){
                linha=2;
                coluna=2;
                
                return;
            }
            if(colocar_canto==4 && contador_nivel4== 0 && (matriz_de_jogo[0][0]=='x' || matriz_de_jogo[2][2]=='x')){
                linha=2;
                coluna=0;
              
                return;
            }
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

void matrizDireita::matrizesDireita(char matriz_de_jogo[3][3],int &i){

Funcoes funcoes;

//para ir guardando as matrizes nas variaveis
       
            matrizes[i]=funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=1);


// a matriz ocupa 13 linhas
           
           
            //jogada 1 aparece o tabuleiro e pede já a jogada 2         
            if(i==0){
                cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main) <<endl;
                cout << left << matrizes[0] << setw(27) << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0)  <<endl;
                funcoes.r_main=1; //para reiniciar as jogadas

            }
            //aparece preenchido o 1 e 2 mas o 3 pede
            if(i==1){

                cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13)<<funcoes.numero_jogada(funcoes.r_main)<<endl;
                cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) << endl;
                funcoes.r_main=1;
        }
            // aparece 1,2,3 e pede 4
            if(i==2){
                
                cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
                cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) << endl;

                funcoes.r_main=1;
            }
            // aparece 1,2,3,4 e pede 5
            if(i==3){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;
            cout << left << funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) << endl;

            funcoes.r_main=1;
            }
            //aparece 1,2,3,4,5 e pede 6
            if(i==4){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;  
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main) <<endl;
            cout << left << matrizes[4] << setw(27) << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0)  <<endl;  

            funcoes.r_main=1;

            }
            //aparece 1,2,3,4,5,6 e pede 7
            if(i==5){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13)<< funcoes.numero_jogada(funcoes.r_main)<<setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;  
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main) << setw(13) << funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left << matrizes[4] << setw(27) << matrizes[5] << setw(27) << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) <<endl;  

            funcoes.r_main=1;
            }
            //aparece 1,2,3,4,5,6,7 e pede 8
            if(i==6){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;  
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left << matrizes[4] << setw(27) << matrizes[5] << setw(27) << matrizes[6] << funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) <<endl;  

            funcoes.r_main=1;
            }
            //aparece 1,2,3,4,5,6,7,8 e pede 9
            if(i==7){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;  
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left << matrizes[4] << setw(27) << matrizes[5] << setw(27) << matrizes[6] << setw(27) << matrizes[7]<< endl;
            cout << left <<  funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left <<  funcoes.printmatriz(funcoes.matriz_de_jogo,funcoes.i_jogo=0) << endl;

            funcoes.r_main=1;
            }
            // aparece o jogo concluido
            if(i==8){
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main)  <<endl;
            cout << left << matrizes[0] << setw(27) << matrizes[1] << setw(27) << matrizes[2] << setw(27) <<matrizes[3] << endl;  
            cout << left << funcoes.numero_jogada(funcoes.r_main) << setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13)<< funcoes.numero_jogada(funcoes.r_main)<< setw(13) << funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left << matrizes[4] << setw(27) << matrizes[5] << setw(27) << matrizes[6] << setw(27) << matrizes[7]<< endl;
            cout << left <<  funcoes.numero_jogada(funcoes.r_main) << endl;
            cout << left <<  matrizes[8] << endl;

            funcoes.r_main=1;
            }

            i++;

}

