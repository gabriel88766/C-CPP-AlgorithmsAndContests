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

        int ind1 = -1;
        set<int> pos1;
        for(int i = 1; i < n; i += 2){
            cout << "? 2 " << i << " " << i+1 << " " << 1 << "\n";
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == 1){
                ind1 = i;
                break;
            }else if(ans == 2){
                pos1.insert(i);
                pos1.insert(i+1);
            }
        }
        if(ind1 == -1 && n%2){
            cout << "? 2 " << n << " " << 1 << " " << 1 << "\n";
            cout.flush();
            int ans;
            cin >> ans;
            if(ans == 1){
                ind1 = n;
            }else if(ans == 2){
                pos1.insert(n);
            }
        }
        if(ind1 == -1){
            for(auto x : pos1){
                if(x == 1){
                    cout << "? 2 " << x << " " << 2 << " " << 1 << "\n";
                }else{
                    cout << "? 2 " << x << " " << 1 << " " << 1 << "\n";
                }
                cout.flush();
                int ans;
                cin >> ans;
                if(ans == 1){
                    ind1 = x;
                    break;
                }
            }
        }
        vector<int> ansv(n+1, 0);
        ansv[ind1] = 1;
        for(int i=1;i<=n;i++){
            if(i == ind1) continue;
            cout << "? 1 " << ind1 << " " << i << " " << n-1 << "\n";
            cout.flush();
            cin >> ansv[i];
        }
        cout << "! ";
        for(int i=1;i<=n;i++){
            cout << ansv[i];
            if(i != n) cout << " ";
        }
        cout << "\n";
        cout.flush();
    }
}
