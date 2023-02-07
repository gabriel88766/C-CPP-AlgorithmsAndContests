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
        string a,b;
        ll n, k;
        vector<int> is(26, 0), ord(26, 0);
        vector<int> change(26, 0);
        cin >> n >> k;
        cin >> a >> b;
        for(int i=0;i<n;i++) is[a[i]-'a'] = 1;
        ll cnt, sum = 0, ans = 0, cnt2 = 1;
        for(int i=0;i<26;i++) if(is[i]) ord[i] = cnt2++;
        int mask = 1 << (cnt2 - 1);
        cnt2--;
        for(int i=0; i < mask; i++){
            if(__builtin_popcount(i) != min(k,cnt2)) continue;
            for(int j=0;j<26;j++) change[j] = 0;
            for(int j=0;j<26; j++) {if( ord[j] && (i  & (1 << (ord[j]-1)))) change[j] = 1;} 
            cnt = 0, sum = 0;
            for(int j=0;j<n;j++){
                if(a[j] == b[j]) cnt++;
                else if(change[a[j]-'a']) cnt++;
                else{
                    sum += (cnt * (cnt+1))/2;
                    cnt = 0;
                }
            }
            sum += (cnt * (cnt+1))/2;
            ans = max(ans, sum);
        }
        cout << ans << "\n";

    }
}
 