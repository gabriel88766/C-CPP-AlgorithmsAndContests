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
        int n, f, k;
        cin >> n >> f >> k;
        int fc;
        vector<int> v;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            v.push_back(x);
            if(i == f) fc = x;
        }
        sort(v.begin(), v.end(), greater<int>());
        if(v[k-1] == fc){
            if(v.size() == k || v[k] != fc) cout << "YES\n";
            else cout << "MAYBE\n";
        }else if(v[k-1] > fc) cout << "NO\n";
        else cout << "YES\n";
    }
}
