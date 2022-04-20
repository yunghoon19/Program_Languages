/*
    단일 연결 리스트 (C++)
*/

#include <iostream>

using namespace std;

template <typename T>
class Node  // 리스트에 하나의 노드
{
private:
    T value;      // 노드가 저장할 값

public:
    Node* nextNode; // 다음 노드 주소

public:
    Node(T _n) : value(_n), nextNode(NULL) { cout << "Node Create!" << endl; }
    ~Node() 
    { 
        //cout << "Node Destroy!" << endl; 
    }

public:
    T GetValue() { return value; }
};

template <typename T>
class Linked_List    // 단일 연결 리스트
{
private:
    int listSize;         // 리스트의 크기
    Node<T>* rootNode;    // 리스트의 루트 노드

public:
    Linked_List() : rootNode(NULL), listSize(0) { cout << "Linked_List Create!" << endl; };
    ~Linked_List()
    {
        cout << "Linked_List Destroy!" << endl;
        while (listSize--)
        {
            Node<T>* temp = rootNode->nextNode;

            delete rootNode;
            rootNode = temp;
        }
    }

public:
    // 리스트 맨 끝에 노드를 추가하는 함수
    void AddInLastNode(T _value)  
    {
        if (rootNode == NULL)
        {
            rootNode = new Node<T>(_value);
        }
        else
        {
            Node<T>* locationCheck = rootNode;

            while (locationCheck->nextNode != NULL) { locationCheck = locationCheck->nextNode; }
            
            locationCheck->nextNode = new Node<T>(_value);
        }
        listSize++;

        return;
    }

    // 리스트의 사이즈 리턴
    int GetListSize()
    {
        return listSize;
    }

    // 리스트의 마지막 노드의 value 리턴
    T GetLastNodeValue()
    {
        Node<T>* lastNodeCheck = rootNode;

        while (lastNodeCheck->nextNode != NULL) { lastNodeCheck = lastNodeCheck->nextNode; }
        
        return lastNodeCheck->GetValue();
    }

    // 연결리스트의 모든 원소 출력
    void PrintList()
    {
        Node<T>* currentNode = rootNode;

        while (currentNode != NULL)
        {
            cout << ">> " << currentNode->GetValue() << endl;
            currentNode = currentNode->nextNode;
        }

        return;
    }

    // 리스트의 원하는 위치에 데이터 삽입
    void InsertInList(T _value, int _location)
    {
        Node<T>* nodeCheck = rootNode;
        Node<T>* temp = NULL;

        if (_location < 1)
        {
            cout << "Error: Not Include Item!" << endl;
            listSize++;
            return;
        }
        else if (_location == 1)
        {
            temp = rootNode;
            rootNode = new Node<T>(_value);
            rootNode->nextNode = temp;
        }
        else if (_location > listSize)
        {
            AddInLastNode(_value);
            return;
        }
        else
        {
            for (int i = 1; i < _location - 1; i++)
            {
                nodeCheck = nodeCheck->nextNode;
            }

            temp = nodeCheck->nextNode;
            nodeCheck->nextNode = new Node<T>(_value);
            nodeCheck->nextNode->nextNode = temp;
        }

        listSize++;
        return;
    }
};

int main(void)
{
    Linked_List<int> l1;

    l1.AddInLastNode(1);
    l1.AddInLastNode(2);
    l1.AddInLastNode(3);
    l1.AddInLastNode(4);

    cout << "List Last Node Value Pirnt : " << l1.GetLastNodeValue() << endl;
    cout << "List Size : " << l1.GetListSize() << endl;
    l1.PrintList();

    cout << "List Size : " << l1.GetListSize() << endl;
    l1.InsertInList(0, 2);
    l1.PrintList();
    cout << "List Size : " << l1.GetListSize() << endl;
    l1.InsertInList(0, 5);
    l1.PrintList();
    cout << "List Size : " << l1.GetListSize() << endl;
    l1.InsertInList(5, 7);
    l1.PrintList();
    cout << "List Size : " << l1.GetListSize() << endl;

    return 0;
}