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
        int n, k;
        cin >> n >> k;
        map<int,int> lmo, rmo;
        for(int i=1;i<=n;i++){
            int st;
            cin >> st;
            if(!lmo.count(st)) lmo[st] = i;
            rmo[st] = i;
        }
        for(int i=0;i<k;i++){
            int a,b;
            cin >> a >> b;
            if(lmo.count(a)){
                if(rmo.count(b) && rmo[b] > lmo[a]){
                    cout << "YES\n";
                }else cout << "NO\n";
            }else cout << "NO\n";
        }
    }
}
