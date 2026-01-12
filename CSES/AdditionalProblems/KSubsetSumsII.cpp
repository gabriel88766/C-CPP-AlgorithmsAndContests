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
    // freopen("test_input.txt", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    
    multiset<tuple<ll, ll, ll>> st;
    ll s = 0;
    for(int j = 0; j < m; j++) s += v[j];
    st.insert({s, m-1, n});
    k+=1;
    while(--k){
        auto [a, b, ck] = *st.begin();
        st.erase(st.begin());
        cout << a << " ";
        if(b == -1) continue;
        for(int j = b + 1;j <= ck-1;j++){
            while(st.size() > k) st.erase(prev(st.end()));
            ll mn = st.size() == k ? get<0>(*prev(st.end())) - 1 : INF_LL;
            if(a - v[b] + v[j] <= mn){
                st.insert({a-v[b]+v[j], b-1, j});
            }else break;
        }
        
    }
    cout << "\n";
}