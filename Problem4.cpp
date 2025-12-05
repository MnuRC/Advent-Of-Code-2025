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

int posady(int i, int j){
    int c = 0;
    int rows = input.size();
    int cols = input[j].size();
    
    if (j+1 < cols && input[i][j+1] == '@') c++;
    if (j-1 >= 0 && input[i][j-1] == '@') c++;
    if (i+1 < rows && input[i+1][j] == '@') c++;
    if (i+1 < rows && j+1 < cols && input[i+1][j+1] == '@') c++;
    if (i+1 < rows && j-1 >= 0 && input[i+1][j-1] == '@') c++;
    if (i-1 >= 0 && input[i-1][j] == '@') c++;
    if (i-1 >= 0 && j+1 < cols && input[i-1][j+1] == '@') c++;
    if (i-1 >= 0 && j-1 >= 0 && input[i-1][j-1] == '@') c++;

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
    
    for(int i = 0; i < input.size(); i++){
        //como las lineas son de longitud constante no haria falta calcular length()
        int l = input[i].size();
        for(int j = 0; j < l; j++){
            if(input[i][j] == '@'){
                if(posady(i, j) < 4){
                    cont++;
                    res[i][j] = 'x';
                }
            }
        }
    }
    
    cout << "resultado:\n" << res;
    cout << "contador: " << cont;
    
    return 0;
}