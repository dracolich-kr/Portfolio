#include <Pch.h>

namespace Redis::Sets
{
	ErrorResult Add::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::None:
			break;
		case ReplyType::String:
			break;
		case ReplyType::Array:
			break;
		case ReplyType::Integer:
			break;
		case ReplyType::Nil:
			break;
		case ReplyType::Status:
			break;
		case ReplyType::Error:
			break;
		default:
			break;
		}

		return ErrorResult::Success;
	}

	ErrorResult Rem::onResult(std::shared_ptr<redisReply> reply)
	{
		switch ((ReplyType)reply->type)
		{
		case ReplyType::None:
			break;
		case ReplyType::String:
			break;
		case ReplyType::Array:
			break;
		case ReplyType::Integer:
			break;
		case ReplyType::Nil:
			break;
		case ReplyType::Status:
			break;
		case ReplyType::Error:
			break;
		default:
			break;
		}

		return ErrorResult::Success;
	}
}