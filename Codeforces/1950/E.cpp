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
        for(int i=1;i<=n;i++){
            if(!(n % i)){
                int cnt = 0;
                for(int j=0;j<i;j++){
                    vector<int> cc(26);
                    for(int k=j;k<n;k+=i){
                        cc[s[k]-'a']++;
                    }
                    int c2 = 0;
                    vector<int> cx;
                    for(int k=0;k<26;k++){
                        cx.push_back(cc[k]);
                    }
                    sort(cx.begin(), cx.end(), greater<int>());
                    for(int k=1;k<26;k++) cnt += cx[k];
                }
                if(cnt <= 1){
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
}
