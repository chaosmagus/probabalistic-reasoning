#include "compute_a_posteriori.h"

using namespace std;
void pHypothesis(int h_number, char obs_flavor, int obsCount, vector<double> &h_prob, vector<double> &pcherry);
double pFlavor(int h_number, char flavor, int obsCount, vector<double> &h_prob, vector<double> &pcherry);

//probability of next flavor P(F(j+1) = f(j+1) | F(j) = f(j))
double pFlavor(int h_number, char flavor, int obsCount, vector<double> &h_prob, vector<double> &pcherry){
    double p_flavor;
    //check terminal condition
    if(obsCount == 0) return 0.5;
    
    if(toupper(flavor) == 'C'){ 
        for(int i = 0; i < pcherry.size(); i++) p_flavor += (pcherry[i] * h_prob[i]);
    }
    if(toupper(flavor) == 'L') {
        for(int i = 0; i < pcherry.size(); i++) p_flavor += ((1 - pcherry[i]) * h_prob[i]);
    }
    
    return p_flavor;    
} 

//probability of hypothesis: P(h | FLavor = flavor)
void pHypothesis(int h_number, char obs_flavor, int obsCount, vector<double> &h_prob, vector<double> &pcherry){
    double p_hypothesis;
    int h(h_number);
    //check terminal condition
   // if(obsCount == 0) {
        if(toupper(obs_flavor) == 'C'){ 
           p_hypothesis = (h_prob[h] * pcherry[h]/pFlavor(h_number, obs_flavor, obsCount, h_prob, pcherry));
            h_prob[h] = p_hypothesis;
        }
        if(toupper(obs_flavor) == 'L') {
            p_hypothesis = (h_prob[h] * (1 - pcherry[h])/pFlavor(h_number, obs_flavor, obsCount, h_prob, pcherry));
            h_prob[h] = p_hypothesis;
        }
    //} 
    
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
   int j(0);
    for(auto c : observations){ 
        for(int i = 0; i < 5; i++){
            pHypothesis(i, c, j, h_prior, p_cherry); 
        }
        cout << "For observation " << j << " " << c << endl;     
        for(auto d : h_prior) cout << "d: "  << d << endl;
        j++;
    }
    
    return 0;
}

