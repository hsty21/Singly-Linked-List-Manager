#include<iostream>
#include<limits>
class Node{
    public:
        int key;
        int data;
        Node* next;
        Node():key(0), data(0), next(nullptr){}
        Node(int k, int d):key(k), data(d), next(nullptr){}
};
class singlyLinkedList{
    public:
        Node*  head;
        int count;
        singlyLinkedList(): head(nullptr), count(0){}
        singlyLinkedList(Node* n){
            head =  n;
            n->next = nullptr;
            count=0;
        }
        ~singlyLinkedList(){
            Node* temp ;
            while(head!=nullptr){
                temp = head;
                head = head->next;
                delete temp;
            }
        }
        Node* keyExist(int k){
            Node* temp = head;
            Node* temp2 = nullptr;
            while(temp!=nullptr){
                if(temp->key==k){
                    temp2 = temp;
                    break;
                }
                temp = temp->next;
            }
            return temp2;
        }
        bool isEmpty(){
            if(head == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
        void append(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key already exist in the list"<<std::endl;
                return;
            }
            if(isEmpty()){
                head = n;
                n->next = nullptr;
                count++;
            }
            else{
                Node* temp = head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->next = n;
                n->next = nullptr;
                count++;
            }
        }
        void prepend(Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The key already exist in the list"<<std::endl;
                return;
            }
            if(isEmpty()){
                head=  n;
                n->next = nullptr;
                count++;
            }
            else{
                Node* temp = head;
                head = n;
                n->next = temp;
                count++;
            }
        }
        void insertAfterKey(int k, Node* n){
            if(keyExist(n->key)!=nullptr){
                std::cout<< "The new node's key already exist in the list"<<std::endl;
                return;
            }
            if(keyExist(k)==nullptr){
                std::cout<< "The required node doesnt exist in the list"<<std::endl;
            }
            else{
                Node* current = keyExist(k);
                Node* after = current->next;
                current->next = n;
                n->next = after;
                count++;
            }
        }
        void deleteKey(int k){
            Node* current = keyExist(k);
            if(current==nullptr){
                std::cout<< "The key doesnt exist in the list"<<std::endl;
                return;
            }
            else if(current == head){
                head = head->next;
            }
            else{
                Node* prev =  head;
                while(prev->next!=current){
                    prev = prev->next;
                }
                prev ->next = current->next;
            }
            delete current;
            count--;
        }
        void update(int k, int d2){
            Node* temp = keyExist(k);
            if(temp == nullptr){
                std::cout<< "The key doesnt exist in the list"<<std::endl;
                return;
            }
            else{
                temp->data = d2;
            }
        }
        int Count(){
            return count;
        }
        void display(){
            Node*  temp = head;
            if(temp == nullptr){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                std::cout<< "Head-->";
                while(temp!=nullptr){
                    std::cout<< " ( "<<temp->key<<" , "<<temp->data<< " )-->";
                    temp = temp->next;
                }
                std::cout<< " Null"<<std::endl;
            }
        }
        void reverse(){
            int size = count;
            Node*  temp = head;
            Node* rev = head;
            int tem;
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                while(size!= count/2){
                    for(int i=1;i<size;i++){
                        rev = rev->next;
                    }
                    tem = temp->data;
                    temp->data = rev->data;
                    rev->data = tem;
                    tem = temp->key;
                    temp->key = rev->key;
                    rev->key = tem;
                    rev = head;
                    temp = temp->next;
                    size--;
                }
            }
        }
        void sort(){
            if(isEmpty()){
                std::cout<< "The list is empty"<<std::endl;
                return;
            }
            else{
                Node* min = head;
                Node* temp = head;
                int tem;
                while(temp!=nullptr){
                    while(min!=nullptr){
                        if(temp->data>min->data){
                            tem = temp->data;
                            temp->data = min->data;
                            min->data = tem;
                            tem = temp->key;
                            temp->key = min->key;
                            min->key = tem;
                        }
                        min = min->next;
                    }
                    temp = temp->next;
                }
            }
        }
        Node* findMiddle(){
            int size = count/2;
            Node*  temp = head;
            for(int i=1;i<=size;i++){
                temp = temp->next;
            }
            return temp;
        }
};
void Merge(singlyLinkedList* s1,singlyLinkedList* s2,singlyLinkedList* merge){
    Node* temp = s1->head;
    while(temp!=nullptr){
        Node* newNode = new Node();
        newNode->key = temp->key;
        newNode->data = temp->data;
        merge->append(newNode);
        temp = temp->next;
    }
    temp = s2->head;
    while(temp!=nullptr){
        Node* newNode = new Node();
        newNode->key = temp->key;
        newNode->data = temp->data;
        merge->append(newNode);
        temp = temp->next;
    }
}
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Inavlid input! please try again"<<std::endl;
        }
        else{
            return num;
        }
    }
}
int main(){
    singlyLinkedList s;
    int op, d, k, key1;
    bool leave = false;
    while(leave== false){
        std::cout<< "################operations################"<<std::endl;
        std::cout<< "1.Does a key exist in the list?\n2.Is the list empty?\n3.Append a new node\n4.Prepend a anew node\n5.Insert a node after a key\n6.Delete a node by key\n7.Update a node's data\n8.How many elements are in the list\n9.Display the list\n10.Reverse the list\n11.Sort the list\n12.Find the middle node\n13.Leave"<<std::endl;
        std::cout<< "Enter the number of operation"<<std::endl;
        op = valid(op);
        while(op>13 || op<1){
            std::cout<< "Invalid number of operation! please try again"<<std::endl;
            op = valid(op);
        }
        Node* n = new Node();
        switch(op){
            case 1:
                std::cout<< "Enter the key valkue you ara looking for";
                k = valid(k);
                n = s.keyExist(k);
                if(n == nullptr){
                    std::cout<< "The key doesnt exist in the list"<<std::endl;
                }
                else{
                    std::cout<< "( "<<n->key<< " , "<<n->data<< " )"<<std::endl;
                }
                break;
            case 2:
                std::cout<< "Is the list empty? "<<s.isEmpty()<<std::endl;
                break;
            case 3:
                std::cout<< "Enter the value of the key: ";
                k = valid(k);
                std::cout<< "Enter the value of the data: ";
                d= valid(d);
                n->key = k;
                n->data = d;
                s.append(n);
                break;
            case 4:
                std::cout<< "Enter the value of the key: ";
                k = valid(k);
                std::cout<< "Enter the value of the data: ";
                d= valid(d);
                n->key = k;
                n->data = d;
                s.prepend(n);
                break;
            case 5:
                std::cout<< "Enter the value of the key: ";
                k = valid(k);
                std::cout<< "Enter the value of the data: ";
                d= valid(d);
                n->key = k;
                n->data = d;
                std::cout<< "Enter the value of the key you want to insert after: ";
                key1 = valid(key1);
                s.insertAfterKey(key1,n);
                break;
            case 6:
                std::cout<< "Enter the key value of the node you want to delete: ";
                key1 = valid(key1);
                s.deleteKey(key1);
                break;
            case 7:
                std::cout<<"Enter the value of the key your want to update: ";
                key1 = valid(key1);
                std::cout<<"Enter the new data: ";
                d = valid(d);
                s.update(key1, d);
                break;
            case 8:
                std::cout<< "Number of nodes in the list: "<<s.Count()<<std::endl;
                break;
            case 9:
                s.display();
                break;
            case 10:
                s.reverse();
                break;
            case 11:
                s.sort();
                break;
            case 12:
                n = s.findMiddle();
                if(n == nullptr){
                    std::cout<< "The list is empty"<<std::endl;
                }
                else{
                    std::cout<< "MIddle Node: ( "<<n->key<< " , "<<n->data<< " )."<<std::endl;
                }
                break;
            case 13:
                leave = true;
                std::cout<< "Bye!"<<std::endl;
                break;
        }
    }
    singlyLinkedList* s1 = new singlyLinkedList;
    singlyLinkedList* s2 = new singlyLinkedList;
    singlyLinkedList* merg = new singlyLinkedList;
    Node n1(1,10);
    Node n2(2,20);
    Node n3(3,30);
    Node n4(4,40);
    s1->append(&n1);
    s1->append(&n2);
    s1->append(&n3);
    s2->append(&n4);
    Merge(s1,s2,merg);
    std::cout<< "First list: ";
    s1->display();
    std::cout<< std::endl;
    std::cout<< "Second List: ";
    s2->display();
    std::cout<<std::endl;
    std::cout<< "Merged list: ";
    merg->display();
    std::cout<< std::endl;
    return 0;
}