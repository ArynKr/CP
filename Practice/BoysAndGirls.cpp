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

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=5e5+5;

void solve() {
  int b, g; cin >> b >> g;
  string ans = "";
  string add;
  if(b>=g) {
  	add = "GB";
  	ans += 'B';
  	b--;
  } else {
  	add = "BG";
  	ans += 'G';
  	g--;
  }

  int mn = min(b, g);

  b -= mn;
  g -= mn;

  for(int i=0; i<mn; i++) ans += add;

 	while(b--) ans += 'B';
 	while(g--) ans += 'G';

 	cout << ans << endl;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  int t = 1;
  while(t--) solve();
  return 0;
}