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
    int n;
    string s;
    cin >> n >> s;
    stack<int> st;
    string ans = "";
    for(int i=0;i<n;i++) ans += '%';
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            if(st.size() % 2) ans[st.top()] = ans[i] = '1';
            else ans[st.top()] = ans[i] = '0';
            st.pop();
        }
    }
    
    cout << ans << "\n";
}
