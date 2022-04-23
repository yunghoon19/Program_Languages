#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	T* value;		// ���Ϳ� ��� ��Ҹ� ������ ����
	int size;		// ������ ũ�⸦ �����ϴ� ����
	int capacity;	// value�� �Ҵ�� ũ�⸦ �����ϴ� ����

public:
	Vector(int _n = 1) : value(new T[_n]), capacity(_n), size(0) { printf("vector����\n"); } // ������
	
	Vector(const Vector &_copy)	: value(_copy.value), capacity(_copy.capacity), size(_copy.size)	// ������
	{
		printf("���� ������ ����\n");
	}

	~Vector()	// �Ҹ���    
	{
		if (value > 0)
		{
			delete[] value;
		}
		printf("�Ҹ�Ǿ����ϴ�.\n");
	}

	T operator[](int i) { return value[i]; }
	// ������ operator�� �̿��ؼ� '�����̸�'[i] �Է½� value[i] ����. [ ������ �����ε� ]

public:
    T* begin()
    {
        return value;
    }

	void Push_back(T input)		// ���Ϳ� ��� �߰� �Լ� Push_back()
	{
		if (capacity <= size)	// �Ҵ�� ���� <= ����� ���� : �Ҵ������ �ø��� �۾��� �ʿ����� �˻�
		{
			capacity *= 2;		// �Ҵ�� ������ �����ϱ� ������ �Ҵ������ 2��� ����
			T* temp = new T[capacity]; // ���� ����� vector���� 2��ū ���� �Ҵ��ϰ� �ּҸ� temp�� ���� 

			for (int i = 0; i < size; i++)
			{
				temp[i] = value[i];		// ������ ���� value���� �ι�� �Ҵ�� temp�� �� ���� 
			}

			delete[] value;		// �Ҵ�� value�� ��°�� ����
			value = temp;		// ���� �Ҵ�� �޸��� �ּ� (temp)�� value�� ���� 
		}

		value[size] = input;	// Push_back ���� �Ҵ�� ������ ����
		size++;					// ��Ұ��� + 1
	}

	void Pop_back()
	{
		if (size == 0)
		{
			printf("empty\n");
		}
		else
		{
			size--;
			printf("Pop : %d\n", value[size]);
		}
	}
	
	int Back()
	{
		return value[size - 1];
	}
	
	int Capacity()
	{
		return capacity;
	}
	
};

int main(void) 
{
	Vector<int> v;
	
	for (int i = 0; i < 10; i++)
	{
		v.Push_back(i + 1);
	}
	
	for (int i = 0; i < 10; i++)
	{
		printf("v[%d]�� ��� : %d\n", i, v[i]);
	}
	
    printf("%p\n", v.begin());
	printf("v.capacity : %d\n", v.Capacity());
	
	return 0;
}