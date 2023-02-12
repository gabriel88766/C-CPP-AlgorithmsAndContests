#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    int n, a=0, b=0;
    cin >> n;
    for(int i=0;i<n;i++){
        string sa, sb;
        cin >> sa >> sb;
        if(sa > sb) a+=3;
        else if(sa < sb) b+=3;
        else a++, b++;
    }
    cout << a << " " << b << "\n";

}

