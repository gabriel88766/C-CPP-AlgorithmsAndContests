#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        vector<ll> qt(676, 0);
        int n;
        ll ans = 0;
        cin >> n;
        vector<pair<char,char>> vc;
        for(int i=0;i<n;i++){
            char a,b;
            cin >> a >> b;
            vc.push_back({a,b});
            int pos = (a - 'a')*26 + (b-'a');
            qt[pos]++;
        }
        for(int i=0;i<n;i++){
            int pos = (vc[i].first - 'a') * 26 + vc[i].second - 'a';
            int ini = (pos/26) * 26;
            int end = ini + 26;
            for(int j=ini; j<end;j++){
                if(j == pos) continue;
                ans += qt[j];
            }
            for(int j = (pos % 26); j< 676; j += 26){
                if(j == pos) continue;
                ans += qt[j];
            }
            qt[pos]--;
        }
        cout << ans << "\n";
    }
}
