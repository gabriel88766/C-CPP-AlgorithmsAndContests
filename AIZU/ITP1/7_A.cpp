#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    while(a != -1 || b != -1 || c != -1){
        int sum = a+b;
        if(a == -1 || b == -1) cout << "F\n";
        else if(sum >= 80) cout << "A\n";
        else if(sum >= 65) cout << "B\n";
        else if(sum >= 50) cout << "C\n";
        else if(sum >= 30){
            if(c >= 50) cout << "C\n";
            else cout << "D\n";
        }else cout << "F\n";
        cin >> a >> b >> c;
    }
}

