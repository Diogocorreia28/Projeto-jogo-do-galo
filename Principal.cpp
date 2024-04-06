#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;


    

int menu(){
int opcao;
cout << "\nPor favor escolha uma das várias opções;\n\n"<< endl;


    cout << "1-Iniciar jogo\n" << "2-Escolher quem inicia primeiro o jogo\n" << "3-Modo de funcionamento\n" << "4-Mostrar top 10\n" 
         << "5-Sair\n" << endl;

    cout << "Opção:";
    cin >> opcao;

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



void colocar_valor(char matriz_de_jogo[3][3],int linha,int coluna){

   matriz_de_jogo[linha][coluna]='x';
                        


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

bool verificarposicaoDisponivel(char matriz_de_jogo[3][3],int c, int l) {


    return ((c >= 0 && c <= 2 && l >= 0 && l <= 2 ) && matriz_de_jogo[c][l] != 'x' && matriz_de_jogo[c][l] != 'O');
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

int resultado_dificuldade(int dificuldade){
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

int main(){
    int dificuldade;
    int opçaomenu,i=0;
    int coluna,linha;
    char x=' ',y=' ',z=' ',w=' ',s=' ',d=' ',a=' ',b=' ',c=' ';
    char matriz_de_jogo[3][3] = {{x,y,z},
                                {a,b,c},
                                {w,d,s}
    };


    cout << "Bem vindo ao jogo do galo\n" << "Escolha a sua dificuldade\n\n" << endl;
    cout << "1-elementar\n" << "2-básico\n" << "3-médio\n" << endl;
    cout << "Dificuldade-";
    cin >> dificuldade;

    opçaomenu = menu();

    if(resultado_dificuldade(dificuldade) == 1) {
        if(opçaomenu == 1) {

            cout << "\nEscolha uma posição para colocar a sua peça das disponíveis no tabuleiro das apresentadas\n\n";
            
            printmatriz(matriz_de_jogo,i=0);
            
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha,coluna);
            
            i=1;

            printmatriz(matriz_de_jogo,i);

            for(int n=0;n<9;n++){
        
            obtercoordenada(coluna,linha); // Aqui chama a função para obter as coordenadas

            colocar_valor(matriz_de_jogo,linha,coluna);

            while(verificarposicaoDisponivel(matriz_de_jogo,coluna,coluna,linha) != 1){
                


            }
           

            
            printmatriz(matriz_de_jogo,i);

            verificafimdojogo(matriz_de_jogo);

            

            }

            cout << "Resultado: Empate" << endl;







            


            
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
    if(resultado_dificuldade(dificuldade) == 2){/*greedy*/
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

if(resultado_dificuldade(dificuldade) == 3){/*ganha sempre*/

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
 


}
