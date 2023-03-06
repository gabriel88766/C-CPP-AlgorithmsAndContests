#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;

void calc(vector<ll> &a, vector<ll> &h){
    ll le = 0;
    a[0] = 0;
    vector<ll> aux(1,0);
    vector<ll> g1;
    ll bp = 1;
    for(ll i=1;i<=n;i++){
        a[i] = a[i-1];
        if(h[i] > le){
            aux.emplace_back(h[i]-le);
            if(h[i] - le > 1) g1.emplace_back(i);
        }else{
            while(le >= h[i]){
                if(g1.size() > 0){
                    ll ind = *g1.rbegin();
                    ll diff = min(le-h[i]+1, aux[ind]-1);
                    a[i] += diff * (i-ind);
                    aux[ind] -= diff;
                    le -= diff;
                    if(aux[ind] == 1) g1.pop_back();
                }else{
                    a[i] += (i-bp);
                    le--;
                    bp++;
                }
            }
            aux.emplace_back(1);
        }
        le = h[i];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> h(n+1), a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> h[i];
        calc(a, h);
        reverse(h.begin()+1, h.end());
        calc(b, h);
        reverse(h.begin()+1, h.end());
        reverse(b.begin()+1, b.end());
        ll ans = INF_LL;
        for(int i=1;i<=n;i++) ans = min(ans, h[i] + a[i] + b[i]);
        cout << ans << "\n";
    }
}
