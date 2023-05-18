#include "Pch.h"

Int32 main(Int32 argc, Char* argv[])
{
	std::shared_ptr<Client> client = std::make_shared<Client>();

	client->Initalize();
	client->Work();
	client->Release();

	return 0;
}