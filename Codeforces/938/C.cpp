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
        int x;
        cin >> x;
        if(x == 0){
            cout << "1 1\n";
            continue;
        }
        bool ok = false;
        for(ll i = 1; ; i++){
            if(i*i <= x) continue;
            if(i*i - (i/2)*(i/2) > x) break;
            ll dif = i*i - x;
            ll sqt = sqrt(dif);
            while(sqt*sqt > dif) sqt--;
            while((sqt+1)*(sqt+1) <= dif) sqt++;
            if(sqt * sqt == dif){
                int lo = 2, hi = i;
                while(lo != hi){
                    int mid = lo + (hi - lo)/2;
                    if((i/mid)*(i/mid) > dif) lo = mid + 1;
                    else hi = mid;
                }
                if((i/lo)*(i/lo) == dif){
                    cout << i << " " << lo << "\n";
                    ok = true;
                    break;
                }
            }
        }
        if(!ok) cout << "-1\n";
    }
}
