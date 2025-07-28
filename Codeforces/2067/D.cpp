#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void ans(char c){
    cout << "! " << c << "\n";
    cout.flush();
}

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
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<int> cnt(n+1);
        bool c2 = false;
        for(int i=1;i<=n;i++){
            cnt[v[i]]++;
            if(cnt[v[i]] >= 2){
                c2 = true;
            }
        }
        
        if(c2){
            int j = -1;
            for(int i=1;i<=n;i++){
                if(cnt[i] == 0){
                    j = i;
                    break;
                }
            }
            //j hasn't out edge
            int an = 1;
            if(an == j) an++;
            int a = ask(j, an);
            if(a == 0) ans('A');
            else ans('B');
        }else{
            //all different, functional graph
            //find vertices of 1 and n, check distance
            int i, j;
            for(int k=1;k<=n;k++){
                if(v[k] == 1) i = k;
                if(v[k] == n) j = k;
            }
            int a = ask(i, j);
            if(a > n-1) ans('B');
            else if(a == n-1){//a = n-1
                int b = ask(j, i);
                if(b == n-1) ans('B');
                else ans('A');
            }else ans('A');
        }
        
    }
}
