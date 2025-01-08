#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct LinkedList{
    LinkedList *prev, *next;
    int val;
    LinkedList(){}
    LinkedList(int num){
        val = num;
        prev = nullptr;
        next = nullptr;
    }
    void insertRight(LinkedList *r){
        if(this->next != nullptr){
            this->next->prev = r;
            r->next = this->next;
        }
        r->prev = this;
        this->next = r;
    }
    void insertLeft(LinkedList *l){
        if(this->prev != nullptr){
            l->prev = this->prev;
            this->prev->next = l;
        }
        this->prev = l;
        l->next = this;
    }
};
const int N = 2e5+3;
LinkedList vx[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> ans(n+1, -1);
        vector<int> k(n+1), s(n+1);
        for(int i=1;i<=n;i++) cin >> k[i] >> s[i];
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        for(int i=1;i<=n;i++){
            vx[i].val = i;
            vx[i].next = nullptr;
            vx[i].prev = nullptr;
        }
        for(int i=2;i<=n;i++){
            vx[i].insertLeft(&vx[i-1]);
        }
        LinkedList *head = &vx[1];
        set<pair<int,int>> st; //backward increasing of priorities
        for(int i=n;i>=1;i--){
            if(st.size() == 0 || prev(st.end())->first < k[i]){
                st.insert({k[i], i});
            }
        }

        for(int i=1;i<=d;i++){
            if(head != nullptr){
                int x = head->val;
                auto aux = head->next;
                head->next = nullptr;
                head = aux;
                if(head != nullptr) head->prev = nullptr; 
                if(ans[x] == -1){
                    ans[x] = i;
                }
                //check if x is in dq
                assert(st.size());
                if(prev(st.end())->second == x){
                    st.erase(prev(st.end()));
                }
                pq.push({i + s[x], s[x], x});
            }
            while(pq.size()){
                auto [x, y, z] = pq.top();
                if(x == i){
                    pq.pop();
                    //go back to the line
                    if(st.size()){
                        //Find the first greater or equal, if any
                        auto it = st.lower_bound({k[z], -1});
                        if(it == st.end()){
                            head->insertLeft(&vx[z]);
                            head = &vx[z];
                            st.insert({k[z], z});
                        }else{
                            LinkedList *left = &vx[it->second];
                            left->insertRight(&vx[z]);
                            if(it->first == k[z]){
                                st.erase(it);
                            }
                            st.insert({k[z], z});
                        }
                    }else{
                        st.insert({k[z], z});
                        head = &vx[z];
                        assert(head->next == nullptr);
                        assert(head->prev == nullptr);
                        //line is empty.
                    }
                }else break;
            }
        }
        int rans = 0;
        for(int i=1;i<=n;i++){
            if(ans[i] == -1){
                rans = -1;
                break;
            }else rans = max(rans, ans[i]);
        }
        cout << rans << "\n";
    }
}
