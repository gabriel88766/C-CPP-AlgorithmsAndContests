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
        string s;
        cin >> s;
        int qt0 = 0, qt1 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') qt0++;
            else qt1++;
        }
        int mlen = 0, qt20 = 0, qt21 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') qt20++;
            else qt21++;
            if(qt20 <= qt1 && qt21 <= qt0) mlen++;
            else break;
        }
        int n = s.size();
        cout << n - mlen << "\n";
    }
}
