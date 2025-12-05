#include<bits/stdc++.h>
#include<string>
using namespace std;
using ll = long long;

/*

ll convert(const string &s) {
    ll res = 0;
    for (char a : s) {
        int tt = a - '0';
        res *= 10;
        res += tt;
    }
    return res;
}

int main() {
    string line;
    ll total = 0;
    const int K = 12;

    while (getline(cin, line)) {
        if (line.empty()) continue;   // skip empty lines

        int n = line.size();
        if (n < K) {
            // Not enough digits for 12-length subsequence; skip or handle as you like
            continue;
        }

        string best;
        int start = 0;  // where we can start searching for the next digit

        for (int t = 0; t < K; t++) {
            int maxPos = start;
            int limit = n - (K - t);  // last index we can start from

            // Find the max digit between [start, limit]
            for (int j = start + 1; j <= limit; j++) {
                if (line[j] > line[maxPos]) {
                    maxPos = j;
                    if (line[maxPos] == '9') break;  // can't beat 9
                }
            }

            best.push_back(line[maxPos]);
            start = maxPos + 1;  // next digit must come after this one
        }

        cout << best << '\n';
        total += convert(best);
    }

    cout << total;
    return 0;
}

*/

// ========================== PART 2 ======================================

ll convert(string s)
{
	ll res =0 ;
	//reverse(s.begin() , s.end());
	
	for(auto& a: s)
	{
		int tt = a-'0';
		res*=10;
		res += tt;
	}
	
	return res;
}
int main() 
{
    string input = "";
    string line;
    ll count = 0;
    
    
    while (getline(cin, line)) 
    {
        
        //if (line.empty()) break;
        
        input += line;
        count++;
    }
    
	ll single = input.length() / count;
	ll res = 0;
	
	for(int i =0 ; i< count ; i++)
	{
		int start = i*single;
		int loop = single - 12;
		string curr = input.substr(start+loop,12 );
		
		int seq = start;
		
		for( int t = 0 ; t < 12 ; t++)
		{
			
			for(int j = seq; j < start+loop+t ; j++)
			{
				//string curr = temp;
				
				if(input[j] > curr[t])
				{
					seq = j+1;
					curr[t] = input[j];
					
					if(input[j] == '9') break;
				}
				
			}
			
		}
		
		cout<<curr<<endl;
		
		res += convert(curr);
		
	}
	
	cout<<res;
	
	return 0;

}


// =================== PART 1 ===============================


int main() 
{
    string input = "";
    string line;
    ll count = 0;
    
    
    while (getline(cin, line)) 
    {
        
        //if (line.empty()) break;
        
        input += line;
        count++;
    }
    
    ll size_single = input.length() / count;
    
    ll res = 0;
    
    for(int j=0 ; j<count ; j++)
    {
    	int x = j*size_single;
    	ll f = input[x] - '0';
    	ll s = input[x+1] -'0';
    	
    	for(int i=1; i < size_single ; i++)
    	{
    		if((input[x+i] - '0') > f && i< size_single-1)
    		{
    			f = input[x+i] - '0';
    			s = input[x+i+1] - '0';
    			continue;
    		}
    		if((input[x+i] - '0') > s)
    		{
    			s = input[x+i] - '0';
    		}
    		
    	}
    	
    	//cout<<f<<" "<<s<<endl;
    	
    	res += ((f*10) + s);
    }
    
    cout<<res;
    //cout<<count<<" "<<size_single;
	return 0;
}