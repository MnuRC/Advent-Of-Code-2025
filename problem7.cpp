
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long split_count = 0;
    string line;
    if(!getline(cin, line)) return 0;
    
    size_t s_pos = line.find('S');
    int len = line.length();
    vector<int> beams(len, 0);
    beams[s_pos] = 1;

    if(!getline(cin, line)) return 0;

    while(getline(cin, line)){
        if(line.empty()) break;
        for(int i = 0; i < len; i++){
            if(beams[i] == 1){
                if(line[i] == '^'){
                    split_count++;
                    beams[i] = 0;
                    if(i + 1 < len){
                        beams[i + 1] = 1;
                    }
                    if(i - 1 >= 0){
                        beams[i - 1] = 1;
                    }
                }
            }
        }
        if(!getline(cin, line)) return 0;
    }

    cout << split_count << "\n";
    return 0;
}