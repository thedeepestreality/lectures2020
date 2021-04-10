#pragma once

template <typename Type>
class AVLTree
{
	enum class Direction { Left, Right };
	struct Node
	{
		Node* parent;
		Node* left;
		Node* right;
		Type data;

		Node(const Type& dat) : parent(nullptr),
			left(nullptr),
			right(nullptr),
			data(dat) {}
		~Node()
		{
			if (left) delete left;
			if (right) delete right;
			left = right = nullptr;
		}

		Node* minimum()
		{
			Node* curr = this;
			while (curr->left != nullptr) curr = curr->left;
			return curr;
		}

		Node* next()
		{
			if (right != nullptr) return right->minimum();
			Node* pCurr = parent;
			Node* curr = this;
			while (pCurr != nullptr)
			{
				if (curr == pCurr->left) break;
				curr = pCurr;
				pCurr = pCurr->parent;
			}
			return pCurr;
		}

		size_t height() const
		{
			size_t left_h = (left == nullptr) ? 0 : left->height();
			size_t right_h = (right == nullptr) ? 0 : right->height();
			return left_h < right_h ? right_h + 1 : left_h + 1;
		}

		signed char balance()
		{
			size_t left_h = (left == nullptr) ? 0 : left->height();
			size_t right_h = (right == nullptr) ? 0 : right->height();
			return right_h - left_h;
		}
	};
	Node* _root;
	size_t _size;
	void rebalance(Node* sub_root);
	Node* rotate(Node* sub_root, Direction dir);
public:
	AVLTree() : _root(nullptr), _size(0) {}
	~AVLTree() { clear(); }
	void clear()
	{
		if (_root)
			delete _root;
		_root = nullptr;
	}
	size_t size() const { return _size; }
	size_t height() const { return _root == nullptr ? 0 : _root->height(); }
	void print() const;

	class iterator
	{
		Node* _curr;
	public:
		iterator(Node* curr = nullptr) : _curr(curr) {}
		Type& operator*() const { return _curr->data; }
		bool operator==(const iterator& it) const { return _curr == it._curr; }
		bool operator!=(const iterator& it) const { return !(*this == it); }
		iterator& operator++()
		{
			if (!_curr) throw "iterator out of bounds";
			_curr = _curr->next();
			return *this;
		}
		iterator operator++(int)
		{
			Node* prev = _curr;
			if (!_curr) throw "iterator out of bounds";
			_curr = _curr->next();
			return iterator(prev);
		}
	};

	iterator begin() const
	{
		if (_root) return iterator(_root->minimum());
		return end();
	}
	iterator end() const { return iterator(nullptr); }

	iterator insert(const Type& elem);

	iterator find(const Type& elem) const
	{
		Node* curr = _root;
		while (curr)
		{
			if (elem == curr->data) break;
			curr = elem < curr->data ? curr->left : curr->right;
		}
		return iterator(curr);
	}

	iterator erase(iterator pos);
};

template <typename Type>
void AVLTree<Type>::print() const
{
	if (_root == nullptr)
		return;
	for (Node* curr = _root->minimum(); curr != nullptr; curr = curr->next())
		std::cout << curr->data << " ";
	std::cout << "\n";
}

template<typename Type>
typename AVLTree<Type>::iterator AVLTree<Type>::insert(const Type& elem)
{
	++_size;
	if (!_root)
	{
		_root = new Node(elem);
		return begin();
	}

	Node* curr = _root;
	Node* pCurr;
	do
	{
		pCurr = curr;
		curr = elem < curr->data ? curr->left : curr->right;
	} while (curr);
	curr = new Node(elem);
	curr->parent = pCurr;
	(elem < pCurr->data) ? (pCurr->left = curr) : (pCurr->right = curr);

	rebalance(curr->parent);
	return iterator(curr);
}

template<typename Type>
void AVLTree<Type>::rebalance(Node* sub_root)
{
	do
	{
		switch (sub_root->balance())
		{
			//right disbalance
			case 2:
			{
				//right-left situation
				if (sub_root->right->balance() == -1)
					rotate(sub_root->right, Direction::Right);
				//right-right
				sub_root = rotate(sub_root, Direction::Left);
				break;
			}
			//left disbalance
			case -2:
			{
				//left-right situation
				if (sub_root->left->balance() == 1)
					rotate(sub_root->left, Direction::Left);
				//left-left
				sub_root = rotate(sub_root, Direction::Right);
				break;
			}
		}
		if (sub_root->parent == nullptr)
			_root = sub_root;
		sub_root = sub_root->parent;
	} while (sub_root != nullptr && sub_root->balance() != 0);
}

template<typename Type>
typename AVLTree<Type>::Node* AVLTree<Type>::rotate(Node* sub_root, Direction dir)
{
	Node* child;
	if (dir == Direction::Right)
	{
		child = sub_root->left;
		sub_root->left = child->right;
		if (child->right != nullptr)
			child->right->parent = sub_root;
		child->right = sub_root;
	}
	else
	{
		child = sub_root->right;
		sub_root->right = child->left;
		if (child->left != nullptr)
			child->left->parent = sub_root;
		child->left = sub_root;
	}

	if (sub_root->parent != nullptr)
	{
		if (sub_root->parent->left == sub_root)
			sub_root->parent->left = child;
		else
			sub_root->parent->right = child;
	}

	Node* tmp = sub_root->parent;
	sub_root->parent = child;
	child->parent = tmp;

	return child;
}

template<typename Type>
typename AVLTree<Type>::iterator AVLTree<Type>::erase(iterator pos)
{
	Node* to_erase = pos._node;
	if (to_erase == nullptr) return pos;

	Node* replace;
	if (to_erase->left == nullptr)
		replace = to_erase->right;
	else if (to_erase->right == nullptr)
		replace = to_erase->left;
	else
	{
		replace = to_erase->right->minimum();
		if (replace->parent != to_erase)
		{
			replace->parent->left = replace->right;
			if (replace->right) replace->right->parent = replace->parent;
			replace->right = to_erase->right;
			to_erase->right->parent = replace;
		}
		replace->left = to_erase->left;
		to_erase->left->parent = replace;
	}

	Node* unbalanced;
	if (replace = nullptr)
		unbalanced = to_erase->parent;
	else
		if (replace->parent == to_erase)
			unbalanced = replace;
		else
			unbalanced = replace->parent;

	if (to_erase->parent == nullptr)
		_root = replace;
	else
	{
		if (to_erase->parent->left == to_erase)
			to_erase->parent->left = replace;
		else
			to_erase->parent->right = replace;
	}

	if (replace != nullptr) replace->parent = to_erase->parent;

	to_erase->right = to_erase->left = nullptr;
	delete to_erase;
	--_size;

	rebalance(unbalanced);
	return iterator(replace);
}