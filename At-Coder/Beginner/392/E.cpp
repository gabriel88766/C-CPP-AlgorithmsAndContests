#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];
vector<tuple<int, int, int>> xe[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int c, int d, int cn){
    int a = get(c);
    int b = get(d);
    if(a == b){
        xe[a].push_back({cn, c, d});
        return;
    }
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    for(auto &x : xe[b]) xe[a].push_back(x);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        unite(a, b, i);
    }
    priority_queue<pair<int, int>> cmp;
    set<int> cmi;
    for(int i=1;i<=n;i++){
        if(!cmi.count(get(i))){
            cmp.push({xe[get(i)].size(), get(i)});
            cmi.insert(get(i));
        }
    }
    cout << cmp.size() - 1 << "\n";
    while(cmp.size() >= 2){
        auto [xxx, a] = cmp.top();
        cmp.pop();
        auto [yyy, b] = cmp.top();
        cmp.pop();
        auto [x, y, z] = xe[a].back();
        xe[a].pop_back();
        cout << x << " " << y << " " << b << "\n";
        unite(a, b, 0);
        cmp.push({xe[get(a)].size(), get(a)});
    }
}
