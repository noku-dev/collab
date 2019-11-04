#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int count = 0;
    for (int i = q.size() - 1 ; i >= 0 ; i--) {
        // Array starts with 1 at index 0 in the array
        // If value at index i is greater than index + 3 positions 
        // it means we have moved more than 2 positions to the left
        // e.g. q[0] should be 1, and at most could have value 3 if 3 had moved 2 
        // positions to the left, os if q[0] is greater than (0 + 3) then it would
        // be too chaotic
        if (q[i] > (i + 3)) {
            cout << "Too chaotic" << endl;
            return;
        }
        // The max guarantees that we don't go into negative index
        // We try to go 2 positions to the left of us and see if those are values
        // that have moved (bribed) to the left of us, i.e. greater than the current
        // value at q[i]
        for (int j = max(0,q[i]-2); j < i ; j++) {
            if (q[j] > q[i]) {
                count++;
            }
        }

    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
