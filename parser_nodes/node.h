#pragma once

#include "date.h"

#include <string>

using namespace std;

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};