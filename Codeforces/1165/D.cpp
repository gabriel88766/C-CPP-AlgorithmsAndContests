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
        int n;
        cin >> n;
        vector<ll> d(n);
        for(int i=0;i<n;i++) cin >> d[i];
        sort(d.begin(), d.end());

        ll num = d[0]*d[d.size()-1];

        bool ok = true;
        for(int i=0;i<d.size();i++){
            if(d[i]*d[d.size()-1-i] != num) ok = false;
        }   
        set<ll> sd;
        for(int i=0;i<d.size();i++) sd.insert(d[i]);
        for(int i=2;i<min(2000006LL, num); i++){
            if(!(num % i)){
                if(!sd.count(i)){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << num << "\n";
        else cout << "-1\n";
    }
}
