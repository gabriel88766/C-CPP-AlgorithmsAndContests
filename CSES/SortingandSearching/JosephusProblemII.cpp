#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;


using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    set<int> s;
    ordered_set<int> st;
    cin >> n >> k;
    k++;
    for(int i=1;i<=n;i++) st.insert(i);
    vector<int> orders; //easy to solve after this, find all orders
    int size = n, cursz = n, curpos=0, cnt, rem = 0;
    while(cursz){
        cnt = 0;
        curpos = -rem;
        if((cursz - curpos) >= k){
            curpos += k;
            while(curpos <= cursz){
                cnt++;
                orders.push_back(curpos-cnt+1);
                curpos += k;
            }
            curpos -= k;
            rem = cursz - curpos;
            if(rem >= cursz) rem -= cursz;
            cursz -= cnt;
        }else{
            int aux = k - ((k/cursz) * cursz);
            curpos += aux;
            if(curpos > cursz) curpos -= cursz; 
            if(curpos <= 0) curpos += cursz;
            orders.push_back(curpos);
            rem = cursz - curpos;
            
            cursz--;
            if(rem >= cursz) rem -= cursz;
        }
    }
    for(auto i : orders){
        auto k = *st.find_by_order(i-1);
        cout << k << " ";
        st.erase(k);
    }
    
    
}
