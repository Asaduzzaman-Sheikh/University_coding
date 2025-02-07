#include <iostream>
using namespace std;

int main() {
    cout << "========Size of the Array============" << endl;
    int size;
    cin >> size;

    int A[size], B[size], C[size], i, cumulative_sum = 0, sum_of_A = 0, sum_of_B = 0, sum_of_C = 0;
    cout << "========Array Elements===============" << endl;
    for(i = 0; i < size; i++){
        cin >> A[i];
    }
    // Implementation of Array B...
    cumulative_sum = A[0];
    B[0] = cumulative_sum;
    for(i = 1; i < size; i++){
        cumulative_sum = cumulative_sum + A[i];
        B[i] = cumulative_sum;
    }
    // Implementation of Array C...
    for(i = 0; i < size; i++){
        C[i] = B[i] - A[i];
    }

    // Printing all three arrays...
    cout << "========Three Arrays=================" << endl;
    for(i = 0; i < size; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    for(i = 0; i < size; i++){
        cout << B[i] << " ";
    }
    cout << endl;
    for(i = 0; i < size; i++){
        cout << C[i] << " ";
    }
    // Calculating Sum of each Array...
    for(i = 0; i < size; i++){
        sum_of_A = sum_of_A + A[i];
    }

    for(i = 0; i < size; i++){
        sum_of_B = sum_of_B + B[i];
    }

    for(i = 0; i < size; i++){
        sum_of_C = sum_of_C + C[i];
    }
    cout << endl;
    cout << "========Average of each Array========" << endl;
    cout << "Avearge of Array A = " << sum_of_A/size << endl;
    cout << "Avearge of Array B = " << sum_of_B/size << endl;
    cout << "Avearge of Array C = " << sum_of_C/size << endl;


}
