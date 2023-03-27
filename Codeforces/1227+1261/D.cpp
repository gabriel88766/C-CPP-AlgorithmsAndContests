#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

bool func(pair<int,int> u, pair<int,int> v){
    if(u.first != v.first) return u.first > v.first;
    else return u.second < v.second;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        cin >> v[i];
        vp.push_back({v[i], i});
    }
    sort(vp.begin(), vp.end(), func);
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<pair<pair<int,int>,int>> queries;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        queries.push_back({{a,b},i});
    }
    sort(queries.begin(), queries.end());
    int sz = 0;
    ordered_set<int> st;
    for(int i=0;i<q;i++){
        int ind = queries[i].second;
        int a = queries[i].first.first;
        int b = queries[i].first.second;
        while(sz < a){
            st.insert(vp[sz].second);
            sz++;
        }
        ans[ind] = *st.find_by_order(b-1);
    }
    for(int i=0;i<q;i++) cout << v[ans[i]] << "\n";
}
