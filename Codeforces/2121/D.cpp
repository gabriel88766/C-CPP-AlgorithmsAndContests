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
        vector<int> a(n+1);
        vector<int> b(n+1);
        vector<pair<int, int>> ans;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++){
            if(a[i] > b[i]){
                ans.push_back({3, i});
                swap(a[i], b[i]);
            }
        }
        auto sra = a, srb = b;
        sort(sra.begin(), sra.end());
        sort(srb.begin(), srb.end());
        for(int i=1;i<=n;i++){
            if(a[i] != sra[i]){
                int fi = -1;
                for(int j=i;j<=n;j++){
                    if(a[j] == sra[i]){
                        fi = j;
                        break;
                    }
                }
                for(int j=fi-1;j>=i;j--){
                    ans.push_back({1, j});
                    swap(a[j], a[j+1]);
                }
            }
            if(b[i] != srb[i]){
                int fi = -1;
                for(int j=i;j<=n;j++){
                    if(b[j] == srb[i]){
                        fi = j;
                        break;
                    }
                }
                for(int j=fi-1;j>=i;j--){
                    ans.push_back({2, j});
                    swap(b[j], b[j+1]);
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto [a, b] : ans) cout << a << " " << b << "\n";
    }
}
