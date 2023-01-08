//prefix sum
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<ll> ps(200005);
    ps[0] = 0;
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        ps[i] = ps[i-1] + aux; 
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << ps[b] - ps[a-1] << "\n";
    }
}
