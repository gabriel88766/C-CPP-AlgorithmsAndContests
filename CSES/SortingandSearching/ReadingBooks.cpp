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
    ll totalsum=0, maxtime=0;
    int n;
    cin >> n;
    while(n--){
        ll aux;
        cin >> aux;
        totalsum += aux;
        maxtime = max(maxtime, aux);
    }
    cout << (2*maxtime > totalsum ? 2*maxtime : totalsum);
}
