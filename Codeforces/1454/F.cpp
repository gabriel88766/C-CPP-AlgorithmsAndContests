#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005, M = 20; // M >= log2(N)
int n;
int sp1[N][M], sp2[N][M];
int v[N];

void build(){
    for(int i=1;i<=n;i++) sp1[i][0] = sp2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            if((i + (1 << (j-1))) <= n) sp1[i][j] = min(sp1[i][j-1], sp1[i + (1 << (j-1))][j-1]), sp2[i][j] = max(sp2[i][j-1], sp2[i + (1 << (j-1))][j-1]);
            else sp1[i][j] = sp1[i][j-1], sp2[i][j] = sp2[i][j-1];
        }
    }
}

void destroy(){
    for(int i=1;i<=n;i++) sp1[i][0] = sp2[i][0] = 0;
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            sp1[i][j] = sp2[i][j] = 0;
        }
    }
}
ll query(int t, int a, int b){
    if(a == b) return sp1[a][0];
    int pot = 32 - __builtin_clz(b - a) - 1; 
    if(t == 1) return min(sp1[a][pot], sp1[b - (1 << pot) + 1][pot]);
    else return max(sp2[a][pot], sp2[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setpreciscion(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        map<int,int> fst, lst;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(!fst.count(v[i])) fst[v[i]] = i;
            lst[v[i]] = i;
        }
        build();
        bool ok = false;
        for(int i=2;i<n;i++){
            int l = fst[v[i]];
            int r = lst[v[i]];
            if(l == i || r == i) continue;
            if(query(2,1,l) != v[i] || query(2,r,n) != v[i]) continue;
            int ml = i, mr = i;
            for(int j=n;j>=1; j/=2){
                while(ml-j > l && query(1,ml-j, i) == v[i]) ml -= j;
                while(mr+j < r && query(1,i, mr+j) == v[i]) mr += j; 
            }
            if(query(2,1,ml-1) == query(1,ml, mr) && query(1,ml,mr) == query(2, mr+1, n)){
                ok = true;
                cout << "YES\n";
                cout << ml-1 << " " << mr-ml+1 << " " << n-mr << "\n";
                break;
            }
        }
        if(!ok) cout << "NO\n";
    }
}
