#pragma once

#include "Pair.h"

//template template argument
template <typename Key, typename Value, template<typename> typename Container>
class Dictionary
{
private:
    Container<Pair<Key, Value>> _container;
public:
    Dictionary() = default;

    size_t size() const
    {
        return _container.size();
    }
     
    Value& operator[](Key const& key)
    {
        auto found = _container.find(key);
        if (found == _container.end())
        {
            auto it = _container.insert(key);
            return (*it)._value;
        }
        return (*found)._value;
    }
};


//Dictionary<string, int> dict;
//dict["one"] = 1;

/// TODO: how to forbid this?
// int two = dict["two"];