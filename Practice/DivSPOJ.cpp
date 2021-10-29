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
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define MAXN   			  1000009

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

int d(int n) {
	vector<int> vec;
	while(n>1) {
		int val = spf[n];
		int cnt = 0;
		while(n % val == 0) {
			n /= val;
			cnt++;
		}
		vec.pb(cnt+1);
	}
	int ans = 1;
	for(int num: vec) ans *= num;
	return ans;
}

bool req(int n) {
	vector<int> pf;
	while(n>1) {
		pf.pb(spf[n]);
		if(pf.size() > 2) return false;
		n /= spf[n];
	}
	if(pf.size()==2 and pf[0] != pf[1]) return true;
	return false;
}

void solve() {
    int n = 1000000;
    int cnt = 0;
    rep(i, 1, n+1) {
    	int val = d(i);
    	if(req(val) and cnt==8) {
    		cnt = 0;
    		printf("%d\n", i);
    	}
    	else if(req(val)) cnt++;
    }
}

signed main(){
    sieve();
    solve();
    return 0;
}