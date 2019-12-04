#pragma once

#include <stdint.h>
/**
Copyright (C) 2017, 2019 Strahinja Janjic

Ova klasa je deo paketa SSTL sto je skracenica za Strahinja STndard Library
Ova biblioteka je licencirana preko GNU General Public Licence,
imas pravo da dodajes/brises ili modifikujes ovaj fajl u skladu sa
GNU General Public Licencom.

Ova bibliotka je distribuirana sa nadom da ce biti od koristi ali
bez ikakvih garancija da data biblioteka radi niti da se moze uklopiti u
vas projekat.

**/

class out_of_range: public std::exception
{

};

namespace sstl
{
	template<class T> class vector
	{
	public :

		/*  Konstrukotri  */

		vector();

		explicit vector(int s);

		vector(const vector& arg);

		vector<T>& operator = (const vector<T>&);

		~vector();

		
		/*  Iteratori  */

		class iterator;
		
		iterator begin();
		const iterator begin() const;

		iterator end();
		const iterator end() const;

		const iterator cbegin() const;

		const iterator cend() const;

		/*  Kapacitet  */

		bool empty() const;

		//Vraca kapacite alociranog prostora
		size_t capacity() const;

		//Trazi promenu kapaciteta
		//reserve() nece nikad smanjiti kapacitet.
		void reserve(size_t);

		//Menja velicinu vektora
		//Ako je nova velicina manja, poslednji elementi ce biti izgubljeni
		//Ima default parametar za proizvoljne vrednosti kada se velicina menja
		void resize(uint32_t, T val = T());

		// Vraca velicinu vektora (broj elemenata)
		size_t size() const;

		//Vraca maksimalnu kolicinu elemenata koju Vektor moze da drzi
		size_t max_size() const;

		//Smanjuje kapacitet da bi prilagodio velicini
		void shrink_to_fit();
	
		
		/*  Modifajeri  */
		
		// Brise sve elemente iz vektora
		// Kapacitet nije promenjen
		void clear();

		// Dodaje element na kraj vektora
		void push_back(const T& d);

		// Brise poslednji element u Vektoru
		T& pop_back();

		/*  Pristup Elementu  */

		// Pristupi elementima sa proverama granicnih vrednosti
		T& at(int n);
		const T& at(int n) const;

		// Pristupi elementima, bez provere granicnih vrednosti
		T& operator[](int i);
		const T& operator[](int i) const;

		//Vraca referencu na prvi element
		T& front();
		const T& front() const;

		//Vraca referencu na poslednji element
		T& back();
		const T& back() const;

		//Vraca pokazivac na niz koriscen u vektoru
		T* data();
		const T* data() const;
	
	private:
		size_t _size; //Broj elemenata u vektoru
		T* _elements; //Pokazivac na prvi element Vektora
		size_t _space; //Ukupna velicina Vektora ukljucujuci i slobodna mesta
	};



	template<class T> class vector<T>::iterator
	{
	public:
		iterator(T* p) :
			_curr(p) {}
		iterator& operator++()
		{
			_curr++;
			return *this;
		}
		iterator& operator--()
		{
			_curr--;
			return *this;
		}
		T& operator*()
		{
			return *_curr;
		}
		bool operator == (const iterator& b) const
		{
			return *_curr = *b._curr;
		}
		bool operator != (const iterator& b) const
		{
			return *_curr != *b._curr;
		}
	private:
		T* _curr;
	};
	template<class T>
	inline vector<T>::vector() : _size(0), _elements(0), _space(0)
	{}
	template<class T>
	inline vector<T>::vector(int s)
		:_size(s), _elements(new T[s]), _space(s)
	{
		for (int i = 0; i < _size; ++i)
		{
			_elements[i] = T();
		}
	}
	template<class T>
	inline vector<T>::vector(const vector& arg)
		:_size(arg._size), _elements(new T[arg._size])
	{
		for (int i = 0; i < arg.size; ++i)
		{
			_elements[i] = arg._elements[i];
		}
	}
	template<class T>
	inline vector<T>& vector<T>::operator=(const vector<T>& c)
	{
		//TODO: Pazi ovo dal radi kako treba

		if (this == &c) return *this; //Ne mozes da dodas sam sebe

		if (c._size <= _space)
		{
			for (int i = 0; i < c.size; ++i)
			{
				_elements[i] = c._elements[i];
				_size = c._size;
			}
			return *this;
		}
		T* ptr = new T[c._size];

		for (int i = 0; i < c._size; ++i)
		{
			ptr[i] = c._elements[i];
		}
		delete[] _elements;
		_size = c._size;
		_space = c._size;
		_elements = ptr;
		return *this;
	}
	template<class T>
	inline vector<T>::~vector()
	{
		delete[] _elements;
	}
	template<class T>
	inline typename vector<T>::iterator vector<T>::begin()
	{
		return vector<T>::iterator(&_elements[0]);
	}
	template<class T>
	inline const typename vector<T>::iterator vector<T>::begin() const
	{
		return vector<T>::iterator(&_elements[0]);
	}

	template<class T>
	inline typename vector<T>::iterator vector<T>::end()
	{
		return vector<T>::iterator(&_elements[_size]);
	}

	template<class T>
	inline const typename vector<T>::iterator vector<T>::end() const
	{
		return vector<T>::iterator(&_elements[_size]);
	}

	template<class T>
	inline const typename vector<T>::iterator vector<T>::cbegin() const
	{
		return vector<T>::iterator(&_elements[0]);
	}

	template<class T>
	inline const typename vector<T>::iterator vector<T>::cend() const
	{
		return vector<T>::iterator(&_elements[_size]);
	}

	template<class T>
	inline bool vector<T>::empty() const
	{
		return (_size == 0);
	}

	template<class T>
	inline size_t vector<T>::capacity() const
	{
		return _space;
	}

	template<class T>
	inline void vector<T>::reserve(size_t newalloc)
	{
		if (newalloc <= _space) return;

		T* p = new T[newalloc];

		for (size_t i = 0; i < _size; i++)
		{
			p[i] = _elements[i];
		}

		delete[] _elements;

		_elements = p;

		_space = newalloc;
	}

	template<class T>
	inline void vector<T>::resize(uint32_t new_size, T val)
	{
		reserve(new_size);
		for (int i = _size; i < new_size; ++i)
		{
			_elements[i] = T();
		}
		_size = new_size;
	}

	template<class T>
	inline size_t vector<T>::size() const
	{
		return _size;
	}



	template<class T>
	inline void vector<T>::clear()
	{
		for (int i = 0; i < _size; ++i)
		{
			delete _elements[i];
		}
	}

	template<class T>
	inline void vector<T>::push_back(const T& d)
	{
		if (_space == 0)
		{
			reserve(8);
		}
		else if (_size == _space)
		{
			reserve(2 * _space);
		}
		_elements[_size] = d;
		++_size;
	}

	template<class T>
	inline T& vector<T>::pop_back()
	{
			if (_size == 0) throw new out_of_range();

			if (_size < 3 * _space / 8)
			{
				reserve(_space / 2);
			}
			return _elements[--_size];
	}

	template<class T>
	inline T& vector<T>::at(int n)
	{

		if (n < 0 || _size <= n) throw new out_of_range();
		return _elements[n];

	}

	template<class T>
	inline const T& vector<T>::at(int n) const
	{
			if (n < 0 || _size <= n) throw new out_of_range();
			return _elements[n];
	}

	template<class T>
	inline T& vector<T>::operator[](int i)
	{
		return _elements[i];
	}

	template<class T>
	inline const T& vector<T>::operator[](int i) const
	{
		return _elements[i];
	}

	template<class T>
	inline T& vector<T>::front()
	{
		return _elements[0];
	}

	template<class T>
	inline const T& vector<T>::front() const
	{
		return _elements[0];
	}

	template<class T>
	inline T& vector<T>::back()
	{
		return _elements[_size - 1];
	}

	template<class T>
	inline const T& vector<T>::back() const
	{
		return _elements[_size - 1];
	}

	template<class T>
	inline T* vector<T>::data()
	{
		return _elements;
	}

	template<class T>
	inline const T* vector<T>::data() const
	{
		return _elements;
	}

}