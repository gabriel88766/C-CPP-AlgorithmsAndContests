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
    ll sum = 0, k;
    int n;
    cin >> n >> k;
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        st.insert({aux, i});
    }
    if(k == 0){
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return 0;
    }
    ll cur = 0;
    vector<int> ans;
    while(st.size() && k){
        ll beg = st.begin()->first;
        ll sz = st.size();
        ll dif = beg - cur;
        if(dif == 0) st.erase(st.begin());
        else if(sz < k){
            ll tt = min((k-1)/sz, dif);
            cur += tt;
            k -= tt*sz;
        }else{
            vector<int> aux;
            set<int> nums;
            vector<int> cnt(n+1);
            for(auto [qt, i] : st){
                cnt[i] = qt - cur;
                nums.insert(i);
            }
            for(auto x : nums){
                if(k == 0){
                    ans.push_back(x);
                }else{
                    k--;
                    if(cnt[x] > 1) aux.push_back(x);
                }
            }
            for(auto x : aux) ans.push_back(x);
        }
    }
    if(k) cout << "-1\n";
    else for(auto x : ans) cout << x << " ";
    
}
