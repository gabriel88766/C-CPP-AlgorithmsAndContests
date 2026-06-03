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
        vector<int> cnt(26, 0);
        for(auto c : s) cnt[c-'a']++;
        int mx = *max_element(cnt.begin(), cnt.end());
        if(2*mx - 1 > s.size()) cout << "No\n";
        else{
            set<pair<int, char>> st;
            for(int i=0;i<26;i++) st.insert({cnt[i], 'a' + i});
            string ans;
            cout << "Yes\n";
            while(prev(st.end())->first != 0){
                pair<int, char> cp;
                if(ans.size() == 0 || prev(st.end())->second != ans.back()){
                    cp = *prev(st.end());
                }else{
                    cp = *prev(prev(st.end()));
                }
                ans += cp.second;
                st.erase(cp);
                cp.first--;
                st.insert(cp);
            }
            cout << ans << "\n";
        }
    }
}
