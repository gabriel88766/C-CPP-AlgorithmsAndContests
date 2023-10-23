#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Interval{
    ll l, r;
    bool operator< (const Interval &d) const{
        return l < d.l;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Interval> vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].l >> vp[i].r;
            vp[i].r += vp[i].l;
        }
        sort(vp.begin(), vp.end());
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll ld = 0;
        int cnt = 0;
        int p = 0;
        while(p < n){
            ll v = vp[p].l;
            while(ld < v && pq.size()){
                if(pq.top() >= ld){
                    ld++;
                    cnt++;
                }
                pq.pop(); 
            }
            while(pq.size() && pq.top() < ld) pq.pop();
            while(p < n && vp[p].l == v){
                pq.push(vp[p].r);
                p++;
            }
            ld = v+1;
            pq.pop(); 
            cnt++;
        }
        while(pq.size()){
            if(pq.top() >= ld){
                ld++;
                cnt++;
            }
            pq.pop(); 
        }
        cout << cnt << "\n";
    }
}   
