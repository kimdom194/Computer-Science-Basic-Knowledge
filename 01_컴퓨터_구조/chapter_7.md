### 시스템 버스

- 컴퓨터 시스템 구성 요소들을 상호 연결해주는 중심 통로
- 버스 : 구성 요소들간의 교환할 각종 정보들을 전송하는 선들로 구성

![1554154763608](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554154763608.png)

- 버스의 종류

  - 데이터 버스
    - 시스템 요소들 사이에 데이터를 전송하는데 사용
    - 양방향 전송
  - (메모리의)주소 버스
    - 메모리의 용량과 관계 되어있음
      - 주소 버스가 16비트인 경우
      - 2^16 64K개 > 바이트 단위일 경우 기억장치 최대 용량 64Kbyte
    - 단방향 전송 CPU > 기억장치, 입출력 장치
    - CPU가 기억장치로 데이터 쓰기 동작을 할 때, 기억장소를 지정하는 주소를 전송할때 사용
  - 제어 버스
    - CPU와 기억장치 및 입출력장치 사이에 제어 신호들을 전송하는데 사용
    - 입력과 출력이 다른선으로 전송되어 양방향이지만 사실상 단방향이다.
      - 제어 신호 종류
        - CPU > 장치
          - 기억장치 쓰기
          - 기억장치 읽기
          - 입출력 쓰기
          - 입출력 읽기
        - CPU > 장치 > CPU
          - 전송 확인

- ### 중재 버스

  - 버스 마스터 : 버스 사용의 주체(CPU, 기억장치, 입출력 장치)

  - 버스 중재 : 버스를 사용하고자 할때 순서대로 한 개의 마스터씩사용할 수 있게 하는 동작

    - 버스 경합 : 하나의 시스템 버스에 접속된 여러개의 버스 마스터들이 동시에 사용을 요구하는 현상

    - 버스 중재 : 한 개씩만 선택하여 순서대로 버스를 사용하게 하는 동작

    - 버스 중재기 : 관재기 : 버스를 중재하는 하드웨어 모듈

    - ### 버스 중재 방식의 분류

      - 병렬 중재 방식
        - 각 버스 마스터들이 독립적인 버스 요구 신호와 버스 승인 신호를 발생
        - 버스 마스터들의 수와 같은 수의 버스 요구 선 및 승인 신호선 필요

      - 직렬 중재 방식
        - 버스 요구와 승인 신호선이 각각 한 개씩만 존재

    - ### 버스 중재기의 위치에 따른 분류

      - 중앙 집중식 중재 방식(대부분 사용)
        - 시스탬 내에 버스 중재기가 한 개씩만 존재
      - 분산식 중재 방식(사용 안함)
        - 버스 마스터 마다 중재기를 가짐

  - 중재 버스 : 버스 중재를 위한 신호 선
    - 버스 요구 신호 : 사용을 요구
    - 버스 승인 신호 : 사용할 수 있을때 사용을 허가
    - 버스 사용중 신호 : 사용 중임을 나타냄

- ### 인터럽트 버스

  - 인터럽트 버스를 이용해서 시스템에 부하를 줄인다.

  - 양방향으로 확인하는게 좀 효율이 떨어진다. 단방향으로 빠르게

  - 인터럽트 매커니즘을 위한 제어 신호선들의 집합
  - 인터럽트 요구 신호 : 입출력 장치가 인터럽트를 요구했음을 알리는 신호
  - 인터럽트 확인 신호 : CPU가 인터럽트 요구를 인식했음을 알리는 신호
  - 그 외의 신호들
    - 버스 클럭 : 버스 동작들의 시작 시간을 일치시키기 위한 신호
    - 리셋 : 시스템 모든 요소 초기화

- ### 버스 대역폭

  - 버스의 속도를 나타내는 척도, 단위 시간당 전송할 수 있는 데이터의 양을 나타냄

- ### 시스템 버스의 기본 동작

  - 쓰기 동작 순서
    1. 버스 마스터가 버스 사용권 획득
    2. 버스를 통하여 주소와 데이터 및 쓰기 신호 전송

  - 읽기 동작 순서
    1. 버스 마스터가 버스 사용권 획득
    2. 주소와 읽기 신호를 보내고, 데이터가 전송되어 올 때까지 대기
  - 버스 동작의 타이밍에 따른 버스의 분류
    - 동기식버스 : 모든 버스의 동작들이 공통의 버스 클럭을 기준으로 발생
      - 회로 간단
      - 클럭보다 짧은 시간이 걸리는 버스 동작의 경우 다음 주기까지 대기
    - 비동기식 버스 : 버스 동작들의 발생 시간이 관련된 다른 버스의 발생 여부에 따라 결정
      - 낭비시간이 없음
      - 회로가 복잡

  ![1554154847072](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554154847072.png)

- ### 병렬 중재 방식

  - 우선순위의 결정 방식에 따른 분류

    - 고정 우선순위 방식 : 각 버스마스터에 지정된 우선순위가 고정되어 있음

      - 중앙 집중식 고정 우선순위 중재 방식

        ![1554154965558](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554154965558.png)

        - 모든 버스 마스터들이 버스 중재기에 접속
        - 중재기와 가장 가까이 위치한 버스 마스터가 우선순위가 높음

      - 분산식 고정 우선순위 방식

        - 모든 버스 마스터들이 중재기를 보유
        - 장점 : 회로가 간단하여 동작속도가 빠르다
        - 단점 : 고장을 일으킨 중재기를 찾아내는 방법이 복잡하고 한 중재기의 고장이 전체 시스템의 동작에 영향을 준다.

    - 가변 우선순위 방식 : 우선순위를 변경할 수 있음 (기아 현상 제거)

      - 단점 : 중재 회로 복잡
      - 모든 마스터들이 공정하게 버스를 사용
      - 회전 우선순위 방식
        - 중재 동작이 끝날 때마다 우선순위가 한 단계씩 낮아지고 가장 낮았던 마스터가 최상위를 가진다.
      - 임의 우선순위 방식 : 임의로 우선순위 결정
      - 동등 우선순위 방식 : FIFO 알고리즘 사용(요구한 순서대로 우선순위 결정)
      - 최소 최근 사용 방식(LRU) : 가장 오랫동안 버스를 사용하지 않은 버스 마스터에게 우선순위 할당 > 회로가 복잡

- ### 직렬 중재 방식

  - 중앙 집중식 직렬 중재 방식

    - 하나의 중재 신호선이 데이지 체인 형태로 모든 버스 마스터들을 직렬로 연결
    - 승인 신호선이 연결된 순서대로 결정
    - 버스를 요구하지 않았다면 승인 신호를 다음 버스 마스터에게 전달
    - 요구한 마스터에게 도달할 때까지 계속 통과

  - 분산식 직렬 중재 방식(좋은방식은 아니다)

    - 데이지 체인이지만 중재기가 마스터마다 붙어있음

    - ##### 단점 : 어느 한 지점에만 결함이 발생해도 전체 시스템의 동작 중단

- ### 폴링 방식

  - 사용을 원하는 버스 마스터가 있는지 버스 중재기가 주기적으로 검사하여 승인 여부 결정
  - 하드웨어 폴링 방식
    - 중재기와 버스 마스터 간에 별도의 폴링 선이 존재
    - 버스 마스터의 수가 많아지면 성능이 낮아짐
  - 소프트웨어 폴링 방식
    - 폴링의 순서와 과정을 중재기의 프로세서가 관장
    - 단점 : 하드웨어 방법에 비해 속도가 느림
    - 장점 : 우선순위의 변경이 용이하다.

- ### 입출력 장치의 접속

- 입출력 제어

  - 입출력장치가 시스템 버스에 직접 접속하지 못하는 이유
    - 입출력 장치들은 종류와 제어 방법이 서로 다르다.
    - 속도가 CPU에 비해 느리다
    - CPU와 입출력장치의 데이터 형식 길이가 다르다.

- ### 인터페이스 장치인 입출력 제어기를 사용(하드웨워적인 방법)

  - 입출력 제어기의 주요 기능
    - 장치 제어와 타이밍 조정
    - CPU와 통신 담당
    - 입출력 장치와 통신 담당
    - 데이터 버퍼링 기능 수행
    - 오류 검출
  - 상태 / 제어 레지스터
    - 내부적으로 두 개의 레지스터로 구성되지만 주소는 하나만 지정되는 레지스터들
  - 상태 레지스터 : 장치 상태와 오류 검사 결과 등을 나타내는 비트들로 구성
  - 제어 레지스터 : CPU가 보낸 입출력 명령 단어를 저장

  ![1554152805467](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554152805467.png)

- ##### CPU가 프린터로 데이터를 출력하는 과정

  1. CPU가 프린터 제어기에게 프린터의 상태를 검사 요청
  2. 제어기는 프린터의 상태를 검사하여 CPU에게 통보 : 프린터의 상태란 데이터를 받아 프린트할 준비가 되었는지, 혹은 다른 데이터를 프린트하는 중인 지를 표시
  3. 데이터를 받을 준비가 된 상태면, CPU는 제어기에게 출력 명령과 데이터를 전송
  4. 제어기는 프린트 동작을 위한 제어 신호와 함께 데이터를 프린터로 전송

- ### 프로그램을 이용한 입출력(소프트웨어적인 방법)

  - 장점 : 간단하며 별도의 하드웨어가 필요하지 않음
  - CPU가 입출력 동작에 직접 관여해야 하므로, 그 동안에 다른 일을 하지 못함

  ![1554152831385](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554152831385.png)

- 입출력 주소 지정

  - 각 입출력 장치당 두 개씩의 주소 할당

    - 데이터 레지스터 주소 및 상태/제어 레지스터 주소

  - ##### 입출력 주소 지정 방법

    - 기억장치 사상 입출력
      - 주기억장치의 일부를 제어기 레지스터들의 주소로 할당하는 방식
      - 기억장치의 읽기 쓰기 신호를 입출력의 신호로 사용 가능
    - 분리형 입출력
      - 입출력 장치의 주소 공간을 기억장치 주소와는 별도로 할당
      - 별도의 입출력 읽기 쓰기 신호 필요

- 인터럽트를 이용한 입출력

  - 인터럽트 매커니즘을 이용하여 입출력 동작이 진행되는 동안에 CPU가 다른 작업을 처리할 수 있음
  - 동작 순서
    - CPU가 입출력 제어기에 명령을 전송 후 CPU는 다른 작업을 수행
    - 제어기는 입출력 장치를 제어하여 명령 실행
    - 입출력 명령 수행이 완료되면, 제어기는 CPU로 인터럽트 신호를 전송
    - CPU는 인터럽트 신호를 받는 즉시 원래의 프로그램으로 복귀하여 수행

- 인터럽트 구동 입출력의 구현 방법

  - 다중 인터럽트 방식

    - 각 제어기와 CPU 사이에 별도의 인터럽트 요구 선과 확인 선을 접속 

    ![1554153285031](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554153285031.png)

    ​	

    - 인터럽트 요구한 장치를 CPU가 쉽게 찾아낼 수 있다.
    - 하드웨어가 복잡하고 접속 가능한 입출력 장치들의 수가 CPU의 인터럽트 요구 핀의 수에 의해 제한된다.

  - 데이지 체인 방식

    - 직렬로 연결
    - 하드웨어가 간단
    - 우선순위가 낮은 장치들이 서비스 받지 못하는 경우 발생

  - 소프트웨어 폴링 방식
    - 인터럽트 확인 신호를 폴링 방식으로 TEST입출력 선을 이용하여 인터럽트를 요구한 장치를 검사하는 방식
    - 우선순위 변경이 용이
    - 처리 시간이 오래걸림(CPU가 주기적으로 체크해야하기에)

- ### DMA(직접기억장치액세스)

  - 입출력 동작을 CPU의 개입없이 입출력장치와 기억장치 사이에 데이터를 전송하는 방식 = 사이클 훔침
  - CPU가 주기억장치를 액세스하지 않는 시간 동안에 시스템 버스를 사용하여 데이터 전송

  ![1554154316689](C:\Users\TAE\AppData\Roaming\Typora\typora-user-images\1554154316689.png)

  - 각 데이터 전송때마다 시스템 버스를 두번씩 사용 > 버스 사용량 증가로 인한 시스템 성능 저하 > 입출력 장치들을 DMA 제어기에 접속, 입출력 버스 사용

  





