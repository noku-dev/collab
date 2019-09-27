#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the equalizeArray function below.
// My logic is that the minimum number of deletions corresponds to the total 
// size of the array minus the removal of the least frequent numbers, so we are left
// with an array that only has the most frequent number in the array. Therefore I 
// use a map to get frequencies, and to avoid having to sort the map by value I 
// decided to keep track of the frequency of the most frequent number and which number 
// this is, updating this if I find a number that is more frequent.
int equalizeArray(vector<int> arr) {
    map<int,int> mp;
    int maxrepeated = -1;
    for (auto i : arr) {
        // Update the frequency of this number
        mp[i]++;
        if (mp[i] > maxrepeated) {
            // This is now the most repeated number
            maxrepeated = mp[i];
        }
    }
    return arr.size() - maxrepeated;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = equalizeArray(arr);

    fout << result << "\n";

    fout.close();

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
