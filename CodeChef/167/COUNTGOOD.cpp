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
    int t;
    cin >> t;
    while(t--){
        ll n, k, q;
        cin >> n >> k >> q;
        ll l = k;
        ll r = k + n - 1;
        if(l == r){
            int q;
            cin >> q;
            for(int i=0;i<q;i++){
                ll nl, nr;
                cin >> nl >> nr;
                if(nl <= l && nr >= r) cout << "1\n";
                else cout << "0\n";
            }
            continue;
        }
        //ors [l, r]
        int b = -1;
        for(int j=62;j>=0;j--){
            ll bn = 1LL << j;
            ll cl = l & bn;
            ll cr = r & bn;
            if(cl != cr){
                b = j;
                break;
            }
        }
        for(int j=b;j>=0;j--){
            r |= 1LL << j;
        }
        for(int i=0;i<q;i++){
            ll nl, nr;
            cin >> nl >> nr;
            nl = max(nl, l);
            nr = min(nr, r);
            if(nr >= nl) cout << nr-nl+1 << "\n";
            else cout << "0\n";
        }
    }
}
