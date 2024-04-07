
#include<iostream>
#include<iomanip>
#include<cstdlib> //para o exit do programa e a função rand
#include<time.h> // para poder usar o time em rand
#include<cstring>
#include<fstream>




using namespace std;

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

void verificafimdojogo(char matriz_de_jogo[3][3]){
 //verifica as linhas
   for (int i = 0; i < 3; ++i) {
        if (matriz_de_jogo[i][0] == matriz_de_jogo[i][1] && matriz_de_jogo[i][1] == matriz_de_jogo[i][2] && matriz_de_jogo[i][0] != ' ') {
            cout << "Resultado: Vitória" << endl;
            exit(0);
        }
     }

 //verificar colunas
    for (int j = 0; j < 3; ++j) {
        if (matriz_de_jogo[0][j] == matriz_de_jogo[1][j] && matriz_de_jogo[1][j] == matriz_de_jogo[2][j] && matriz_de_jogo[0][j] != ' ') {
            cout << "Resultado: Vitória" << endl;
            exit(0);
        }
    }

//verificar diagonais
    if ((matriz_de_jogo[0][0] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][2] && matriz_de_jogo[0][0] != ' ')
     || (matriz_de_jogo[0][2] == matriz_de_jogo[1][1] && matriz_de_jogo[1][1] == matriz_de_jogo[2][0] && matriz_de_jogo[0][2] != ' ')) {
        cout << "Resultado: Vitória" << endl;
        exit(0);
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

int main(){
    int opçaomenu,i=0;
    int coluna,linha;
    int j,r=1;
    string confirmar;
    char x=' ',y=' ',z=' ',w=' ',s=' ',d=' ',a=' ',b=' ',c=' ';
    char matriz_de_jogo[3][3] = {{x,y,z},
                                 {a,b,c},
                                 {w,d,s}
    };
    srand((unsigned int)time(NULL)); //plantar a semente 

    
    cout << "Bem vindo ao jogo do galo " << endl;
    
    
    opçaomenu = menu();

    if(opçaomenu == 5){   
     do{                    /*fecha jogo*/
      cout << "Tem a certeza que quer sair?\n" ;
      getline(cin,confirmar);
     }while(confirmar != "sim");
     cout<< "a sair...";
        exit(0);

        }

if(menu_dificuldades() == 1) {

        if(opçaomenu == 1) {
            j=1;
            if(j==1 || j==3 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            printmatriz(matriz_de_jogo,i=0);
            
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            numero_jogada(r);

            printmatriz(matriz_de_jogo,i);

            for(int n=0;n<9;n++){
            
            numero_jogada(r);
            jogada_computador(matriz_de_jogo,linha,coluna);

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha,coluna);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);
            
              //Função trocar jogador;

           

            
            numero_jogada(r);
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna,linha);
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor(matriz_de_jogo,linha,coluna);
           
            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);
            
            }

            cout << "Resultado: Empate" << endl;
            
        }
         //fim do jogo com eu primeiro

        }

        if(opçaomenu == 2){                 /*escolhe contra quem joga*/

        // Tem de haver uma função para escolher quem joga
        // a função vai dar a informação por referencia de quem joga
        quem_joga_primeiro(j);

        if(j==1 ){ //quando o jogador joga primeiro
            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n";
            
            printmatriz(matriz_de_jogo,i=0);
            
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha,coluna);

            
            
            
            i=1;

            numero_jogada(r);

            printmatriz(matriz_de_jogo,i);

            for(int n=0;n<9;n++){
            
            numero_jogada(r);
            jogada_computador(matriz_de_jogo,linha,coluna);

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha,coluna);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor_computador(matriz_de_jogo,linha,coluna);

            
            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);
            
              //Função trocar jogador;

           

            
            numero_jogada(r);
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna,linha);
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor(matriz_de_jogo,linha,coluna);
           
            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);
            
            }

            cout << "Resultado: Empate" << endl;
            
        }
         //fim do jogo com eu primeiro

        if(j == 2){
                numero_jogada(r);

                jogada_computador(matriz_de_jogo,linha,coluna);

                colocar_valor_computador(matriz_de_jogo,linha,coluna);

                printmatriz(matriz_de_jogo,i=1); 

                cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n\n";
            
                i=1;

            for(int n=0;n<9;n++){  

            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){
                        cout << "\nA linha já se encontra preenchida"<< endl;
                        obtercoordenada(coluna,linha);
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor(matriz_de_jogo,linha,coluna);
           
            numero_jogada(r);    

            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);
            
              //trocar jogador
            
            numero_jogada(r);

            jogada_computador(matriz_de_jogo,linha,coluna);

            while(verificarposicaoDisponivel(matriz_de_jogo,linha,coluna) != 1){  //verificar a linha do computador
                        
                        jogada_computador(matriz_de_jogo,linha,coluna);
                        
                        verificarposicaoDisponivel(matriz_de_jogo,linha,coluna);
            }

            colocar_valor_computador(matriz_de_jogo,linha,coluna);

            verificafimdojogo(matriz_de_jogo);
           
            printmatriz(matriz_de_jogo,i);
            }


            

            cout << "Resultado: Empate" << endl;
        }
        }

        if(opçaomenu == 3){         /*escolher a dificuldade*/
        //menu_dificuldades(); ver com joao por causa de andar a saltar

        }

        if(opçaomenu == 4){         /*mostra top 10*/


        }

}
if(menu_dificuldades() == 2){/*greedy*/
        if(opçaomenu == 1){                         /*inicia o jogo*/


        }
        if(opçaomenu == 2){                 /*escolhe contra quem joga*/


        }
        if(opçaomenu == 3){         /*apaga histórico de jogadas*/


        }
        if(opçaomenu == 4){         /*mostra top 10*/


        }
        if(opçaomenu == 5){         /*fecha jogo*/


        }

    }

if(menu_dificuldades() == 3){/*ganha sempre*/

    if(opçaomenu == 1){                         /*inicia o jogo*/


    }
    if(opçaomenu == 2){                 /*escolhe contra quem joga*/


    }
    if(opçaomenu == 3){         /*apaga histórico de jogadas*/


    }
    if(opçaomenu == 4){         /*mostra top 10*/


    }
    if(opçaomenu == 5){         /*fecha jogo*/


    }



}
//para ele fazer um tipo de jump para voltar para a dificuldade

}

