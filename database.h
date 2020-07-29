#pragma once

#include "date.h"

#include <functional>
#include <map>
#include <set>
#include <string>
#include <vector>

using Predicate = function<bool(const Date&, const string&)>;

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& out_stream) const;

    int RemoveIf(Predicate pred);

    vector<string> FindIf(Predicate pred) const;

    string Last(const Date& date) const;
private:
    map<Date, vector<string>> storage;
    map<Date, set<string>> presence;
};