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
    //freopen(" in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> vp(n);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first;
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        ll sum = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(sum < vp[i].first){
                while(st.size()){
                    ans[st.top()] = i-1;
                    st.pop();
                }
            }
            sum += vp[i].first;
            st.push(vp[i].second);
        }
        while(st.size()){
            ans[st.top()] = n-1;
            st.pop();
        }
        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
