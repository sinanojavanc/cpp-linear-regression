#include <iostream>
#include <vector>
#include "perceptron.h"
using namespace std;

int main(){

    Perceptron nuron(2,0.1f);
    vector<vector<float>> inputs = {
        {0,0},  {0,1},
        {1,0},  
    };
    vector<int> label = {
        0,  0,
        1,  
    };

    nuron.train(inputs,label,10);
    cout << "\n (0,0): (P,R) (" << (nuron.predict({0,0}) ? 1 : 0) <<  " , " << label[0] << ")";
    cout << "\n (0,1): (P,R) (" << (nuron.predict({0,1}) ? 1 : 0) <<  " , " << label[1] << ")";
    cout << "\n (1,0): (P,R) (" << (nuron.predict({1,0}) ? 1 : 0) <<  " , " << label[2] << ")";
    cout << "\n (1,1): (P,R) (" << (nuron.predict({1,1}) ? 1 : 0) <<  " , "  << ")";

    cin.get();
    return 0;
}