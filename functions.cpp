#include <iostream>
#include <vector>
#include <cmath>


std::vector<double> calculate_m(double a, double r, const std::vector<double>& i, const std::vector<double>& j) {
    int dim = i.size();
    std::vector<double> m(dim);

    for (int t = 0; t < dim; t++) {
        m[t] = (a / r) * i[t] - sqrt(1 - pow(a / r, 2)) * j[t];
    }

    return m;
}

std::vector<double> calculate_n(double k, double h, double a, const std::vector<double>& i, const std::vector<double>& j) {
    int dim = i.size();
    std::vector<double> n(dim);

    for (int t = 0; t < dim; t++) {
        n[t] = (-k * h * sin(k * a) * i[t] + j[t]) / sqrt(1 + pow(k * h * sin(k * a), 2));
    }

    return n;
}

void print_vector(const std::vector<double>& v) {
    int dim = v.size();

    std::cout << "(";
    for (int t = 0; t < dim; t++) {
        std::cout << v[t];
        if (t < dim - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")" << std::endl;
}

int main() {
    double a, r, k, h;
    int dim;
    std::vector<double> i, j, m, n;

    std::cout << "Enter the value of a: ";
    std::cin >> a;

    std::cout << "Enter the value of r: ";
    std::cin >> r;

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::cout << "Enter the value of h: ";
    std::cin >> h;

    std::cout << "Enter the dimension of the vectors: ";
    std::cin >> dim;

    std::cout << "Enter the values of i: ";
    for (int t = 0; t < dim; t++) {
        double val;
        std::cin >> val;
        i.push_back(val);
    }

    std::cout << "Enter the values of j: ";
    for (int t = 0; t < dim; t++) {
        double val;
        std::cin >> val;
        j.push_back(val);
    }

    m = calculate_m(a, r, i, j);
    n = calculate_n(k, h, a, i, j);

    std::cout << "m = ";
    print_vector(m);

    std::cout << "n = ";
    print_vector(n);
    return 0;
}