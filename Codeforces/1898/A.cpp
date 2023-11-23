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
        string s;
        cin >> s;
        int cnt = 0;
        for(int i=0;i<n;i++) if(s[i] == 'B') cnt++;
        if(cnt == k) cout << "0\n";
        else if(cnt > k){
            int ind = 0;
            while(cnt > k){
                if(s[ind] == 'B') cnt--;
                ind++;
            }
            cout << "1\n";
            cout << ind << " " << "A\n";
        }else{
            int ind = 0;
            while(k > cnt){
                if(s[ind] == 'A') cnt++;
                ind++;
            }
            cout << "1\n";
            cout << ind << " " << "B\n";
        }
    }
}
