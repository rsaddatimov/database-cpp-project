#pragma once

#include <functional>

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

template<class ValueType>
bool Compare(ValueType lhs, ValueType rhs, Comparison cmp) {
    switch (cmp) {
    case Comparison::Less:
        return lhs < rhs;
    case Comparison::LessOrEqual:
        return lhs <= rhs;
    case Comparison::Greater:
        return lhs > rhs;
    case Comparison::GreaterOrEqual:
        return lhs >= rhs;
    case Comparison::Equal:
        return lhs == rhs;
    case Comparison::NotEqual:
        return lhs != rhs;
    default:
        return true;
    }
}
