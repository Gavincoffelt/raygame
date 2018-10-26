#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize = 0;                   // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	bool empty()						 // Returns true if the vector contains no elements.
	void resize(size_t)				    // Resizes the vector to contain the given number of elements.
	void shrink_to_fit()			    // Resizes the vector's capacity to match its size.
	void clear()					    // Empties the vector (all elements are destroyed in this process)
	void reserve(size_t)				// Allocates enough space in the underlying array to store the given number of elements.
	tVector();                          // initializes the vector's default values
	~tVector();                         // destroys the underlying array
	T& operator[] (size_t index);
	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements
	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector

	T &at(size_t index);                // returns the element at the given element

	tVector(const tVector &vec);
	tVector& operator=(const tVector &vec);

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template<typename T>
inline tVector<T>::tVector()
{
	arr = nullptr;
	arrSize = 0;
	arrCapacity = 0;
}

template<typename T>
inline tVector<T>::~tVector()
{
	delete[] arr;

}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	return at(index);
}

template<typename T>
 T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	T *temp = new T [newCapacity];
	if (!(newCapacity > arrCapacity)) { return; }
			
	for (size_t i = 0; i < arrSize; i++) {
		temp[i] = arr[i];
	}
	arrCapacity = newCapacity;
	arr = temp;
	delete[] arr;	
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	if (arrSize >= arrCapacity) {
		if (arrCapacity == 0) {
			reserve(1);
	}
		else
		{
			reserve(arrCapacity * GROWTH_FACTOR);
		}
		
	 }
	arr[arrSize++] = value;


}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;

}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	return arr[index];
	
}

template<typename T>
inline tVector<T>::tVector(const tVector & vec)
{

}

template<typename T>
inline tVector & tVector<T>::operator=(const tVector & vec)
{
	
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return  arrCapacity;
}
