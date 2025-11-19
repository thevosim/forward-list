#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template<class T>
class ForwardList
{
	struct Node
	{
		T m_data;
		Node* m_next = nullptr;
		Node(T data, Node* next = nullptr) : m_data{data}, m_next{next}
        {}
	};
	Node* first = nullptr;
    int m_size = 0;
public:
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
		Node* curr = first;
		while(curr)
		{
			Node* tmp = curr->m_next;
			delete curr;
			curr = tmp;
		}
		if(!list.first) return;

		first = new Node(list.first->m_data);
		for(Node* curr = first; !curr; curr = curr->m_next)
		{
			Node* tmp = new Node(curr->m_data);
			curr->m_next = tmp;
			curr = curr->m_next;
		}
        m_size = list.m_size;
	}
	ForwardList(const ForwardList& list) {copy(list);}
	ForwardList& operator=(const ForwardList& list) 
	{
		if(first != list.first) copy(list);
		return *this;
	}
	Node* push_front(T elem)
	{
		Node* tmp = new Node(elem);
		tmp->next = first;
		first = tmp;	
	}
	Node* insert_after(T elem, Node* prev)
	{
		if(!prev)
		{
			push_front(elem);
			return nullptr;
		}
		Node* tmp = new Node(elem);
		tmp->next = prev->next;
		prev->next = tmp;
	}
	Node* erase_after(Node* prev)
	{
		if(!prev) return erase_front();
		if(prev->m_next)
		{
			Node* tmp = prev->next->m_next;
			delete prev->m_next;
			prev->m_next = tmp;
		}
		return nullptr;
	}
	Node* erase_front(Node* prev)
	{
		if(!first) return nullptr;
		Node* tmp = first->next;
		delete first;
		first = tmp;
		return first;
	}
	
	T& operator[](int index)
	{
		int i = 0;
		Node* cur = first;
		for(Node* cur = first; cur->m_next && i < index; cur = cur->m_next, ++i);
		return cur->m_data;
	}

	T operator[](int index) const
	{
		int i = 0;
		Node* cur = first;
		for(Node* cur = first; cur->m_next && i < index; cur = cur->m_next, ++i);
		return cur->m_data;	
	}

	T at(int index) const
	{
		if(index >= m_size || index < 0) throw "Invalid index.";
		int i = 0;
		Node* cur = first;
		for(Node* cur = first; cur->m_next && i < index; cur = cur->m_next, ++i);
		return cur->m_data;
	}
	size_t size() {return m_size;}
	// ++it, *it, !it (class)
};

#endif