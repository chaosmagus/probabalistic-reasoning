#include "compute_a_posteriori.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2){
         cout << "Incorrect number of arguments\n"; 
         exit(1);
    }
    string observations(argv[1]); 
    return 0;
}

