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
    string s, ans;
    cin >> s;
    vector<int> cnt(26, 0);
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'a']++;
    }
    stack<char> st;
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
        cnt[s[i]-'a']--;
        while(st.size()){
            bool ok = true;
            char cur = st.top();
            for(int j=0;j<cur-'a';j++){
                if(cnt[j]) ok = false;
            }
            if(ok){
                ans += cur;
                st.pop();
            }else break;
        }
    }
    cout << ans << "\n";
}
