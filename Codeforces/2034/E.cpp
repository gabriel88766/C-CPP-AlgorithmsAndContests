#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int fat[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int n;
vector<int> opp(vector<int> &perm){
    vector<int> ans;
    for(auto x : perm) ans.push_back(n + 1 - x);
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
        int  k;
        cin >> n >> k;
        if(n == 1 && k > 1) cout << "NO\n";
        else if(n == 2 && k > 2) cout << "NO\n";
        else if(n == 3 && k > 6) cout << "NO\n";
        else if(n == 4 && k > 24) cout << "NO\n";
        else if(n == 5 && k > 120) cout << "NO\n";
        else if(n == 6 && k > 720) cout << "NO\n";
        else if(n == 7 && k > 5040) cout << "NO\n";
        else if(n == 8 && k > 40320) cout << "NO\n";
        else if(k == 1){
            if(n == 1){
                cout << "YES\n";
                cout << "1\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if(k % 2 == 0){
                vector<int> perm;
                for(int i=1;i<=n;i++) perm.push_back(i);
                cout << "YES\n";
                for(int i=0;i<k;i+=2){
                    for(auto x : perm) cout << x << " ";
                    cout << "\n";
                    for(auto x : perm) cout << n-x+1 << " ";
                    cout << "\n";
                    next_permutation(perm.begin(), perm.end());
                }
            }else{
                //try k == 3
                if(n % 2){
                    //both odd
                    if(n <= 8 && fat[n] < k + 3) cout << "NO\n";
                    else{
                        vector<int> perm;
                        vector<int> perms[3];
                        cout << "YES\n";
                        for(int i=1;i<=n;i++){
                            perm.push_back(i);
                            perms[0].push_back(i);
                        }
                        int xs = 2 + n / 2;
                        int cd = xs - 1;
                        for(int i=1;i<=n;i++){
                            perms[1].push_back(xs - cd);
                            perms[2].push_back(cd);
                            cd = xs - cd;
                            xs++;
                        }
                        reverse(perms[1].begin(), perms[1].end());
                        reverse(perms[2].begin(), perms[2].end());
                        for(auto x : perms[0]) cout << x << " ";
                        cout << "\n";
                        for(auto x : perms[1]) cout << x << " ";
                        cout << "\n";
                        for(auto x : perms[2]) cout << x << " ";
                        cout << "\n";
                        k -= 3;
                        for(int i=0;i<k;i+=2){
                            while(perm == perms[0] || perm == perms[1] || perm == perms[2] || \
                                perm == opp(perms[0]) || perm == opp(perms[1]) || perm == opp(perms[2])) next_permutation(perm.begin(), perm.end());
                            for(auto x : perm) cout << x << " ";
                            cout << "\n";
                            for(auto x : perm) cout << n-x+1 << " ";
                            cout << "\n";
                            next_permutation(perm.begin(), perm.end());
                        }
                    }
                }else cout << "NO\n";
            }
        }
    }
}
