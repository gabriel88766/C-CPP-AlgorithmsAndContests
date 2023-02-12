#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, cnt = 0;
    cin >> x;
    while(x){
        cout << "Case " << ++cnt << ": " << x << "\n";
        cin >> x;
    }
}