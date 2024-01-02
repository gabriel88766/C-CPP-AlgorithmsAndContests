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
    string s, t;
    cin >> s >> t;
    vector<ll> c1(26, 0), c2(26, 0);
    ll k = 0;
    for(int i=0;i<s.size();i++) if(s[i] != '?') c1[s[i]-'a']++; else k++;
    for(int i=0;i<t.size();i++) c2[t[i]-'a']++;
    ll lo = 0, hi = 1000001;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1) / 2;
        ll tts = 0;
        for(int i=0;i<26;i++){
            if(c2[i]* mid > c1[i]) tts += c2[i] * mid - c1[i];
        }
        if(tts <= k) lo = mid;
        else hi = mid - 1;
    }
    int p = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '?'){
            if(p == 26) s[i] = 'a';
            else{
                while(p < 26 && c2[p]*lo <= c1[p]) p++;
                if(p == 26) s[i] = 'a';
                else{
                    s[i] = 'a' + p;
                    c1[p]++;
                }
            }
        }
    }
    cout << s << "\n";
}
