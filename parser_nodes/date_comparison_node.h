#pragma once

#include "comparison.h"
#include "node.h"

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date);

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison comparison;
    Date dateStored;
};