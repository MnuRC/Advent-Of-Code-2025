#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> input;


ostream& operator<<(ostream& os, const vector<string>& v) {
    for (const auto& s : v) {
        os << s << '\n';
    }
    return os;
}

int posady(int i, int j, vector<string> in){
    int c = 0;
    int rows = in.size();
    int cols = in[j].size();
    
    if (j+1 < cols && in[i][j+1] == '@') c++;
    if (j-1 >= 0 && in[i][j-1] == '@') c++;
    if (i+1 < rows && in[i+1][j] == '@') c++;
    if (i+1 < rows && j+1 < cols && in[i+1][j+1] == '@') c++;
    if (i+1 < rows && j-1 >= 0 && in[i+1][j-1] == '@') c++;
    if (i-1 >= 0 && in[i-1][j] == '@') c++;
    if (i-1 >= 0 && j+1 < cols && in[i-1][j+1] == '@') c++;
    if (i-1 >= 0 && j-1 >= 0 && in[i-1][j-1] == '@') c++;

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line;
    
    while (getline(cin, line)){
        if(!line.empty()){
            input.push_back(line);
        }
    }
    
    int cont = 0;
    vector<string> res = input;
    int bo = true;
    while(bo){
        vector<string> res2 = res;
        for(int i = 0; i < res.size(); i++){
            int l = res[i].size();
            for(int j = 0; j < l; j++){
                if(res[i][j] == '@'){
                    if(posady(i, j, res) < 4){
                        cont++;
                        res[i][j] = 'x';
                    }
                }
            }
        }
        if(res2 == res) bo = false;
    }
    
    cout << "resultado:\n" << res;
    cout << "contador: " << cont;
    
    return 0;
}