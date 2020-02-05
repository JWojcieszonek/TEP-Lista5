#include "CTreeStatic.h"



CTreeStatic::CTreeStatic()
{
	c_root = CNodeStatic();
}


CTreeStatic::~CTreeStatic()
{
}

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
	cout << endl;
}

bool CTreeStatic::bMoveSubtree(CNodeStatic * pcParentNode, CNodeStatic * pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		int old_child_index = pcNewChildNode->iGetIndex(); //indeks wêz³a do usuniêcia
		pcParentNode->vAddNewChild(pcNewChildNode); //dodanie wêz³a do nowego rodzica
		int new_child_index = pcParentNode->iGetChildrenNumber() - 1; // indeks gdzie zosta³ dodany wêze³
		pcParentNode->pcGetChild(new_child_index)->vSetParent(pcParentNode); // zmiana wskaŸnika na nowego rodzica
		
		pcNewChildNode->pcGetParent()->bDeleteChild(old_child_index); // usuniecie wêz³a ze starego rodzica
		
		
		return true;
	}
	else
		return false;
}

