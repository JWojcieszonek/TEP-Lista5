#include "CTreeDynamic.h"



CTreeDynamic::CTreeDynamic()
{
	pc_root = new CNodeDynamic();
}


CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
	pc_root = NULL;
}

void CTreeDynamic::vPrintTree()
{
	pc_root->vPrintAllBelow();
	cout << endl;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic * pcParentNode, CNodeDynamic * pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		
		pcParentNode->vAddNewChild(new CNodeDynamic(*pcNewChildNode));
		int new_child_index = pcParentNode->iGetChildrenNumber() - 1; // indeks gdzie zosta³ dodany wêze³
		pcParentNode->pcGetChild(new_child_index)->vSetParent(pcParentNode);
		pcNewChildNode->pcGetParent()->bDeleteChild(pcNewChildNode->iGetIndex());

		return true;
	}
	else
		return false;
}


