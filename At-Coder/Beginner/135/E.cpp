#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k, x, y, d, curx = 0, cury = 0;
    cin >> k >> x >> y;
    d = abs(x)+abs(y);
    vector<pair<int,int>> ans;
    if(d == k){
        cout << "1\n" << x << " " << y;
        return 0;
    }
    while(d > 2*k){
        for(int i=0;i<k;i++){
            if(x > curx) curx++;
            else if(x < curx) curx--;
            else if(y > cury) cury++;
            else cury--;
        }
        d = abs(x-curx) + abs(y-cury);
        ans.push_back({curx, cury});
    }
    if(k % 2){
        if(d % 2){
            if(abs(curx-x) >= k){
                if(curx < x) curx+=k;
                else curx-=k;
            }else{
                int j2 = k - abs(curx-x);
                curx = x;
                if(y > cury) cury += j2;
                else cury -= j2;
            }
            ans.push_back({curx, cury});
        }
    }else{
        if(d % 2){
            cout << "-1\n";
            return 0;
        }
    }
    
    int d1 = abs(curx-x);
    int d2 = abs(cury-y);
    int diff = abs(d1-d2)/2;
    if(d1 >= d2){
        if(y > cury) cury += k-diff;
        else cury -= k-diff;
        if(x > curx) curx += diff;
        else curx -= diff;
    }else{
        if(x > curx) curx += k-diff;
        else curx -= k-diff;
        if(y > cury) cury += diff;
        else cury -= diff;
    }
    ans.push_back({curx,cury});
    ans.push_back({x,y});
    
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.first << " " << x.second << "\n";
    }
}
