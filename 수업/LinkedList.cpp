#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        
        Node(int v){
            value = v;
            next = NULL;
        }
};

void traverse(Node* head){
    Node* cur = head;

    while( cur != NULL){
        cout << cur->value << "->"; // 현재 값 출력
        cur = cur ->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node* &head,int val){
    Node* newNode = new Node(val);//노드 생성
    
    newNode -> next = head; // 원래 헤드 노드를 포인팅
    head = newNode; // new node를 헤드로 설정

}

void insertAtLast(Node* &head,int val){

    if(head == NULL){ // 빈 배열일때
        insertAtHead(head,val);
        return;
    }

    Node* newNode = new Node(val); //생성
    Node* cur = head;

    while(cur->next != NULL){ //마지막 노드 전에 도착
        cur = cur ->next;
    }

    cur -> next = newNode;
}

void insertAtMiddle(Node* &head,int val, int pos){

    if(pos == 1){
        insertAtHead(head,val);
        return;
    }

    Node* newNode = new Node(val);
    Node* cur = head;
    int cnt = 1;

    while(cnt < pos -1){ // k-1 번째 까지 탐색
        cur = cur -> next;
        cnt++;
    }

    newNode -> next = cur->next;
    cur->next = newNode;
}

void deleteAtStart(Node*  &head){
    
    if(head == NULL)
        return;

    Node* cur = head;
    head = head->next;
    free(cur);
}

void deleteAtEnd(Node* &head){
    if(head == NULL)
        return;
    
    if(head->next ==NULL){ //노드가 하나만 있을 떄
        deleteAtStart(head);
        return;
    }

    Node* secondLastNode = head;

    while(secondLastNode->next->next != NULL){ //마지막 전 노드 찾기
        secondLastNode = secondLastNode -> next;
    }

    Node* lastNode = secondLastNode->next;
    secondLastNode -> next = NULL;
    free(lastNode); //마지막 노드 할당 해제
}

void deleteAtMiddle(Node* &head,int pos){

    if(pos == 1){
        deleteAtStart(head);
        return;
    }

    Node* prev = head;
    int cnt = 1;
    
    while(cnt < pos -1){ // pos 전까지 도착
        prev = prev->next;
        cnt++;
    }
    Node* cur = prev->next;

    prev -> next = cur->next; //삭제할 포인터의 next를 가리키게 해야함
    free(cur);

}

void updatePositionValue(Node* &head,int value ,int pos){
    Node* cur = head;
    int cnt = 1;

    while(cnt < pos){ // cur이 pos 도착
        cur = cur->next;
        cnt++;
    }

    cur -> value = value;
}

int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1 -> next = node2;
    node2 -> next = node3;

    Node* head = node1;//head
    insertAtHead(head,0);
    traverse(head);
    insertAtLast(head,4);
    traverse(head);
    insertAtMiddle(head,999,4);
    traverse(head);

    return 0;
}