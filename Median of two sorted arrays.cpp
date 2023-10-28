#include <iostream>
#include<vector>
using namespace std;
int GetMedian(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    if (n > m) {
        swap(A, B);
        swap(n, m);
    }
    int imin = 0, imax = n, halfLen = (n + m + 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = halfLen - i;
        if (i < n && B[j - 1] > A[i]) {
            imin = i + 1;
        }
        else if (i > 0 && A[i - 1] > B[j]) {
            imax = i - 1;
        }
        else {
            int maxOfLeft;
            if (i == 0) maxOfLeft = B[j - 1];
            else if (j == 0) maxOfLeft = A[i - 1];
            else maxOfLeft = max(A[i - 1], B[j - 1]);
            if ((n + m) % 2 == 1) return maxOfLeft;
            int minOfRight;
            if (i == n) minOfRight = B[j];
            else if (j == m) minOfRight = A[i];
            else minOfRight = min(A[i], B[j]);
            return (maxOfLeft + minOfRight) / 2.0;
        }
    }
    return 0.0;
}
int main()
{
    vector<int>A = { 1,12,15,26,38 };
    vector<int>B = { 2,13,17,30,45 };
    int medianValue = GetMedian(A, B);
    cout << "Median of the two sorted arrays is: " << medianValue << endl;
    system("pause");
}