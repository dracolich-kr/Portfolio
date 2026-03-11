## BehaviorTree 설명서
해당 비헤이비어 트리는 언리얼의 비헤이비어트리 기반으로 작업.

Node
 ㄴ Task
 ㄴ ControlFlow
	ㄴ Sequence
	ㄴ Selector
	ㄴ Paralle
	ㄴ Root


Decorator
Service

설명

Task
 - 실제 행위를 구성 하는 Node
	
ControlFlow
 - 순회 처리를 하는 Node

Paralle
 - 노드를 무조건 순회를 한다.

Sequence
 - 노드를 순회하며 false를 만날때까지 순회 한다.
 
Selector
 - 노드를 순회하며 true를 만날때까지 순회 한다.

Root
 - 트리의 시작점

Decorator
 - 조건절로 ContorlFlow나 Task에 붙여서 해당 노드가 실행될것인지 정의 한다.
