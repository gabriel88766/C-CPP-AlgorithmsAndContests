#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
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
    vector<pair<int, vector<int>>> gr;
    for(int i=0;i<m;i++){
        pair<int, vector<int>> p;
        int k;
        cin >> k >> p.first;
        for(int j=0;j<k;j++){
            int aux;
            cin >> aux;
            p.second.push_back(aux);
        }
        gr.push_back(p);
    }
    init();
    sort(gr.begin(), gr.end(), [&](pair<int, vector<int>> &u, pair<int, vector<int>> &v){
        return u.first < v.first;
    });
    ll ttw = 0;
    int cnt = 0;
    for(auto [w, v] : gr){
        for(int i=1;i<v.size();i++){
            if(get(v[i]) != get(v[0])){
                cnt++;
                unite(v[i], v[0]);
                ttw += w;
            }
        }
    }
    assert(cnt <= n-1);
    if(cnt == n-1) cout << ttw << "\n";
    else cout << "-1\n";
}
