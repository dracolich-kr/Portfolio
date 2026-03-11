#pragma once

class FlatBufferAllocator 
	: public flatbuffers::Allocator
{
public:
	FlatBufferAllocator() {}
	virtual ~FlatBufferAllocator() {}

	virtual UInt8* allocate(Size size) override;

	virtual void deallocate(UInt8* p, Size size) override;
private:

};