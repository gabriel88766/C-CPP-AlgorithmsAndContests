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
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        vector<int> di;
        for(int i=0;i<n;i++){
            if(a[i] < b[i]) di.push_back(i);
        }
        if(di.size() > 1) cout << "NO\n";
        else if(di.size() == 0) cout << "YES\n";
        else{
            int j = di[0];
            int sum = b[j] - a[j];
            bool ok = true;
            for(int i=0;i<n;i++){
                if(i == j) continue;
                if(a[i] - b[i] < sum) ok = false;
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
 