#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

int main()
{
	CTreeStatic  c_static_tree_1 =  CTreeStatic();
	c_static_tree_1.pcGetRoot()->vSetValue(0);
	c_static_tree_1.pcGetRoot()->vAddNewChild();
	c_static_tree_1.pcGetRoot()->vAddNewChild();
	c_static_tree_1.pcGetRoot()->vAddNewChild();
	c_static_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_static_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_static_tree_1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
	c_static_tree_1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_static_tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);
	c_static_tree_1.vPrintTree();
	
	CTreeStatic c_static_tree_2 = CTreeStatic();
	c_static_tree_2.pcGetRoot()->vSetValue(50);
	c_static_tree_2.pcGetRoot()->vAddNewChild();
	c_static_tree_2.pcGetRoot()->vAddNewChild();
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_static_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_static_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
	c_static_tree_2.vPrintTree();
	//c_static_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vPrintUp();

	c_static_tree_1.bMoveSubtree(c_static_tree_1.pcGetRoot()->pcGetChild(2), (c_static_tree_2.pcGetRoot()->pcGetChild(0)));
	c_static_tree_1.vPrintTree();
	c_static_tree_2.vPrintTree();

	CTreeDynamic c_dynamic_tree_1 = CTreeDynamic();
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);
	c_dynamic_tree_1.vPrintTree();
	
	CTreeDynamic c_dynamic_tree_2 = CTreeDynamic();
	c_dynamic_tree_2.pcGetRoot()->vSetValue(50);
	c_dynamic_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
	c_dynamic_tree_2.vPrintTree();
	//delete c_dynamic_tree_2.pcGetRoot()->pcGetChild(0);
	c_dynamic_tree_1.bMoveSubtree(c_dynamic_tree_1.pcGetRoot()->pcGetChild(2), c_dynamic_tree_2.pcGetRoot()->pcGetChild(0));
	c_dynamic_tree_1.vPrintTree();
	c_dynamic_tree_2.vPrintTree();

	return 0;
}