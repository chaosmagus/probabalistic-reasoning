#include "compute_a_posteriori.h"

using namespace std;

//probability of next candy
void pHypothesis(int h_number, char obs_flavor, int obsCount, vector<double> &h_prob, vector<double> &pcherry){
    double p_hypothesis;
    int h(h_number);
    //check terminal condition
    if(obsCount == 0) {
        if(toupper(obs_flavor) == 'C'){ 
            p_hypothesis = (h_prob[h] * pcherry[h]/0.5);
            h_prob[h] = p_hypothesis;
        }
        if(toupper(obs_flavor) == 'L') {
            p_hypothesis = (h_prob[h] * (1 - pcherry[h])/0.5);
            h_prob[h] = p_hypothesis;
        }
    } 
    
}

int main(int argc, char* argv[]){
    //check number of arguments
    if(argc != 2){
         cout << "Incorrect number of arguments\n"; 
         exit(1);
    }
    
    //get observations
    string observations(argv[1]);
    double totalObs = observations.size();
    
    //store prior probablilities
    vector<double> h_prior{0.1, 0.2, 0.4, 0.2, 0.1};
    vector<double> p_cherry{1, 0.75, 0.5, 0.25, 0};
    
    for(int i = 0; i < totalObs; i++){
        pHypothesis(i, 'c',  0, h_prior, p_cherry); 
    }

    return 0;
}

