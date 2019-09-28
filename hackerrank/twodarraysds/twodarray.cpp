#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max = -100;
    auto numrows = arr.size();
    auto numcols = arr[0].size();
    cout << "numrows is " << numrows << " numcols is " << numcols << endl;
    int col = 0;
    int row = 0;
    // Start from left corner and slide from top to bottom and left to right
    // As we move the hourglass, the topmost leftmost corner cannot go too much
    // to the right or to the bottom and still fit the hourglass, to the topmost
    // leftmost corner has to be at least two levels up and two positions left of the 
    // to be able to fit the hourglass
    for (col = 0 ; col < numcols - 2; col++) {
        for (row = 0 ; row < numrows - 2; row++) {
            int hg;
            cout << "col = " << col << " row = " << row << endl;
            // Now compute the value of the hourglass in this position
            // starting from left corner and offsetting the other row col values
            // that make the hourglass
            hg = arr[row][col] + arr[row][col+1] + arr[row][col+2]+arr[row+1][col+1]+\
            arr[row+2][col]+arr[row+2][col+1]+arr[row+2][col+2];
            cout << arr[row][col] << " " << arr[row][col+1] << " " <<  arr[row][col+2] << endl;
            cout << "  " << arr[row+1][col+1] << endl;
            cout << arr[row+2][col] << " " << arr[row+2][col+1] << " " << arr[row+2][col+2] << endl;
            if (hg > max) {
                max = hg;
            }
        }
    }
    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
