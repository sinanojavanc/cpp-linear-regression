#pragma once
#include <vector>
using namespace std;

double sigmoid(double x);

class Perceptron {
private:
    vector<float> weight;
    float bias;
    float learningrate;

public:
    Perceptron(int inputsize, float lr);
    ~Perceptron();

    bool predict(const vector<float>& inputs);
    void train(const vector<vector<float>>& inputs,
               const vector<int>& label,
               int epoch);
};
