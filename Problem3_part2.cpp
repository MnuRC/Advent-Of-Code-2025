#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve_bank(string s) {
    int n = s.length();
    int K = 12;

    int start_index = 0;
    string result_str = "";
    
    for(int k = 0; k < 12; k++){
        int end = n - (K - k);
        char max = '0';
        int max_i = start_index;
        for(int i = start_index; i <= end; i++){
            if(s[i] > max){
                max = s[i];
                max_i = i;
            }
        }
        result_str = result_str + max;
        start_index = max_i + 1;
    }
    
    return stoll(result_str);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total_joltage = 0; 

    while (getline(cin, line)) {
        if (line.empty()) break;
        total_joltage += solve_bank(line);
    }

    cout << "Joltage nuevo : " << total_joltage << "\n";
    return 0;
}