#include <iostream>
#include <cstdlib>
#include <ctime>

double rand_gen() {
    return static_cast<double>(rand()) / (RAND_MAX + 1.0);
}

double exp_rand(double lambda) {
    return (1.0 - rand_gen()) / lambda;
}

int main() {
    const int num_processes = 1000;
    const double arrivalRate = 2.0;
    const double serviceTime = 1.0;
      srand(static_cast<unsigned>(time(nullptr)));
    double currentTime = 0.0;

    for (int i = 1; i <= num_processes; ++i) {
double arrivalTime = exp_rand(arrivalRate);
        currentTime += arrivalTime;
double requestedServiceTime = exp_rand(1.0 / serviceTime);
        // Print process information
        std::cout << "< Process ID: " << i
                  << " Arrival time: " << currentTime
                  << " Requested service time: " << requestedServiceTime << ">"
                  << std::endl;
    }
