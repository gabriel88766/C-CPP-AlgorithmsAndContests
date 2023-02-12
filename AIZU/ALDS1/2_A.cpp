    #include <bits/stdc++.h>

    using namespace std;

    int main(){
        int n, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        //bubble sort (another o(n2))
        for(int i=0;i<n;i++){
            for(int j=(n-1); j>=(i+1);j--){
                if(v[j] < v[j-1]){
                    swap(v[j], v[j-1]);
                    cnt++;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout << v[i];
            if(i == (n-1)) cout << "\n";
            else cout << " ";
        }
        cout << cnt << "\n";
    }