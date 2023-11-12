#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N];
ll dr[N];
vector<int> cmp[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i;  dr[i] = 0; cmp[i].push_back(i);}
}

void unite(int a, int b, ll c){
    int xa = p[a];
    int xb = p[b];
    if(cmp[xa].size() < cmp[xb].size()){
         swap(xa,xb);
         swap(a, b);
         c = -c;
    }
    p[xb] = xa;
    dr[xb] = dr[a] + c - dr[b]; 
    for(auto x : cmp[xb]){
        if(x != xb) dr[x] = dr[xb] + dr[x];
        p[x] = xa;
        cmp[xa].push_back(x);
    }
}

ll query(int a, int b){
    return dr[b] - dr[a];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    set<int> s;
    init();
    for(int i=1;i<=q;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if(p[a] != p[b]){
            unite(a, b, c);
            s.insert(i);
        }else{
            if(query(a, b) == c) s.insert(i);
        }
        
    }
    for(auto x : s) cout << x << " ";
}
