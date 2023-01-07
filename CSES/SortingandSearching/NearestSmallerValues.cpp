#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<int> v(n), ans(n, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<pair<int,int>> st;
    st.push({v[n-1], n-1});
    for(int i=(n-2);i>=0;i--){
        auto top = st.top();
        while(top.first > v[i]){
            ans[top.second] = i+1;
            st.pop();
            if(st.empty()) break;
            top = st.top();
        }
        st.push({v[i], i});
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
}
