#pragma once 

class Application
{
public:
	Application() {}
	virtual ~Application() {}
	
	virtual ErrorResult Initalize() PURE;
	virtual ErrorResult Release() PURE;
	virtual ErrorResult Update(DeltaTime time) PURE;

	virtual ErrorResult Work();

private:

};