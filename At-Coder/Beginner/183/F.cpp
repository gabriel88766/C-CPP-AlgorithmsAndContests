#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N];
map<int, int> mp[N];
int cl[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; }
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(mp[a].size() < mp[b].size()) swap(a,b);
    p[b] = a;
    for(auto [k, v] : mp[b]){
        mp[a][k] += v;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    init();
    for(int i=1;i<=n;i++){
        cin >> cl[i];
        mp[i][cl[i]]++;
    }
    for(int i=1;i<=q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            unite(b, c);
        }else{
            cout << mp[get(b)][c] << "\n";
        }
    }
}
