#include "compute_a_posteriori.h"

using namespace std;

int main(int argc, char* argv[]){
    //check number of arguments
    if(argc != 2){
         cout << "Incorrect number of arguments\n"; 
         exit(1);
    }
    
    //get observations
    string observations(argv[1]);
    double totalObs = observations.size();
    
    //set hypothesis prior probablilities
    double h1Prior(0.1), h2Prior(0.2), h3Prior(0.4), h4Prior(0.2), h5Prior(0.1);
    

    return 0;
}

