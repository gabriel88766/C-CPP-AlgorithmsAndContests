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
    set<int> st;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    map<int, int> mp;
    for(int i=1;i<=n;i++){
        if(mp[v[i]] == 0){
            st.insert(v[i]);
        }
        if(mp[v[i]] == 1){
            st.erase(v[i]);
        }
        mp[v[i]]++;
        if(i > k){
            if(mp[v[i-k]] == 2){
                st.insert(v[i-k]);
            }
            if(mp[v[i-k]] == 1){
                st.erase(v[i-k]);
            }
            mp[v[i-k]]--;
        }
        if(i >= k){
            if(st.size()) cout << *prev(st.end()) << "\n";
            else cout << "Nothing\n";
        }
    }

}   
