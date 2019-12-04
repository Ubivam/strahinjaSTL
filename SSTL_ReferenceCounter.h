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

namespace sstl 
{

	//Jednostavna klasa za brojenje sistemskih referenci

	class ReferenceCounter 
	{
	public:

		ReferenceCounter() : m_counter(0) {};

		//Brisemo operator dodele i konstruktor sa vrednoscu kako niko ne bi mogo da menja counter
		ReferenceCounter(const ReferenceCounter&) = delete;
		ReferenceCounter operator = (const ReferenceCounter&) = delete;

		~ReferenceCounter()
		{
		}
		void reset()
		{
			m_counter = 0;
		}
		uint32_t get()
		{
			return m_counter;
		}
		// Overlodovanje pre/post inkrement operatora
		void operator++()
		{
			m_counter++;
		}
		void operator++(int)
		{
			m_counter++;
		}
		void operator --()
		{
			m_counter--;
		}
		void operator--(int)
		{
			m_counter--;
		}

		// Loging opcija
		friend std::ostream& operator <<(std::ostream& os, const ReferenceCounter& rc)
		{
			return os << "Vrednost Brojaca Referenci : " << rc.m_counter << std::endl;
		}
	private:
		uint32_t m_counter;
	};
}