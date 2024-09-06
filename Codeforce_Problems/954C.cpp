#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int aaaaa = 0; aaaaa < t; aaaaa++) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> ind;
        string temp;
        cin >> temp;
        for (char c : temp) {
            ind.push_back(c - '1'); // Assuming indices start from 1 (adjust if needed)
        }
        sort(ind.begin(), ind.end());

        vector<char> c;
        cin >> temp;
        for (char chr : temp) {
            c.push_back(chr);
        }

        // Handle duplicate indices efficiently
        for (int i = ind.size() - 1; i >= 1; i--) {
            if (ind[i] == ind[i - 1]) {
                c.insert(c.begin() + i - 1, c.back());
                c.pop_back();
            }
        }

        // Apply characters based on sorted indices
        for (int i = 0; i < n; i++) {
            s[ind[i]] = c[i];
        }

        cout << s << endl;
    }

    return 0;
}
