#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
using namespace std;


const ll N = 500001;
ll P[N];
//O(N sqrt(N))
void calc(int n = N-1){
    P[0] = 1;
    cout << 1 << " ";
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            int v1 = i - (k*(3*k-1))/2;
            int v2 = i - (k*(3*k+1))/2;
            int s = (k+1) % 2 ? -1 : 1;
            if(v1 < 0 && v2 < 0) break;
            if(v1 >= 0) P[i] += s*P[v1];
            if(v2 >= 0) P[i] += s*P[v2];
            P[i] %= MOD;
        }
        if(P[i] < 0) P[i] += MOD;
        cout << P[i] << " ";
    }
    cout << "\n";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin);
    int n;
    cin >> n;
    calc(n);
}