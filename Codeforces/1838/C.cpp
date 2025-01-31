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
        if((n % 2) && (m % 2)){ //both odd..
            vector<int> v;
            for(int i=0;i<n;i+=2) v.push_back(i);
            for(int i=1;i<=n-2;i+=2) v.push_back(i);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    int x = j + 1 + v[i] * m;
                    cout << x << " ";
                }
                cout << "\n";
            }
        }else{
            if(m % 2 == 0){
                int x = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        int x = i*m + j + 1;
                        cout << x << " ";
                    }
                    cout << "\n";
                }
            }else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        int x = j*n + i + 1;
                        cout << x << " ";
                    }
                    cout << "\n";
                }
            }
        }
    }
}
