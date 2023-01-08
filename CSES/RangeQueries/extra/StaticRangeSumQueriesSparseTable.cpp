//sparse table
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;
 
ll sparse[200005][20];
vector<int> v;
void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = sparse[i][j-1] + sparse[i + (1 << (j-1))][j-1];
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}
 
ll query(int a, int b){
    ll sum = 0;
    for(int i=20;i>=0;i--){
        int x = 1 << i;
        if((b-a+1) >= x){
            sum += sparse[a-1][i];
            a+= x;
        } 
    }
    return sum;
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    build();
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << query(a,b) << "\n";
    }
}