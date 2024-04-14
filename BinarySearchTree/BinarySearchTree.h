#pragma once
#include<iostream>
using namespace std;

template <class K>
struct BSTNode
{
	BSTNode* _left;
	BSTNode* _right;
	K _key;

	BSTNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template <class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	bool Insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* pre = nullptr;
		while (cur)//�ҵ����ֵ,����Ҫѭ������,��new��ֵ
		{		   //��cur����ѭ��
			pre = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (pre->_key < key)
		{
			pre->_right = cur;
		}
		else
		{
			pre->_left = cur;
		}
		return true;
	}
	bool Find(const T& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	bool Erase(const T& key)
	{
		Node* cur = _root;
		Node* pre = nullptr;
		while (cur)//�ҵ�Ҫɾ���ĸýڵ�
		{
			if (cur->_key < key)
			{
				pre = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				pre = cur;
				cur = cur->_left;
			}
			else
			{
				break;
			}
		}
		if (cur == nullptr)
		{
			return false;
		}
		if (cur->_left == nullptr)//����Ϊ��
		{
			if (cur == _root)
			{
				_root = cur->_right;
			}
			else
			{
				if (cur == pre->_left)
				{
					pre->_left = cur->_right;

				}
				else
				{
					pre->_right = cur->_right;
				}
			}
			delete cur;
			return true;
		}
		else if (cur->_right == nullptr)//����Ϊ��
		{
			if (cur == _root)
			{
				_root = cur->_left;
			}
			else
			{
				if (cur == pre->_right)
				{
					pre->_right = cur->_left;
				}
				else
				{
					pre->_left = cur->_left;
				}
			}


		}
		else//��������Ϊ��
		{
			Node* tmp = cur;
			Node* LeftRoot = cur;
			Node* MinNode = cur->_right;
			while (MinNode->_left)
			{
				tmp = MinNode;
				MinNode = MinNode->_left;
			}
			swap(LeftRoot->_key, MinNode->_key);

			if (MinNode == tmp->_left)
			{
				tmp->_left = MinNode->_right;
			}
			else
			{
				tmp->_right = MinNode->_right;
			}
			cur = MinNode;
		}
		delete cur;
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool InsertR(const T& key)
	{
		return _InsertR(_root, key);
	}
	bool EraseR(const T& key)
	{
		return _EraseR(_root, key);
	}
	bool FindR(const T& key)
	{
		return _FindR(_root, key);
	}
private:
	void _InOrder(const Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->_left);
		cout << _root->_key << " ";
		_InOrder(_root->_right);
	}

	bool _InsertR(Node*& root, const T& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		Node* cur = root;
		if (cur->_key < key)
			return _InsertR(cur->_right, key);
		else if (cur->_key > key)
			return _InsertR(cur->_left, key);
		else
			return false;
	}
	bool _EraseR(Node*& root, const T& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key > key)
			return _EraseR(root->_left, key);
		else if (root->_key < key)
			return _EraseR(root->_right, key);
		else
		{ 
			//���Ϊnull
			if (root->_left == nullptr)
			{
				Node* tmp = root;
				root = root->_right;
				delete tmp;
			}
			//�Ҹ�Ϊnull
			else if (root->_right == nullptr)
			{
				Node* tmp = root;
				root = root->_left;
				delete tmp;
			}
			//���߶���Ϊ��,���������ֵ����������Сֵ
			//���������ֵ
			else
			{
				Node* head = root->_left;
				while(head->_right != nullptr)
				{
					head = head->_right;
				}
				swap(head->_key, root->_key);
				//�����߼�������ɾ�������Ϊ�սڵ�����һ��
				/*if (head->_left == nullptr)
				{
					delete head;
					head = nullptr;
				}
				else
				{
					Node* tmp = head;
					head = head->_left;
					delete tmp;
				}*/
				//����ֱ�ӵݹ�ɾ��
				//return _EraseR(head, key);
				return _EraseR(root->_left, key);//��ߴ�ֵ���봫ԭ�ڵ�,���ܴ����head,��Ϊhead��root->left����ʾ���ڴ沢��һ��
			}
			return true;

		}
	}
	bool _FindR(Node* root, const T& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		Node* cur = root;
		if (cur->_key < key)
			return _FindR(cur->_right, key);
		else if (cur->_key > key)
			return _FindR(cur->_left, key);
		else
			return true;
	}

	Node* _root = nullptr;
};