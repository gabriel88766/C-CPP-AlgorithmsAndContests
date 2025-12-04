#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> cnt(2*n+1, 0);
        for(int i=1;i<=2*n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        bool ho = false;
        int m4 = 0;
        int ans = 0;
        for(int i=1;i<=2*n;i++){
            if(cnt[i] == 0) continue;
            if(cnt[i] % 2) ho = true, ans += 1;
            else ans += 2;
            if(cnt[i] % 4 == 0) m4++;
        }
        if(!ho){
            if(m4 % 2) ans -= 2;
        }
        cout << ans << "\n";
    }
}
