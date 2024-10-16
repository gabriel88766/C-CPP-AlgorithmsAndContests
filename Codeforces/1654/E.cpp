#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e7+4;
const int mid = 2e7+5e6;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    int opt1 = 0, opt2 = 0;
    //all sequences with up to 500 members, any diff
    for(int i=1;i<=n;i++){
        vector<int> aux;
        for(int j=i+1;j<=min(n, i+499);j++){
            int di = j - i;
            int dx = v[j] - v[i];
            if(!(dx % di)){
                aux.push_back(dx/di);
                cnt[mid+aux.back()]++;
            }
        }
        int mv = 0;
        for(auto x : aux) mv = max(mv, cnt[mid+x]);
        opt1 = max(opt1, mv + 1);
        for(auto x : aux) cnt[mid + x]--;
    }
    //-200 <= r <= 200
    vector<int> aux;
    aux.reserve(n);
    for(int r=-200;r<=200;r++){
        for(int j=1;j<=n;j++){
            aux.push_back(r*(j-1) + v[j]);
            cnt[mid + aux.back()]++;
        }
        int mv = 0;
        for(auto x : aux) mv = max(mv, cnt[mid+x]);
        opt2 = max(opt2, mv);
        for(auto x : aux) cnt[mid + x]--;
        while(aux.size())aux.pop_back();
    }
    cout << n - max(opt1, opt2) << "\n";
}
