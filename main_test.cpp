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
	//�����㣬����������һ�߲��룬��һ����ʱ����壬�ʰ�ABCDFE˳������ܹ���Ҫ��Ķ�����
	test_binary_tree.insert(Record1);
	test_binary_tree.insert(Record2);
	test_binary_tree.insert(Record3);
	test_binary_tree.insert(Record4);
	test_binary_tree.insert(Record6);
	test_binary_tree.insert(Record5);
	//���������ӡ
	test_binary_tree.postorder(print_record);
	//������������
	cout << "\n���ǰ������: " << test_binary_tree.size() << endl;
	test_binary_tree.clear();
	cout << "����������: " << test_binary_tree.size() << endl;
	return 0;
}