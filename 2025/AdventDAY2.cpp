#include<bits/stdc++.h>
using namespace std;
using ll = long long;


bool isRepPattern(string s) 
{
    int n = s.length();
    
    for (int len = 1; len <= n / 2; len++) 
    {
        if (n % len == 0) 
        {
            int repeats = n / len;
            string pattern = s.substr(0, len);
            bool matches = true;
            
            for (int i = 1; i < repeats; i++) 
            {
                if (s.substr(i * len, len) != pattern) 
                {
                    matches = false;
                    break;
                }
            }
            if (matches && repeats >= 2) 
            {
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    string input = "";
    string line;
    
    while (getline(cin, line)) 
    {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        line.erase(remove(line.begin(), line.end(), '\t'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        
        if (line.empty()) break;
        input += line;
    }
    
    ll total = 0;
    stringstream ss(input);
    string range;
    
    while (getline(ss, range, ',')) 
    {
        if (range.empty()) continue;
        
        size_t dashPos = range.find('-');

        ll start = stoll( range.substr(0, dashPos ));
        ll end = stoll(range.substr(dashPos + 1));
        
        for (ll i = start; i <= end; i++) 
        {
            string s = to_string(i);

            if (isRepPattern(s)) 
            {
                total += i;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}