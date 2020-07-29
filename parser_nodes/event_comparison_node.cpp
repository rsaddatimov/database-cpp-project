#include "event_comparison_node.h"

EventComparisonNode::EventComparisonNode(Comparison cmp, const Date& date)
    : comparison(cmp), date(date) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(event, eventStored, comparison);
}