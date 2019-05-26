//Lili Chen
#ifndef MY_MEMORY_H
#define MY_MEMORY_H

template <class T>
class my_unique_ptr
{
private:
	T* nPtr;
public:
	my_unique_ptr();
	my_unique_ptr(T *newPtr);
	my_unique_ptr(my_unique_ptr &&rhs);
	my_unique_ptr(const my_unique_ptr &rhs) = delete;
	~my_unique_ptr();
	T& operator*() const;
	T* operator->() const;
	my_unique_ptr& operator=(my_unique_ptr&& other);
	my_unique_ptr& operator=(const my_unique_ptr& other) = delete;
};


template <class T>
class my_shared_ptr
{
private:
	T* dPtr;
	int *cPtr;
		;
public:
	my_shared_ptr();
	my_shared_ptr(T *newPtr);
	my_shared_ptr(const my_shared_ptr &rhs);
	my_shared_ptr(my_shared_ptr &&rhs);
	~my_shared_ptr();
	T& operator*() const;
	T* operator->() const;
	my_shared_ptr& operator=(my_shared_ptr&& other);
	my_shared_ptr& operator=(const my_shared_ptr& other);
};


#include "my_memory.cpp"
#endif