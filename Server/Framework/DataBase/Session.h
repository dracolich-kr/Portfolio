#pragma once

namespace DataBase
{
	class Session
	{
	public:
		Session()
			: mHost()
			, mUser()
			, mPassword()
			, mDbName()
			, mPort(0)
		{
			mHost.reserve(128);
			mUser.reserve(128);
			mPassword.reserve(128);
			mDbName.reserve(128);
		}
		
	protected:
		DefWString mDbName;

		DefWString mHost;
		Port mPort;

		DefWString mUser;
		DefWString mPassword;
	};

	using SharedSession = std::shared_ptr<Session>;
}