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
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<tuple<int,int,int>> vq(q);
    for(int i=0;i<q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vq[i]= {a, b, c};
    }
    reverse(vq.begin(), vq.end());
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        int ans = x;
        for(int j=0;j<q;j++){
            auto [qx, l, r] = vq[j];
            if(qx == 1){
                if(l <= ans && ans <= r){
                    if(ans == l) ans = r;
                    else ans--;
                }
            }else{
                if(l <= ans && ans <= r){
                    ans = r - (ans - l);
                }
            }
        }
        cout << v[ans] << " ";
    }
    cout << "\n";
}
