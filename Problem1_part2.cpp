#include <iostream>
#include <string>

using namespace std;

int num = 50;

long long op(char key, int n){
    long long count = n / 100;
    int res = n % 100;

    if (key == 'L') {
        if (num > 0 && num - res <= 0) {
            count++;
        }
        num -= res;
        if (num < 0) num += 100;
    } else {
        if (num + res >= 100) {
            count++;
        }
        num = (num + res) % 100;
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;

    while (getline(cin, line)) {
        if(line.empty()) break;

        char key = line[0];
        long long val = stoll(line.substr(1));

        total += op(key, val);
    }
    
    cout << "La contrasenya es: " << total << "\n";
    return 0;
}