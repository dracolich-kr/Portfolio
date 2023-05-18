
/// <summary>
/// 핸들러 등록 함수
/// </summary>
class HandlerRegister
{
public:
	HandlerRegister() {}
	virtual ~HandlerRegister() {}

	virtual void Register();

private:
	Map<Int32, Handler> mHandlers;
};