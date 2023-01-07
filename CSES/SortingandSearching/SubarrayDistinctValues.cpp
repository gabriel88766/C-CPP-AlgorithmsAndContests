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
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    
    vector<ll> cnt(n, 0);

    map<int,int> qt; //multiset
    set<int> st;
    
    int bp = 0, cntd = 1;
    qt[v[0]]++;
    st.insert(v[0]);
    for(int i=1;i<n;i++){
        if(st.count(v[i])){ //ok
            qt[v[i]]++;
            
        }else{
            if(cntd < k){ // also ok
                
                cntd++;
                st.insert(v[i]);
                qt[v[i]]++;
            }else{
                while(cntd == k){
                    qt[v[bp]]--;
                    cnt[bp] = i;
                    if(qt[v[bp]] == 0){
                        st.erase(v[bp]);
                        cntd--;   
                    }
                    bp++;
                }
                i--;
            }
        }   
    }

    for(int i=0;i<n;i++){
       if(!cnt[i]) cnt[i] = n;
       ans += cnt[i] - i;
    }
    cout << ans;

}
 