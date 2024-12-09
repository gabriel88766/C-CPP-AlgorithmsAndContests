#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 500005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    v.resize(n+1);
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
         cin >> v[i];
         ps[i] = ps[i-1] + v[i];
    }
    build();
    for(int i=1;i<=n;i++){
        int l = i, r = i;
        while(true){
            ll cs = ps[r] - ps[l-1];
            ll nl = l, nr = r;
            for(int j=n/2;j>=1;j>>=1){
                while(nl - j >= 1 && query(nl-j, l-1) < cs) nl -= j;
                while(nr + j <= n && query(r+1, nr + j) < cs) nr += j;
            }
            if(nl != l || nr != r){
                r = nr;
                l = nl;
            }else break;
        }
        cout << ps[r] - ps[l-1] << " ";
    }
    cout << "\n";
}
