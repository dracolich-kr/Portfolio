#pragma once

template<class T>
using Vector = std::vector<T, Allocator<T>>;

template<class T>
using Deque = std::deque<T, Allocator<T>>;

template<class T>
using List = std::list<T, Allocator<T>>;

template<class T>
using Queue = std::queue<T, Allocator<T>>;

template<class Key, class Value, class TPredicate = std::less<Key>>
using Map = std::map<Key, Value, TPredicate, Allocator<std::pair<const Key, Value>>>;

template<class Key, class Value, class TPredicate = std::less<Key>>
using MultiMap = std::multimap<Key, Value, TPredicate, Allocator<std::pair<const Key, Value>>>;

template<class Key, class TPredicate = std::less<Key>>
using Set = std::set<Key, TPredicate, Allocator<Key>>;

template<class Key, class TPredicate = std::less<Key>>
using MultiSet = std::multiset<Key, TPredicate, Allocator<Key>>;

using CharVector = Vector<const char*>;
using SizeTVector = Vector<Size>;