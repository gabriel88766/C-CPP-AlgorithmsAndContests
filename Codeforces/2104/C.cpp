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
        string s;
        cin >> n >> s;
        if(s[n-1] == s[0]){
            //s[n-1] is win!
            if(s[0] == 'A') cout << "Alice\n";
            else cout << "Bob\n";
        }else{
            if(s[0] == 'A'){
                //if there is any B different of n-1, then Bob wins, otherwise alice wins
                bool ok = false;
                for(int i=1;i<n-1;i++) if(s[i] == 'B') ok = true;
                if(ok) cout << "Bob\n";
                else cout << "Alice\n";
            }else{
                //B xxxxxxx A
                if(n == 2) cout << "Bob\n";
                else if(s[n-2] == 'A') cout << "Alice\n";
                else cout << "Bob\n";
            }
        }
    }
}
