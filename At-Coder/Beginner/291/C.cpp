#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char movet[] = {'R','L','U','D'};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<pair<int,int>, int> mp;
    mp[{0,0}] = 1;
    int x = 0, y = 0;
    int n;
    string s;
    cin >> n >> s;
    bool ok = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(s[i] == movet[j]){
                x += dx[j];
                y += dy[j];
                break;
            }
        }
        if(mp[{x,y}]) ok = true;
        mp[{x,y}] = 1;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}   
