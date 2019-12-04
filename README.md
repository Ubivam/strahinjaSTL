# Custom STL C++ library
<p>This is long term projet where i would implement different part of C++ standard library and publish them with GNU Public Licences, with a goal of
crating simple and efficient implementations of known Standard Library Template Classes</p>

<h1>Currently Implemented Features </h1>

<h2>Vector</h2>

<h4>Matches C++ STL vector</h4>
* Works with custom built types
* Dynamic resizing when inserting elements
* Implements iterators

<h4>Advantages Over C++ STL vector</h4>
* Slightly faster times when inserting built in types and almost identical times when inserting custom types.

<h4>Disadvantages Over C++ STL vector</h4>
* Slower popping times.

<h4>Implemented Methods</h4>
<h5>Constructors</h5>
```cpp
  Vector();
  explicit Vector(size_t s);
  Vector(const Vector& arg);
  Vector<T>& operator=(const Vector<T>& arg);
  ~Vector();
```
<h5>Iterators</h5>
```
  iterator begin();
  const iterator begin() const;
  iterator end();
  const iterator end() const;
  const iterator cbegin() const;
  const iterator cend() const;
```
<h5>Capacity</h5>
```
  bool empty() const;
  size_t capacity() const;
  void reserve(size_t);
  void resize(size_t, T = T());
  size_t size() const;
  size_t max_size() const;
```
<h5>Modifiers</h5>
```
  void clear();
  void push_back(constT&);
  void pop_back();
```
<h5>Element Access</h5>
```
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
<h2>Smart Pointers</h2>

<h4>Matches C++ STL memory</h4>

* Works with custom built types
* Smart memory management system
* Implemet Reference Counting method for keeping instance alive

<h4>Advantages Over C++ STL memory</h4>
* A slightly better algorithm for Reference Counting

<h4>Disadvantages Over C++ STL vector</h4>
* not yet implemented unique_ptr and weak_ptr
<h4>Implemented Methods</h4>
<h5>Constructors</h5>
  ```
  explicit shared_ptr(T* ptr = nullptr);
  shared_ptr(shared_ptr<T>& s_pointer);
  ```
<h5>Count operators</h5>
 ```
  uint32_t use_count();
  T* get();
 ```
<h5>Desturctor</h5>
```
  ~shared_ptr();
```
<h5>Overloaded operators</h5>
```
  T& operator*() 
  T& operator*() const
  T* operator->() const
  shared_ptr& operator=(const shared_ptr<T>& s_pointer)
  bool operator == (const shared_ptr& b) const
  bool operator != (const shared_ptr& b) const
  friend std::ostream& operator <<(std::ostream& os, shared_ptr<T>& sp) 
```
