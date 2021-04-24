#pragma once
#include "../String/String.h"
#include <iostream>

template <typename Key, typename Value>
struct Pair
{
    Key _key;
    Value _value;

    Pair(Key const& key = Key(), Value const& value = Value()) : _key(key), _value(value) {}
};

template <typename Key, typename Value>
bool operator<(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return left._key < right._key;
}

template <typename Key, typename Value>
bool operator<=(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return !(right < left);
}

template <typename Key, typename Value>
bool operator>(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return right < left;
}

template <typename Key, typename Value>
bool operator>=(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return !(left < right);
}

template <typename Key, typename Value>
bool operator==(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return !((left < right) || (right < left));
}

template <typename Key, typename Value>
bool operator!=(Pair<Key, Value> const& left, Pair<Key, Value> const& right)
{
    return (left < right) || (right < left);
}


std::ostream& operator<<(std::ostream& out, Pair<String,String> const& pair)
{
    return out << pair._key << ": " << pair._value << std::endl;
}

std::istream& operator>>(std::istream& in, Pair<String, String>& pair)
{
    char tmp[1024];
    in.getline(tmp, 1024);
    char* p = tmp;
    while ((*p != '$') && (*p)) ++p;
    if (*p) { *p = '\0'; ++p; }
    pair = Pair<String, String>(String(tmp), String(p));
    return in;
}