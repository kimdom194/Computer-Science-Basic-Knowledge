### 기억 장치

- 기억장치 액세스 : CPU가 어떤 정보를 기억장치에 쓰거나 기억장치로부터 읽는 동작
  -  액세스의 유형
    - 순차적 액세스 : 처음부터 순서대로 액세스하는 방식[자기테이프]
    - 직접 액세스 : 액세스할 위치 근처로 이동후 순차적 검색을 사용[CD-ROM, 하드 디스크]
    - 임의 액세스 : 주소에 의해 직접 기억장소를 찾아 액세스, 어떤 기억 장소든 액세스 시간이 동일[반도체 기억장치 램, 롬]
    - 연관 액세스 : 특정 비트를 비교하여 일치하는 내용 액세스[연관 기억장치 > 연관 검색어 같은 개념 > 캐시 메모리에서 사용]
- 기억장치 시스템을 설계하는데 고려사항
  - 용량
  - 액세스 속도
- 전송 단위 : CPU가 한번의 기억장치 액세스에 의하여 읽거나 쓸 수  있는 비트 수(bps)
  - 주기억장치 : 단어(WORD)단위
  - 보조기억장치 : 블록(512, 1K 바이트) 단위
- 주소 지정 단위
  - 바이트 단위 혹은 단어 단위
  - 주소 비트의 수 A와 주소지정 단위의 수 N과의 관계 : 2xxA = N
- 액세스 속도와 관련된 파라미터들
- 액세스 시간 : 주소와 쓰기/읽기 신호가 도착한 순간부터 데이터 액세스가 완료되는 순간까지의 시간
- 기억장치 사이클 시간 : 액세스 시간 + 데이터 복원 시간
- 데이터 전송률 : 기억장치로부터 초당 액세스 되는 비트 수
  - (1/액세스 시간) x (한번에 읽혀지는 데이터 비트 수)



기억장치의 유형

- 기억장치의 제조 재료에 따른 유형
  - 반도체 기억장치 : 반도체 물질인 실리콘 칩을 이용한 기억장치(RAM, ROM)
  - 자기 표면 기억장치 : 자화 물질로 코팅된 표면에 정보를 저장하는 기억장치(디스크)
- 데이터를 저장하는 성질에 따른 유형
  - 휘발성 기억장치 : 전원 공급이 중단되면 내용이 지워짐(RAM)
  - 비휘발성 기억장치 : 전원 공급에 관계없는 영구 저장장치(ROM)
- 삭제 불가능 기억장치 : 내용 변경이 불가능한 기억장치 (ROM)



##### 계층적 기억장치 시스템

```
계층 : 레지스터 > 캐시 > 메모리 > usb > 하드 > 테이프
```

필요성 : 기억장치들은 속도, 용량 및 가격 측면에서 매우 다양

효과 : 기억장치 시스템의 성능 대 가격비 향상

- 기억장치 특성들간의 관계
  - 액세스 속도가 높아질수록 비트당 가격은 증가
  - 용량이 커질수록 비트당 가격은 낮아진다
  - 용량이 커질수록 액세스 시간은 길어진다
- 계층적 기억장치시스템의 구성방법
  - 첫번째 계층 기억장치 : 속도가 빠르나 가격은 높은 기억장치 사용
  - 두번째 계층 기억장치 : 속도는 느리지만 가격은 낮은 기억장치 사용



##### 반도체 기억장치

- 메모리의 단위 : bit

- RAM

  - DRAM : 주기억장치 (가격이 싸고 집적도가 높음)
  - SRAM : 캐시메모리 (가격이 비싸고 빠름 집적도가 떨어짐)

- ROM

  - PROM : 한번만 작성 가능
  - EPROM : 자외선으로 내용을 지울 수 있음
  - EEPROM : 전기적으로 지울 수 있음
  - 플래시 메모리 : 블록 단위로 삭제, 페이지 단위로 읽기, 쓰기가 가능함

  

### 캐시 메모리

- 사용 목적 : CPU와 주기억장치(DRAM)의 속도차이로 인한 CPU 대기 시간을 최소화 시키기 위하여 CPU와 주 기억장치 사이에 설치하는 고속 반도체 기억장치(SRAM)
- 특징
  - 주 기억장치보다 액세스 속도가 높은 칩 사용
  - 가격 및 제한된 공간 때문에 용량이 적다

- 캐시 적중 : CPU가 원하는 데이터가 캐시에 있는 상태

- 캐시 미스 : CPU가 원하는 데이터가 캐시에 없는 상태, 이 경우에는 주기억장치로부터 데이터를 읽어온다.

- 적중률 : 캐시에 적중되는 정도 > 적중횟수 / 전체 기억장치 액세스 횟수

  - 캐시 적중률은 프로그램과 데이터의 지역성에 따라 달라진다.

    - ### 지역성

      - 시간적 지역성 : 최근 액 세스된 프로그램이나 데이터가 다시 액세스 될 가능성이 높다(Loop)
      - 공간적 지역성 : 인접하여 저장되어 있는 데이터들이 연속적으로 액세스 될 가능성이 높다(배열)
      - 순차적 지역성 : 분기가 발생하지 않는 한, 명령어들은 기억장치에 저장된 순서대로 인출되어 실행된다

- 캐시의 미스율 : (1 - 적중률)

- 평균 기억장치 액세스 시간 : 적중률 * 액세스 시간 + 미스율 * 액세스 시간

- ### 캐시 설계의 목표

  - 캐시 적중률의 극대화
  - 캐시 액세스 시간의 최소화
  - 캐시 미스에 따른 지연시간의 최소화
  - 주기억장치(원본 데이터)와 캐시(복사본 데이터)간의 데이터 일관성 유지 및 그에 따른 오버헤드 최소화

- 인출 방식
  - 요구 인출 방식 : 필요한 정보만 인출해 오는 방법
  - 선인출 방식
    - 필요한 정보 외에 앞으로 필요할 것으로 예측되는 정보로 미리 인출
      - 지역성이 높은 경우에 효과가 높다

- 블록 : 주기억장치로부터 동시에 인출되는 정보들의 그룹

- 라인 : 캐시에서 한 블록이 저장되는 장소

- 태그 : 라인에 적재된 블록을 구분해주는 정보

### 사상(매핑) 방식

- 주기억장치 블록들이 어느 캐시 라인을 공유할 것인 지를 결정해 주는 방법

  - 직접 사상(적중률 낮음)

  - 완전 연관 사상(구현 불가능)

  - ### 세트 연관 사상(실제 사용)

    - 직접 사상과 완전 연관 사상의  조합

    - 주기억장치 블록 그룹이 하나의 캐시 세트를 공유하며, 그 세트에는 두 개 이상의 라인들이 적재될 수 있다.

    - 기억장치 주소 형식

      - 태그 필드와 세트 필드를 합한 (t+d)비트가 주기억장치의 2^(t+d)블록들 중의 하나를 지정 

      - ### [태그필드 / 세트필드 / 단어필드]

        - 태그 필드 : 전체 주소비트 7비트 - 세트 단어 = 3 bit 
        - 세트 필드 : 4세트 2^2 
        - 단어 필드 : 블록의 크기 (4 byte = 2^2(2bit))
        - 메인 메모리 128 byte / 하나의 블록 4 byte = 32개의 블록 
        - 캐시의 크기 32 byte /  하나의 블록 4 byte = 8개의 라인 > 4세트 (2개의 라인 = 1 세트) 

    - 동작 원리

      - 세트 비트들을 이용하여 캐시 세트들 중의 하나를 선택
      - 주소의 태그 필드 내용과 그 세트내의 태그들을 비교
        - 일치하는 것이 있으면(캐시 적중)
        - 일치하는 것이 없다면(캐시 미스)

    - ### 교체 알고리즘

      - 세트 연관 사상에서 주기억장치로부터 새로운 블록이 캐시로 적재될 때, 모든 라인들이 다른 블록으로 채워져 있다면, 그들 중의 하나를 선택하여 새로운 블록으로 교체

      - 캐시 적중률을 극대화할 수 있도록 교체할 블록을 선택하기 위한 알고리즘
        - 최소 최근 사용(LRU)알고리즘 : 사용되지 않은 채로 가장 오래 있었던 블록을 교체
        - FIFO 알고리즘 : 캐시에 가장 적재된 지 오래된 블록을 교체
        - 최소 사용 빈도(LFU) 알고리즘 : 참조되었던 횟수가 가장 적은 블록을 교체

    - 쓰기 정책

      - 캐시의 블록이 변경되었을 때 그 내용을 주기억장치에 갱신하는 시기와 방법의 결정
        - Write through : 주기억장치, 캐시 한번에 바뀜 > 내용이 항상 같다. 쓰는 시간이 길어진다. 병렬처리에 사용
        - Write back : 캐시는 변경되어도 주기억장치는 변경 x
          - 블록을 교체할때 캐시의 상태를 확인하여 갱신
          - 쓰는 횟수가 최소화되고, 쓰는 시간이 짧아진다

    - ### 다중 캐시(L1, L2, L3)

      - 온-칩 캐시 : 캐시 액세스 시간을 단축시키기 위해 CPU 칩내에 포함시킨 캐시
      - 계층적 캐시
        - 온-칩 캐시를 1차(L1) 캐시로 사용하고, 칩 외부에 더 큰 용량의 2차(L2)캐시를 설치하는 방식 
        - 속도 : L1>L2(L2는 L1의 슈퍼세트(L2는 L1을 모두 포함한다))>MM 크기는 반대
      - 분리 캐시(L1이 사용)
        - 캐시를 명령어 캐시와 데이터 캐시로 분리
        - 파이프라인에 의한 명령어 인출 유니트와 실행 유니트 간에 캐시 액세스 충돌 현상 제거

 