#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
int p[N], sz[N], v[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
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
    v[a] += v[b];
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    while(n || m){
        int ans = 0;
        init(n);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 1) unite(b, c);
            else{
                b = get(b);
                c = get(c);
                if(v[b] > v[c] && get(b) == get(1)) ans++;
                else if(v[b] < v[c] && get(c) == get(1)) ans++;
            }
        }


        cout << ans << "\n";
        cin >> n >> m;
    }
}
