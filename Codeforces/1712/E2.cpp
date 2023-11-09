#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+6;
 
ll bit[N];
ll v[N];
int n = 200000;
 
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    vector<vector<int>> div(400005);
    vector<vector<int>> hd(400005);
    vector<int> pdiv(400005, 0);
    vector<ll> tt(200005, 0);
    for(int i=1;i<=400000;i++){
        for(int j=i;j<=400000;j+=i){
            div[j].push_back(i);
            hd[i].push_back(j);
        }
    }
    for(ll i=3;i<=200000;i++){
        tt[i] = tt[i-1] + ((i-1) * (i-2))/2;
    }
    vector<pair<int,int>> vq;
    while(t--){
        ll l, r;
        cin >> l >> r;
        vq.push_back({l, r});
    }
    vector<int> ord;
    vector<ll> ans(vq.size());
    for(int i=0;i<vq.size();i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int u, int v){ return vq[u].first < vq[v].first;});
    int pi = 1;

    for(int i=1;i<=200000;i++){
        ll cnt = 0;
        ll d = div[i].size();
        d--;
        cnt += (d*(d-1))/2;
        //lcm = 2*k and i+j > k
        int xx = 2*i;
        for(int j = 0; j < div[xx].size();j++){
            for(int k = j+1; k < div[xx].size();k++){
                if(div[xx][k] >= i) break;
                if((i % div[xx][j]) || (i % (div[xx][k]))){
                    if(div[xx][j] + div[xx][k] > i) cnt++;;
                }
            }
        }
        add(i, cnt);
    }
    for(int i=0;i<vq.size();i++){
        int l = vq[ord[i]].first;
        int r = vq[ord[i]].second;
        while(pi != l){
            //erase pi
            for(int j=0;j<hd[pi].size();j++){
                int d = hd[pi][j];
                ll ctd;
                if(d <= 200000){
                    //d = k
                    ctd = div[d].size() - pdiv[d] - 1;
                    add(d, -(ctd-1));
                }
                //d == 2k
                if((d % 2) == 0){
                    ctd = 0;
                    for(int j=pdiv[d]+1; j<div[d].size();j++){
                        if(div[d][j] >= d/2 || pi >= d/2) break;
                        if(((d/2) % div[d][j]) || ((d/2) % pi)){
                            if((div[d][j] + pi) > (d/2)){
                                ctd++;
                            }
                        }
                    }
                    add(d/2, -ctd);
                }
                pdiv[d]++;
            }
            pi++;
        }
        ans[ord[i]] = tt[r-l+1];
        ans[ord[i]] -= query(r) - query(l-1);
        //lcm == k
    }
    for(auto x : ans) cout << x << "\n";

}
