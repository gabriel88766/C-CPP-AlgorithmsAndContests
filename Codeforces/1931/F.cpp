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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(k, vector<int>(n));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        bool ok = true;
        if(k >= 2){
            vector<int> ord, ord1, ord2;
            bool tp = false;
            for(int i=1;i<n;i++) ord.push_back(v[0][i]);
            int p = 0;
            for(int i=1;i<n;i++){
                if(p < n-1 && v[1][i] == ord[p]){
                    ord1.push_back(ord[p]);
                    ord2.push_back(ord[p]);
                    p++;
                }else{
                    if(p < n-1 && ord[p] == v[1][0]){
                        if(v[1][i] == v[0][0]){
                            tp = true;
                            ord1.push_back(ord[p]);
                            ord1.push_back(v[1][i]);
                            ord2.push_back(v[1][i]);
                            ord2.push_back(ord[p]);
                            p++;
                        }else{
                            ord1.push_back(ord[p]);
                            p++;
                            i--;
                        }
                    }else if(v[1][i] == v[0][0]){
                        ord1.push_back(v[1][i]);
                    }else{
                        ok = false;
                        break;
                    }
                }
            }
            if(p < n-1 && ord[p] == v[1][0]) ord1.push_back(ord[p]);
            if(ok && k > 2){
                assert(ord1.size() == n);
                ok = false;
                bool cok = true;
                for(int i=0;i<k;i++){
                    int p = 0;
                    for(int j=1;j<n;j++){
                        if(ord1[p] == v[i][0]) p++;
                        if(ord1[p] == v[i][j]) p++;
                        else cok = false;
                        if(ord1[p] == v[i][0]) p++;
                    }
                }
                if(cok) ok = true;
                if(tp){
                    bool cok = true;
                    for(int i=0;i<k;i++){
                        int p = 0;
                        for(int j=1;j<n;j++){
                            if(ord2[p] == v[i][0]) p++;
                            if(ord2[p] == v[i][j]) p++;
                            else cok = false;
                            if(ord2[p] == v[i][0]) p++;
                        }
                    }
                    if(cok) ok = true;
                }
            }
        }




        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
