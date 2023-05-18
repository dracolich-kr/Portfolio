
// 메시지 처리
class Handler
{
public:
	Handler(ProtocolId id) 
		: mProtocolId(id)
	{}

	virtual ~Handler() {}

	// 준비단계
	virtual ErrorResult Prepare(std::shared_ptr<Packet> packet) { return ErrorResult::Success; }
	// 프로세싱 단계
	virtual ErrorResult Process(std::shared_ptr<Packet> packet) { return ErrorResult::Success; }
	// 완료 처리
	virtual ErrorResult Finish(std::shared_ptr<Packet> packet) { return ErrorResult::Success; }

private:
	ProtocolId mProtocolId;

};