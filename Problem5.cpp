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
	
	long long cont = 0;
    while(getline(cin, line)){
        long long x = stoll(line);
        
        int l = 0, r = merged.size() - 1;
        bool found = false;

        while (l <= r) {
            int m = (l + r) / 2;
            if (x < merged[m].first) {
                r = m - 1;
            } else if (x > merged[m].second) {
                l = m + 1;
            } else {
                found = true;
                break;
            }
        }
        if(found) cont++;
    }
    cout << cont;
	return 0;
}