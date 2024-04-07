#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
#include<fstream>

using namespace std;

class jogo_do_galo{
public:

int menu_dificuldades(){
   int dificuldade;
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

int menu(){
int opcao;
cout << "\nPor favor escolha uma das várias opções;\n"<< endl;

do{
    cout << "1-Iniciar jogo\n" << "2-Escolher quem inicia primeiro o jogo\n" << "3-Modo de funcionamento\n" << "4-Mostrar top 10\n" 
         << "5-Sair\n" << endl;

    cout << "Opção:";
    cin >> opcao;
}while(opcao<1 || opcao >5);
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
        
        case(4):        /*  mostrar o top 10*/

        return 4;
        break;
        
        case(5):        /*  fechar o jogo*/

        return 5;
        break;
    }
    }while(opcao>5 || opcao<0);
}

int verificafimdojogo(char matriz_de_jogo[3][3]){
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

int verificafimdojogo_computador(char matriz_de_jogo[3][3]){
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

void jogada_computador(char matriz_de_jogo[3][3],int &linha,int &coluna) {
        
    
        linha = rand()%(2-0+1);
        coluna = rand()%(2-0+1); 
    
        
}

void colocar_valor(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='x';
                        


}

void colocar_valor_computador(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='0';
                        
}

void printmatriz(char matriz_de_jogo[3][3],int i){
   




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

bool verificarposicaoDisponivel(char matriz_de_jogo[3][3],int l, int c) {


    return ((c >= 0 && c <= 2 && l >= 0 && l <= 2 ) && matriz_de_jogo[l][c] != 'x' && matriz_de_jogo[l][c] != '0');
}

void obtercoordenada(int &c,int &l){
    
    do{
        cout << "Insira um numero para a linha" << endl;
        cin >> l;
        
    }while(l != 0 && l != 1 && l != 2);

     do{
        cout << "Insira um numero para a coluna" << endl;
        cin >> c;
        
    }while(c != 0 && c != 1 && c != 2);

}

void quem_joga_primeiro(int &p){
    
    cout << "\nQuem pretende que comece a jogar?" << endl;
    cout << "1-Eu ou 2-Computador ou 3-aleatório" << endl;
    do{
        cin >> p;
    }while(p<1 && p>3);

    if(p == 3){

        p = rand()%2;
    }

}

void numero_jogada(int &n){
        
        cout << "\nJogada:" << n << endl;
        n++;
}

void tirar_valores(char matriz_de_jogo[3][3]){
 //limpar linhas
    int c=0;
    for(c;c<3;c++){
        
        matriz_de_jogo[0][c] =' ';
        matriz_de_jogo[1][c] =' ';
        matriz_de_jogo[2][c] =' ';


    }
}

void jogada_nivel2(char matriz_de_jogo[3][3],int &linha,int &coluna){
    int x=0;
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

void jogada_nivel3(char matriz_de_jogo[3][3],int &linha,int &coluna){
   int x=0;
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

};

int main(){
    int opçaomenu,i=0,dificuldade;
    int coluna,linha;
    int j,r=1;
    string confirmar;
    char x=' ',y=' ',z=' ',w=' ',s=' ',d=' ',a=' ',b=' ',c=' ';
    char matriz_de_jogo[3][3] = {{x,y,z},
                                 {a,b,c},
                                 {w,d,s}
    };

    jogo_do_galo funcoes;

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

            for(int n=0;n<9;n++){
            
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
            
             if(n==8){
            cout << "Resultado: Empate" << endl;
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

            for(int n=0;n<9;n++){
            
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
              if(n==8){
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

            for(int n=0;n<9;n++){  

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
             if(n==8){
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

            for(int n=0;n<9;n++){
            
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
            
             if(n==8){
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

            for(int n=0;n<9;n++){
            
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
            
             if(n==8){
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
            
             if(n<4){
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

        if(opçaomenu == 4 ){         /*mostra top 10*/


        }

        


}while(opçaomenu !=5);

 if(opçaomenu == 5){   
     do{                    /*fecha jogo*/
      cout << "Tem a certeza que quer sair?\n" ;
      getchar() != '/n'; //para limpar o buffer
      getline(cin,confirmar);
     }while(confirmar != "sim");
     cout<< "a sair...";
        exit(0);
}
        }
