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


#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))


void googleFormat(){
  static int tno = 1;
  cout << "Case #" <<tno++ <<": ";
}

#ifdef ARYN
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
void _print(long x) {cerr << x;}
void _print(unsigned x) {cerr << x;}
void _print(unsigned long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(const char *x) {cerr << '\"' << x << '\"';}
void _print(const string &x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;


const int N=5e5+5;

void solve() {
  int n; cin >> n;
  vector<pii> arr(n);
  int xsum=0, ysum=0;
  rep(i, 0, n) cin >> arr[i].ff >> arr[i].ss;
  rep(i, 0, n) {
  	xsum += arr[i].ff;
  	ysum += arr[i].ss;
  }
  int x = xsum/n, y = ysum/n;
  // cout << x << " " << y << endl;

  set<pii> points;
  int tlx, tly, brx, bry;
  tlx = x-2, brx = x+2;
  tly = y-2, bry = y+2;
  for(int i=tlx; i<= brx; i++) {
  	for(int j=tly; j<=bry; j++) {
  		points.insert({i, j});
  	}
  }
  // debug(points);
  vector<int> dis;
  int mn = INT_MAX;
  for(auto p: points) {
  	int dist=0;
  	rep(i, 0, n) {
  		dist += abs(arr[i].ff - p.ff) + abs(arr[i].ss - p.ss);
  	}
  	mn = min(mn, dist);
  	dis.pb(dist);
  }
  debug(dis);
  int cnt=0;
  rep(i, 0, dis.size()) {
  	if(dis[i]==mn) {
  		cnt++;
  	}
  }
  cout << cnt << endl;
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef ARYN
  freopen("D:/CP/Input.txt", "r", stdin);
  freopen("D:/CP/Output.txt", "w", stdout);
  freopen("D:/CP/Error.txt", "w", stderr);
  #endif
  int t = 1;
  cin >> t;
  while(t--) solve();
  return 0;
}