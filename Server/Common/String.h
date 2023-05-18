#pragma once

#include <string>

using DefString = std::basic_string<char, std::char_traits<char>, Allocator<char>>;
using DefWString = std::basic_string<wchar_t, std::char_traits<wchar_t>, Allocator<wchar_t>>;

using StringList = std::list<DefString, Allocator<DefString>>;
using WStringList = std::list<DefWString, Allocator<DefWString>>;

using DefStringStream = std::basic_stringstream<char, std::char_traits<char>, Allocator<char>>;
using DefWStringStream = std::basic_stringstream<wchar_t, std::char_traits<wchar_t>, Allocator<wchar_t>>;
