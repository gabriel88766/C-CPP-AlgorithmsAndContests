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
        string s;
        cin >> s;
        int sn = 0;
        vector<int> cnt(10);
        for(int j=0;j<s.size();j++){
            sn += s[j] - '0';
            if(j == 0) cnt[s[j]-'1']++;
            else cnt[s[j] - '0']++;
        }
        int ans = 0;
        int p = 9;
        while(sn > 9){
            if(cnt[p] > 0){
                cnt[p]--;
                ans++;
                sn -= p;
            }else --p;
        }
        cout << ans << "\n";
    }
}
