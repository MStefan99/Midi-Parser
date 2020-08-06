//
// Created by MStefan99 on 25.11.19.
//

#ifndef MIDI_PARSER_LIST_H
#define MIDI_PARSER_LIST_H

template <class T>
class list {
protected:
	struct element;

public:
	class iterator {  // bidirectional iterator
	public:
		iterator() = default;

		iterator& operator ++();
		const iterator operator ++(int);

		iterator& operator --();
		const iterator operator --(int);

		bool operator ==(const iterator& it) const;
		bool operator !=(const iterator& it) const;

		iterator& operator =(const T&);

		T* operator ->() const;
		T& operator *() const;

		friend class list;

	private:
		explicit iterator(element* elementPointer);
		element* elementPointer {nullptr};
		element* lastPointer {nullptr};
	};

	list() = default;
	list(const list& list);
	~list();

	void push_back(const T& value);
	void push_front(const T& value);

	T& front() const;
	T& back() const;

	void pop_back();
	void pop_front();

	int remove(const T& value);
	int remove_if(bool (* predicate)(const T&));

	iterator insert(iterator position, const T& value);

	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void clear();

	int size() const;
	bool empty() const;

	T& operator [](int n) const;
	list& operator =(const list& list);

	iterator begin() const;
	iterator end() const;

protected:
	struct element {
		explicit element(const T& value, element* prev, element* next);
		element(const element& listElement) = default;
		~element() = default;

		element& operator =(const element& listElement) = default;
		element& operator =(const T& value);

		T elementValue;
		element* nextElement {nullptr};
		element* prevElement {nullptr};
	};

	element* first {nullptr};
	element* last {nullptr};

	void destroyElement(element* e);
	int listSize {0};
};


template <class T>
list<T>::element::element(const T& value, element* prev, element* next):
		elementValue(value), prevElement(prev), nextElement(next) {}


template <class T>
list<T>::list(const list& l) {
	for (const auto& e : l) {
		push_back(e);
	}
	listSize = l.size();
}


template <class T>
list<T>::~list() {
	clear();
}


template <class T>
void list<T>::push_back(const T& value) {
	auto e = new element {value, last, nullptr};

	if (!first) {
		first = e;
	}
	if (last) {
		last->nextElement = e;
	}
	last = e;
	++listSize;
}


template <class T>
void list<T>::push_front(const T& value) {
	auto e = new element {value, nullptr, first};

	if (!last) {
		last = e;
	}
	if (first) {
		first->prevElement = e;
	}
	first = e;
	++listSize;
}


template <class T>
void list<T>::pop_back() {
	auto e {last};
	if (e) {
		if (e->prevElement) {
			e->prevElement->nextElement = nullptr;
		} else {
			first = nullptr;
		}

		last = e->prevElement;
		--listSize;
		delete e;
	}
}


template <class T>
void list<T>::pop_front() {
	auto e {first};
	if (e) {
		if (e->nextElement) {
			e->nextElement->prevElement = nullptr;
		} else {
			last = nullptr;
		}

		first = e->nextElement;
		--listSize;
		delete e;
	}
}


template <class T>
T& list<T>::front() const {
	return first->elementValue;
}


template <class T>
T& list<T>::back() const {
	return last->elementValue;
}


template <class T>
void list<T>::destroyElement(list<T>::element* e) {
	if (e->nextElement) {
		e->nextElement->prevElement = e->prevElement;
	} else {
		last = e->prevElement;
	}
	if (e->prevElement) {
		e->prevElement->nextElement = e->nextElement;
	} else {
		first = e->nextElement;
	}
	delete e;
}


template <class T>
typename list<T>::iterator list<T>::insert(iterator position, const T& value) {
	auto e {position.elementPointer};
	auto n = new element {value, nullptr, e};

	if (e) {
		if (e->prevElement) {
			n->prevElement = e->prevElement;
			e->prevElement->nextElement = n;
		} else {
			first = n;
		}
		e->prevElement = n;
	} else {
		if (!first) {
			first = n;
		}
		if (last) {
			last->nextElement = n;
			n->prevElement = last;
		}
		last = n;
	}
	++listSize;
	return iterator(n);
}


template <class T>
typename list<T>::iterator list<T>::erase(iterator position) {
	auto temp = position;

	++position;
	destroyElement(temp.elementPointer);
	--listSize;
	return position;
}


template <class T>
typename list<T>::iterator list<T>::erase(iterator f, iterator l) {
	while (f != l) {
		auto temp {f};
		++f;
		destroyElement(temp.elementPointer);
		--listSize;
	}
	return l;
}


template <class T>
int list<T>::remove(const T& value) {
	int i {0};
	element* e {first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		if (temp->elementValue == value) {
			destroyElement(temp);
			++i;
			--listSize;
		}
	}
	return i;
}


template <class T>
int list<T>::remove_if(bool (* p)(const T&)) {
	int i {0};
	element* e {first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		if (p(temp->elementValue)) {
			destroyElement(temp);
			++i;
			--listSize;
		}
	}
	return i;
}


template <class T>
void list<T>::clear() {
	element* e {first};

	while (e) {
		auto temp = e;
		e = e->nextElement;
		destroyElement(temp);
		listSize = 0;
	}
}


template <class T>
int list<T>::size() const {
	return listSize;
}


template <class T>
bool list<T>::empty() const {
	return first == nullptr;
}


template <class T>
typename list<T>::iterator list<T>::begin() const {
	return iterator(first);
}


template <class T>
typename list<T>::iterator list<T>::end() const {
	iterator it {};
	it.lastPointer = last;
	return it;
}


template <class T>
T& list<T>::operator [](int n) const {
	auto p {first};
	for (int i {0}; i < n; ++i) {
		p = p->nextElement;
	}
	return p->elementValue;
}


template <class T>
list<T>& list<T>::operator =(const list& l) {
	if (this == &l) {
		return *this;
	}
	clear();
	for (auto p = l.first; p != nullptr; p = p->nextElement) {
		push_back(p->elementValue);
	}
}


template <class T>
typename list<T>::element& list<T>::element::operator =(const T& value) {
	elementValue = value;
	return *this;
}


template <class T>
list<T>::iterator::iterator(element* elementPointer): elementPointer(elementPointer) {}


template <class T>
typename list<T>::iterator& list<T>::iterator::operator ++() {
	if (!elementPointer->nextElement) {
		lastPointer = elementPointer;
	} else {
		elementPointer = elementPointer->nextElement;
	}
	return *this;
}


template <class T>
const typename list<T>::iterator list<T>::iterator::operator ++(int) { // NOLINT(readability-const-return-type)
	iterator temp {this};
	if (!elementPointer->nextElement) {
		lastPointer = elementPointer;
	} else {
		elementPointer = elementPointer->nextElement;
	}
	return temp;
}


template <class T>
typename list<T>::iterator& list<T>::iterator::operator --() {
	if (!elementPointer) {
		elementPointer = lastPointer;
	} else {
		elementPointer = elementPointer->prevElement;
	}
	return *this;
}


template <class T>
const typename list<T>::iterator list<T>::iterator::operator --(int) { // NOLINT(readability-const-return-type)
	iterator temp {this};
	if (!elementPointer) {
		elementPointer = lastPointer;
	} else {
		elementPointer = elementPointer->prevElement;
	}
	return temp;
}


template <class T>
bool list<T>::iterator::operator ==(const iterator& it) const {
	return elementPointer == it.elementPointer;
}


template <class T>
bool list<T>::iterator::operator !=(const iterator& it) const {
	return elementPointer != it.elementPointer;
}


template <class T>
typename list<T>::iterator& list<T>::iterator::operator =(const T& value) {
	elementPointer->elementValue = value;
	return *this;
}


template <class T>
T* list<T>::iterator::operator ->() const {
	return &elementPointer->elementValue;
}


template <class T>
T& list<T>::iterator::operator *() const {
	return elementPointer->elementValue;
}


#endif //MIDI_PARSER_LIST_H
