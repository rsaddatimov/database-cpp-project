#include "date_comparison_node.h"

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& date)
    : comparison(cmp), dateStored(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(date, dateStored, comparison);
}