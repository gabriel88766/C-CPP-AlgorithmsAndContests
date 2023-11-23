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
        int n, m, k;
        cin >> n >> m >> k;
        int minp = n + m - 2;
        if(k < minp) cout << "NO\n";
        else if((k-minp) % 2) cout << "NO\n";
        else{
            //is possible
            if(k == minp){
                cout << "YES\n";
                for(int i=1;i<n;i++){
                    for(int j=1;j<m;j++){
                        cout << "R ";
                    }
                    cout << "\n";
                }
                int x = n % 2;
                for(int j=1;j<m;j++){
                    if(x) cout << "R ";
                    else cout << "B ";
                    x ^= 1;
                }
                cout << "\n";
                x = 1;
                for(int i=1;i<n;i++){
                    for(int j=1;j<=m;j++){
                        if(j == 1){
                            if(x) cout << "R ";
                            else cout << "B ";
                            x ^= 1;
                        }else cout << "R ";
                    }
                    cout << "\n";
                }
            }else{
                cout << "YES\n";
                for(int i=1;i<n;i++){
                    int x = (n + m - 3) % 2;
                    for(int j=1;j<m;j++){
                        if(j == 1) cout << "R ";
                        else if(x) cout << "R ";
                        else cout << "B ";
                    }
                    cout << "\n";
                }
                int x = n % 2;
                for(int j=1;j<m;j++){
                    if(j != (m-1)){
                        if(x) cout << "R ";
                        else cout << "B ";
                        x ^= 1;
                    }else{
                        x ^= 1;
                        if(x) cout << "R ";
                        else cout << "B ";
                    }
                }
                cout << "\n";
                x = 1;
                for(int i=1;i<n;i++){
                    for(int j=1;j<=m;j++){
                        if(j == 1){
                            if(x) cout << "R ";
                            else cout << "B ";
                            x ^= 1;
                        }else if(i == 1 && j == 2) cout << "B ";
                        else{
                            int xx = (n+m-2) % 2;
                            if(xx) cout << "R ";
                            else cout << "B ";
                        }
                    }
                    cout << "\n";
                }
            }
        }
    }
}
