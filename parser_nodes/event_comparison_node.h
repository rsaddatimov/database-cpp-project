#pragma once

#include "node.h"

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison comparison;
    string eventStored;
};