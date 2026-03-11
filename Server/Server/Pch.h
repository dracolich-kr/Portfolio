#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define NOMINMAX
#pragma warning(disable:26495)
#pragma warning(disable:26812)
#pragma warning(disable:6812)
#pragma warning(disable:6011)
#pragma warning(disable:26454)
#pragma warning(disable:26439)

#include <iostream>

// Socket
#include <WinSock2.h>
#include <asio.hpp>

// DataBase
#include <sql.h>
#include <sqlTypes.h>
#include <sqlext.h>
// #include <sqlncli.h>
#include <sqlucode.h>
#pragma comment(lib, "odbc32.lib")

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// mysql
#include <mysql.h>
#pragma comment(lib, "libmariadb.lib")

#pragma warning(push)
#pragma warning(disable: 4200)
// redis
#include <hiredis.h>
#ifdef _DEBUG
#pragma comment(lib, "hiredisd.lib")
#else
#pragma comment(lib, "hiredis.lib")
#endif
#pragma warning(pop)

#include <flatbuffers/flatbuffers.h>
#pragma comment(lib, "flatbuffers.lib")

#include <log4cplus/log4cplus.h>
#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>

#ifdef _DEBUG
#pragma comment(lib, "log4cplusUD.lib")
#else
#pragma comment(lib, "log4cplus.lib")
#endif

extern "C"
{
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}
#pragma comment(lib, "lua54.lib")

#pragma warning(default:26495)
#pragma warning(default:26812)
#pragma warning(default:6812)
#pragma warning(default:6011)
#pragma warning(default:26454)
#pragma warning(default:26439)

#include <map>
#include <list>
#include <queue>
#include <set>
#include <atomic>
#include <thread>
#include <future>
#include <memory>
#include <condition_variable>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include <concurrent_unordered_map.h>
#include <mutex>
#include <random>
#include <mswsock.h>
#include <functional>

// Common
#include "Common/CommonHeader.h"
#include "Common/ErrorCode.h"
#include "Common/Interface.h"

#include "Framework/Core/Singleton.h"
#include "Framework/Memory/MemoryBlockList.h"
#include "Framework/Memory/MemoryPool.h"
#include "Framework/Memory/InterfaceMemory.h"
#include "Framework/Memory/Allocator.h"
#include "Framework/Memory/FlatBufferAllocator.h"

#include "Common/String.h"
// Allocate로 생성 관리되는 자료구조 선언
#include "Common/DataStructure.h"

#include "Framework/Core/ToConvert.h"
#include "Framework/Core/Random.h"
#include "Framework/Memory/ObjectPool.h"

#include "Framework/Thread/Thread.h"
#include "Framework/Task/TaskThread.h"
#include "Framework/Task/TaskThreadPool.h"

#include "Framework/Thread/ThreadManager.h"

#include "Framework/Logger/Logger.h"

#include "Framework/Time/DateTime.h"
#include "Framework/Time/TickTimer.h"
#include "Framework/Time/TimeSpan.h"

// DataBase
#include "Framework/DataBase/Session.h"
#include "Framework/DataBase/Command.h"
#include "Framework/DataBase/Result.h"

#include "Framework/DataBase/mysql/Session.h"
#include "Framework/DataBase/mysql/SessionPool.h"
#include "Framework/DataBase/mysql/Query.h"
#include "Framework/DataBase/mysql/Command.h"

#include "Framework/DataBase/Odbc/Session.h"
#include "Framework/DataBase/Odbc/Value/SqlValue.h"
#include "Framework/DataBase/Odbc/Value/SqlInt8.h"
#include "Framework/DataBase/Odbc/Value/SqlInt16.h"
#include "Framework/DataBase/Odbc/Value/SqlInt32.h"
#include "Framework/DataBase/Odbc/Value/SqlInt64.h"
#include "Framework/DataBase/Odbc/Value/SqlUInt8.h"
#include "Framework/DataBase/Odbc/Value/SqlUInt16.h"
#include "Framework/DataBase/Odbc/Value/SqlUInt32.h"
#include "Framework/DataBase/Odbc/Value/SqlUInt64.h"
#include "Framework/DataBase/Odbc/Value/SqlString.h"
#include "Framework/DataBase/Odbc/Value/SqlWString.h"
#include "Framework/DataBase/Odbc/Value/SqlDouble.h"
#include "Framework/DataBase/Odbc/Value/SqlFloat.h"
#include "Framework/DataBase/Odbc/Value/SqlDateTime.h"

#include "Framework/DataBase/Odbc/Command.h"
#include "Framework/DataBase/Odbc/Result.h"
#include "Framework/DataBase/Odbc/Query.h"
#include "Framework/DataBase/Odbc/DBThread.h"

// Protocol
#include <Common/Common_generated.h>
#include <L2L/body_generated.h>
#include <C2S/body_generated.h>
#include <S2C/body_generated.h>

// Math
#include <Framework/Math/Common.h>
#include <Framework/Math/Vector2.h>
#include <Framework/Math/Vector3.h>

// Redis
#include "Framework/Redis/Constraint.h"
#include "Framework/Redis/Command.h"
#include "Framework/Redis/Bit/Bit.h"
#include "Framework/Redis/Hashes/Hashes.h"
#include "Framework/Redis/Lists/Lists.h"
#include "Framework/Redis/Sets/Sets.h"
#include "Framework/Redis/SortedSets/SortedSets.h"
#include "Framework/Redis/Strings/Strings.h"
#include "Framework/Redis/Session.h"
#include "Framework/Redis/Executor/Executor.h"
#include "Framework/Redis/Cluster/Cluster.h"
#include "Framework/Redis/Sentinel/Sentinel.h"
#include "Framework/Redis/PipeLine/PipeLine.h"

// Lua
#include "Framework/Lua/Value/BaseValue.h"
#include "Framework/Lua/Value/Bool.h"
#include "Framework/Lua/Value/Int8.h"
#include "Framework/Lua/Value/Int16.h"
#include "Framework/Lua/Value/Int32.h"
#include "Framework/Lua/Value/Int64.h"
#include "Framework/Lua/Value/Float.h"
#include "Framework/Lua/Value/Double.h"
#include "Framework/Lua/Value/String.h"
#include "Framework/Lua/Value/MetaTable.h"

#include "Framework/Lua/Function.h"
#include "Framework/Lua/Session.h"

// Network
#include "Network/SocketUtil.h"

#include "Network/Network.h"
#include "Network/Packet/Packet.h"
#include "Network/Packet/PacketQueue.h"
#include "Network/BSDSocket.h"

#include "Network/RingBuffer.h"
#include "Network/NetworkBuffer.h"

#include "Network/Asio/Asio.h"
#include "Network/Asio/AsioAccept.h"
#include "Network/Asio/AsioThread.h"

#include "Network/Iocp/IocpOverlapped.h"
#include "Network/Iocp/Iocp.h"
#include "Network/Iocp/IocpThread.h"

#include "Network/ListenSocket.h"
#include "Network/Socket.h"
#include "Network/ClientSocket.h"

#include <../../ThirdParty/LeksysINI-master/iniparser.hpp>
#include "Framework/Parser/iniParser.h"

#include "Framework/Parser/JsonParser.h"

#include "Logic/LogicThread.h"
#include <Framework/Application.h>

#include "Server.h"

#include "Framework/Handler/Handler.h"
#include "Framework/Handler/HandlerRegister.h"
#include "Framework/Handler/HandlerManager.h"

// 유저 색션
#include "Network/Session.h"
#include "Logic/Session/ServerSession.h"
#include "Logic/Session/UserSession.h"
#include "Logic/Session/SessionManager.h"


// Loader
#include "Logic/Loader/BaseElem.h"
#include "Logic/Loader/BaseDict.h"
#include "Logic/Loader/ItemElem.h"
#include "Logic/Loader/ItemDict.h"

#include "Logic/Loader/SkillElem.h"
#include "Logic/Loader/SkillDict.h"

#include "Logic/Loader/LoadManager.h"

// System
#include "Logic/Manager/DropManager.h"
#include "Logic/Manager/KeyGenerator.h"

// BehaviorTree
#include "Logic/AI/BehaviorTree/Node.h"
#include "Logic/AI/BehaviorTree/Task/Task.h"
#include "Logic/AI/BehaviorTree/ControlFlow.h"

#include "Logic/AI/BehaviorTree/Selector/Selector.h"
#include "Logic/AI/BehaviorTree/Decorator/Decorator.h"
#include "Logic/AI/BehaviorTree/Paralle/Paralle.h"
#include "Logic/AI/BehaviorTree/Sequence/Sequence.h"
#include "Logic/AI/BehaviorTree/Service/Service.h"

#include "Logic/AI/BehaviorTree/BehaviorTree.h"

// HFSM
#include "Logic/AI/HFSM/Transition/Transition.h"
#include "Logic/AI/HFSM/State/State.h"
#include "Logic/AI/HFSM/Machine.h"

// Collision
#include "Logic/Collision/Point.h"
#include "Logic/Collision/Circle.h"
#include "Logic/Collision/Rectangle.h"
#include "Logic/Collision/Line.h"
#include "Logic/Collision/Collision.h"

#include "Logic/Position.h"

// Stat
#include "Logic/Attribute/Stat/Stat.h"
#include "Logic/Attribute/Stat/StatGroup.h"
#include "Logic/Attribute/Attribute.h"

// Skill
#include "Logic/Skill/EffectLogic/EffectLogic.h"
#include "Logic/Skill/Skill.h"
#include "Logic/Skill/SkillState.h"
#include "Logic/Skill/SkillManager.h"

// Item
#include "Logic/Item/Item.h"
#include "Logic/Item/ItemKeyGenerator.h"
#include "Logic/Item/Inventory.h"

// Entity
#include "Logic/Entity/Entity.h"
#include "Logic/Entity/CombatObject/CombatObject.h"

#include "Logic/Entity/Monster/Monster.h"
#include "Logic/Entity/Monster/MonsterState/MonsterState.h"

#include "Logic/Player/Resource/Resource.h"
#include "Logic/Player/Player.h"
#include "Logic/Entity/EntityManager.h"

// FieldObject
#include "Logic/FieldObject/FieldObjectKeyGenerator.h"
#include "Logic/FieldObject/FieldObject.h"
#include "Logic/FieldObject/FieldItem.h"
#include "Logic/FieldObject/FieldManager.h"

// World
#include "Logic/Sector/Cell/Cell.h"
#include "Logic/Sector/Cell/CellManager.h"
#include "Logic/Sector/SectorScript.h"
#include "Logic/Sector/Sector.h"
#include "Logic/Sector/SectorManager.h"

