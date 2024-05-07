//搜索二叉树的场景
//	key的搜索模型:确定一个值在不在(或插入,删除等),所有的门禁系统都是key的搜索模型,不一定是搜索树,但搜索树一定可做这个模型
//	1.字典树的应用(KEY/VALUE)--->key在不在 ,通过key查找value


BSTree<string,string> dict;
dict.Insert("sort", "排序");
dict.Insert("left", "左边");
dic t.Insert("right", "右边");
dict.Insert("hello", "你好");
string ret;
dict.Insert("middle", "中间");
while (cin >> ret)
{
	BSTNode<string,string>* tmp = dict.Find(ret);
	if (tmp)
	{
		cout << tmp->_value << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

}
//	2.统计单单词出现的次数,出现次数最多的某个值
	string arr[] = { "香蕉","苹果","梨子","梨子","梨子","香蕉","苹果","梨子","苹果","梨子","梨子" ,"香蕉","苹果" };

	BSTree<string, int> ret;  // 创建一个二叉搜索树，键类型为string，值类型为int
	for (auto& e : arr)
	{
		BSTNode<string, int>* tmp = ret.Find(e);  // 在二叉搜索树中查找键为e的节点
		if (tmp == nullptr)
		{
			ret.Insert(e, 1);  // 如果节点不存在，则将键为e，值为1的节点插入到二叉搜索树中
		}
		else
		{
			tmp->_value++;  // 如果节点存在，则将节点的值加1
		}
	}
	ret.InOrder();


//搜索树源码
#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace key_value
{
	template <class K, class V>
	struct BSTNode
	{
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;
		K _key;
		V _value;

		BSTNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}
	};

	template <class T, class V>
	class BSTree
	{
		typedef BSTNode<T, V> Node;
	public:
		BSTree() = default;//对于构造函数(拷贝也是一种构造函数)没写会自动生成,写了就不会生成默认的构造函数
		//default强制生产默认构造
		bool Insert(const T& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key,value);
				return true;
			}
			Node* cur = _root;
			Node* pre = nullptr;
			while (cur)//找到后给值,所以要循环先找,再new给值
			{		   //让cur进行循环
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
			cur = new Node(key,value);
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
		Node* Find(const T& key)
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
					return cur;
				}
			}
			return nullptr;
		}
		bool Erase(const T& key)
		{
			Node* cur = _root;
			Node* pre = nullptr;
			while (cur)//找到要删除的该节点
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
			if (cur->_left == nullptr)//左树为空
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
			else if (cur->_right == nullptr)//右树为空
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
			else//两树都不为空
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


		~BSTree()
		{
			Destory(_root);
		}


	private:

		void Destory(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root == nullptr;
		}
		void _InOrder(const Node* _root)
		{
			if (_root == nullptr)
			{
				return;
			}
			_InOrder(_root->_left);
			cout << _root->_key << ":" << _root->_value << endl;
			_InOrder(_root->_right);
		}




		Node* _root = nullptr;
	};
}
