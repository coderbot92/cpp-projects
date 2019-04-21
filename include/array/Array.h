#pragma once

#include <memory>

namespace ds {

const int DEFAULT_CAPACITY = 4;
const int INITIAL_SIZE = 0;

/// \brief This is an implementation of resizable array.
template <typename T>
class Array
{
public:

  /// \brief Creates an Array instance
  Array();

  /// \brief Destroys an Array instance
  virtual ~Array() = default;

  /// \brief Move constructs an instance
  Array(Array&& arr);

  /// \brief Move assignment operator
  Array& operator=(Array&& arr);

  /// \brief Deleting the copy constructor and copy assignment operator
  ///        because of unique_ptr data type in member fields
  Array(Array& arr) = delete;
  Array& operator=(Array& arr) = delete;

  /// \brief Returns the size of filled array
  /// \return the size of array
  inline int size() const { return m_size; }

  /// \brief Returns the number of items array can hold
  /// \return the array capacity
  inline int capacity() const { return m_capacity; }

  /// \brief Returns whether the array is empty or not
  /// \return the empty status
  inline bool isEmpty() const { return m_size == 0; }

  /// \brief Returns element at an index
  /// \param index the index of element to be fetched
  /// \return the element of array at index
  T const& at(int index) const;

  /// \brief Adds element at the end of array and resizes it if capacity is reached
  /// \param element the element to be added
  void push(T const& element);

  /// \brief Displays the contents of array
  void displayContents() const;

private:

  /// The number of items array can hold
  int m_capacity{ DEFAULT_CAPACITY };

  /// The size of filled array
  int m_size{ INITIAL_SIZE };

  /// The data contained in array
  std::unique_ptr<T[]> m_data{ nullptr };

  /// \brief Resizes array by changing its capacity and copying over elements
  /// \param capacity the new capacity value
  void resize(int capacity);
};

} // namespace ds (data structures)
