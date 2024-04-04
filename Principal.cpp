#include<iostream>

using namespace std;

int menu(){
int opcao;
cout << "Por favor escolha uma das várias opções;\n\n"<< endl;


    cout << "1-Iniciar jogo\n" << "2-Escolher quem inicia primeiro o jogo\n" << "3-Modo de funcionamento\n" << "4-Mostrar top 10\n" 
         << "5-Sair\n" << endl;

    cout << "Opção:";
    cin >> opcao;

    switch(opcao){

        case(1):        /* inicia o jogo,aleatorio quem joga primeiro */

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







}





int main(){
int dificuldade;
int menu;
    cout << "Bem vindo ao jogo do galo\n" << "Escolha a sua difículdade \n\n" << endl;

    cout<< "1-elementar\n" << "2-básico\n" << "3-médio\n" << endl;
    
    cout<<"Dificuldade-";
    
    cin >> dificuldade;

    switch(dificuldade){
                            case(1):        /*computador joga aleatoriamente perdendo maior parte das vezes*/
                                    menu=menu();
                            break;
                            case(2):        /*computador ganhar na jogada corrente usando a estratégia greddy */
                                    menu=menu();
                            break;
                            case(3):        /*o computador ganha na jogada corrente, não sendo possível faz empate*/
                                    menu=menu();
                            break;

    }
    if(menu == 1){        /*iniciar função jogo*/


    }if(menu == 2){       /*função para escolher contra quem joga*/


    }if(menu == 3){       /*Função apagar histórico de jogadas*/


    }if(menu == 4){       /*Função mostrar top 10*/  


    }if(menu == 5){       /*fechar jogo*/
    
    cout << "Jogo fechado";
    return 0;

    }

}