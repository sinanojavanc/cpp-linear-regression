#include <iostream>
#include <vector>
using namespace std;


class Perceptron {
private:
    vector<float> weight;
    float bias;
    float learningrate;

public:
    Perceptron(int inputsize,float lr){
        learningrate = lr;
        weight.resize(inputsize);
    }
    ~Perceptron(){ weight.clear(); }

    float predict(vector<float> inputs){
        float sum = bias;
        for (int i = 0; i < inputs.size(); i++)
            sum += weight[i] * inputs[i];
        
        return sum;
    }

    void train( vector<vector<float>> inputs,
                vector<int> label,
                int epoch)
    {
        for (int k = 0; k < epoch; k++){
            for (int i = 0; i < inputs.size(); i++){
                int prediction = predict(inputs[i]);
                int error = label[i] - prediction;

                // update weight
                for (int j = 0; j < inputs.size(); j++){
                    weight[i] += learningrate * error * inputs[i][j];
                }
                bias += learningrate * error;
            }
        }
    }

};

int main(){

    Perceptron nuron(2,0.1);
    vector<vector<float>> inputs = {
        {0,0},  {0,1},
        {1,0},  {1,1},
    };
    vector<int> label = {
        0,  0,
        1,  1,
    }

    nuron.train(inputs,label,0.1);
    cout << "\n (0,0): (P,R) (" << norun.predict({0,0})
        <<  " , " << label[0];
    cout << "\n (0,1): (P,R) (" << norun.predict({0,1})
        <<  " , " << label[1];
    cout << "\n (1,0): (P,R) (" << norun.predict({1,0})
        <<  " , " << label[2];
    cout << "\n (1,1): (P,R) (" << norun.predict({1,1})
        <<  " , " << label[3];
    return 0;
}