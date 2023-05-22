#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 10;   
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
    vector<string> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    init();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt = 0;
            for(int k=0;k<m;k++){
                if(v[i][k] != v[j][k]) cnt++;
            }
            if(cnt == 1) unite(i, j);
        }
    }
    int x = get(1);
    bool ok = true;
    for(int i=2;i<=n;i++){
        if(x != get(i)) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";

}
