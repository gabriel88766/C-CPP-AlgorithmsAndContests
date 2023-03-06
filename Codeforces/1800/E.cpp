//e1 e2 
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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s, t;
        cin >> n >> k >> s >> t;
        vector<int> qts(26, 0), qtt(26, 0);
        bool ok = true;
        for(int i=0;i<n;i++) qts[s[i]-'a']++, qtt[t[i]-'a']++;
        for(int i=0;i<26;i++) if(qts[i] != qtt[i]) ok = false;
        for(int i=0;i<n;i++){
            if(n-i <= k && i < k){
                if(s[i] != t[i]) ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
