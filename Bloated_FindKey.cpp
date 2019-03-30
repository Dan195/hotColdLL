//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

// user headers
#include "bloated.h"
#include "Node.h"

#define STUB_PLEASE_REPLACE(x) (x)

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//               starting from the head until you find it
//
// Return true if you find the node
// Return the pointer in the argument list to the node (if found)
//----------------------------------------------------------------------------------

bool Bloated::FindKey(int key, Node *&foundNode) const
{
	Node * temp = this->pHead;
	while (temp)
	{
		if (temp->key == key)
		{
			*&foundNode = temp;
			return true;
		}
		temp = temp->pNext;
	}
	return false;
}

// End of File
