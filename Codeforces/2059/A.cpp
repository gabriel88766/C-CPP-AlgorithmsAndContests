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
        set<int> s1, s2;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            s1.insert(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            s2.insert(x);
        }
        if(s1.size() >= 2 && s2.size() >= 2) cout << "YES\n";
        else if(max(s1.size(), s2.size()) >= 3) cout << "YES\n";
        else cout << "NO\n";
    }
}
