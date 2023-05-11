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
        int n, t;
        cin >> n >> t;
        vector<bool> can(n);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(t-i >= x) can[i] = true;
            else can[i] = false;
        }
        int best = 0, ind = -1;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            if(can[i]){
                if(x > best){
                    best = x;
                    ind = i+1;
                }
            }
        }
        cout << ind << "\n";
    }
}
