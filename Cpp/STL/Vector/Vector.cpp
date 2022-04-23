#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	T* value;		// 백터에 담길 요소를 저장할 변수
	int size;		// 백터의 크기를 저장하는 변수
	int capacity;	// value에 할당될 크기를 저장하는 변수

public:
	Vector(int _n = 1) : value(new T[_n]), capacity(_n), size(0) { printf("vector생성\n"); } // 생성자
	
	Vector(const Vector &_copy)	: value(_copy.value), capacity(_copy.capacity), size(_copy.size)	// 복사자
	{
		printf("복사 생성자 실행\n");
	}

	~Vector()	// 소멸자    
	{
		if (value > 0)
		{
			delete[] value;
		}
		printf("소멸되었습니다.\n");
	}

	T operator[](int i) { return value[i]; }
	// 연산자 operator를 이용해서 '백터이름'[i] 입력시 value[i] 리턴. [ 연산자 오버로딩 ]

public:
    T* begin()
    {
        return value;
    }

	void Push_back(T input)		// 백터에 요소 추가 함수 Push_back()
	{
		if (capacity <= size)	// 할당된 공간 <= 요소의 개수 : 할당공간을 늘리는 작업이 필요한지 검사
		{
			capacity *= 2;		// 할당된 공간이 부족하기 때문에 할당공간을 2배로 증가
			T* temp = new T[capacity]; // 원래 선언된 vector보다 2배큰 공간 할당하고 주소를 temp에 저장 

			for (int i = 0; i < size; i++)
			{
				temp[i] = value[i];		// 가득찬 기존 value에서 두배로 할당된 temp로 값 복사 
			}

			delete[] value;		// 할당된 value를 통째로 삭제
			value = temp;		// 새로 할당된 메모리의 주소 (temp)를 value에 복사 
		}

		value[size] = input;	// Push_back 값을 할당된 공간에 넣음
		size++;					// 요소개수 + 1
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
		printf("v[%d]의 요소 : %d\n", i, v[i]);
	}
	
    printf("%p\n", v.begin());
	printf("v.capacity : %d\n", v.Capacity());
	
	return 0;
}