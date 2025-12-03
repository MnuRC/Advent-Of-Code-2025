 #include <iostream>
#include <string>
#include <sstream>

using namespace std;
long long sol = 0;

void find_range(long long x, long long y){
    for(long long i = x; i <= y; i++){
        string s = to_string(i);
        if(s.length() % 2 == 0) {
            string p1 = s.substr(0, s.length()/2);
            string p2 = s.substr(s.length()/2);
            if(p1 == p2){
                sol = sol + i;
            }
        }                
    }
}
int main() {
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
} 
