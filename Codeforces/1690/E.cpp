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
        int n, k;
        cin >> n >> k;
        multiset<ll> s[k];
        for(int i=0;i<n;i++){
            ll aux;
            cin >> aux;
            s[aux%k].insert(aux);
        }
        ll ans = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                // (j + x) % k == i
                int x = i - j;
                if(x < 0) x += k;
                if(x != j){
                    while(s[x].size() && s[j].size()){
                        ll sum = *s[x].begin();
                        sum += *s[j].begin();
                        s[x].erase(s[x].begin());
                        s[j].erase(s[j].begin());
                        ans += sum/k;
                    }
                }else{
                    while(s[x].size() >= 2){
                        ll sum = *s[x].begin();
                        s[x].erase(s[x].begin());
                        sum += *s[x].begin();
                        s[x].erase(s[x].begin());
                        ans += sum/k;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
