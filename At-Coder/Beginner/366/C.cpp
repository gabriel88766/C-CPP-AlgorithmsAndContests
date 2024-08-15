#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int cnt[N];
int ans = 0;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    while(q--){
        int tq;
        cin >> tq;
        if(tq == 1){
            int x;
            cin >> x;
            if(!cnt[x]) ans++;
            cnt[x]++;
        }else if(tq == 2){
            int x;
            cin >> x;
            cnt[x]--;
            if(!cnt[x]) ans--;
        }else{
            cout << ans << "\n";
        }
    }
}
