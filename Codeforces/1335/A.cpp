#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int y = n/2;
        int x = n-y;
        if(x == y) x++,y--;
        cout << y << "\n";
    }
}