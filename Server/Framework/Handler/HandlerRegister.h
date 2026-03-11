
/// <summary>
/// 핸들러 등록 함수
/// </summary>
class HandlerRegister
{
public:
	HandlerRegister(HandlerManager& manager)
		: mHandlerManager(manager)
	{}
	virtual ~HandlerRegister() {}

	virtual void Register();

private:
	HandlerManager& mHandlerManager;
};