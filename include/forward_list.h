#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template<class T>
class ForwardList
{
	struct Node
	{
		T m_data;
		Node* m_next = nullptr;
		Node(T data, Node* next = nullptr) : m_data{data}, m_next{next} {}
	};
	Node* first = nullptr;
    int m_size = 0;
public:
	ForwardList(){}
	ForwardList(size_t n, T def)
	{
		if(n == 0) return;
		first = new Node(def);
        Node* curr = first;
        int i = 1;
		for(i; i < n; ++i)
		{
			Node* tmp = new Node(def);
			curr->m_next = tmp;
			curr = curr->m_next;
		}
        m_size = n;
	}
	~ForwardList()
	{
		Node* curr = first;
		while(curr)
		{
			Node* tmp = curr->m_next;
			delete curr;
			curr = tmp;
		}
	}
	// copy constr, operator=
	void copy(const ForwardList& list)
	{
		if(!(list.first)) return;
		Node* cur_this = first;
		while(cur_this)
		{
			Node* tmp = cur_this->m_next;
			delete cur_this;
			cur_this = tmp;
		}

		first = new Node(list.first->m_data);
		Node* curr = first;
		Node* src_curr = list.first->m_next;
		while(src_curr)
		{
			curr->m_next = new Node(src_curr->m_data);
			curr = curr->m_next;
			src_curr = src_curr->m_next;
		}
        m_size = list.m_size;
	}
	ForwardList(const ForwardList& list) {copy(list);}
	ForwardList& operator=(const ForwardList& list) 
	{
		if(first != list.first) copy(list);
		return *this;
	}
	void push_front(T elem)
	{
		Node* tmp = new Node(elem);
		tmp->m_next = first;
		first = tmp;
		++m_size;
	}
	Node* insert_after(Node* prev, T elem)
	{
		++m_size;
		if(!prev)
		{
			push_front(elem);
			return nullptr;
		}
		Node* tmp = new Node(elem);
		tmp->m_next = prev->m_next;
		prev->m_next = tmp;
		return prev->m_next;
	}
	Node* erase_after(Node* prev)
	{
		if(!prev) return erase_front();
		if(prev->m_next)
		{
			Node* tmp = prev->m_next->m_next;
			delete prev->m_next;
			prev->m_next = tmp;
			--m_size;
		}
		return nullptr;
	}
	Node* erase_front()
	{
		if(!first) return nullptr;
		Node* tmp = first->m_next;
		delete first;
		first = tmp;
		--m_size;
		return first;
	}
	
	T& operator[](int index)
	{
		int i = 0;
		Node* cur = first;
		for(cur; cur && i < index; cur = cur->m_next, ++i);
		return cur->m_data;
	}

	T operator[](int index) const
	{
		int i = 0;
		Node* cur = first;
		for(cur; cur && i < index; cur = cur->m_next, ++i);
		return cur->m_data;	
	}

	T at(int index) const
	{
		if(index >= m_size || index < 0) throw "Invalid index.";
		int i = 0;
		Node* cur = first;
		for(cur; cur && i < index; cur = cur->m_next, ++i);
		return cur->m_data;
	}
	size_t size() {return m_size;}
	// ++it, *it, !it (class)
	class Iterator
	{
		Node* m_it = nullptr;
	public:
		Iterator(Node* ptr) : m_it{ptr} {}
		operator Node*() const {return m_it;}
		Iterator& operator++() 
		{
			m_it = m_it->m_next;
			return *this;
		}
		T operator*() {return m_it->m_data;}
		bool operator!=(Iterator it) {return m_it != it;}
		bool operator!() {return m_it == nullptr;}
	};
	Iterator begin() {return first;}
	Iterator end() {return nullptr;}
};

#endif