#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        ll cur = 0;
        vector<int> dif;
        for(int i=0;i<n;i++){
            int tL = i, tR = n-i-1;
            if(s[i] == 'L'){
                cur += tL;
                dif.push_back(max(tR-tL, 0));
            }else{
                cur += tR;
                dif.push_back(max(tL-tR, 0));
            }
        }
        sort(dif.begin(), dif.end(), greater<int>());
        for(int i=0;i<n;i++){
            cur += dif[i];
            cout << cur << " ";
        }
        cout << "\n";
    }
}
