#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    const ll neg = 0x8000000000000000;
    cin >> t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pair<ll,ll> dir1, dir2, dir3;
        char isOK = true;
        //copy paste
        dir1 = {x2-x1, y2-y1}, dir2 = {x3-x1, y3-y1}, dir3 ={x4-x1, y4-y1};
        ll cross1 = dir1.first * dir2.second - dir1.second * dir2.first;
        ll cross2 = dir1.first * dir3.second - dir1.second * dir3.first;
        if(cross1 && cross2){
            if((cross1 > 0 && cross2 > 0) || (cross1 < 0 && cross2 < 0)) isOK = false;
        }else if(!cross1 && !cross2){
            if(dir1.first){
                if((dir1.first > 0 && dir2.first < 0) || (dir1.first < 0 && dir2.first > 0)){
                    if((dir1.first > 0 && dir3.first < 0) || (dir1.first < 0 && dir3.first > 0)){
                        isOK = false;
                    }
                }
            }else{
                if((dir1.second > 0 && dir2.second < 0) || (dir1.second < 0 && dir2.second > 0)){
                    if((dir1.second > 0 && dir3.second < 0) || (dir1.second < 0 && dir3.second > 0)){
                        isOK = false;
                    }
                }
            }
            dir1 = {x1-x2, y1-y2}, dir2 = {x3-x2, y3-y2}, dir3 ={x4-x2, y4-y2};
            if(dir1.first){
                if((dir1.first > 0 && dir2.first < 0) || (dir1.first < 0 && dir2.first > 0)){
                    if((dir1.first > 0 && dir3.first < 0) || (dir1.first < 0 && dir3.first > 0)){
                        isOK = false;
                    }
                }
            }else{
                if((dir1.second > 0 && dir2.second < 0) || (dir1.second < 0 && dir2.second > 0)){
                    if((dir1.second > 0 && dir3.second < 0) || (dir1.second < 0 && dir3.second > 0)){
                        isOK = false;
                    }
                }
            }
        }
        //swap x1,x3 and x2,x4 before copypaste
        swap(x1,x3), swap(y1, y3), swap(x2, x4), swap(y2, y4);
        dir1 = {x2-x1, y2-y1}, dir2 = {x3-x1, y3-y1}, dir3 ={x4-x1, y4-y1};
        cross1 = dir1.first * dir2.second - dir1.second * dir2.first;
        cross2 = dir1.first * dir3.second - dir1.second * dir3.first;
        if(cross1 && cross2){
            if((cross1 > 0 && cross2 > 0) || (cross1 < 0 && cross2 < 0)) isOK = false;
        }
        if(isOK) cout << "YES\n";
        else cout << "NO\n";
    }
}
