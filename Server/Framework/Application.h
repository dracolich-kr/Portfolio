#pragma once 

class Application
{
public:
	Application() {}
	virtual ~Application() {}
	
	virtual ErrorResult Initalize() abstract;
	virtual ErrorResult Release() abstract;
	virtual ErrorResult Update(DeltaTime time) abstract;

	virtual ErrorResult Work();

private:

};