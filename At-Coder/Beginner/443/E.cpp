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
        int n, c;
        cin >> n >> c;
        --c;
        vector<string> gr(n);
        vector<bool> can(n, false);
        can[c] = true;
        vector<int> nc = {c};
        for(int i=0;i<n;i++){
            cin >> gr[i];
        }
        vector<int> mxw(n, -1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(gr[i][j] == '#'){
                    mxw[j] = i;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            vector<bool> nxc(n, false);
            for(auto x : nc){
                if(x > 0){
                    if(gr[i][x-1] == '.') nxc[x-1] = true; 
                    else if(mxw[x-1] == i) nxc[x-1] = true;
                } 
                {
                    if(gr[i][x] == '.') nxc[x] = true;
                    else if(mxw[x] == i) nxc[x] = true;
                }
                if(x < n-1){
                    if(gr[i][x+1] == '.') nxc[x+1] = true; 
                    else if(mxw[x+1] == i) nxc[x+1] = true;
                }
            }
            nc.clear();
            for(int j=0;j<n;j++){
                if(nxc[j] || can[j]){
                    nc.push_back(j);
                    if(i >= mxw[j]) can[j] = true;
                    if(i == 0) can[j] = true;
                }
            }
        }
        for(int i=0;i<n;i++) cout << can[i];
        cout << "\n";
    }
}
