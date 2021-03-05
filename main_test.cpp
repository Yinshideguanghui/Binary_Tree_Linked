#include"Binary_tree_linked.h"
#include"Binary_tree_linked.cpp"

void print(Record& this_Entry)
{
	cout << this_Entry.retrieve_item();
}

int main()
{
	void(*print_record)(Record&) = &print;
	Record Record1('A'), Record2('B'), Record3('C'), Record4('D'), Record5('E'), Record6('F');
	Binary_tree<Record> test_binary_tree;
	//插入结点，由于往矮的一边插入，且一样高时往左插，故按ABCDFE顺序插入能构造要求的二叉树
	test_binary_tree.insert(Record1);
	test_binary_tree.insert(Record2);
	test_binary_tree.insert(Record3);
	test_binary_tree.insert(Record4);
	test_binary_tree.insert(Record6);
	test_binary_tree.insert(Record5);
	//后序遍历打印
	test_binary_tree.postorder(print_record);
	//清除，输出长度
	cout << "\n清除前结点个数: " << test_binary_tree.size() << endl;
	test_binary_tree.clear();
	cout << "清除后结点个数: " << test_binary_tree.size() << endl;
	return 0;
}