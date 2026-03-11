#include <Pch.h>

ErrorResult SessionManager::Initalize()
{

	return ErrorResult::Success;
}

ErrorResult SessionManager::AddUser(Network::SharedISocket socket)
{
	std::lock_guard<std::mutex> guard(mMutex);

	auto user = MakeShared<UserSession>(GenerateIndex());
	user->SetSocket(socket);
	socket->SetSessionIndex(user->GetIndex());

	mUserSession.emplace(user->GetIndex(), user);

	return ErrorResult::Success;
}

ErrorResult SessionManager::EraseUser(SessionIndex session_id)
{
	std::lock_guard<std::mutex> guard(mMutex);
	mUserSession.erase(session_id);
	
	return ErrorResult::Success;
}

SharedUserSession SessionManager::GetUserSession(SessionIndex session_index)
{
	std::lock_guard<std::mutex> guard(mMutex);
	auto session = mUserSession.find(session_index);
	IF_RETURN(session == mUserSession.end(), nullptr);

	return session->second;
}