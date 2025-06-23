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
    s = "(" + s + ")";
    bool ok = true;
    vector<int> cnt(26, 0);
    stack<char> st;
    for(auto &c : s){
        if(c != ')'){
            st.push(c);
            if(c != '('){
                if(cnt[c-'a']){
                    ok = false;
                }
                cnt[c-'a']++;
            }
        }else{
            while(st.top() != '('){
                cnt[st.top()-'a']--;
                st.pop();
            }
            st.pop();
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
