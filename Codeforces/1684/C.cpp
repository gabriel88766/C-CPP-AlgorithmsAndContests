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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        bool ok = true;
        vector<int> cmp(m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
        for(int j=1;j<m;j++){
            bool ok1 = true, ok2 = true;
            for(int i=0;i<n;i++){
                if(v[i][j-1] > v[i][j]) ok1 = false;
                if(v[i][j-1] < v[i][j]) ok2 = false;
            }
            if(ok1 && !ok2) cmp[j-1] = 1;
            else if(!ok1 && ok2) cmp[j-1] = -1;
            else cmp[j-1] = 0;
            if(!ok1 && !ok2){
                ok = false;
                break;
            }
        }
        if(!ok) cout << "-1\n";
        else{
            int ind = -1;
            for(int j=1;j<m;j++){
                if(cmp[j-1] == -1){
                    ind = j-1;
                    break;
                }
            }
            if(ind == -1) cout << "1 1\n";
            else{
                int ind2 = m-1;
                bool ok = true;
                for(int j = ind+1;j<m;j++){
                    bool ok1 = true, ok2 = true;
                    for(int i=0;i<n;i++){
                        if(v[i][ind] > v[i][j]) ok1 = false;
                        if(v[i][ind] < v[i][j]) ok2 = false;
                    }
                    if(!ok1 && !ok2) ok = false;
                    else if(ok1){
                        ind2 = j-1;
                        break;
                    }
                }
                for(int i=0;i<n;i++) swap(v[i][ind], v[i][ind2]);
                for(int j=1;j<m;j++){
                    for(int i=0;i<n;i++){
                        if(v[i][j-1] > v[i][j]) ok = false;
                    }
                }
                if(ok) cout << ind+1 << " " << ind2+1 << "\n";
                else cout << "-1\n";
            }
        }
    }
}
