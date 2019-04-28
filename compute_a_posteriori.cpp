#include "compute_a_posteriori.h"

using namespace std;
void update_h_prior(vector<double> &h_prob, vector<double> &pcherry, double &p_cherry, char obs);

int main(int argc, char* argv[]){
    //check number of arguments
    if(argc > 2){
         cout << "Incorrect number of arguments\n"; 
         exit(1);
    }
    string observations;
    //get observations
    if(argc == 2) observations.assign(argv[1], strlen(argv[1]));
    else observations = "";
    int totalObs = observations.size();
    
    //store prior probablilities
    vector<double> h_prior{0.1, 0.2, 0.4, 0.2, 0.1};
    vector<double> p_cherry_given_h{1, 0.75, 0.5, 0.25, 0};
    double p_cherry(0.5);
    for(auto c : observations){
        update_h_prior(h_prior, p_cherry_given_h, p_cherry, c);
    }
    //print to file
    FILE *fw;
    fw = fopen("results.txt", "w");
    fprintf(fw, "Observation sequence Q: %s \nLength of Q: %d\n\n", observations.c_str(), totalObs);
    for(int ix = 0; ix < h_prior.size(); ix++) fprintf(fw,"P(h%d|Q) = %f\n",(ix + 1), h_prior[ix]);
    fprintf(fw,"Probability that the next candy will be C, given Q: %f\n", p_cherry); 
    fprintf(fw,"Probability that the next candy will be L, given Q: %f\n", (1 - p_cherry)); 
    
    return 0;
}

void update_h_prior(vector<double> &h_prob, vector<double> &pcherry, double &p_cherry, char obs){
    int ix(0);
    if(toupper(obs) == 'C') for(ix = 0; ix < h_prob.size(); ix++) h_prob[ix] *= (pcherry[ix]/p_cherry);
    else for(ix = 0; ix < h_prob.size(); ix++) h_prob[ix] *= ((1 - pcherry[ix])/(1 - p_cherry));
    p_cherry = 0;
    for(int ix = 0; ix < h_prob.size(); ix++) p_cherry += (h_prob[ix]*pcherry[ix]);
}

