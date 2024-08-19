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
        int n, m;
        cin >> n >> m;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        int l = 1, r = n;
        string s;
        cin >> s;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i] == 'L'){
                st.push(l);
                l++;
            }else{
                st.push(r);
                 r--;
            }
        }
        vector<int> ans;
        int cur = 1;
        while(!st.empty()){
            cur = (cur * v[st.top()]) % m;
            ans.push_back(cur);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
