#include <iostream>
#include <vector>
#include <cmath>

// calculate mean of a vector
double calculateMean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// calculate linear regression coefficients
std::pair<double, double> calculateLinearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    double x_mean = calculateMean(x);
    double y_mean = calculateMean(y);

    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += std::pow((x[i] - x_mean), 2);
    }

    double slope = numerator / denominator;
    double intercept = y_mean - (slope * x_mean);

    return std::make_pair(slope, intercept);
}

int main() {
    // data
    std::vector<double> x = {125, 150, 175};
    std::vector<double> y = {63, 75.6, 88.2};

    // applying linear regression coefficients
    std::pair<double, double> regressionCoefficients = calculateLinearRegression(x, y);
    double slope = regressionCoefficients.first;
    double intercept = regressionCoefficients.second;

    std::cout << "The linear function for the line of best fit is: "
              << "Experimental Weight = " << slope << " * Coil Turns + " << intercept << std::endl;

    return 0;
}
