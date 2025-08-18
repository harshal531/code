#include <bits/stdc++.h>
using namespace std;

// Function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2); // ceil(gap/2)
}

void mergeInPlace(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = nextGap(m + n);
    
    while (gap > 0) {
        int i = 0, j = gap;

        while (j < m + n) {
            // i in arr1, j in arr1
            if (i < m && j < m) {
                if (arr1[i] > arr1[j]) 
                    swap(arr1[i], arr1[j]);
            }
            // i in arr1, j in arr2
            else if (i < m && j >= m) {
                if (arr1[i] > arr2[j - m]) 
                    swap(arr1[i], arr2[j - m]);
            }
            // i in arr2, j in arr2
            else {
                if (arr2[i - m] > arr2[j - m]) 
                    swap(arr2[i - m], arr2[j - m]);
            }

            i++;
            j++;
        }
        gap = nextGap(gap);
    }
}

// -------------------
// 🔹 Driver code
// -------------------
int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergeInPlace(arr1, arr2, arr1.size(), arr2.size());

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
