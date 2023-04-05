#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int arr[] = {4, 8, 15, 16, 23, 42};
set<int> st[6];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        for(int j=0;j<6;j++) if(arr[j] == aux) st[j].insert(i);
    }
    int minv = 0;
    while(true){
        bool ok = true;
        int mini = 0;
        for(int i=0;i<6;i++){
            auto it = st[i].lower_bound(mini);
            if(it != st[i].end()){
                mini = *it;
                st[i].erase(it);
            }else{
                ok = false; break;
            }
        }
        if(!ok) break;
        else minv++;
    }
    
    cout << n - minv*6;
}
