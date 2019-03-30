//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"

#define STUB_PLEASE_REPLACE(x) (x)

HotCold::HotCold(const Bloated * const pBloated)
{
	hotSpace = new char[sizeof(HotNode)*pBloated->GetSize()];
	coldSpace = new char[sizeof(ColdNode)*pBloated->GetSize()];
	this->pHotHead = placement_new(hotSpace, HotNode);

	//Initialize hot head

	Node * tempBloated = pBloated->GetListHead();
	pHotHead->key = tempBloated->key;
	pHotHead->pPrev = nullptr;
	pHotHead->pNext = nullptr;

	//Keeps track of the amount of hot and cold nodes respectively in order to properly
	//iterate through the memory and place them directly next to each other.
	int hotCount = 1;
	int coldCount = 0;
	HotNode * tempHot = pHotHead;
	while (tempBloated) {
		if (tempBloated->pNext)
		{
			tempHot->pNext = placement_new(hotSpace + (hotCount * sizeof(HotNode)), HotNode);
			tempHot->pNext->pPrev = tempHot;
			tempHot->pNext->key = tempBloated->pNext->key;

		}
		else
			tempHot->pNext = nullptr;

		tempHot->pCold = placement_new(coldSpace + (coldCount * sizeof(ColdNode)), ColdNode);
		hotCount++;
		coldCount++;
		this->setUpColdNode(tempHot, tempBloated);
		tempBloated = tempBloated->pNext;
		tempHot = tempHot->pNext;
	}
}

HotCold::~HotCold()
{
	delete hotSpace;
	delete coldSpace;
}

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	//Same as bloated's findKey method.
	HotNode * temp = this->pHotHead;
	while (temp)
	{
		if (temp->key == key)
		{
			*&pFoundColdNode = temp->pCold;
			*&pFoundHotNode = temp;
			return true;
		}
		temp = temp->pNext;
	}
	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

void HotCold::setUpColdNode(HotNode *hot, Node *bloated)
{
	hot->pCold->pHot = hot;
	hot->pCold->x = bloated->x;
	hot->pCold->y = bloated->y;
	hot->pCold->z = bloated->z;
	hot->pCold->A = bloated->A;
	hot->pCold->B = bloated->B;
	hot->pCold->C = bloated->C;
	hot->pCold->MA = bloated->MA;
	hot->pCold->MB = bloated->MB;
	hot->pCold->MC = bloated->MC;
	hot->pCold->MD = bloated->MD;
	strcpy_s(hot->pCold->name, sizeof(bloated->name), bloated->name);
}

// ---  End of File ---------------
