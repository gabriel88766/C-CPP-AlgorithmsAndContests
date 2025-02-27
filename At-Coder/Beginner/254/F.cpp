#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Sparse{
    const int M = 20; // M >= log2(N)
    int n;
    vector<vector<int>> sparse;
    Sparse(vector<int> v){
        n = v.size();
        sparse.resize(n, vector<int>(20));
        for(int i=0;i<n;i++) if(i+1 < n) sparse[i][0] = abs(v[i+1] - v[i]);
        for(int j = 1; j < M; j++){
            for(int i = 0; i < n; i ++){
                if((i + (1 << (j-1))) < n) sparse[i][j] = gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
                else sparse[i][j] = sparse[i][j-1];
            }
        }
    }

    ll query(int a, int b){
        if(a == b) return sparse[a][0]; //bug
        int pot = 32 - __builtin_clz(b - a) - 1; 
        return gcd(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    Sparse sp1(a), sp2(b);
    for(int i=0;i<q;i++){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        --x1,--x2,--y1,--y2;
        --x2, --y2;
        int ans = 0;
        if(x1 <= x2) ans = gcd(ans, sp1.query(x1,x2));
        if(y1 <= y2) ans = gcd(ans, sp2.query(y1,y2));
        ans = gcd(ans, a[x1] + b[y1]);
        cout << ans << "\n";
    }
}
