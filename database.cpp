#include "database.h"

#include <algorithm>
#include <sstream>
#include <stack>

void Database::Add(const Date& date, const string& event) {
    if (presence.count(date) && presence[date].count(event)) {
        return;
    }

    storage[date].push_back(event);
    presence[date].insert(event);
}

void Database::Print(ostream& out_stream) const {
    for (const auto& [date, ev_queue] : storage) {
        for (const string& event : ev_queue) {
            out_stream << date << " " << event << endl;
        }
    }
}

int Database::RemoveIf(Predicate pred) {
    int count = 0;
    stack<Date> to_pop;

    for (auto& kv : storage) {
        auto& date = kv.first;
        auto& ev_queue = kv.second;

        auto it = remove_if(ev_queue.begin(), ev_queue.end(), [&date, &pred](const string& event) {
            return pred(date, event);
        });

        count += ev_queue.end() - it;

        for_each(it, ev_queue.end(), [this, &date](const string& event) {
            presence[date].erase(event);
        });

        ev_queue.erase(it, ev_queue.end());

        if (ev_queue.empty()) {
            to_pop.push(date);
        }
    }

    while (!to_pop.empty()) {
        const Date& date = to_pop.top();

        storage.erase(date);
        presence.erase(date);

        to_pop.pop();
    }

    return count;
}

vector<string> Database::FindIf(Predicate pred) const {
    vector<string> result;

    for (const auto& kv : storage) {
        const auto& date = kv.first;
        const auto& ev_queue = kv.second;
        
        for_each(ev_queue.begin(), ev_queue.end(), [&pred, &result, &date](const string& event) {
            if (pred(date, event)) {
                ostringstream fmt;
                fmt << date << ' ' << event;

                result.push_back(fmt.str());
            }
        });
    }

    return result;
}

string Database::Last(const Date& date) const {
    if (storage.empty() || storage.begin()->first > date) {
        return "No entries";
    }

    auto it = storage.lower_bound(date);
    if (it == storage.end() || it->first > date) {
        --it;
    }

    ostringstream fmt;
    fmt << it->first << ' ' << it->second.back();

    return fmt.str();
}