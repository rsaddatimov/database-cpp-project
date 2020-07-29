#pragma once

#include "logical_operation.h"
#include "node.h"

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> lhs, shared_ptr<Node> rhs);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    LogicalOperation op;
    shared_ptr<Node> leftOperand;
    shared_ptr<Node> rightOperand;
};