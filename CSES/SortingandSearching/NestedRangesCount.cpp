#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;



using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

bool compare(pair<pair<int,int>,int> &left, pair<pair<int,int>,int> &right){
    if(left.first.first != right.first.first ) return left < right;
    else return left.first.second > right.first.second;
}

bool compare2(pair<pair<int,int>,int> &left, pair<pair<int,int>,int> &right){
    if(left.first.second != right.first.second) return left.first.second < right.first.second;
    else return left.first.first > right.first.first;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<pair<int,int>,int>> v;
    ordered_set<pair<int,int>> ss;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({{a,b}, i});
    }
    sort(v.begin(), v.end(), compare);
    ss.insert({v[0].first.second, v[0].first.first});
    vector<int> ans1(n), ans0(n);
    for(int i=1;i<n;i++){
        auto it = ss.lower_bound({v[i].first.second, 0});
        if(it != ss.end()){;
            ans1[v[i].second] = ss.size() - ss.order_of_key(*it);
        }
        ss.insert({v[i].first.second, v[i].first.first});
    }
    ss.clear();
    sort(v.begin(), v.end(), compare2);
    ss.insert({v[0].first.first, v[0].first.second});

    for(int i=1;i<n;i++){
        auto it = ss.lower_bound({v[i].first.first, 0});
        if(it != ss.end()){
            ans0[v[i].second] = ss.size() - ss.order_of_key(*it);
        }
        ss.insert({v[i].first.first, v[i].first.second});
    }


    for(int i=0;i<n;i++) cout << ans0[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << ans1[i] << " ";
    
}
