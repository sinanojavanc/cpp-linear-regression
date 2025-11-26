#include <iostream>
#include <vector>
#include "perceptron.h"
#include <cmath>
using namespace std;

double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}


Perceptron::Perceptron(int inputsize, float lr) {
    learningrate = lr;
    weight.assign(inputsize, 0.0f);
    bias = 0.0f;
}

Perceptron::~Perceptron() {
    weight.clear();
}

bool Perceptron::predict(const vector<float>& inputs) {
    float sum = bias;
    for (int i = 0; i < inputs.size(); i++)
        sum += weight[i] * inputs[i];

    return sum >= 0;
}

void Perceptron::train(const vector<vector<float>>& inputs,
                       const vector<int>& label,
                       int epoch)                   // need to normalize the inpuuts
{
    for (int k = 0; k < epoch; k++) {
        double mse = 0.0;
        double lr  = learningrate * epoch; // curve lr 

        for (int i = 0; i < inputs.size(); i++) {
            int prediction = predict(inputs[i]);
            int error = label[i] - prediction;
            mse += error * error;

            // update weight
            for (int j = 0; j < weight.size(); j++) {
                weight[j] += learningrate * error * inputs[i][j];
            }
            bias += learningrate * error;
        }

        lr -= learningrate; // curve lr 

        // calculate the average and print for each epoch
        mse /= inputs.size();
        cout << "Epoch " << k + 1 << " MSE: " << mse << endl;
    }
}
