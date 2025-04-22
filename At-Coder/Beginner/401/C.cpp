#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+2;
int val[N], ps[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=0;i<k;i++) val[i] = 1;
    for(int i=0;i<=n;i++){
        if(val[i] == 0){
            assert(i >= k);
            val[i] = ps[i-1];
            if(i > k) val[i] -= ps[i-k-1];
            if(val[i] < 0) val[i] += MOD;
            if(val[i] >= MOD) val[i] -= MOD;
        }
        ps[i] = (ps[i-1] + val[i]) % MOD;
    }
    cout << val[n] << "\n";
}
