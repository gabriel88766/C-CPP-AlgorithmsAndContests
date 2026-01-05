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
        vector<int> v(n);
        vector<bool> has(n+1, false);
        for(int i=0;i<n;i++){
            cin >> v[i];
            has[v[i]] = true;
        }
        int dh = -1;
        for(int i=1;i<=n;i++){
            if(!has[i]) dh = i;
        }
        if(dh == -1){
            for(int i=0;i<k;i++){
                cout << v[i] << " ";
            }
            cout << "\n";
        }else{
            int ah = -1;
            for(int i=1;i<=n;i++){
                if(i != dh && i != v[n-1]) ah = i;
            }
            for(int i=0;i<k;i++){
                if(i % 3 == 0) cout << dh << " ";
                if(i % 3 == 1) cout << ah << " ";
                if(i % 3 == 2) cout << v[n-1] << " ";
            }
            cout << "\n";
        }
        

    }
}
