#pragma once

#include "node.h"

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};