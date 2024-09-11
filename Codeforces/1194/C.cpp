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
    int q;
    cin >> q;
    while(q--){
        string s, t, s2;
        cin >> s >> t >> s2;
        int p = 0;
        for(int i=0;i<t.size();i++){
            if(p < s.size() && t[i] == s[p]) p++;
        }
        if(p == s.size()){
            vector<int> cnt1(26, 0), cnt2(26, 0);
            for(int i=0;i<s.size();i++) cnt1[s[i]-'a']++;
            for(int i=0;i<s2.size();i++) cnt1[s2[i]-'a']++;
            for(int i=0;i<t.size();i++) cnt2[t[i]-'a']++;
            bool ok = true;
            for(int i=0;i<26;i++) if(cnt2[i] > cnt1[i]) ok = false;
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }else cout << "NO\n";
    }
}
