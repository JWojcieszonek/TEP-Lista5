#pragma once
#include <vector>
#include <iostream>
using namespace std;
class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
	CNodeDynamic(CNodeDynamic &other);
	~CNodeDynamic();
	//CNodeDynamic& operator= (CNodeDynamic &other);
	void vSetValue(int iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic *pcNewChild);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vSetParent(CNodeDynamic *newParent);
	CNodeDynamic *pcGetParent();
	int iGetIndex() { return i_index; };
	void vSetIndex( int iIndex);
	bool bDeleteChild(int iIndex);


	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
private:
	vector<CNodeDynamic *> v_children;
	CNodeDynamic *pc_parent_node;
	int i_val;
	int i_index;
};

