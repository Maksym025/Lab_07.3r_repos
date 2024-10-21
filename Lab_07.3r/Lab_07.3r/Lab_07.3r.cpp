#include <iostream>
using namespace std;

void FindEqualRowsAndColumns(int** a, const int n, int k = 0, int j = 0, bool equal = true);
int SumRowsWithNegative(int** a, const int n, int i = 0, int j = 0, bool hasNegative = false, int sum = 0);

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    FindEqualRowsAndColumns(a, n);
    int sum = SumRowsWithNegative(a, n);
    cout << "Sum of elements in rows with at least one negative element: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


void FindEqualRowsAndColumns(int** a, const int n, int k, int j, bool equal) {
    if (k >= n) return;

    if (j < n) {
   
        if (a[k][j] != a[j][k]) {
            equal = false;
        }

        FindEqualRowsAndColumns(a, n, k, j + 1, equal);
    }
    else {
      
        if (equal) {
            cout << "Row " << k << " is equal to Column " << k << endl;
        }
        
        FindEqualRowsAndColumns(a, n, k + 1, 0, true);
    }
}


int SumRowsWithNegative(int** a, const int n, int i, int j, bool hasNegative, int sum) {
    if (i >= n) return sum;

    if (j < n) {
       
        if (a[i][j] < 0) {
            hasNegative = true;
        }
    
        return SumRowsWithNegative(a, n, i, j + 1, hasNegative, sum);
    }
    else {
      
        if (hasNegative) {
            for (int k = 0; k < n; k++) {
                sum += a[i][k];
            }
        }
   
        return SumRowsWithNegative(a, n, i + 1, 0, false, sum);
    }
}
