#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printmatriz(){
   int i,j;

    cout << setw(4) << "0" << " |" << setw(2) << "1" << " |" << setw(2) << "2" << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---" << "|" << setw(2) << "---" << endl;
    cout << "0"    << "|" << setw(2) << "x" << " |" << setw(2) << "0" << " |" << setw(2) << "x" << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---" << "|" << setw(2) << "---" << endl;
    cout << "1"    << "|" << setw(2) << "0" << " |" << setw(2) << "x" << " |" << setw(2) << "0" << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---" << "|" << setw(2) << "---" << endl;
    cout << "2"    << "|" << setw(2) << "0" << " |" << setw(2) << "x" << " |" << setw(2) << "x" << endl;


}

bool verificarposicaodisponivel(int l, int c, char matriz[][]){
        return matriz[l][c] == ' ';
}

void posicoesvazias(int i, int j, char matriz[][]){
    if(matriz[i][j] != 'x' && matriz[i][j] != 'o'){
        cout << ' ' << endl;
    }
}


char verificarvencedor(char matriz[3][3]){
    for(int i = 0; i<3; i++){
        if(matriz[i][0] != ' ' && matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]){
            return matriz[i][0];
        }
    }
}



void verificafimdojogo(){

    if((matriz[0][0] == matriz[0][1] == matriz[0][2]) || (matriz[1][0] == matriz[1][1] == matriz[1][2]) || (matriz[2][0] == matriz[2][1] == matriz[2][2])
     || (matriz[0][0] == matriz[1][0] == matriz[2][0]) || (matriz[0][1] == matriz[1][1] == matriz[2][1]) || (matriz[0][2] == matriz[1][2] == matriz[2][2])
     || (matriz[0][0] == matriz[1][1] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] == matriz[2][0])){
        cout << " Resultado: Vitoria" << endl;
        return 1;
     }else if((matriz[0][0] != matriz[0][1] != matriz[0][2]) || (matriz[1][0] != matriz[1][1] != matriz[1][2]) || (matriz[2][0] != matriz[2][1] != matriz[2][2])
     || (matriz[0][0] != matriz[1][0] != matriz[2][0]) || (matriz[0][1] != matriz[1][1] != matriz[2][1]) || (matriz[0][2] != matriz[1][2] != matriz[2][2])
     || (matriz[0][0] != matriz[1][1] != matriz[2][2]) || (matriz[0][2] != matriz[1][1] != matriz[2][0])){
        cout << "Resultado: Empate" << endl;
        return 2;
     }else{
        cout << "E a sua vez de jogar" << endl;
        return 3;
     }
}

