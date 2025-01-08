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
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> vq(q);
        for(int i=0;i<q;i++) cin >> vq[i];
        if(vq[0] == m){
            int r = 1, l = n;
            cout << 2 << " ";
            for(int i=1;i<q;i++){
                if(vq[i] > r) r++;
                if(vq[i] < l) l--;
                if(r < l) cout << r + n-l+1 << " ";
                else cout << n << " ";
            }
        }else{
            int rb = -1, le = -1, l = m, r = m;
            bool fl = false;
            for(int i=0;i<q;i++){
                if(rb != -1 && vq[i] > rb) rb++;
                if(le != -1 && vq[i] < le) le--;
                if(vq[i] >= l && vq[i] <= r){
                    if(!fl){
                        fl = true;
                        rb = 1, le = n;
                    }
                }
                if(vq[i] < l) l--;
                if(vq[i] > r) r++;
                if(fl){
                    if(l > rb && le > r){
                        cout << rb + r - l + 1 + n - le + 1 << " ";
                    }else if(l > rb){
                        cout << rb + n - l + 1 << " ";
                    }else if(le > r){
                        cout << r + n - le + 1 << " ";
                    }else cout << n << " ";
                }else{
                    cout << r - l + 1 << " ";
                }
            }
        }
        cout << "\n";
    }
}
