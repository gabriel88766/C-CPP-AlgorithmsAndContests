#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 501;
ll ans[N];
void init(){
    for(int i=2;i<=500;i++){
        ans[i] = (i * (i-1))/2;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; //n <= 100000
        vector<int> aux;
        for(int i=500;i>=2;i--){
            while(n >= ans[i]){
                aux.push_back(i);
                n -= ans[i];
            }
        }
        int sum = 0;
        for(auto &x : aux) sum += x;
        assert(sum <= 500); //should be, at least. not proved.
        cout << sum << "\n";
        int x = 1, y = 1;
        for(auto &num : aux){
            for(int i=0;i<num;i++){
                cout << x << " " << y << "\n";
                y++;
            }
            x++;
        }
    }   
}
