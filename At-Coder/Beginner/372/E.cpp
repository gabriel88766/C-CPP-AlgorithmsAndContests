#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N], sz[N];
vector<int> v[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1; v[i].push_back(i);}
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
    //merge v[a] v[b]
    vector<int> aux;
    int p0 = 0, p1 = 0, cnt = 0;
    while(p0 < v[a].size() && p1 < v[b].size() && aux.size() < 10){
        if(v[a][p0] > v[b][p1]) aux.push_back(v[a][p0++]);
        else aux.push_back(v[b][p1++]);
    }
    while(p0 < v[a].size() && aux.size() < 10) aux.push_back(v[a][p0++]);
    while(p1 < v[b].size() && aux.size() < 10) aux.push_back(v[b][p1++]);
    v[a] = aux;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t, u, k;
        cin >> t >> u >> k;
        if(t == 1) unite(u, k);
        else{
            if(v[get(u)].size() >= k) cout << v[get(u)][k-1] << "\n";
            else cout << "-1\n";
        }
    }
}
