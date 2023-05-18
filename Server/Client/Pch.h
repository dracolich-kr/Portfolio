#pragma once

#define NOMINMAX
#pragma warning(disable:26495)
#pragma warning(disable:26812)
#pragma warning(disable:6812)
#pragma warning(disable:6011)
#pragma warning(disable:26454)
#pragma warning(disable:26439)

#include <iostream>
#include <memory>

#include <WinSock2.h>

#include <sql.h>
#include <sqlTypes.h>
#include <sqlext.h>

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#pragma warning(push)
#pragma warning(disable: 4200)

#include <flatbuffers/flatbuffers.h>
#pragma comment(lib, "flatbuffers.lib")

#pragma warning(default:26495)
#pragma warning(default:26812)
#pragma warning(default:6812)
#pragma warning(default:6011)
#pragma warning(default:26454)
#pragma warning(default:26439)

#include <atomic>
#include <thread>
#include <future>
#include <memory>
#include <condition_variable>
#include <functional>
#include <stdexcept>
#include <type_traits>
#include <mutex>
#include <random>
#include <mswsock.h>

#include <log4cplus/log4cplus.h>
#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>

#ifdef _DEBUG
#pragma comment(lib, "log4cplusUD.lib")
#else
#pragma comment(lib, "log4cplus.lib")
#endif

// Common
#include "Common/CommonHeader.h"
#include "Common/ErrorCode.h"
#include "Common/Interface.h"

#include "Framework/Core/Singleton.h"
#include "Framework/Memory/MemoryBlockList.h"
#include "Framework/Memory/MemoryPool.h"
#include "Framework/Memory/Allocator.h"
#include "Framework/Memory/InterfaceMemory.h"

#include "Common/String.h"

// Allocate로 생성 관리되는 자료구조 선언
#include "Common/DataStructure.h"

#include "Framework/Core/ToConvert.h"
#include "Framework/Core/Random.h"
#include "Framework/Memory/ObjectPool.h"

#include "Framework/Thread/Thread.h"
#include "Framework/Logger/LoggerThread.h"

#include "Framework/Task/TaskThread.h"

#include "Framework/Thread/ThreadManager.h"

#include "Framework/Logger/Logger.h"

#include "Framework/Time/DateTime.h"
#include "Framework/Time/TickTimer.h"

#include "Framework/Application.h"

// Protocol
#include <Common/Common_generated.h>
#include <L2L/body_generated.h>
#include <C2S/body_generated.h>
#include <S2C/body_generated.h>

// Network
#include "Network/SocketUtil.h"
#include "Network/Network.h"
#include "Network/Packet/Packet.h"
#include "Network/Socket.h"
#include "Network/ReceiveBuffer.h"

#include "Network/Iocp/IocpOverlapped.h"
#include "Network/Iocp/Iocp.h"
#include "Network/Iocp/IocpThread.h"

#include "Network/ReceiveBuffer.h"

#include "Network/ListenSocket.h"
#include "Network/UserSocket.h"
#include "Network/ClientSocket.h"

#include "Client.h"
