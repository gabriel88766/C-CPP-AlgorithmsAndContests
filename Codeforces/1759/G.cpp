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
        vector<int> v(n+1), inv(n+1, 0);
        set<int> st;
        bool ok = true;
        for(int i=2;i<=n;i+=2){
            cin >> v[i];
            if(inv[v[i]] != 0){
                ok = false;
            }
            inv[v[i]] = i;
        }
        if(ok){
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(inv[i]){
                    cnt--;
                    if(cnt < 0) ok = false;
                }else{
                    cnt++;
                    st.insert(i);
                }
            }
        }
        //check 2
        if(!ok){
            cout << "-1\n";
            continue;
        }else{
            for(int i=n;i>=2;i-=2){
                auto it = st.lower_bound(v[i]);
                --it;
                v[i-1] = *it;
                st.erase(v[i-1]);
            }
            for(int i=1;i<=n;i++) cout << v[i] << " ";
            cout << "\n";
        }
    }
}
