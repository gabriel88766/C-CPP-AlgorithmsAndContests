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
    string s;
    cin >> s;
    set<int> st;
    for(int i=0;i<s.size();i++) st.insert(i);
    auto it = st.begin();
    while(it != st.end()){
        auto it2 = it, it3 = it;
        if(next(it) != st.end()){
            it2 = next(it);
        }else break;
        if(next(it2) != st.end()){
            it3 = next(it2);
        }else break;
        if(s[*it] == 'A' && s[*it2] == 'B' && s[*it3] == 'C'){
            auto nxt = it;
            if(nxt != st.begin()){
                 nxt = prev(nxt);
                 if(nxt != st.begin()) nxt = prev(nxt);
            }else nxt = next(it3);
            st.erase(it); st.erase(it2); st.erase(it3);
            it = nxt;
        }else ++it;
    }
    string ans;
    for(auto x : st) ans += s[x];
    cout << ans << "\n";
}
