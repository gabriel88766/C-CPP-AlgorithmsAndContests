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
        ll pos;
        cin >> s >> pos;
        int n = s.size();
        vector<int> rem;
        vector<bool> jmp(n+1, false);
        stack<int> st;
        for(int i=0;i<n-1;i++){
            st.push(i);
            while(!st.empty() && s[st.top()] > s[i+1]){
                rem.push_back(st.top());
                st.pop();
            }
        }
        st.push(n-1);
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        ll cnt = 0, p = 0;
        while(cnt + (n - p) < pos){
            cnt += (n - p);
            p++;
        }
        for(int i=0;i<p;i++) jmp[rem[i]] = true;
        int c = 0;
        for(int i=1;i<pos-cnt; i++){
            while(jmp[c]) c++;
            c++;
        }
        while(jmp[c]) c++;
        cout << s[c];
    }
}
