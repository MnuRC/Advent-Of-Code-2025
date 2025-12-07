#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para swap

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if(!getline(cin, line)) return 0;
    
    size_t s_pos = line.find('S');
    int len = line.length();
    
    vector<long long> current_beams(len, 0);
    vector<long long> next_beams(len, 0);

    current_beams[s_pos] = 1;
    if(!getline(cin, line)) return 0;
    while(getline(cin, line)){
        if(line.empty()) break;

        fill(next_beams.begin(), next_beams.end(), 0);

        bool active = false;

        for(int i = 0; i < len; i++){
            if(current_beams[i] == 0) continue;

            active = true;
            long long count = current_beams[i];

            if(line[i] == '^'){
                if(i - 1 >= 0)  next_beams[i - 1] += count;
                if(i + 1 < len) next_beams[i + 1] += count;
            } else {
                next_beams[i] += count;
            }
        }
        vector<long long> temp = current_beams;
        current_beams = next_beams;
        next_beams = temp;
        if(!getline(cin, line)) return 0;
    }
    long long suma = 0;
    for (long long x : current_beams) suma += x;

    cout << "Universos paralelos: " << suma << "\n";
    
    return 0;
}