Custom STL C++ library
===================================
<p>This is long term projet where i would implement different part of C++ standard library and publish them with GNU Public Licences, with a goal of
crating simple and efficient implementations of known Standard Library Template Classes</p>

Currently Implemented Features

# Vector

## Matches C++ STL vector
* Works with custom built types
* Dynamic resizing when inserting elements
* Implements iterators

## Advantages Over C++ STL vector
* Slightly faster times when inserting built in types and almost identical times when inserting custom types.

## Disadvantages Over C++ STL vector
* Slower popping times.

## Implemented Methods
### Constructors
```cpp
  Vector();
  explicit Vector(size_t s);
  Vector(const Vector& arg);
  Vector<T>& operator=(const Vector<T>& arg);
  ~Vector();
```
### Iterators
```cpp
  iterator begin();
  const iterator begin() const;
  iterator end();
  const iterator end() const;
  const iterator cbegin() const;
  const iterator cend() const;
```
### Capacity
```cpp
  bool empty() const;
  size_t capacity() const;
  void reserve(size_t);
  void resize(size_t, T = T());
  size_t size() const;
  size_t max_size() const;
```
### Modifiers
```cpp
  void clear();
  void push_back(constT&);
  void pop_back();
```
### Element Access
```cpp
  T& at(size_t n);
  const T& at(size_t n) const;
  T& operator[](int i);
  const T& operator[](int i) const;
  T& front();
  const T& front() const;
  T& back();
  const T& back() const;
  T* data();
  const T* data() const;
```
# Smart Pointers

## Matches C++ STL memory

* Works with custom built types
* Smart memory management system
* Implemet Reference Counting method for keeping instance alive

## Advantages Over C++ STL memory
* A slightly better algorithm for Reference Counting

## Disadvantages Over C++ STL vector
* not yet implemented unique_ptr and weak_ptr
### Implemented Methods
### Constructors
  ```cpp
  explicit shared_ptr(T* ptr = nullptr);
  shared_ptr(shared_ptr<T>& s_pointer);
  ```
### Count operators
 ```cpp
  uint32_t use_count();
  T* get();
 ```
## Desturctor
```cpp
  ~shared_ptr();
```
### Overloaded operators
```cpp
  T& operator*(); 
  T& operator*() const;
  T* operator->() const;
  shared_ptr& operator=(const shared_ptr<T>& s_pointer);
  bool operator == (const shared_ptr& b) const;
  bool operator != (const shared_ptr& b) const;
  friend std::ostream& operator <<(std::ostream& os, shared_ptr<T>& sp);
```
