
// 메시지 처리
class Handler abstract
{
public:
	Handler(ProtocolId id) 
		: mProtocolId(id)
	{
	}

	virtual ~Handler() {}

	// 준비단계
	virtual ErrorResult Prepare(Network::SharedSession session, Network::SharedPacket packet) abstract;
	// 실제 작업 단계
	virtual ErrorResult Process(Network::SharedSession session, Network::SharedPacket packet) abstract;
	// 완료 처리
	virtual ErrorResult Finish(Network::SharedSession session, Network::SharedPacket packet) abstract;

	template<class TPacket>
	const TPacket* GetHandle(Network::SharedPacket packet)
	{
		static_assert(std::is_base_of<flatbuffers::Table, TPacket>::value, "is not flatbuffer table");

		flatbuffers::Verifier verifier(packet->GetBody(), packet->GetSize());
		IF_RETURN(false == verifier.VerifyBuffer<TPacket>(), nullptr);

		return flatbuffers::GetRoot<TPacket>(packet->GetBody());
	}

private:
	ProtocolId mProtocolId;

};

class C2SReqLoginHandler : public Handler
{
public:
	C2SReqLoginHandler() : Handler(Protocol::C2S::eID_ReqLogin) {}
	virtual ~C2SReqLoginHandler() {}

public:
	virtual ErrorResult Prepare(Network::SharedSession session, Network::SharedPacket packet) override;
	virtual ErrorResult Process(Network::SharedSession session, Network::SharedPacket packet) override;
	virtual ErrorResult Finish(Network::SharedSession session, Network::SharedPacket packet) override;

private:
};

class C2STestmsgHandler : public Handler
{
public:
	C2STestmsgHandler() : Handler(Protocol::C2S::eID_ReqTestMsg) {}
	virtual ~C2STestmsgHandler() {}

public:
	virtual ErrorResult Prepare(Network::SharedSession session, Network::SharedPacket packet) override;
	virtual ErrorResult Process(Network::SharedSession session, Network::SharedPacket packet) override;
	virtual ErrorResult Finish(Network::SharedSession session, Network::SharedPacket packet) override;

private:
	Protocol::C2S::ReqTestMsg* mPacket;
};