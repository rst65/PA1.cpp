#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double exp_rand(double lambda) {
    double u = static_cast<double>(rand()) / RAND_MAX;
    return -log(1.0 - u) / lambda;}

int main() {
    const int num_processes = 1000;
    const double arrivalRate = 2.0;
    const double serviceTime = 1.0;

    cout << "Process ID\tArrival Time\tService Time" << endl;

    double currentTime = 0.0;

    for (int i = 1; i <= num_processes; ++i) {

        double arrivalTime = exp_rand(arrivalRate);
        currentTime += arrivalTime;
        double requestedserviceTime = exp_rand(1.0 / serviceTime);

        cout << i << "  \t\t" << currentTime << "  \t\t" << requestedserviceTime << endl;
    }

    double actual_Rate = num_processes / currentTime;
    double actual_Time = serviceTime;

    cout << "\n<Actual Average Arrival Rate: " << actual_Rate << " processes per second" << ", Actual Average Service Time: " << actual_Time << " seconds>" << std::endl;

    return 0;
}
