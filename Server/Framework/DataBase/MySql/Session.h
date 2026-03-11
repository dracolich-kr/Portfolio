#pragma once

namespace DataBase::MySql
{
	class MySqlInit
	{
	public:
		MySqlInit()
		{
			mysql_library_init(0, nullptr, nullptr);
		}

		virtual ~MySqlInit()
		{
			mysql_library_end();
		}

	private:

	};

	class Session
		: public DataBase::Session
	{
	public:
		Session()
		{
			mConnector.reset(mysql_init(nullptr), [](MYSQL* mysql)
				{
					mysql_close(mysql);
				});

			mysql_thread_init();
		}

		virtual ~Session()
		{
			mysql_thread_end();
		}

		ErrorResult Connect(DefWString db_name, DefWString ip, Port port, DefWString user, DefWString password);
		ErrorResult Disconnect();

		std::shared_ptr<MYSQL> GetInfo() { return mConnector; }

	private:
		std::shared_ptr<MYSQL> mConnector;
		log4cplus::Logger mLogger = LogManager::GetInstance()->GetLogger(L"mysql");

	};

	using SharedSession = std::shared_ptr<Session>;
}