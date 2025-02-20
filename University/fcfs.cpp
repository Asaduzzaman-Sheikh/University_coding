#include <iostream>
using namespace std;

int main()
{
    cout << "=========================================\n";
    int process;
    cout << "How many processes? ";
    cin >> process;
    
    int BT[process], AT[process], TAT[process], CT[process], WT[process], PID[process];
    int i, j, temp = 0;
    float sum_tat = 0.0, sum_wt = 0.0;
    
    // Initializing Process IDs
    for(i = 0; i < process; i++) {
        PID[i] = i + 1;  // P1, P2, P3, ...
    }

    cout << "_____________Provide your processes' Burst Time (B.T)_______________\n\n";
    for(i = 0; i < process; i++){
        cout << "B.T(P" << i+1 << ")---> ";
        cin >> BT[i];
    }

    cout << "_____________Provide Arrival Time (A.T.)_________________\n\n";
    for(i = 0; i < process; i++){
        cout << "A.T(P" << i+1 << ")---> ";
        cin >> AT[i];
    }

    // Unsorted version
    cout << "\nUnsorted version of A.T. and B.T.\n";
    cout << "Process | A.T. | B.T.\n";
    for(i = 0; i < process; i++){
        cout << "   P(" << PID[i] << ") |  " << AT[i] << "   |  " << BT[i] << endl;
    }

    // Sorting based on Arrival Time (A.T.)
    for (i = 0; i < process - 1; i++) {
        for (j = 0; j < process - 1 - i; j++) { 
            if (AT[j] > AT[j + 1]) {
                // Swap AT
                temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                // Swap BT
                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                // Swap Process IDs
                temp = PID[j];
                PID[j] = PID[j + 1];
                PID[j + 1] = temp;
            }
        }
    }

    // Sorted version
    cout << "\n==========Sorted Version based on A.T.==========\n";
    cout << "Process | A.T.| B.T.\n";
    for(i = 0; i < process; i++){
        cout << " P(" << PID[i] << ")   |  " << AT[i] << "  |  " << BT[i] << endl;
    }

    // Calculate Completion Time (CT)
    int sum = BT[0];
    CT[0] = sum;
    for (i = 1; i < process; i++) {
        sum += BT[i];
        CT[i] = sum;
    }

    // Calculate Turnaround Time (TAT) = CT - AT
    for (i = 0; i < process; i++) {
        TAT[i] = CT[i] - AT[i];
    }

    // Calculate Waiting Time (WT) = TAT - BT
    for (i = 0; i < process; i++) {
        WT[i] = TAT[i] - BT[i];
    }

    // Calculate total TAT and WT
    for (i = 0; i < process; i++) {
        sum_tat += TAT[i];
        sum_wt += WT[i];
    }

    // Display results
    cout << "\n*******************************************\n";
    cout << "Process | A.T.| B.T. | C.T. | T.A.T. | W.T.\n";
    for(i = 0; i < process; i++){
        cout << "  P(" << PID[i] << ")  |  " << AT[i] << "  |  " << BT[i] << "   |  " << CT[i] << "   |  " << TAT[i] << "     | " << WT[i] << endl;
        cout << "-----------------------------------------\n";
    }
    cout << "*******************************************\n";

    cout << "\nAverage TAT = " << (sum_tat / process) << endl;
    cout << "Average WT = " << (sum_wt / process) << endl;

    return 0;
}
