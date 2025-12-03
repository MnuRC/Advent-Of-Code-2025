#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

long long sol = 0;


bool es_repetitivo(long long n) {
    string s = to_string(n);
    int len = s.length();
    if (len < 2) return false;
    for (int len_patron = 1; len_patron <= len / 2; len_patron++) {
        if (len % len_patron == 0) {
            string sub = s.substr(0, len_patron);
            string reconstruido = "";
            int repeticiones = len / len_patron;

            for (int k = 0; k < repeticiones; k++) {
                reconstruido += sub;
            }
            if (reconstruido == s) {
                return true; 
            }
        }
    }
    return false;
}

void find_range(long long x, long long y){
    for(long long i = x; i <= y; i++){
        if(es_repetitivo(i)) {
            sol = sol + i;
        }                
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);
    stringstream ss(line);
    string pair_string;

    while (getline(ss, pair_string, ',')) {
        size_t dash = pair_string.find('-');

        long long x = stoll(pair_string.substr(0, dash));
        long long y = stoll(pair_string.substr(dash + 1));
        find_range(x, y);
    }
    
    cout << "La solucion es: " << sol << "\n";
    return 0;
}