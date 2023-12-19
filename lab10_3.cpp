#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("score.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    
    vector<double> data;
    double value;
    while (inputFile >> value) {
        data.push_back(value);
    }

    inputFile.close();

    
    double sum = 0.0;
    for (double num : data) {
        sum += num;
    }
    double mean = sum / data.size();
    double sumOfSquares = 0.0;
    for (double num : data) {
        sumOfSquares += pow(num - mean, 2);
    }
    double standardDeviation = sqrt(sumOfSquares / data.size());

    
    cout << "Number of data = " << data.size() << endl;
    cout << setprecision(3);
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << standardDeviation << endl;

    return 0;
}
