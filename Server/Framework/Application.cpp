#include <Pch.h>

ErrorResult Application::Work()
{
	DeltaTime delta_time = GetTickCount64();
	DeltaTime end_time = delta_time;

	std::chrono::milliseconds ms(1);
	auto logger = LogManager::GetInstance()->GetLogger(L"Main");

	LOG_DEBUG(logger, L"Appliation Start");

	ErrorResult result = ErrorResult::Success;

	while (true)
	{
		try
		{
			delta_time = GetTickCount64() - end_time;
			end_time = GetTickCount64();

			result = Update(delta_time);

			std::this_thread::sleep_for(ms);
		}
		catch (...)
		{

		}
	}

	return ErrorResult::Success;
}