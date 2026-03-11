
// 전투 움직임 없고 생성 삭제가 자주 발생하는 객체들

class FieldManager
	: public IUpdate
{
public:
	FieldManager() {}
	virtual ~FieldManager() {}

	ErrorResult Initalize();
	ErrorResult Update(DeltaTime deltatime) override;



private:
	Map<FieldObjectId, SharedFieldObject> mObjects;
	FieldObjectKeyGenerator mGenerater;
	
};