#include <iostream>
#include <cmath>    // For pow() function
#include <cstdlib>  // For stoi()
#include <limits>   // For numeric_limits

using namespace std;

// Function to compute the sum of the series
double computeSeries(int n) {
    double S = 0.0;
    
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i);  // Compute 1/(i^i)
        if (i % 2 == 0) {  // Alternate sign for even terms
            term = -term;
        }
        S += term;
    }
    
    return S;
}

int main(int argc, char *argv[]) {
    int n;

    // Check if command-line argument is provided
    if (argc > 1) {
        try {
            n = stoi(argv[1]);  // Convert argument to integer
            if (n <= 0) {
                throw invalid_argument("Negative number or zero entered.");
            }
        } catch (exception &e) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            return 1;
        }
    } else {
        // Prompt the user for input if no argument is provided
        cout << "Enter the number of terms (n): ";
        while (!(cin >> n) || n <= 0) {
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore incorrect input
        }
    }

    // Compute and display the result
    double result = computeSeries(n);
    cout << "The sum of the first " << n << " terms of the series is: " << result << endl;

    return 0;
}