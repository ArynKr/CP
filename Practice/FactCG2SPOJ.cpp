#include "bits/stdc++.h" 
using namespace std;
#define int               long long
#define vi                vector<int>
#define vvi               vector<vector<int>>
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define endl              '\n'
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define ff                first
#define ss                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define MAXN   			  10000009

int spf[MAXN];
 
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i) {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void solve() {
    int n=0;
    while(cin >> n) {
    	if(n==1) {
    		cout << 1 << endl;
    		continue;
		}
    	vector<int> fac;
    	while(n>1) {
    		fac.pb(spf[n]);
    		n /= spf[n];
    	}
    	// cout << n+2 << endl;
    	// for(auto val: fac) cout << val << endl;
    	int last = fac[fac.size()-1];
    	fac.pop_back();
    	cout << "1 x ";
    	for(auto val: fac) {
    		cout << val << " x ";
    	}
    	cout << last << endl;	
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef ARYN
    freopen("D:/CP/Input.txt", "r", stdin);
    freopen("D:/CP/Output.txt", "w", stdout);
    freopen("D:/CP/Error.txt", "w", stderr);
    #endif
    sieve();
	solve();
    return 0;
}