/*
    단일 연결 리스트 (C++)
*/

#include <iostream>

using namespace std;

class Node  // 리스트에 하나의 노드
{
private:
    int value;      // 노드가 저장할 값

public:
    Node* nextNode; // 다음 노드의 포인터

public:
    Node(int _n) : value(_n), nextNode(NULL) { printf("Node Create!\n"); }

public:
    int GetValue() { return value; }
};

class Linked_List    // 단일 연결 리스트
{
private:
    int size;       // 리스트의 크기
    Node* rootNode; // 리스트의 루트 노드

public:
    Linked_List() : rootNode(NULL), size(0) { printf("Linked_List Create!\n"); };
    ~Linked_List()
    {
        while (size--)
        {
            Node* temp = rootNode->nextNode;

            delete rootNode;
            rootNode = temp;

            printf("Node Destroy\n");
        }
    }

public:
    // 리스트 맨 끝에 노드를 추가하는 함수
    void AddNodeInList(int _value)  
    {
        if (rootNode == NULL)
        {
            rootNode = new Node(_value);
        }
        else
        {
            Node* locationCheck = rootNode->nextNode;

            while (locationCheck != NULL) { locationCheck = locationCheck->nextNode; }
            
            locationCheck = new Node(_value);
        }
    }

    // 리스트의 마지막 노드의 value 리턴
    int OutputLastNode()
    {
        Node* lastNodeCheck = rootNode;

        while (lastNodeCheck->nextNode == NULL) { lastNodeCheck = lastNodeCheck->nextNode; }
        
        return lastNodeCheck->GetValue();
    }

};

int main(void)
{
    Linked_List l1;

    l1.AddNodeInList(1);
    l1.AddNodeInList(2);

    printf("리스트 마지막 원소 출력 %d\n", l1.OutputLastNode());

    return 0;
}