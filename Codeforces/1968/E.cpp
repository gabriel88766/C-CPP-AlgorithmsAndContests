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
        if(n == 2){
            cout << "1 1\n1 2\n";
        }else if(n == 3){
            cout << "2 1\n2 3\n3 1\n";
        }else if(n == 4){
            cout << "1 1\n1 3\n4 3\n4 4\n";
        }else if(n == 5){
            cout << "1 1\n1 3\n1 4\n2 1\n5 5\n";
        }else{
            map<pair<int,int>, bool> used;
            int xi = 1, yi = 2;
            int cnt = 2;
            cout << "1 1\n1 2\n";
            used[{1,1}] = used[{1,2}] = 1;
            while(yi != n){
                yi = min(yi + 2, n);
                used[{1, yi}] = 1;
                cnt++;
                cout << 1 << " " << yi << "\n";
            }
            cnt += 2;
            cout << n-1 << " " << n << "\n";
            used[{n-1, n}] = true;
            cout << n << " " << n << "\n";
            used[{n, n}] = true;
            assert(cnt <= n);
            xi = yi = 1;
            while(cnt < n){
                if(used.count({xi, yi})){
                    xi++;
                    if(xi > n){
                        xi = 1;
                        yi++;
                    }
                }else{
                    cout << xi << " " << yi << "\n";
                    cnt++;
                    used[{xi, yi}] = true;
                }
            }
        }
        cout << "\n";
    }
}
