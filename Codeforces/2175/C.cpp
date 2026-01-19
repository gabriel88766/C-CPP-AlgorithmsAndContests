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
        string s, x, ans, aux;
        cin >> s >> x;
        vector<int> cnt(26);
        for(auto &c : s) cnt[c-'a']++;
        for(auto &c : x){
            if(cnt[c-'a']){
                cnt[c-'a']--;
            }else{
                aux += c;
            }
        }
        if(*max_element(cnt.begin(), cnt.end()) > 0){
            cout << "Impossible\n";
            continue;
        }
        sort(aux.begin(), aux.end());
        int p2 = 0, p = 0;
        while(p < s.size() || p2 < aux.size()){
            if(p < s.size() && p2 < aux.size()){
                if(s[p] <= aux[p2]) ans += s[p++];
                else ans += aux[p2++];
            }else{
                if(p < s.size()) ans += s[p++];
                if(p2 < aux.size()) ans += aux[p2++];
            }
        }
        cout << ans << "\n";
    }
}
