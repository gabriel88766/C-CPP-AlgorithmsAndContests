#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ask(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

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
        int ln = -1;
        vector<int> v;
        vector<int> ans(n, -1);
        for(int i=2;i<n;i++){
            int ans = ask(1, i);
            if(ans != 1){
                ln = i;
                break;
            }
        }
        for(int i=1;i<ln;i++){
            ans[i] = 0;
        }
        ans[ln] = 1;
        deque<int> par;
        for(int i=2;i<=ln;i++) par.push_back(i);
        for(int i=ln+1;i<n;i++){
            while(par.size() >= 2){
                int x = ask(par.front(), i);
                if(x == 0){
                    ans[i] = par.front();
                    par.pop_front();
                    par.push_back(i);
                    break;
                }else{
                    par.pop_front();
                }
            }
            if(ans[i] == -1){
                assert(par.size() == 1);
                ans[i] = par.front();
                par.pop_front();
                par.push_back(i);
            }
        }
        cout << "! ";
        for(int i=1;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
        cout.flush();
        
    }
}
