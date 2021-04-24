#pragma once
#include <iostream>

class String
{
private:
    size_t _size;
    char* _data;
public:
    String(const char* str = "");
    String(size_t size);
    String(String const& str);
    String(String&& str);
    ~String();

    size_t size() const;
    size_t length() const;
    char* str();
    const char* str() const;

    char& operator[](size_t idx);
    char const& operator[](size_t idx) const;
    String& operator=(String const& str);
    String& operator=(String&& str);

    String& operator+=(String const& str);
    void reserve(size_t size);
};

String operator+(String const& left, String const& right);
bool operator==(String const& left, String const& right);
bool operator!=(String const& left, String const& right);
bool operator<=(String const& left, String const& right);
bool operator>=(String const& left, String const& right);
bool operator< (String const& left, String const& right);
bool operator> (String const& left, String const& right);

std::ostream& operator<<(std::ostream& out, String const& str);
std::istream& operator>>(std::istream& in, String& str);