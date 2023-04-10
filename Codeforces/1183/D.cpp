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
        int n;
        cin >> n;
        vector<int> cnt(n+1, 0);
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            cnt[aux]++;
        }
        vector<int> qt;
        for(int i=1;i<=n;i++){
            if(cnt[i]){
                qt.push_back(cnt[i]);
            }
        }
        sort(qt.begin(), qt.end(), greater<int> ());
        set<int> st;
        st.insert(qt[0]);
        for(int i=1;i<qt.size();i++){
            int x = *st.begin();
            if(qt[i] >= (x-1) && x > 1){
                st.insert(x-1);
            }else{
                st.insert(qt[i]);
            }
        }
        ll ans = 0;
        for(auto x : st) ans += x;
        cout << ans << "\n";
    }
}
