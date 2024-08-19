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
        if(n == 1){
            cout << 9999 << "\n";
            for(int i=1;i<=9999;i++){
                cout << i+1 << " " << i << "\n";
            }
            continue;
        }
        string s = to_string(n);
        int sz = s.size();
        vector<pair<int,int>> ans;
        for(int i=1;;i++){
            string aux;
            int p = 0;
            while(aux.size() != i){
                aux += s[p];
                p++;
                p %= sz;
            }
            //sz * a - b = i
            //n  * a - b = num;
            int num = stoi(aux);
            assert(num >= i);
            if(num >= 1000000) break;
            if(!((num - i) % (n-sz))){
                int a = (num - i) / (n-sz);
                int b = sz*a - i;
                if(b <= 10000 && b >= 1 && a <= 10000 && a >= 1) ans.push_back({a, b});
            }
            
        }
        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++){
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
