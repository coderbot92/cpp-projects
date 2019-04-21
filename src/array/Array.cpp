#include "Array.h"

#include <iostream>

namespace ds {

template <class T>
Array<T>::Array()
{
  m_data = std::unique_ptr<T[]>(new T[m_capacity]);
}

template <class T>
Array<T>::Array(Array&& arr)
{
  m_capacity = arr.m_capacity;
  m_size = arr.m_size;

  m_data = std::move(arr.m_data);
}

template <class T>
Array<T>& Array<T>::operator=(Array&& arr)
{
  m_capacity = arr.m_capacity;
  m_size = arr.m_size;

  m_data = std::move(arr.m_data);

  return *this;
}

template <class T>
const T& Array<T>::at(int index) const
{
  if (index >= m_size || index < 0)
  {
    throw std::out_of_range("Invalid Index");
  }

  return m_data[index];
}

template <class T>
void Array<T>::push(T const& element)
{
  if (m_size >= m_capacity)
  {
    resize(m_capacity * 2);
  }

  m_data[m_size] = element;
  ++m_size;
}

template <class T>
void Array<T>::resize(int capacity)
{
  m_capacity = capacity;

  std::unique_ptr<T[]> data(new T[m_capacity]);

  for (int index = 0; index < m_size; ++index)
  {
    data[index] = m_data[index];
  }

  m_data = std::move(data);
}

template <class T>
void Array<T>::displayContents() const
{
  std::cout << "Contents: ";

  for (int index = 0; index < m_size; ++index)
  {
    std::cout << m_data[index] << " ";
  }

  std::cout << std::endl;
}

} // namespace ds (data structures)
