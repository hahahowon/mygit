//포인터는 기본적으로 변수와 같다
/*
값을 저장하면 일반 변수 주소를 저장하면 포인터 변수
포인터 변수: 주소를 저장하는 변수 포인터 변수의 크기는 주소의 크기와 같음
컴퓨터의 주소 체계에 따라 크기가 결정 : 32비트 시스템 기반 4바이트, 64비트 시스템 기반 8바이트
컴파일러 운영체계 프로세서 비트 확인
gcc, vs, vs code 각가의 컴파일러마다 달라질 수 있음
ex) int *a, char *b, double *c
주소지정: int *pA=&a --- &사용으로 주소지정
*/


/*
포인터 타입은 참조할 메모의 크기 정보를 제공

주소 지정 *사용 X 값 지정할때 * 사용

포인터를 초기화 하지 않은경우 쓰레기값이 들어가있기때문에 초기화 해주지 않은 경우 문제가 발생할 수 있다
287p까지 보기
*/