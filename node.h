#pragma once

#include "comparison.h"
#include "logical_operation.h"
#include "date.h"

#include <string>


class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};


class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};


class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison comparison;
    Date dateStored;
};


class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison comparison;
    string eventStored;
};


class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op, shared_ptr<Node> lhs, shared_ptr<Node> rhs);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    LogicalOperation op;
    shared_ptr<Node> leftOperand;
    shared_ptr<Node> rightOperand;
};