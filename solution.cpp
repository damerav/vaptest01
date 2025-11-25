#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solution(vector<int> A, int K) {
        if (A.empty()) return;

        // Find the maximum width needed for any number
        int maxWidth = 0;
        for (int num : A) {
            maxWidth = max(maxWidth, (int)to_string(num).length());
        }

        int N = A.size();
        string result;

        int idx = 0;
        while (idx < N) {
            int numCols = min(K, N - idx);

            // Create top border for first row only
            if (idx == 0) {
                result += createBorder(numCols, maxWidth) + "\n";
            }

            // Create content row
            result += "|";
            for (int i = 0; i < numCols; i++) {
                result += formatNumber(A[idx + i], maxWidth) + "|";
            }
            result += "\n";

            // Create bottom border (serves as top border for next row)
            result += createBorder(numCols, maxWidth);
            if (idx + numCols < N) {
                result += "\n";
            }

            idx += numCols;
        }

        // Print the result
        cout << result;
    }

private:
    string createBorder(int numCols, int cellWidth) {
        string border;
        for (int i = 0; i < numCols; i++) {
            border += "+" + string(cellWidth, '-');
        }
        border += "+";
        return border;
    }

    string formatNumber(int num, int width) {
        string numStr = to_string(num);
        int padding = width - numStr.length();
        return string(padding, ' ') + numStr;
    }
};

// Test driver
int main() {
    Solution sol;

    cout << "Test 1: A = [4, 35, 80, 123, 12345, 44, 8, 5], K = 10" << endl;
    sol.solution({4, 35, 80, 123, 12345, 44, 8, 5}, 10);
    cout << "\n\n";

    cout << "Test 2: A = [4, 35, 80, 123, 12345, 44, 8, 5, 24, 3], K = 4" << endl;
    sol.solution({4, 35, 80, 123, 12345, 44, 8, 5, 24, 3}, 4);
    cout << "\n\n";

    cout << "Test 3: A = [4, 35, 80, 123, 12345, 44, 8, 5, 24, 3, 22, 35], K = 4" << endl;
    sol.solution({4, 35, 80, 123, 12345, 44, 8, 5, 24, 3, 22, 35}, 4);
    cout << "\n\n";

    cout << "Test 4: A = [4], K = 1" << endl;
    sol.solution({4}, 1);
    cout << "\n\n";

    return 0;
}
