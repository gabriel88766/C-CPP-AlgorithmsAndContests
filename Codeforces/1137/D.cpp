#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string s1 = "next 0\n";
string s2 = "next 0 1\n";
string s4 = "next 0 1 2 3 4 5 6 7 8 9\n";
string s3;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    while(true){
        
        cout << s1;
        cout.flush();
        cin >> n;
        for(int i=0;i<n;i++) cin >> s3;
        
        cout << s2;
        cout.flush();
        cin >> n;
        for(int i=0;i<n;i++) cin >> s3;
        if(n  == 2){
            break;
        }
    }
    while(true){
        cout << s4;
        cout.flush();
        cin >> n;
        for(int i=0;i<n;i++) cin >> s3;
        if(n == 1){
            cout << "done";
            break;
        }
    }
}
