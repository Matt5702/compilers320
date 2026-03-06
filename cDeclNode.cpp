//****************************************************
// cDeclNode.cpp - Implementation of cDeclNode methods
//

#include "cDeclNode.h"

// Check if this type is compatible with another type for assignment
bool cDeclNode::IsCompatibleWith(cDeclNode *otherType)
{
    if (otherType == nullptr)
        return false;
    
    // Same type is always compatible
    if (this == otherType)
        return true;
    
    // Within integer category: promote smaller to larger
    if (this->IsInt() && otherType->IsInt())
    {
        return otherType->GetSize() <= this->GetSize();
    }
    
    // Within floating-point category: promote smaller to larger
    if (this->IsFloat() && otherType->IsFloat())
    {
        return otherType->GetSize() <= this->GetSize();
    }
    
    // Across categories: integer can promote to float
    if (this->IsFloat() && otherType->IsInt())
    {
        return true;
    }
    
    if (this->IsInt() && otherType->IsFloat())
    {
        return false;
    }
    
    return false;
}
