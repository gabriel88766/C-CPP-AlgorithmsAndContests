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
        int be = 0;
        vector<vector<int>> vr(n, vector<int>(5));
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<5;j++){
                cin >> vr[i][j];
                if(i > 0 && vr[i][j] < vr[be][j]) cnt++;
            }
            if(cnt >= 3) be = i;
        }
        bool ok = true;
        for(int i=0;i<n;i++){
            if(i == be) continue;
            int cnt = 0;
            for(int j=0;j<5;j++){
                if(vr[i][j] < vr[be][j]) cnt++;
            }
            if(cnt >= 3) ok = false;
        }
        if(ok) cout << be + 1 << "\n";
        else cout << "-1\n";
    }
}
