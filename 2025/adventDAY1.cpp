#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll hits_during(int start, ll a, char dir) 
{
    
    int k;
    if (dir == 'R') {
        k = (100 - start) % 100;
    } else {
        k = start % 100;
    }
    if (k == 0) k = 100;          
    if (a < k) return 0;
    return 1 + (a - k) / 100;
}

int main() 
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    string token;
    int start = 50;         
    ll part1 = 0;       
    ll part2 = 0;       

    while (cin >> token) 
    {
        if (token.empty()) continue;
        char dir = token[0];
        ll a = stoll(token.substr(1));

        part2 += hits_during(start, a, dir);

        int rem = (int)(a % 100);
        if (dir == 'R') 
        {
            start = (start + rem) % 100;
        } else 
        {
            start = (start - rem) % 100;
            if (start < 0) start += 100;
        }

        if (start == 0) part1++;
    }

    cout << part1 << "\n";
    cout << part2 << "\n";
    return 0;
}



// int main() 
// {
//     //ios::sync_with_stdio(false);
//     //cin.tie(nullptr);

//     string token;
//     int start = 50;         
//     ll count = 0;      

//     while (cin >> token) 
//     {
//         if (token.empty()) continue;
//         char dir = token[0];
//         ll a = stoll(token.substr(1));

//         int rem = (int)(a % 100);
//         if (dir == 'R') 
//         {
//             start = (start + rem) % 100;
//             count+= rem
//         } else 
//         {
//             start = (start - rem) % 100;
//             if (start < 0) start += 100;
//             count -= rem;
//         }

//         if (start == 0) part1++;
//     }

//     cout << count << "\n";
//  
//     return 0;
// }
