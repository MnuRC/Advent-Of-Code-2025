#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve_bank(string s) {
    int n = s.length();

    int max_jolt = 0;
    int d2 = s[n - 1] - '0';

    for (int i = n - 2; i >= 0; i--) {
        int d1 = s[i] - '0';
        int par = d1 * 10 + d2;
        if (par > max_jolt) max_jolt = par;

        if (d1 > d2) d2 = d1;
    }
    return max_jolt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;
        
    while (getline(cin, line)) {
        if (line.empty()) break;
        total += solve_bank(line);
    }

    cout << "Joltage : " << total << "\n";
    return 0;
}