#pragma once

template<typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;

    Allocator() = default;
    virtual ~Allocator() = default;

    template <typename U>
    Allocator(const Allocator<U>& other) { }

    // allocate
    pointer allocate(size_type n, const void* hint = nullptr)
    {
        return reinterpret_cast<pointer>(MemoryPool::GetInstance()->Allocate(n));
    }

    // deallocate
    void  deallocate(pointer p, size_type n)
    {
        MemoryPool::GetInstance()->Deallocate(p);
    }

};