#pragma once
//**************************************
// cWhileNode.h
//
// Defines AST node for while statements
//
// Author: Phil Howard
//

#include "cStmtNode.h"
#include "cExprNode.h"

class cWhileNode : public cStmtNode
{
    public:
        cWhileNode(cExprNode *cond, cStmtNode *body) : cStmtNode()
        {
            AddChild(cond);
            AddChild(body);
        }

        virtual string NodeType() { return string("while"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
