#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dg[N];
vector<int> cmp[N];

int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    init();
    for(int i=0;i<m;i++){
        int a,b;
        char c,d;
        cin >> a >> c >> b >> d;
        unite(a,b);
        dg[a]++, dg[b]++;
    }
    int cnt1 = 0, cnt2 = 0;

    set<int> ss;
    for(int i=1;i<=n;i++){
        cmp[get(i)].emplace_back(i);
        ss.insert(get(i));
    }
    cnt2 = ss.size();
    
    for(auto x: ss){
        bool ok = true;
        for(auto y : cmp[x]){
            if(dg[y] != 2) ok = false;
        }
        if(ok) cnt1++;
    }
    cout << cnt1 << " " << cnt2-cnt1;
}
