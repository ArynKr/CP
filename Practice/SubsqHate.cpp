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
    string s; cin >> s;
    int n = s.size();
    int f0 = -1, l0 = -1, f1 = -1, l1 = -1;
    rep(i, 0, n) {
    	if(s[i]=='0' and f0==-1) f0 = i;
    	else if(s[i]=='1' and f1==-1) f1 = i;
    }
    for(int i=n-1; i>=0; i--) {
    	if(s[i]=='0' and l0==-1) l0 = i;
    	else if(s[i]=='1' and l1==-1) l1 = i;
    }
    vi le0(n, 0), r0(n, 0), le1(n, 0), r1(n, 0);
    if(s[0]=='0') le0[0]++;
    else le1[0]++;
    rep(i, 1, n) {
    	le0[i] = le0[i-1];
    	le1[i] = le1[i-1];
    	if(s[i]=='0') le0[i]++;
    	else le1[i]++;
    }
    if(s[n-1]=='0') r0[n-1]++;
    else r1[n-1]++;
    for(int i=n-2; i>=0; i--) {
    	r0[i] = r0[i+1];
    	r1[i] = r1[i+1];
    	if(s[i]=='0') r0[i]++;
    	else r1[i]++;
    }
    debug(le0);
    debug(le1);
    debug(r0);
    debug(r1);
    int mn = INT_MAX;
    rep(i, 0, n) {
    	int ans1 = le0[i] + r1[i+1];
    	int ans2 = le1[i] + r0[i+1];
    	if(i==n-1) {
    		ans1 = le0[i];
    		ans2 = le1[i];	
    	}
    	mn = min({mn, ans1, ans2});
    }
    cout << mn << endl;
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