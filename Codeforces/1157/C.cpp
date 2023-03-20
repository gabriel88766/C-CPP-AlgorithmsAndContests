#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[200005];
int checkMax(int l, int r, int li){
    if(v[l] <= li && v[r] <= li) return 0;
    int L = 0, R = 0;
    for(int i=l;i<=r;i++){
        if(v[i] > v[i-1]) L++;
        else break;
    }
    for(int i=r;i>=l;i--){
        if(v[i] > v[i+1]) R++;
        else break;
    }
    if(L > R) return L;
    else return -R;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    int p1=1, p2=n;
    int ans = 0;
    string s;
    int li = 0;
    while(true){
        if(v[p1] < v[p2]){
            if(v[p1] > li){
                li = v[p1++];
                s += 'L';
            }else if(v[p2] > li){
                li = v[p2--];
                s += 'R';
            }else break;
            ans++;
        }else if(v[p1] > v[p2]){
            if(v[p2] > li){
                s += 'R';
                li = v[p2--];
            }else if(v[p1] > li){
                s += 'L';
                li = v[p1++];
            }else break;
            ans++;
        }else{
            int magic = checkMax(p1, p2, li);
            if(magic == 0) break;
            else if(magic > 0){
                ans += magic;
                for(int i=0;i<magic;i++) s += 'L';
            }else{
                ans += abs(magic);
                for(int i=0;i<abs(magic);i++) s += 'R';
            }
            break;
        }
    }
    cout << ans << "\n" << s;
}
