

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printmatriz(){
   int i,j;

    cout << setw(4) << "0"  << " |" << setw(2) << "1"  << " |"    << setw(2) << "2"  << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "0"     << "|"  << setw(2) << "x" << " |"  << setw(2) << "0"     << " |" << setw(2) << "x"   << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "1"     << "|"  << setw(2) << "0" << " |"  << setw(2) << "x"     << " |" << setw(2) << "0"   << endl;
    cout << setw(2) << "-|" << setw(3) << "---" << "|" << setw(2) << "---"   << "|"  << setw(2) << "---" << endl;
    cout << "2"     << "|"  << setw(2) << "0" << " |"  << setw(2) << "x"     << " |" << setw(2) << "x"   << endl;


}


int main(){
  

    printmatriz();

    return 0;
}

