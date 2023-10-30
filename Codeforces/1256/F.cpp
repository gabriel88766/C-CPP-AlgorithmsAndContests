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
        string s,t;
        cin >> n >> s >> t;
        string s1 = s, s2 = t;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1 != s2) cout << "NO\n";
        else{
            s1.resize(unique(s1.begin(), s1.end()) - s1.begin());
            if(s1.size() != s2.size()) cout << "YES\n";
            else{
                //check parity // len(s) <= 26 (allowed O(n^2 t))
                int cnt1 = 0, cnt2 = 0;
                s1 = s, s2 = t;
                for(int i=0;i<n;i++){
                    for(int j=1;j<n;j++){
                        if(s1[j-1] > s1[j]){
                            swap(s1[j-1], s1[j]);
                            cnt1++;
                        }
                        if(s2[j-1] > s2[j]){
                            swap(s2[j-1], s2[j]);
                            cnt2++;
                        }
                    }
                }
                if(abs(cnt1-cnt2)%2) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
}
