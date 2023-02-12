#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,w,h,r;
    cin >> w >> h >> x >> y >> r;
    bool ok = true;
    if(x-r < 0 || x + r > w) ok = false;
    if(y-r < 0 || y + r > h) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}