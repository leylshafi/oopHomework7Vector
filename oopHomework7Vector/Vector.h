#pragma once
class Vector {
private:
	int* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 15;
public:
	Vector() = default;
	Vector(size_t capacity = 4) {
		_capacity = capacity;
		_array = new int[_capacity];
	}
	int* getData() const { return _array; }
	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }
	void print() const {
		for (size_t i = 0; i < _size; i++)
			cout << _array[i] << ' ';
		cout << endl;
	}
	int& operator[](const size_t& index) const
	{
		return _array[index];
	}


	void operator()() const
	{
		for (size_t i = 0; i < _size; i++)
			cout << _array[i] << ' ';
		cout << endl;
	}

	void push_back(const int value) {
		if (_size < _capacity)
		{
			_array[_size++] = value;
			return;
		}


		_capacity *= 2;
		int* temp = new int[_capacity];

		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];

		temp[_size++] = value;

		delete[] _array;
		_array = temp;

	}
	void push_front(const int value) {
		if (_size < _capacity)
		{
			int* temp = new int[_capacity]{};

			temp[0] = value;
			for (size_t i = 1,j=0; i <= _size; i++)
				temp[i] = _array[j++];
			_size++;
			delete[] _array;
			_array = temp;

			return;
		}


		_capacity *= 2;
		int* temp = new int[_capacity];

		temp[0] = value;
		for (size_t i = 0; i < _size; i++)
			temp[i] = _array[i];
		_size++;

		delete[] _array;
		_array = temp;
	}

	void pop_back() {
		int* temp = new int[_capacity] {};
			for (size_t i = 0; i < _size; i++)
				temp[i] = _array[i];
			_size--;
			delete[] _array;
			_array = temp;
	}
	void pop_front() {
		int* temp = new int[_capacity] {};
		for (size_t i = 1,j=0; i <=_size; i++)
			temp[j++] = _array[i];
		_size--;
		delete[] _array;
		_array = temp;
	}
	void delete_by_index(const size_t index) {
		int* temp = new int[_capacity] {};
		for (size_t i = 0; i < index; i++)
			temp[i] = _array[i];
		for (size_t i = index+1,j=index; i <=_size; i++)
		{
			temp[j++] = _array[i];
		}
		_size--;
		delete[] _array;
		_array = temp;
	}
	void insert_by_index(const size_t index, const int element) {
		int* temp = new int[_capacity] {};
		for (size_t i = 0; i < index; i++)
			temp[i] = _array[i];
		temp[index] = element;
		for (size_t i = index + 1,j=index; i <= _size; i++)
		{
			temp[i] = _array[j++];
		}
		_size++;
		delete[] _array;
		_array = temp;
	}
	// tapsa index-ni qaytarsin,
	// tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
	size_t find(const int element) {
		for (size_t i = 0; i < _size; i++)
		{
			if (_array[i] == element)
				return i;
		}
		return -1;
	}
	size_t rfind(const int element) {
		for (size_t i = _size; i >=0; i--)
		{
			if (_array[i] == element)
				return i;
		}
		return -1;
	}
	// reverse true gonderilse, tersine sort olunsun.
	void sort(bool reverse = false);

	/*Operator overloading

		1) operator+ 2 Vector - daki array - leri birleshdirib, yeni Vector qaytarmaq

		[1, 2] + [3, 4, 5] = [1, 2, 3, 4, 5]
}

2) operator== 2 Vector - daki array - larin sayi ve ededler beraberdi ya yox ?

[1, 4, 2] == [1, 4, 2] = > true

3) operator!= yuxarda yazilanin eksi
4) operator++ {array - daki butun ededleri 1 vahid artirmaq} {Postfix, Prefix}
5) operator-- {array - daki butun ededleri 1 vahid azaltmaq} {Postfix, Prefix}
NOTE: Yazilan kodunun uzerinə, qeyd olunanlari elavə etmək lazimdi.*/


	///Operator overloading

	/*Vector operator+(const Vector& vec) {
		Vector temp;
		temp._array = new int [] {};
	}*/

	~Vector()
	{
		delete[] _array;
	}
};
