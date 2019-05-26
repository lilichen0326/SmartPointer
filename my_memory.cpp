//Lili Chen
#include <iostream>

using namespace std;

template <class T>
my_unique_ptr<T>::my_unique_ptr() :nPtr(nullptr) {}

template <class T>
my_unique_ptr<T>::my_unique_ptr(T *newPtr) : nPtr(newPtr) {}

template <class T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr &&rhs)
{
	cout << "Move constructor called!" << endl;

	nPtr = rhs.nPtr;

	rhs.nPtr = nullptr;

}

template <class T>
my_unique_ptr<T>::~my_unique_ptr() { delete nPtr; }

template <class T>
T& my_unique_ptr<T>::operator*() const { return *nPtr; }

template <class T>
T* my_unique_ptr<T>::operator->() const { return nPtr; }

template <class T>
my_unique_ptr<T>& my_unique_ptr<T>::operator=(my_unique_ptr&& other)
{
	if (this != &other)
	{
		nPtr = other.nPtr;
		other.nPtr = nullptr;
	}
	return *this;
}





template <class T>
my_shared_ptr<T>::my_shared_ptr() 
{
	cPtr = nullptr;
	dPtr = nullptr;
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(T *newPtr)
{
	dPtr = newPtr;
	cPtr = new int(1);
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &rhs)
{
	if (rhs.dPtr != nullptr)
	{
		dPtr = rhs.dPtr;
		*rhs.cPtr = *rhs.cPtr + 1;
		cPtr = rhs.cPtr;
	}
	
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr &&rhs)
{
	if (rhs.dPtr != nullptr)
	{
		dPtr = rhs.dPtr;
		cPtr = rhs.cPtr;
		rhs.dPtr = nullptr;
		rhs.cPtr = nullptr;
	}
}

template <class T>
my_shared_ptr<T>::~my_shared_ptr()
{
	dPtr = nullptr;
	cPtr = nullptr;
}

template <class T>
T& my_shared_ptr<T>::operator*() const { return *dPtr; }


template <class T>
T* my_shared_ptr<T>::operator->() const { return dPtr; }


template <class T>
my_shared_ptr<T>& my_shared_ptr<T> ::operator=(my_shared_ptr&& other)
{
	if ((cPtr != nullptr) && (*cPtr != 1))
	{
		*cPtr = *cPtr - 1;
	}
	else if ((cPtr != nullptr) && (*cPtr == 1) )
	{
		delete cPtr;
		delete dPtr;
	}

	dPtr = other.dPtr;
	cPtr = other.cPtr;

	other.dPtr = nullptr;
	other.cPtr = nullptr;
	return *this;
}

template<class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr& other)
{
	if ((cPtr != nullptr) && (*cPtr != 1))
	{
		*cPtr = *cPtr - 1;
	}
	else if ((cPtr != nullptr) && (*cPtr == 1))
	{
		delete cPtr;
		delete dPtr;
	}

	dPtr = other.dPtr;
	if(other.cPtr != nullptr)	*other.cPtr += 1;
	cPtr = other.cPtr;
	return *this;
}
