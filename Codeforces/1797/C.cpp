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
        //ask 1,1 // 1, n
        cout << "? 1 1\n";
        cout.flush();
        int ans1;
        cin >> ans1;
        cout << "? 1 " << m << "\n";
        cout.flush();
        int ans2;
        cin >> ans2;
        if(ans1 + ans2 == (m-1)){
            int y = 1+ans1;
            cout << "? " << 1 << " " << y << "\n";
            cout.flush();
            int ans3;
            cin >> ans3;
            cout << "! " << 1+ans3 << " " << y << "\n";
            cout.flush();
        }else if(ans1 == ans2){
            int x = 1 + ans1;
            cout << "? " << x << " " << 1 << "\n";
            cout.flush();
            int ans3;
            cin >> ans3;
            cout << "! " << x << " " << 1+ans3 << "\n";
            cout.flush(); 
        }else{
            if(ans1 > ans2){
                int y = ans1 + 1;
                cout << "? " << 1 << " " << y << "\n";
                cout.flush();
                int ans3;
                cin >> ans3;
                cout << "! " << 1+ans3 << " " << y << "\n";
                cout.flush();
            }else{
                int y = m-ans2;
                cout << "? " << 1 << " " << y << "\n";
                cout.flush();
                int ans3;
                cin >> ans3;
                cout << "! " << 1+ans3 << " " << y << "\n";
                cout.flush();
            }
        }
    }
}
