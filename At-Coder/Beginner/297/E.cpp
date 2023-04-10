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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    set<ll> st;
    st.insert(0);
    int cnt = 0;
    for(int i=0;i<k;i++){
        ll cur = *st.begin();
        for(int j=0;j<n;j++){
            st.insert(cur+a[j]);
        }
        st.erase(cur);
    }
    cout << *st.begin();
}
