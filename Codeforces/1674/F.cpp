#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;

ll bit[N][N];
int n, m, q;

ll sum(int a, int b){ // sum in range [1, 1] to [a, b]
    ll ans = 0;
    for(int i = a; i >= 1; i -= i & -i){
        for(int j = b; j >= 1; j -= j & -j){
            ans += bit[i][j];
        }
    }
    return ans;
}

void add(int a, int b, ll value){ //add value to position [a, b]
    for(int i = a; i <= n; i += i & -i){
        for(int j = b; j <= m; j += j & -j){
            bit[i][j] += value;
        }
    }
}

bool val[N][N];

void build(){
    for(int i=1;i<=n;i++) 
        for(int j=1; j<=m; j++)
            if(val[i][j]) add(i, j, 1);
}




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> q;
    int tt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            if(c == '*'){
                val[i][j] = true;
                tt++;
            }
        }
    }
    build();
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(val[a][b]){
            add(a, b, -1);
            tt--;
        } else{
            add(a, b, 1);
            tt++;
        } 
        val[a][b] ^= true;
        int cur = 0;
        int ttc = tt/n;
        int ttlr = tt - n*ttc;
        if(ttc != 0) cur = sum(n, ttc);
        if(ttlr != 0){
            cur += sum(ttlr, ttc+1);
            if(ttc != 0) cur -= sum(ttlr, ttc);
        }
        cout << tt-cur << "\n";
    }
}
