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
    int n, m;
    cin >> n >> m;
    vector<bool> has(m+1, false);
    int cnt = 0;
    bool pr = false;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(!has[x]){
            cnt++;
            has[x] = true;
        }
        if(cnt == m && pr == false){
            pr = true;
            cout << n - i + 1 << "\n";
        }
    }
    if(!pr) cout << "0\n";
}   
