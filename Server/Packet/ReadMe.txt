패킷 구성에 따른 flatbuffers 대한 설명 및 룰에 대한 설명서

스키마 타입
	문자열 string
	8 bit: byte (int8), ubyte (uint8), bool
	16 bit: short (int16), ushort (uint16)
	32 bit: int (int32), uint (uint32), float (float32)
	64 bit: long (int64), ulong (uint64), double (float64)
	백터: [변수타입]
	배열

일반 변수 선언
	변수명:스키마 타입;
	ex)
		type_name2 : int;

백터 변수 선언
	변수명:[변수타입];
	ex)
		type_name3 : [float];

배열 변수 선언 [현재 struct에서만 선언이 가능하다]
	변수명:[변수타입:배열크기];
	ex)
		type_name4 : [flaot:3];

패킷 프로젝트 설명
- 기본 구조체 및 테이블 객체들은 Common폴더에 선언하세요.
	ㅇ FlatBuffer로 추출할 때 include의 경우 폴더역 참조는 무시하고 inlcude 선언하기 때문

- 패킷쿠커는 ProtocolIdRange.fbs을 기준으로 정리됩니다.
	ㅇ GenerateRange의 경우 자동으로 ProtocolId를 발급하는 패킷 그룹은 여기에 포함 하세요.
		ㅁ 재빌드가 될 때 패킷의 ProtocolId가 변화가 있어도 안전한 패킷 ex) 서버간 통신 또는 서버내 통신들

	ㅇ Range의 경우 수동으로 아이디를 변경하는 경우 [안정성 보장]은 여기에 포함 하세요.
		ㅁ 혹시라도 패킷의 ProtocolId가 변화가 없어야하는 패킷 ex) 클라와 서버간 통신
		
패킷 그룹 구성

- 패킷은 패킷그룹명 폴더 내에  "body.fbs", "id.fbs"로 구성이 됩니다.

	ㅇ body.fbs : 실제 패킷들을 선언하는 파일
		ㅁ 패킷의 경우 무조건 맨 아래로 추가하는 것이 안전합니다.
	ㅇ id.fbs : Protocol ID 값을 가지고있는 데이터 
		ㅁ GenrateRange 경우 body.fbs를 가지고 id.fbs를 자동생성 합니다. 
		ㅁ Range의 경우 수동으로 정의를 하여야 합니다. 

- 패킷 구성 방식
	sample)

	namespace Protocol.패킷그룹명;
	// eID Enum을 가져오기 위해 필요
	include "id.fbs";
	// 위에 설명과 같이 아래처럼 선언을 해도 실제 Cpp 빌드 하면 #inlcude "Common_generated.h"로 처리되어 있다.
	include "../Common/Common.fbs";

	table Test
	{
		// 첫줄에 반드시 선언한다. 해당 값이 없으면 일반 구조체로 인식한다.
		// 패킷그룹이 GenerateRange 인 경우 id : eID 만 해두면 뒤에는 자동으로 생성 된다.
		// Range나 그룹내 선언이 없는 경우는 수동으로 작업 해야 한다. 
		id : eID = Test;
		// 통신에 필요한 데이터들은 아래에 선언한다.
		a : int;
	}

