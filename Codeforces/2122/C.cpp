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
        vector<tuple<int, int, int>> vt(n);
        for(int i=1;i<=n;i++){
            int a, b;
            cin >> a >> b;
            vt[i-1] = {a, b, i};
        }
        sort(vt.begin(), vt.end());
        vector<tuple<int, int, int>> vp(n);
        for(int i=0;i<n/2;i++){
            vp[i] = {get<1>(vt[i]), get<2>(vt[i]), 0};
        }
        for(int i=n/2;i<n;i++){
            vp[i] = {get<1>(vt[i]), get<2>(vt[i]), 1};
        }
        sort(vp.begin(), vp.end());
        int p1 = n/2, p2 = n/2;
        for(int i=0;i<n/2;i++){
            if(get<2>(vp[i]) == 0){
                while(get<2>(vp[p2]) != 1) p2++;
                cout << get<1>(vp[i]) << " " << get<1>(vp[p2]) << "\n";
                p2++;
            }else{
                while(get<2>(vp[p1]) != 0) p1++;
                cout << get<1>(vp[i]) << " " << get<1>(vp[p1]) << "\n";
                p1++;
            }
        }

    }
}
