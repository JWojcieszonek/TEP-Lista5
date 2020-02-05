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
		int old_child_index = pcNewChildNode->iGetIndex(); //indeks w�z�a do usuni�cia
		pcParentNode->vAddNewChild(pcNewChildNode); //dodanie w�z�a do nowego rodzica
		int new_child_index = pcParentNode->iGetChildrenNumber() - 1; // indeks gdzie zosta� dodany w�ze�
		pcParentNode->pcGetChild(new_child_index)->vSetParent(pcParentNode); // zmiana wska�nika na nowego rodzica
		
		pcNewChildNode->pcGetParent()->bDeleteChild(old_child_index); // usuniecie w�z�a ze starego rodzica
		
		
		return true;
	}
	else
		return false;
}

