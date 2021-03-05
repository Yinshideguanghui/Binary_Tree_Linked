#pragma once

#include<iostream>
using namespace std;

enum Error_code { success, underflow, overflow, Range_error, not_present, fail };

template <class Node_entry>		//二叉节点
struct Binary_node
{
	Node_entry data;
	Binary_node<Node_entry>* left;
	Binary_node<Node_entry>* right;

	Binary_node() { left = NULL; right = NULL; }
	Binary_node(const Node_entry& data_, Binary_node<Node_entry>* left_ = NULL, Binary_node<Node_entry>* right_ = NULL)
		:data(data_), left(left_), right(right_) {}
};

//键(内容为1个char)
class Key
{
public:
	Key(char item = '\0') :item_(item) {}
	bool operator == (Key& k) { return item_ == k.item_; }
	bool operator > (Key& k) { return item_ > k.item_; }
	bool operator < (Key& k) { return item_ < k.item_; }
	bool operator >= (Key& k) { return item_ >= k.item_; }
	bool operator <= (Key& k) { return item_ <= k.item_; }
protected:
	char item_;
};
//记录的项目(内容为1个char)
class Record
{
public:
	Record(char Item = '\0') :item(Item) {}
	operator Key() const
	{
		Key k(item);
		return k;
	}
	char retrieve_item() const { return item; }
protected:
	char item;
};

template<class Entry>
class Binary_tree
{
public:
	//构造函数和安全措施
	Binary_tree() { root = NULL; }										//默认构造函数
	Binary_tree(const Binary_tree<Entry>& original);					//复制构造函数
	Binary_tree<Entry>& operator=(const Binary_tree<Entry>& original);	//重载赋值运算符
	//析构函数
	~Binary_tree() { clear(); }
	//是否为空
	bool empty() const;
	//函数遍历
	void inorder(void(*visit)(Entry&));		//中序遍历LVR
	void preorder(void(*visit)(Entry&));	//前序遍历VLR
	void postorder(void(*visit)(Entry&));	//后序遍历LRV
	//当前结点个数
	int size() const;
	//当前高度
	int height() const;
	//清空
	void clear();
	//插入，到矮的一边(一样高插入到左边)
	void insert(const Entry&);
protected:
	//递归遍历辅助函数
	void recursive_inorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));		//中序遍历LVR
	void recursive_preorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));	//前序遍历VLR
	void recursive_postorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));	//后序遍历LRV
	//递归求结点个数辅助函数
	int recursive_size(Binary_node<Entry>* sub_root) const;
	//递归求高度辅助函数
	int recursive_height(Binary_node<Entry>* sub_root) const;
	//清空递归辅助函数
	void recursive_clear(Binary_node<Entry>*& sub_root);
	//插入递归辅助函数，到矮的一边(一样高插入到左边)
	void recursive_insert(Binary_node<Entry>*& sub_root, const Entry& x);
	//复制构造函数递归辅助函数
	Binary_node<Entry>* recursive_copy(const Binary_node<Entry>* sub_root);
	//根结点
	Binary_node<Entry>* root;
};