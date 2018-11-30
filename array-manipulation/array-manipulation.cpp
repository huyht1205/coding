#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    long arr[n];
    long max = 0;

    memset(arr, 0, sizeof(arr));

    for (size_t r = 0; r < queries.size(); r++)
    {
        int a = queries.at(r).at(0);
        int b = queries.at(r).at(1);
        int k = queries.at(r).at(2);

        for (int i = (a-1); i < b; i++)
        {
            arr[i] += k;
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
    }

    return max;
}

int main(int argc, char *argv[])
{
    if (nullptr == argv[1])
    {
        cout << "Usage: array-manipulation <input file>" << endl;
        return -1;
    }

    string inputFile(argv[1]);

    ifstream fin(inputFile);
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(fin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            fin >> queries[i][j];
        }

        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    cout << result << endl;
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
