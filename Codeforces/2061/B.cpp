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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<int> eq;
        for(int i=1;i<n;i++){
            if(v[i] == v[i-1]) eq.push_back(v[i]);
        }
        sort(eq.begin(), eq.end());
        eq.resize(unique(eq.begin(), eq.end()) - eq.begin());
        if(eq.size() >= 2){
            cout << eq[0] << " " << eq[0] << " " << eq[1] << " " << eq[1] << "\n";
        }else if(eq.size() == 1){
            vector<int> v2;
            int c = 2;
            for(int i=0;i<n;i++){
                if(eq[0] == v[i]){
                    if(c){
                        c--;
                    }else v2.push_back(v[i]);
                }else v2.push_back(v[i]);
            }
            bool ok = false;
            for(int i=1;i<v2.size();i++){
                if(v2[i] - v2[i-1] < 2 * eq[0]){
                    cout << eq[0] << " " << eq[0] << " " << v2[i] << " " << v2[i-1] << "\n";
                    ok = true;
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }else cout << "-1\n";
    }
}
