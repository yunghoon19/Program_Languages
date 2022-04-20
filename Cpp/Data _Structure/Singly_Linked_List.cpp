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
    Node* nextNode; // 다음 노드 주소

public:
    Node(int _n) : value(_n), nextNode(NULL) { cout << "Node Create!" << endl; }

public:
    int GetValue() { return value; }
};

class Linked_List    // 단일 연결 리스트
{
private:
    int listSize;       // 리스트의 크기
    Node* rootNode;     // 리스트의 루트 노드

public:
    Linked_List() : rootNode(NULL), listSize(0) { cout << "Linked_List Create!" << endl; };
    ~Linked_List()
    {
        while (listSize--)
        {
            Node* temp = rootNode->nextNode;

            delete rootNode;
            rootNode = temp;

            //cout << "Node Destroy" << endl;
        }
    }

public:
    // 리스트 맨 끝에 노드를 추가하는 함수
    void AddInLastNode(int _value)  
    {
        if (rootNode == NULL)
        {
            rootNode = new Node(_value);
        }
        else
        {
            Node* locationCheck = rootNode;

            while (locationCheck->nextNode != NULL) { locationCheck = locationCheck->nextNode; }
            
            locationCheck->nextNode = new Node(_value);
        }
        listSize++;
    }

    // 리스트의 사이즈 리턴
    int GetListSize()
    {
        return listSize;
    }

    // 리스트의 마지막 노드의 value 리턴
    int GetLastNodeValue()
    {
        Node* lastNodeCheck = rootNode;

        while (lastNodeCheck->nextNode != NULL) { lastNodeCheck = lastNodeCheck->nextNode; }
        
        return lastNodeCheck->GetValue();
    }

    // 연결리스트의 모든 원소 출력
    void PrintList()
    {
        Node* currentNode = rootNode;

        while (currentNode != NULL)
        {
            cout << ">> " << currentNode->GetValue() << endl;
            currentNode = currentNode->nextNode;
        }
    }
};

int main(void)
{
    Linked_List l1;

    l1.AddInLastNode(1);
    l1.AddInLastNode(2);
    l1.AddInLastNode(3);
    l1.AddInLastNode(4);

    cout << "List Last Node Value Pirnt : " << l1.GetLastNodeValue() << endl;
    cout << "List Size : " << l1.GetListSize() << endl;
    l1.PrintList();

    return 0;
}