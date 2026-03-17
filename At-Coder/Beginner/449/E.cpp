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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), cnt(m+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    vector<pair<ll, int>> qr;
    for(int i=0;i<q;i++){
        ll x;
        cin >> x;
        qr.push_back({x, i});
    }
    sort(qr.begin(), qr.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=1;i<=m;i++){
        pq.push({cnt[i], i});
    }
    ll cv = pq.top().first;
    ll adv = n;
    ordered_set<int> os;
    while(pq.size() && pq.top().first == cv){
        os.insert(pq.top().second);
        pq.pop();
    }
    for(auto [x, i] : qr){
        if(x <= n) ans[i] = a[x];
        else{
            ll cp = x - adv;
            while(cp > os.size()){
                if(os.size() == m){
                    ll red = ((cp-1) / m) * m;
                    adv += red;
                    cp -= red;
                }else{
                    cv++;
                    adv += os.size();
                    cp -= os.size();
                }
                while(pq.size() && pq.top().first == cv){
                    os.insert(pq.top().second);
                    pq.pop();
                }
            }
            ans[i] = *os.find_by_order(cp-1);
        }
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
}
