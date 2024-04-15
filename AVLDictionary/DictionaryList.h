#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H
#include <string>

template <class KeyT>
class DictionaryList
{
public:
	DictionaryList() :
		head_(nullptr),
		size_(0)
	{}
	struct Node
	{
		KeyT key;
		Node* next;

		Node(const KeyT& k, Node* n = nullptr) :
			key(k),
			next(n)
		{}
	};
	DictionaryList(const DictionaryList&);
	DictionaryList(DictionaryList&&) noexcept;
	DictionaryList& operator=(const DictionaryList&) = delete;
	DictionaryList& operator=(DictionaryList&& list)
	{
		if (this != &list)
		{
			while (head_)
			{
				Node* temp = head_;
				head_ = head_->next;
				delete temp;
			}
			head_ = list.head_;
			list.head_ = nullptr;
		}
		return *this;
	}
	~DictionaryList();
	bool insert(const KeyT&);
	bool remove(const KeyT&);
	bool search(const KeyT&);
	const KeyT& getKey(Node*);
	Node* head();
	int size();
	void merge(DictionaryList&);
	template <class T>
	friend std::ostream& operator<<(std::ostream& stream, const DictionaryList<T>& list);
private:
	Node* head_;
	int size_;
};

template<class KeyT>
inline DictionaryList<KeyT>::DictionaryList(const DictionaryList& src)
{
	if (src.head_ != nullptr)
	{
		Node* temp1 = src.head_;
		head_ = new Node(temp1->key);
		Node* temp2 = head_;
		temp1 = temp1->next;
		while (temp1 != nullptr)
		{
			temp2->next = new Node(temp1->key);
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
	}
	else
	{
		head_ = nullptr;
	}
	size_ = src.size_;
}

template <class KeyT>
DictionaryList<KeyT>::DictionaryList(DictionaryList&& list) noexcept :
	head_(list.head_)
{
	list.head_ = nullptr;
}

template <class KeyT>
DictionaryList<KeyT>::~DictionaryList()
{
	while (head_)
	{
		Node* temp = head_;
		head_ = head_->next;
		delete temp;
	}
}

template <class KeyT>
bool DictionaryList<KeyT>::insert(const KeyT& val)
{
	bool added = false;
	if (head_ == nullptr)
	{
		Node* newNode = new Node(val);
		head_ = newNode;
		added = true;
		++size_;
	}
	else if (head_->key > val)
	{
		Node* newNode = new Node(val, head_);
		head_ = newNode;
		added = true;
		++size_;
	}
	else
	{
		
		Node* temp = head_;
		Node* tempNext = head_->next;
		while (!added && tempNext != nullptr)
		{
			if (tempNext->key > val && temp->key < val)
			{
				Node* newNode = new Node(val, tempNext);
				temp->next = newNode;
				added = true;
				++size_;
			}
			else if (temp->key == val || tempNext->key == val)
			{
				return false;
			}
			else
			{
				temp = temp->next;
				tempNext = tempNext->next;
			}
		}
		if (!added)
		{
			if (temp->key == val)
			{
				return false;
			}
			else
			{
				Node* newNode = new Node(val);
				temp->next = newNode;
				added = true;
				++size_;
			}
		}
	}
	return added;
}

template <class KeyT>
bool DictionaryList<KeyT>::remove(const KeyT& val)
{
	bool deleted = false;
	if (head_ == nullptr)
		return false;
	else if (head_->key == val)
	{
		Node* temp = head_;
		head_ = head_->next;
		delete temp;
		deleted = true;
		--size_;
	}
	else if (head_->key > val)
		return false;
	else
	{
		Node* temp = head_;
		Node* tempNext = head_->next;
		while (!deleted && tempNext != nullptr)
		{
			if (tempNext->key == val)
			{
				temp->next = tempNext->next;
				delete tempNext;
				deleted = true;
				--size_;
			}
			else if (tempNext->key > val)
			{
				return false;
			}
			else
			{
				temp = temp->next;
				tempNext = tempNext->next;
			}
		}
	}
	return deleted;
}

template <class KeyT>
bool DictionaryList<KeyT>::search(const KeyT& val)
{
	bool found = false;
	if (head_->key == val)
		found = true;
	else if (head_->key > val)
		return found;
	else
	{
		Node* temp = head_->next;
		while (!found && temp != nullptr)
		{
			if (temp->key == val)
			{
				found = true;
			}
			else if (head_->key > val)
			{
				return found;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	return found;
}

template<class KeyT>
inline const KeyT& DictionaryList<KeyT>::getKey(Node* node)
{
	return node->key;
}

template<class KeyT>
inline typename DictionaryList<KeyT>::Node* DictionaryList<KeyT>::head()
{
	return head_;
}

template<class KeyT>
inline int DictionaryList<KeyT>::size()
{
	return size_;
}

template<class KeyT>
void DictionaryList<KeyT>::merge(DictionaryList& list)
{
	if (list.head_ != nullptr)
	{
		if (head_ == nullptr)
		{
			head_ = list.head_;
			list.head_ = nullptr;
		}
		else
		{
			Node* temp = head_;
			Node* tempNext = head_->next;
			Node* tempList = list.head_;
			if (list.head_->key < head_->key)
			{
				list.head_ = list.head_->next;
				tempList->next = head_;
				head_ = tempList;
				tempList = list.head_;
				temp = head_;
				tempNext = head_->next;
			}
			while (tempNext != nullptr && tempList != nullptr)
			{
				if (temp->key == tempList->key || tempNext->key == tempList->key)
				{
					list.head_ = list.head_->next;
					delete tempList;
					tempList = list.head_;
				}
				else if (temp->key < tempList->key && tempNext->key > tempList->key)
				{
					list.head_ = list.head_->next;
					tempList->next = tempNext;
					temp->next = tempList;
					temp = tempList;
					tempList = list.head_;
				}
				else
				{
					temp = temp->next;
					tempNext = tempNext->next;
				}
			}
			if (tempList != nullptr)
			{
				if (temp->key == tempList->key)
				{
					list.head_ = list.head_->next;
					delete tempList;
					tempList = list.head_;
				}
				temp->next = tempList;
				list.head_ = nullptr;
			}
		}
	}
}


template <class T>
std::ostream& operator<<(std::ostream& stream, const DictionaryList<T>& list)
{
	typename DictionaryList<T>::Node* temp = list.head_;
	while (temp)
	{
		stream << temp->key << "  ";
		temp = temp->next;
	}
	return stream;
}

#endif