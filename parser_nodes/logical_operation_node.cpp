#include "logical_operation_node.h"

LogicalOperationNode::LogicalOperationNode(
    LogicalOperation op,
    shared_ptr<Node> lhs,
    shared_ptr<Node> rhs) : op(op), leftOperand(lhs), rightOperand(rhs) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (op == LogicalOperation::Or) {
        return leftOperand->Evaluate(date, event) || rightOperand->Evaluate(date, event);
    } else {
        return leftOperand->Evaluate(date, event) && rightOperand->Evaluate(date, event);
    }
}
