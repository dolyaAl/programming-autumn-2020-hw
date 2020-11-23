#include<iostream>
#include "LinkedList.h"

using namespace std;
void someAdds(LinkedList& list)
{
	list.addToHead(5);
	list.addToHead(53);
	list.addToHead(2);
	list.addToHead(4);
	list.addToTail(6);
	list.addToTail(7);
	list.addToTail(8);
	list += 10;
	list += 11;
	list += 12;
	list += 31;
	list += 46;
	list += 82;
	list += 3;

}
void printList(LinkedList list)
{
	cout << "PRINTED LIST : " << list << endl << endl;
}

int main()
{
	LinkedList list;
	cout << "It must be empty" << endl;
	cout << list << endl;
	cout << endl;
	system("pause");
	cout << "add elements (using add to head/tail and +=)" << endl;
	someAdds(list);
	cout << list << endl;
	cout << endl;
	system("pause");
	cout << "extracting tail while list != nullptr" << endl;
	while (list.length() != 0)
	{
		cout << list.extractTail() << endl;
		cout << list << endl;
	}
	cout << endl;
	system("pause");
	cout << "get our elements back" << endl;
	someAdds(list);
	cout << list << endl;
	cout << endl;
	system("pause");
	cout << "some index extracts" << endl;
	cout << list << endl;
	cout << "list.extract(5)" << endl;
	cout << list.extract(5) << endl;
	cout << list << endl;
	cout << "list.extract(5)" << endl;
	cout << list.extract(5) << endl;
	cout << list << endl;
	cout << "list.extract(0)" << endl;
	cout << list.extract(0) << endl;
	cout << list << endl;
	cout << "list.extract(9)" << endl;
	cout << list.extract(9) << endl;
	cout << list << endl;
	cout << "list.extract(9)" << endl;
	cout << list.extract(9) << endl;
	cout << list << endl;
	cout << endl;
	system("pause");

	cout << "list -= 3" << endl;
	list -= 3;
	cout << list << endl;
	cout << endl;
	system("pause");

	cout << "indexOf(31)" << " = " << list.indexOf(31) << endl;
	cout << "indexOf(83)" << " = " << list.indexOf(83) << endl;
	cout << list << endl;
	cout << endl;
	system("pause");
	cout << "contains(31)" << endl;
	if (list.contains(31) == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << "contains(83)" << endl;
	if (list.contains(81) == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << endl;
	cout << list << endl;

	LinkedList list2;
	someAdds(list2);
	cout << " creating list2 and adding elements to it" << endl;
	cout << "list2 " << list2 << endl;
	cout << "list = list2" << endl;
	list = list2;
	cout << "list " << list << endl;
	cout << "list2 " << list2 << endl;
	return 0;
}