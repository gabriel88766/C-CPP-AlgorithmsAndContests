#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;


//BIT 2D
const int M = 1e3+5;

ll bit[M][M];
ll v[M][M];
int n;

ll sum(int a, int b){ // sum in range [1, 1] to [a, b]
    ll ans = 0;
    for(int i = a; i >= 1; i -= i & -i){
        for(int j = b; j >= 1; j -= j & -j){
            ans += bit[i][j];
        }
    }
    return ans;
}

void add(int a, int b, ll value){ //add value to position [a,b]
    for(int i = a; i <= n; i += i & -i){
        for(int j = b; j <= n; j += j & -j){
            bit[i][j] += value;
        }
    }
}

void build(){
    for(int i=1;i<=n;i++) 
        for(int j=1; j<=n; j++)
            add(i, j, v[i][j]);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin >> c;
            if(c == '*') v[i][j] = 1;
        }
    }
    build();
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << sum(c,d) - sum(a-1, d) - sum(c, b-1) + sum(a-1, b-1) << "\n";
    }
}
