#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 4005;

int p[N], sz[N];

void init(int n){
    for(int i=1;i<n;i++) {p[i] = i; sz[i] = 1;}
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
    //coding
    //L1 == 1,2, L2 == 3,4, ..... Ln = 2n-1, 2n
    //C1 == 2n+1, 2n+2, ....  Cn = 4n-1, 4n
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(4*n+1);
        vector<vector<char>> u(n+1, vector<char>(n+1));
        vector<vector<char>> v(n+1, vector<char>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> u[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> v[i][j];
                if(u[i][j] != v[i][j]){
                    //So Li ^ Cj = 1
                    //Li <-> ~Cj & ~Li <-> Cj
                    unite(2*i, 2*(n+j)-1);
                    unite(2*i-1, 2*(n+j));
                }else{
                    //So Li ^ Cj = 0
                    //~Li <-> ~Cj & Li <-> Cj
                    unite(2*i, 2*(n+j));
                    unite(2*i-1, 2*(n+j)-1);
                }
            }
        }
        bool ok = true;
        for(int i=1;i<=2*n;i++){
            if(get(2*i) == get(2*i-1)) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        
    }
}
