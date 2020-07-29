#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
    : comparison(cmp), dateStored(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare<const Date&>(date, dateStored, comparison);
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event)
    : comparison(cmp), eventStored(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare<const string&>(event, eventStored, comparison);
}

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