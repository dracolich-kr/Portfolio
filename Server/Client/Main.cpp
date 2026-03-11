#include "Pch.h"

Int32 main(Int32 argc, Char* argv[])
{
	MemoryPool::GetInstance()->Initalize();

	std::shared_ptr<Client> client = std::make_shared<Client>();

	client->Initalize();
	client->Work();
	client->Release();

	return 0;
}