
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