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
        weight.assign(inputsize, 0.0f);
        bias = 0.0f;
    }
    ~Perceptron(){ weight.clear(); }

    bool predict(const vector<float>& inputs){
        float sum = bias;
        for (int i = 0; i < inputs.size(); i++)
            sum += weight[i] * inputs[i];
        
        return sum >= 0;
    }

    void train(const vector<vector<float>>& inputs,
               const vector<int>& label,
                int epoch)
    {   // need to normalize the inpuuts
        for (int k = 0; k < epoch; k++){
            double mse = 0.0;

            for (int i = 0; i < inputs.size(); i++){
                int prediction = predict(inputs[i]);
                int error = label[i] - prediction;
                mse += error * error; // mse sum

                // need to be curve lr
                // update weight
                for (int j = 0; j < weight.size(); j++){
                    weight[j] += learningrate * error * inputs[i][j];
                }
                bias += learningrate * error;
            }
            // calculate the average and print for each epoch
            mse /= inputs.size(); 
            cout << "Epoch " << k+1 << " MSE: " << mse << endl;
        }
    }

};

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
    return 0;
}