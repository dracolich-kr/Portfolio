#pragma once

namespace Redis::Lists
{
	template<typename T>
	ErrorResult LPush<T>::onResult(std::shared_ptr<redisReply> reply)
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

	ErrorResult LPush<DefString>::onResult(std::shared_ptr<redisReply> reply)
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

	ErrorResult LPush<DefWString>::onResult(std::shared_ptr<redisReply> reply)
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
