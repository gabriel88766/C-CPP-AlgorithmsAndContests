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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> opt1(n), opt2(n);
        for(int i=0;i<n;i++){
            int x = 2*i + (!(n % 2) && 2 * i >= n ? 1 : 0);
            int y = 2*i + 1 + (!(n % 2) && 2 * i + 1 >= n ? -1 : 0);
            opt1[x%n] = v[i];
            opt2[y%n] = v[i];
        }
        bool ok1 = true;
        bool ok2 = true;
        for(int i=1;i<n-1;i++){
            if(i % 2){
                if(opt1[i] <=  opt1[i-1] || opt1[i] <= opt1[i+1]) ok1 = false;
                if(opt2[i] >=  opt2[i-1] || opt2[i] >= opt2[i+1]) ok2 = false;
            }else {
                if(opt1[i] >=  opt1[i-1] || opt1[i] >= opt1[i+1]) ok1 = false;
                if(opt2[i] <=  opt2[i-1] || opt2[i] <= opt2[i+1]) ok2 = false;
            }
        }
        if(ok1 || ok2){
            if(ok1){
                for(auto x : opt1) cout << x << " ";
                cout << "\n";
            }else{
                for(auto x : opt2 ) cout << x << " ";
                cout << "\n";
            }
        }else cout << "-1\n";
    }
}
