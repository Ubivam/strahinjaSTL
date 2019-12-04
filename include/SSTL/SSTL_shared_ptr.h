#pragma once
#include <stdint.h>
#include "SSTL_ReferenceCounter.h"
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

namespace sstl
{

//Template klasa jako slicne implementacije kao

template <typename T>
class shared_ptr
{
public:
	explicit shared_ptr(T *ptr = nullptr)
	{
		m_ptr = ptr;
		m_counter = new ReferenceCounter();
		if (ptr)
		{
			(*m_counter)++;
		}
	}

	//Kopirajuci konstruktor

	shared_ptr(shared_ptr<T> &s_pointer)
	{
		m_ptr = s_pointer.m_ptr;
		m_counter = s_pointer.m_counter;
		(*m_counter)++;
	}

	uint32_t use_count()
	{
		return m_counter->get();
	}

	T *get()
	{
		return m_ptr;
	}

	~shared_ptr()
	{
		(*m_counter)--;
		if (m_counter->get() == 0)
		{
			delete m_counter;
			delete m_ptr;
		}
	}

	T &operator*()
	{
		return *m_ptr;
	}
	T &operator*() const
	{
		return *m_ptr;
	}
	T *operator->() const
	{
		return m_ptr;
	}
	shared_ptr &operator=(const shared_ptr<T> &s_pointer)
	{
		m_ptr = s_pointer.m_ptr;
		m_counter = s_pointer.m_counter;
		(*m_counter)++;
		return *this;
	}
	bool operator==(const shared_ptr &b) const
	{
		return m_ptr == b.m_ptr;
	}
	bool operator!=(const shared_ptr &b) const
	{
		return m_ptr != b.m_ptr;
	}
	//Loging opcija
	friend std::ostream &operator<<(std::ostream &os, shared_ptr<T> &sp)
	{
		return os << "Adresa na koju pokazuje: " << sp.get()
				  << std::endl
				  << *(sp.m_counter) << std::endl;
	}

private:
	ReferenceCounter *m_counter;

	T *m_ptr;
};

} // namespace sstl