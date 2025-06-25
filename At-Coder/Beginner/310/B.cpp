#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<105> bs[105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    bool ok = false;
    for(int i=0;i<n;i++){
        cin >> p[i];
        int cc;
        cin >> cc;
        for(int j=0;j<cc;j++){
            int x;
            cin >> x;
            bs[i][x] = 1;
        }
    }   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(p[i] < p[j]) continue;
            if(p[i] >= p[j] && bs[j] == (bs[j] | bs[i])){
                if(bs[i] != bs[j] || p[i] != p[j]){
                    ok = true;
                }
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
