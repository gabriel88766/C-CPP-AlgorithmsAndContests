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
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> b(m);
        for(int i=0;i<m;i++) cin >> b[i];
        sort(b.begin(), b.end());
        for(int i=0;i<q;i++){
            int x;
            cin >> x;
            auto it = lower_bound(b.begin(), b.end(), x);
            if(it == b.begin()){
                cout << *it - 1 << "\n";
            }else if(it == b.end()){
                cout << n - *prev(it) << "\n";
            }else{
                int p1 = *prev(it);
                int p2 = *it;
                cout << (p2 - p1)/2 << "\n";
            }
        }
    }
}
