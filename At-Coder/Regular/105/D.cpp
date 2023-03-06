#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        
        if(n % 2) cout << "Second\n";
        else {
            sort(v.begin(), v.end());
            bool ok = true;
            for(int i=0;i<n;i+=2){
                if(v[i] != v[i+1]) ok = false;
            }
            if(ok) cout << "Second\n";
            else cout << "First\n";
        }
    }
}
