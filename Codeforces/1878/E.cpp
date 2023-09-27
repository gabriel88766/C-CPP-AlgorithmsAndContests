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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<vector<int>> pos(30);
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if(!(v[i] & (1 << j))){
                    pos[j].push_back(i);
                }
            }
        }
        for(int j=0;j<30;j++) pos[j].push_back(n+1);
        int q;
        cin >> q;
        while(q--){
            int l, k;
            cin >> l >> k;
            if(v[l] < k) cout << "-1 ";
            else{
                vector<pair<int,int>> bits;
                for(int j=0;j<30;j++){
                    if(v[l] & (1 << j)){
                        int nxt = *lower_bound(pos[j].begin(), pos[j].end(), l);
                        bits.push_back({nxt, j});
                    }
                }
                sort(bits.begin(), bits.end());
                int curnum = v[l], ans = l;
                for(int i=0;i<bits.size();i++){
                    ans = bits[i].first - 1;
                    curnum ^= (1 << bits[i].second);
                    if(curnum < k) break;
                }
                cout << ans << " ";
            }   
        }
        cout << "\n";
    }
}
