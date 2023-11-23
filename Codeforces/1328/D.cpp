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
        bool alleq = true;
        for(int i=1;i<n;i++) if(v[i] != v[0]) alleq = false;
        if(alleq){
            cout << "1\n";
            for(int i=1;i<=n;i++) cout << "1 ";
            cout << "\n";
        }else{
            int ind = -1;
            for(int i=0;i<n;i++){
                if(v[i] == v[(i+1)%n]){
                    ind = i;
                    break;
                }
            }
            if(n % 2 == 0){
                //1 2 1 2 1 2
                cout << "2\n";
                int p = 0;
                for(int i=1;i<=n;i++){
                    cout << p+1 << " ";
                    p ^= 1;
                }
                cout << "\n";
            }else if(ind != -1){
                //1 2 1 1 2 
                int p = 0;
                cout << "2\n";
                for(int i=0;i<ind;i++){
                    cout << p+1 << " ";
                    p ^= 1;
                }
                cout << p + 1 << " ";
                for(int i=ind+1;i<n;i++){
                    cout << p+1 << " ";
                    p ^= 1;
                }
                cout << "\n";
            }else{
                // 2 1 2 1 3
                cout << "3\n";
                for(int i=1;i<=n-1;i++) cout << (i%2 + 1) << " ";
                cout << "3\n";
            }
        }
    }
}
