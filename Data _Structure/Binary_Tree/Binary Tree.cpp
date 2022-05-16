#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T value;
	
	Node* leftNode = NULL;
	Node* rightNode = NULL;
	
	Node(T _n) : value(_n) { printf("노드 생성!!\n"); } 
};

template <typename T>
class Binary_Tree
{
private:
	Node<T>* rootNode;
	
public:
	Binary_Tree() : rootNode(NULL) { printf("이진 트리 생성!\n"); }
	
	Node<T>* Get_RootNode() { return rootNode; }
	
	void Add_Node(T _input, Node<T>* _currentNode = Get_RootNode())
	{		
		if (_currentNode == NULL)
		{
			_currentNode = new Node<T>(_input);
		}
		else
		{
			if (_currentNode->leftNode == NULL)
			{
				_currentNode->leftNode = new Node<T>(_input);
			}
			else if (_currentNode->rightNode == NULL)
			{
				_currentNode->rightNode = new Node<T>(_input);
			}
			else if (_currentNode->leftNode->leftNode == NULL)
			{
				Add_Node(_input, _currentNode->rightNode);
			}
			else
			{
				Add_Node(_input, _currentNode->leftNode);
			}
		}
	}
	
	void Preorder(Node<T>* _currentNode = Get_RootNode())		// 전위 순회
	{
		if (_currentNode == NULL)
		{
			printf("트리가 존재하지 않음.");
			return; 
		}
		
		if (_currentNode->leftNode != NULL)
		{
			printf("%c ", _currentNode->value);
			Preorder(_currentNode->leftNode);
			
			if(_currentNode->rightNode != NULL)
			{
				Preorder(_currentNode->rightNode);
			}
		}
		else
		{
			printf("%c ", _currentNode->value);
			return;
		}
	}
	
	void Inorder(Node<T>* _currentNode = Get_RootNode())		// 중위 순회 
	{
		if (_currentNode == NULL)
		{
			printf("트리가 존재하지 않음.");
			return;
		}
		
		if (_currentNode->leftNode != NULL)
		{
			Inorder(_currentNode->leftNode);
			if (_currentNode->rightNode != NULL)
			{
				printf("%c ", _currentNode->value);
				Inorder(_currentNode->rightNode);
			}
		}
		else
		{
			printf("%c ", _currentNode->value);
			return;
		}
	}
	
	void Postorder(Node<T>* _currentNode = Get_RootNode())		// 후위 순회
	{
		if (_currentNode == NULL)
		{
			printf("트리가 존재하지 않음.");
			return;
		}
		
		if (_currentNode->leftNode != NULL)
		{
			Postorder(_currentNode->leftNode);
			
			if(_currentNode->rightNode != NULL)
			{
				Postorder(_currentNode->rightNode);
				printf("%c ", _currentNode->value);
			}
		}
		else
		{
			printf("%c ", _currentNode->value);
			return;
		}
	}
};

int main(void)
{
	Binary_Tree<char> tree1;
	
	printf("전위 순회\n");
	
	return 0;
}
