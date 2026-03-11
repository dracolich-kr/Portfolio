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

template<class Key, class Value, class _Hasher = std::hash<Key>, class _Keyeq = std::equal_to<Key>>
using UnorderedMap = std::unordered_map<Key, Value, _Hasher, _Keyeq, Allocator<std::pair<const Key, Value>>>;

using CharVector = Vector<const char*>;
using SizeTVector = Vector<Size>;

template <class Key, class Value, class _Hasher = ::std::hash<Key>, class _Key_equality = ::std::equal_to<Key>>
using ConCurrentUnorderedMap = Concurrency::concurrent_unordered_map<Key, Value, _Hasher, _Key_equality, Allocator<std::pair< const Key, Value>>>;

namespace HFSM
{
	template<class TState, class TTrigger>
	using SharedStateList = std::shared_ptr<List<SharedState<TState, TTrigger>>>;

	template<class TState, class TTrigger>
	using WeakStateList = std::shared_ptr<List<WeakState<TState, TTrigger>>>;
}