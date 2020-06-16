#pragma once
#include <cstring>

template <class T>
class MyStack
{
private:
	T* m_paData;
	unsigned int m_uiSize;
	int m_iTop;
	unsigned int m_uiGrowSize;

public:
	MyStack(unsigned int a_uiSize, unsigned int a_uiGrowSize = 1);
	MyStack(const MyStack &a_rStack);
	~MyStack(void);

	// Accessory Functions
	bool isEmpty() const;
	int getSize() const;

	// Access Functions
	void push(T &a_rValue);
	void pop();
	const T* top();

	// So we can draw the stack - takes a callback function
	void draw(void (*drawCallback)(const T*));
};

template<class T>
MyStack<T>::MyStack(unsigned int a_uiSize, unsigned int a_uiGrowSize) :
	m_paData(NULL), m_uiSize(a_uiSize), m_uiGrowSize(a_uiGrowSize), m_iTop(-1)
{
	// Check the initial size is valid. If so, allocate memory
	if(m_uiSize) {
		// allocate memory and set all values to 0
		m_paData = new T[m_uiSize];
		memset(m_paData, 0, sizeof(T) * m_uiSize);
	}
}

template<class T>
MyStack<T>::MyStack(const MyStack &a_rStack) {
	// normally you would implement this function
}

template<class T>
MyStack<T>::~MyStack(void) {
	// If dynamic memory was allocated, delete it and set pointer to NULL
	if(m_paData != NULL) {
		delete[] m_paData;
		m_paData = NULL;
	}
}

template<class T>
bool MyStack<T>::isEmpty() const {
	return (m_iTop == -1)?true:false;
}

template<class T>
int MyStack<T>::getSize() const {
	return m_iTop + 1;
}

template<class T>
void MyStack<T>::push(T &a_rValue) {
	// check for space in the stack
	if(m_iTop == m_uiSize-1) {
		T* oldStack = m_paData;
		m_paData = new T[m_uiSize + m_uiGrowSize];
		memset(m_paData, 0, sizeof(T) * m_uiSize + m_uiGrowSize);
		memcpy(m_paData, (void*)oldStack, m_uiSize * sizeof(T));
		m_uiSize += m_uiGrowSize;
		delete oldStack;
	}
	// add value to back of stack
	m_paData[++m_iTop] = a_rValue;
}

template<class T>
void MyStack<T>::pop() {
	// remove value from back of stack
	if(m_iTop >= 0)
		--m_iTop;
}

template<class T>
const T* MyStack<T>::top() {
	// return value from back of stack
	return (m_iTop >= 0)?&m_paData[m_iTop]:NULL;
}

template<class T>
void MyStack<T>::draw(void (*drawCallback)(const T*)) {
		// since the template doesn't know how to draw the template type,
		// use a callback function to draw the elements in our stack
	T* pEnd = m_paData + m_iTop;
	for(T* p = pEnd; p >= m_paData; --p) {
		drawCallback(p);
	}
}
