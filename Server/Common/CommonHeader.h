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
#include <utility>

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
using SkillIndex = Int32;

using ElemIndex = Int32;

template<class T>
using UniquePtr = std::unique_ptr<T, std::function<void(T*)>>;

namespace Network 
{
	class Packet;
	using SharedPacket = std::shared_ptr<Packet>;
	class PacketQueue;

	class Session;
	using SharedSession = std::shared_ptr<Session>;
}

class Handler;
using SharedHandler = std::shared_ptr<Handler>;
class HandlerManager;
using SharedHandlerManager = std::shared_ptr<HandlerManager>;

using ItemId = Int64;
using ItemCount = Int32;

class Item;
using SharedItem = std::shared_ptr<Item>;

class ItemOption;
using SharedItemOption = std::shared_ptr<ItemOption>;

class Inventory;
using SharedInventory = std::shared_ptr<Inventory>;

class CombatObject;
using SharedCombatObject = std::shared_ptr<CombatObject>;
using WeakCombatObject = std::weak_ptr<CombatObject>;

class Stat;
using SharedStat = std::shared_ptr<Stat>;

class Attribute;
using SharedAttribute = std::shared_ptr<Attribute>;

class Skill;
using SharedSkill = std::shared_ptr<Skill>;
using WeakSkill = std::weak_ptr<Skill>;

class SkillState;
using SharedSkillState = std::shared_ptr<SkillState>;

class SkillManager;
using SharedSkillManager = std::shared_ptr<SkillManager>;

class EffectLogic;
using SharedEffectLogic = std::shared_ptr<EffectLogic>;

class MonsterState;
using SharedMonsterState = std::shared_ptr<MonsterState>;

class Monster;
using SharedMonster = std::shared_ptr<Monster>;
using WeakMonster = std::weak_ptr<Monster>;

using CellIndex = Int32;
using CellSize = Int32;
using GridIndex = Int32;

class Grid;
using SharedGrid = std::shared_ptr<Grid>;
using WeakGrid = std::weak_ptr<Grid>;

class Cell;
using SharedCell = std::shared_ptr<Cell>;
using WeakCell = std::weak_ptr<Cell>;

class Entity;
using SharedEntity = std::shared_ptr<Entity>;
using WeakEntity = std::weak_ptr<Entity>;

class Sector;
using SharedSector = std::shared_ptr<Sector>;

class FieldObject;
using SharedFieldObject = std::shared_ptr<FieldObject>;

namespace HFSM
{
	template<class TState, class TTrigger>
	class Machine;

	template<class TState, class TTrigger>
	using SharedMachine = std::shared_ptr<Machine<TState, TTrigger>>;

	template<class TState, class TTrigger>
	using WeakMachine = std::weak_ptr<Machine<TState, TTrigger>>;

	template<class TState, class TTrigger>
	class State;

	template<class TState, class TTrigger>
	using SharedState = std::shared_ptr<State<TState, TTrigger>>;

	template<class TState, class TTrigger>
	using WeakState = std::weak_ptr<State<TState, TTrigger>>;

	template<class TState, class TTrigger>
	class Transition;

	template<class TState, class TTrigger>
	using SharedTransition = std::shared_ptr<Transition<TState, TTrigger>>;
}

enum class StateType : Int32
{
	None = 0
	, Root = 1
	, Alive = 2
		, Spawn = 21
		, Idle = 22
		, Move = 23
		, Chase = 24
		, UseSkill = 25
	, Dead = 3
		, Revive = 31
		, Exit = 32
};

enum class TriggerType : Int32
{
	None = 0
	, Timeout
};

enum class SkillStateType :Int32
{
	None = 0
	, Root = 0
	, Init = 1
	, Cast = 2
	, Shot = 3
	, Finish = 4
	, Exit = 5
};

enum class SkillTriggerType : Int32
{
	None = 0
	, Timeout
};

enum class LoaderType
{
	None
	, Item = 1
	, Skill = 2
	, Max
};

enum class ServerType
{
	None = 0
	, Login
	, Lobby
	, World
	, Zone
};

static constexpr Int32 NetworkBufferSize = 64 * 1024;

#define IF_RETURN(value, result) if(value) { return result; }
#define IF_DO(value, _do) if(value) { _do; }
#define IF_CONTINUE(value) if(value) continue;
#define IF_BREAK(value) if(value) break;

#define SAFE_DELETE(value)	\
	if(nullptr != value)	\
	{						\
		delete value;		\
		value = nullptr; 	\
	}
