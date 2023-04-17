#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 1e3+5;

int bit[2][M][M];
int n;

int sum(int v, int a, int b){ // sum in range [1, 1] to [a, b]
    ll ans = 0;
    for(int i = a; i >= 1; i -= i & -i){
        for(int j = b; j >= 1; j -= j & -j){
            ans += bit[v][i][j];
        }
    }
    return ans;
}

void add(int v, int a, int b, ll value){ //add value to position [a, b]
    for(int i = a; i <= n; i += i & -i){
        for(int j = b; j <= n; j += j & -j){
            bit[v][i][j] += value;
        }
    }
}

void addSq(int v, int a, int b, int c, int d){
    if(b > d) return;
    if(a > c) return;
    add(v, a, b, 1);
    add(v, a, d+1, -1);
    add(v, c+1, b, -1);
    add(v, c+1, d+1, 1);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int N, K;
    cin >> N >> K;
    n = K+1;
    for(int i=1;i<=N;i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if(c == 'B') c = 1;
        else c = 0;
        //
        int d1 = x/K, d2 = y/K;
        int kx = (d1+d2)%2;
        c ^= kx;
        int mx, my;
        mx = x - (x/K)*K;
        my = y - (y/K)*K;
        addSq(c, 1, 1, mx+1, my+1);
        addSq(c^1, 1, my+2, mx+1, K);
        addSq(c^1, mx+2, 1, K, my+1);
        addSq(c, mx+2, my+2, K, K);
    }
    int ans = 0;
    for(int i=0;i<2;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=K;k++){
                ans = max(ans, sum(i, j, k));
            }
        }
    }
    cout << ans;
}
