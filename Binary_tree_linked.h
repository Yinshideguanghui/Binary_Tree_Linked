#pragma once

#include<iostream>
using namespace std;

enum Error_code { success, underflow, overflow, Range_error, not_present, fail };

template <class Node_entry>		//����ڵ�
struct Binary_node
{
	Node_entry data;
	Binary_node<Node_entry>* left;
	Binary_node<Node_entry>* right;

	Binary_node() { left = NULL; right = NULL; }
	Binary_node(const Node_entry& data_, Binary_node<Node_entry>* left_ = NULL, Binary_node<Node_entry>* right_ = NULL)
		:data(data_), left(left_), right(right_) {}
};

//��(����Ϊ1��char)
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
//��¼����Ŀ(����Ϊ1��char)
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
	//���캯���Ͱ�ȫ��ʩ
	Binary_tree() { root = NULL; }										//Ĭ�Ϲ��캯��
	Binary_tree(const Binary_tree<Entry>& original);					//���ƹ��캯��
	Binary_tree<Entry>& operator=(const Binary_tree<Entry>& original);	//���ظ�ֵ�����
	//��������
	~Binary_tree() { clear(); }
	//�Ƿ�Ϊ��
	bool empty() const;
	//��������
	void inorder(void(*visit)(Entry&));		//�������LVR
	void preorder(void(*visit)(Entry&));	//ǰ�����VLR
	void postorder(void(*visit)(Entry&));	//�������LRV
	//��ǰ������
	int size() const;
	//��ǰ�߶�
	int height() const;
	//���
	void clear();
	//���룬������һ��(һ���߲��뵽���)
	void insert(const Entry&);
protected:
	//�ݹ������������
	void recursive_inorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));		//�������LVR
	void recursive_preorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));	//ǰ�����VLR
	void recursive_postorder(Binary_node<Entry>* sub_root, void(*visit)(Entry&));	//�������LRV
	//�ݹ����������������
	int recursive_size(Binary_node<Entry>* sub_root) const;
	//�ݹ���߶ȸ�������
	int recursive_height(Binary_node<Entry>* sub_root) const;
	//��յݹ鸨������
	void recursive_clear(Binary_node<Entry>*& sub_root);
	//����ݹ鸨��������������һ��(һ���߲��뵽���)
	void recursive_insert(Binary_node<Entry>*& sub_root, const Entry& x);
	//���ƹ��캯���ݹ鸨������
	Binary_node<Entry>* recursive_copy(const Binary_node<Entry>* sub_root);
	//�����
	Binary_node<Entry>* root;
};