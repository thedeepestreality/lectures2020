#pragma once

template <typename Key, typename Value>
struct Pair
{
    Key _key;
    Value _value;

    Pair(Key const& key = Key(), Value const& value = Value()) : _key(key), _value(value) {}
    Pair(Pair const& pair) : Pair(pair._key, pair._value) {} 

    Pair& operator=(Pair const& pair)
    {
        _key = pair._key;
        _value = pair._value;
        return *this;
    }
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