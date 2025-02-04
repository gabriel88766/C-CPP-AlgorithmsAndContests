#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], pl[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pl[a[i]] = i;
    }
    for(int i=1;i<=n;i++){//find the lowest and try rotation x erases
        int av = pl[i] - 1;
        int bv = n - pl[i] + 1;
        if(min(av, bv) <= k){
            //found
            //try rotation
            vector<pair<int,int>> a1, a2;
            if(bv <= k){
                int op = k - bv;
                for(int j=pl[i];j<=n;j++){
                    while(a1.size() && a1.back().first > a[j] && op >= a1.back().second){
                        op -= a1.back().second;
                        a1.pop_back(); 
                    }
                    a1.push_back({a[j], 0});
                }
                for(int j=1;j<pl[i];j++){
                    while(a1.size() && a1.back().first > a[j] && op >= a1.back().second){
                        op -= a1.back().second;
                        a1.pop_back(); 
                    }
                    a1.push_back({a[j], 1});
                }
                while(op){
                    a1.pop_back();
                    op--;
                }
            }else a1.push_back({INF_INT, 0});

            
            //try erase everything
            if(av <= k){
                int op = k;
                for(int j=1;j<=n;j++){
                    while(a2.size() && a2.back().first > a[j] && op >= a2.back().second){
                        op -= a2.back().second;
                        a2.pop_back(); 
                    }
                    a2.push_back({a[j], 1});
                }
                while(op){
                    a2.pop_back();
                    op--;
                }
            }else a2.push_back({INF_INT, INF_INT});

            for(auto &[a, b] : a1) b = 0;
            for(auto &[a, b] : a2) b = 0;
            if(a1 < a2){
                for(auto &x : a1) cout << x.first << " ";
            }else{
                for(auto &x : a2) cout << x.first << " ";
            }
            cout << "\n";
            break;
        }
    }
}
