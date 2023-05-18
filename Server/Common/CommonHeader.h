#pragma once
// 공용 헤더 

#include <iostream>
#include <Windows.h>

// Data structure
#include <map>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <concurrent_unordered_map.h>

#include <DbgHelp.h>
#pragma comment (lib, "dbghelp")

// 기본
using Char = CHAR;
using Byte = BYTE;
using Bool = bool;
using Int8 = int8_t;
using UInt8 = uint8_t;
using Int16 = int16_t;
using UInt16 = uint16_t;
using Int32 = int32_t;
using UInt32 = uint32_t;
using Int64 = int64_t;
using UInt64 = uint64_t;
using Double = double;
using Float = float;

// DateTime
using Year = UInt32;
using Month = UInt32;
using Day = UInt32;
using Hour = UInt32;
using Minute = UInt32;
using Second = UInt32;

using SocketId = Int64;
using SocketResult = Int32;

using IocpHandle = HANDLE;
using ThreadIndex = Int32;
using ProtocolId = UInt32;
using Port = UInt32;
using DeltaTime = UInt64;

using Size = size_t;
using SessionIndex = Int32;

using EntityId = Int32;
using FieldObjectId = Int64;

#define IF_RETURN(value, result) if(value) { return result; }
#define IF_DO(value, _do) if(value) { _do; }
#define IF_CONDINUE(value) if(value) continue;
#define IF_BREAK(value) if(value) break;

#define SAFE_DELETE(value)	\
	if(nullptr != value)	\
	{						\
		delete value;		\
		value = nullptr; 	\
	}
