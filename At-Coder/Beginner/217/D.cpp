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
    int L;
    cin >> L;
    set<pair<int,int>> st;
    st.insert({1, L});
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int c, x;
        cin >> c >> x;
        if(c == 2){
            auto it = st.lower_bound({x+1, 0});
            assert(it != st.begin());
            it = prev(it);
            int len = it->second - it->first + 1;
            cout << len << "\n";
        }else{
            auto it = st.lower_bound({x+1, 0});
            assert(it != st.begin());
            it = prev(it);
            auto [l, r] = *it;
            st.erase(it);
            st.insert({l, x});
            st.insert({x+1, r});
        }
    }
}
