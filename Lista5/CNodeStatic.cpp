#include "CNodeStatic.h"


CNodeStatic::~CNodeStatic()
{
	//pc_parent_node = NULL;
	//v_children.clear();
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic cChild =  CNodeStatic();
	cChild.pc_parent_node = this;
	cChild.i_index = v_children.size();
	v_children.push_back(cChild);
}

void CNodeStatic::vAddNewChild(CNodeStatic * pcNewChild)
{
	pcNewChild->i_index = v_children.size();
	v_children.push_back(*pcNewChild);
}

CNodeStatic * CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= 0 && iChildOffset < v_children.size())
	{
		return &v_children[iChildOffset];
	}
	else
		return nullptr;
}

void CNodeStatic::vSetIndex(int iIndex)
{
	i_index = iIndex;
}


void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	if (!v_children.empty())
	{
	
		for (vector<CNodeStatic>::iterator it = v_children.begin(); it != v_children.end(); it++)
		{

			(*it).vPrintAllBelow();
		}
	}
	
}

void CNodeStatic::vPrintUp()
{
	vPrint();
	if(pc_parent_node!=NULL)
		pc_parent_node->vPrintUp();
	else 
		cout<<endl;
}

void CNodeStatic::vSetParent(CNodeStatic * newParent)
{
	pc_parent_node = newParent;
}

CNodeStatic * CNodeStatic::pcGetParent()
{
	return pc_parent_node;
}

bool CNodeStatic::bDeleteChild(int iIndex)
{
	if (iIndex >= 0 && iIndex < v_children.size())
	{
		v_children.erase(v_children.begin() + iIndex);
		for (vector<CNodeStatic>::iterator it = v_children.begin(); it != v_children.end(); it++)
		{

			(*it).vSetIndex(std::distance(v_children.begin(), it));
		}
		return true;
	}
	else
		return false;
	
}

