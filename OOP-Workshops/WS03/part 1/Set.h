#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds
{
	template <typename T, unsigned N>
	class Set
	{
		T s_array[N]{};
		unsigned s_size{ 0u };

	public:
		size_t size() const
		{
			return this->s_size;
		}

		const T& operator[](size_t idx) const
		{
			return this->s_array[idx]; // assume that the parameter is valid
		}

		void operator+=(const T& item)
		{
			if (this->s_size < N)
			{
				this->s_array[this->s_size++] = item;
			}
		}
	};
}

#endif // !SDDS_SET_H
