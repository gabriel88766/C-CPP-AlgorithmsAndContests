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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> va(a), vb(b), vc(c);
    for(int i=0;i<a;i++) cin >> va[i];
    for(int i=0;i<b;i++) cin >> vb[i];
    for(int i=0;i<c;i++) cin >> vc[i];
    sort(va.begin(), va.end(), greater<ll>());
    sort(vb.begin(), vb.end(), greater<ll>());
    sort(vc.begin(), vc.end(), greater<ll>());
    int p0 = 0, p1 = 0, p2 = 0;
    ll ans = 0;
    while(p0 + p1 + p2 < x + y){
        if(p0 < x && p1 < y && p2 < c){
            if(va[p0] == max({va[p0], vb[p1], vc[p2]})){
                ans += va[p0++];
            }else if(vb[p1] == max({va[p0], vb[p1], vc[p2]})){
                ans += vb[p1++];
            }else{
                ans += vc[p2++];
            }
        }else if(p0 < x && p2 < c){
            if(va[p0] > vc[p2]){
                ans += va[p0++];
            }else{
                ans += vc[p2++];
            }
        }else if(p0 < x && p1 < y){
            if(va[p0] > vb[p1]){
                ans += va[p0++];
            }else{
                ans += vb[p1++];
            }
        }else if(p1 < y && p2 < c){
            if(vb[p1] > vc[p2]){
                ans += vb[p1++];
            }else{
                ans += vc[p2++];
            }
        }else if(p0 < x){
            ans += va[p0++];
        }else if(p1 < y){
            ans += vb[p1++];
        }else{
            //heresy!!
            assert(false);
        }
    }
    cout << ans << "\n";
}
