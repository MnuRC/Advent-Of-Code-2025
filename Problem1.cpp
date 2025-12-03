#include <iostream>
#include <string>

using namespace std;

int num = 50;

void op(char key, int n){
    int res = n % 100;

    if (key == 'L') {
        num -= res;
        if (num < 0) num += 100;
    } else {
        num = (num + res) % 100;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int total = 0;

    while (getline(cin, line)) {
        if(line.empty()) break;

        char key = line[0];
        long long val = stoll(line.substr(1));
        op(key, val);
        if(num == 0) total++;
    }
    
    cout << "La contrasenya es: " << total << "\n";
    return 0;
}