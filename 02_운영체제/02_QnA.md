1. ##### 메모리 계층의 빈칸 채우기

   (상위층)레지스터 > (      ) > (      ) > 디스크

   레지스터 > 캐시 > 메모리 > 디스크



2. ##### 동기, 비동기식 입출력에 대해 설명하고 장단점을 살명하시오.

   - 동기
     - I/O 요청 후 입출력 작업이 완료된 후에야 제어가 사용자 프로그램에 넘어감
     - 안정성 보장, 순서 보장
     - 느리다.
   - 비동기
     - I/O가 시작된 후 입출력 작업이 끝나기를 기다리지 않고 제어가 사용자 프로그램에 즉시 넘어감
     - 빠르다
     - 처리하기 까다롭다. 순서 보장 X



3. ##### PCB(Process Control Block)을 설명하시오.

   - 프로세스 생성 시 마다 고유의 PCB를 생성한다.
   - 프로세스에 대한 중요 정보를 저장하고 불러오는 작업을 하기 위해 이용된다.
   - PID, Program Counter, Register 정보 등을 포함하고있다.



4. ##### System call과 Interrupt의 차이점을 설명하시오.

   - System call :   user level에서 커널이 제공하는 서비스(OS에서 제공하는 기능/모듈)를 이용하기 위해 호출
   - Interrupt :   주변 장치와 커널이 소통하는 방식 중 하나