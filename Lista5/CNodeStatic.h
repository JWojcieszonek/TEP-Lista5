#pragma once
#include <vector>
#include <iostream>
using namespace std;
class CNodeStatic
{
public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; i_index = 0; };
	~CNodeStatic();

	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeStatic *pcNewChild);

	CNodeStatic *pcGetChild(int iChildOffset);
	void vSetIndex(int iIndex);
	int iGetIndex() { return i_index; };
	void vSetParent(CNodeStatic *newParent);
	CNodeStatic *pcGetParent();
	bool bDeleteChild(int iIndex);

	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();
	


private:
	vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;
	int i_index;
};

