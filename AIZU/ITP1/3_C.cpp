#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    while(a || b){
        if(a > b) swap(a,b);
        cout << a << " " << b << "\n";
        cin >> a >> b;
    }
}