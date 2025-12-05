#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct par{
  long long first;         
  long long second;  
  bool operator<(const par &other) const {
        return first < other.first;
  }
  string to_string() const {
        return "{ " + std::to_string(first) + ", " + std::to_string(second) + " }";
  }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string line;
	vector<par> fresh;

	while(getline(cin, line)) {
		if(line.empty()) break;
        else{
            size_t pos = line.find('-');
            long long a = stoll(line.substr(0, pos));
            long long b = stoll(line.substr(pos + 1));
            fresh.push_back({a,b});
        }
	}
	sort(fresh.begin(), fresh.end());
    vector<par> merged;
    
    for (par &p : fresh) {
        if (merged.empty() || p.first > merged.back().second) {
            merged.push_back(p);
        } else {
            merged.back().second = max(merged.back().second, p.second);
        }
    }
	long long sol = 0;
	for(par p : merged){
	    sol += p.second - p.first + 1; 
	}
	
	cout << sol;
    
	return 0;
}