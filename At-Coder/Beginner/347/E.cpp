#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int vq[N];
ll ps[N];
int in[N];
ll ans[N];
vector<int> vx[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for(int i=1;i<=q;i++){
        cin >> vq[i];
        vx[vq[i]].push_back(i);
        if(in[vq[i]]){
            cnt--;
            in[vq[i]] = 0;
        }else{
            cnt++;
            in[vq[i]] = 1;
        }
        ps[i] = cnt + ps[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<vx[i].size();j+=2){
            if(j+1 < vx[i].size()){
                ans[i] += ps[vx[i][j+1] - 1] - ps[vx[i][j] - 1];
            }else{
                ans[i] += ps[q] - ps[vx[i][j] - 1];
            }
        }
        cout << ans[i] << " ";
    }
    cout << "\n";


}
