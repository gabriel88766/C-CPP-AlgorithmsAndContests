#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+6;
ll bit[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
ll query(int l, int r){
    return query(r) - query(l-1);
}
 
struct Query{
    ll cur;
    int l, r;
};
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(nums.begin(), nums.end()); //O(n log n)
    int p = 0;
    map<ll, vector<int>> mp;
    vector<Query> vq(q);
    for(int i=0;i<q;i++){
        Query q;
        cin >> vq[i].l >> vq[i].r;
        vq[i].cur = 1;
        mp[1].push_back(i);
    }
    vector<ll> ans(q);
    while(!mp.empty()){
        auto [cur, vec] = *mp.begin();
        mp.erase(mp.begin());
        while(p < n && nums[p].first <= cur){
            add(nums[p].second, nums[p].first); //O(n log n)
            p++;
        }
        for(auto i : vec){
            ll sum = query(vq[i].l, vq[i].r); // O(n log^2 n)
            if(sum >= cur){
                vq[i].cur = sum + 1;
                mp[vq[i].cur].push_back(i);
            }else ans[i] = cur;
        }
    }
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
}