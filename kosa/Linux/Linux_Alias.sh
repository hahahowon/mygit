알아두어야 할 것

- NDR
- 디스크 파일 시스템

### 임베디드 리눅스 4가지 요소

- 툴체인
    
    소스코드를 실행코드로 바꾸어 주는 컴파일 도구의 집합
    
- 부트로더 (DAS U-Boot 많이 사용)
    
    부팅시 보드 초기화와 커널 로드를 담당
    
- 커널
    
    시스템 자원 관리 및 하드웨어 제어
    
- 루트 파일시스템
    
    커널 초기화 이후 / 하위에 있는 프로그램 및 라이브러리
    

### 임베디드 리눅스 하드웨어

툴체인 내용 기억 무조건 → gcc 써보았다고 대답해야함

---

# 🔧 C 컴파일 과정과 파일 생성 흐름 정리

---

## 📌 개요

C 소스코드 `hello.c`를 GCC로 컴파일할 때 생성되는 **중간 파일**, **실행 파일**, 그리고 **심볼 및 메모리 구조**, **보안 고려사항**까지 정리한 자료

---

## 🧩 GCC 컴파일 4단계

| 단계 | 명령 | 설명 | 결과 파일 |
| --- | --- | --- | --- |
| 1단계 | `gcc -E hello.c -o hello.i` | 전처리 (`#include`, `#define` 등) | `hello.i` |
| 2단계 | `gcc -S hello.c -o hello.s` | 컴파일 (C → Assembly) | `hello.s` |
| 3단계 | `gcc -c hello.c -o hello.o` | 어셈블 (Assembly → Object) | `hello.o` |
| 4단계 | `gcc hello.o -o hello` | 링킹 (Object + 라이브러리) | `hello` |
- **전처리 (Preprocessing)**
    
    ```bash
    bash
    gcc -E hello.c
    ```
    
    - `hello.c` 파일을 전처리(preprocessing)만 수행하여 C 코드의 주석 제거, 매크로 치환 등 전처리 결과를 출력.
- **어셈블리 코드 생성 (Compilation)**
    
    ```bash
    bash
    gcc -S hello.c
    ```
    
    - C 코드를 어셈블리 코드(`.s`)로 변환. `hello.s` 생성됨.
- **오브젝트 파일 생성 (Assembly)**
    
    ```bash
    bash
    gcc -c hello.c
    ```
    
    - 컴파일 및 어셈블리 단계를 거쳐 오브젝트 파일(`hello.o`) 생성.
- 링킹

```bash
bash
gcc hello.o -o hello
```

---

## 🔍 각 파일 설명

| 파일명 | 설명 |
| --- | --- |
| `hello.i` | 전처리 결과 (헤더 포함된 순수 C코드) |
| `hello.s` | 어셈블리 코드 |
| `hello.o` | 오브젝트 파일 (기계어) |
| `hello` | 최종 실행 파일 (ELF 포맷) |

### 📦 각 **파일 확인**

```bash
bash
ls -l hello.o
```

- `hello.o`의 파일 크기, 권한, 수정 시간 등 메타 정보 출력.

```bash
bash
cat hello.o

```

- 목적 파일 내용 출력 (대부분 바이너리이므로 사람이 읽기 어려움).

```bash
bash
cat hello.s

```

- 어셈블리 코드(텍스트 형식) 출력.

---

### 📏 **오브젝트 파일 크기 확인**

```bash
bash
size hello.o
```

출력 예시:

```
yaml
   text	   data	    bss	    dec	    hex	filename
   1014	    568	      0	   1582	    62e	hello.o
```

각 필드 설명:

- `text`: 코드 섹션 (실행 명령어)
- `data`: 초기화된 전역/정적 변수
- `bss`: 초기화되지 않은 전역/정적 변수
- `dec`: 전체 크기 (10진수)
- `hex`: 전체 크기 (16진수)
- `filename`: 분석 대상 파일 이름

## 🧭 전체 컴파일 플로우 (파일 흐름 + 메모리 구조 시각화)

```
plaintext
복사편집
      ┌────────────┐
      │ hello.c    │ ←─ 사람이 작성한 소스
      └────┬───────┘
           │
           ▼
    gcc -E hello.c > hello.i
           │
           ▼
      ┌────────────┐
      │ hello.i    │ ←─ 전처리된 C 코드
      └────┬───────┘
           │
           ▼
     gcc -S hello.c
           │
           ▼
      ┌────────────┐
      │ hello.s    │ ←─ 어셈블리 코드 (ASCII)
      └────┬───────┘
           │
           ▼
     gcc -c hello.c
           │
           ▼
      ┌────────────┐
      │ hello.o    │ ←─ 오브젝트 파일 (ELF 형식)
      │            │    ├ text: 132B
      │            │    ├ data: 0B
      │            │    └ bss : 0B
      └────┬───────┘
           │
           ▼
      gcc hello.c -o hello
           │
           ▼
      ┌────────────┐
      │ hello      │ ←─ 실행 파일 (a.out)
      └────────────┘
```

## 🔍 참고 명령 정리

| 명령어 | 설명 |
| --- | --- |
| `file <filename>` | 파일의 형식과 타입 확인 |
| `size hello.o` | 목적 파일의 섹션 크기 확인 |
| `cat <파일>` | 텍스트 파일 내용 확인 |
| `ls -l` | 파일의 상세 정보 확인 |
| `gcc -E/-S/-c` | 각각 전처리, 컴파일, 어셈블 단계 수행 |

---

## 🛠️ 내부 컴파일러 구성 요소

GCC 내부 컴파일러 검색

```bash
bash
find /usr -name cc1
```

GCC 내부 컴파일러(`cc1`)의 경로를 검색 결과

```bash
 /usr/libexec/gcc/x86_64-linux-gnu/13/cc1
```

### ⚙️ **`cc1` 직접 실행 실험**

```bash
bash
/usr/libexec/gcc/x86_64-linux-gnu/13/cc1 hello.c
/usr/libexec/gcc/x86_64-linux-gnu/13/cc1 hello.s
/usr/libexec/gcc/x86_64-linux-gnu/13/cc1 hello.o
```

| 컴포넌트 | 역할 | 명령어 |
| --- | --- | --- |
| `cpp` | 전처리기 | `gcc -E` |
| `cc1` | 컴파일러 본체 | `/usr/libexec/gcc/.../cc1 hello.c` |
| `as` | 어셈블러 | `gcc -c` 내부에서 사용 |
| `ld` | 링커 | 오브젝트 + 라이브러리 → 실행파일 |
| `crt0` / `crt1` | C 런타임 초기화 | `main()` 호출 전 초기화 |
| `libc` | 표준 C 라이브러리 | `printf`, `scanf` 등 제공 |

---

## 🧠 메모리 구조 (실행 시)

```
pgsql
복사편집
+---------------------------+ ← 높은 주소
|     Stack                 |
+---------------------------+
|     Heap                  |
+---------------------------+
| .bss (초기값 없는 전역변수)|
+---------------------------+
| .data(초기값 있는 전역변수)|
+---------------------------+
| .text (실행 코드: main 등) |
+---------------------------+ ← 낮은 주소

```

---

## 📂 파일 유형 확인 명령

```bash
bash
file hello.o     # ELF 64-bit relocatable object file
file hello.c     # C source, ASCII text
file hello.s     # Assembler source, ASCII text
file hello.i     # C source, ASCII text

```

---

## 🧮 size 명령으로 메모리 사용 확인

```bash
bash
size hello.o
# 출력 예시
text  data  bss  dec  hex  filename
 132    0     0  132   84   hello.o

```

---

## 🧷 nm 명령으로 심볼 확인

```bash
bash
nm hello.o
```

출력 예시:

```bash
bash
0000000000000000 T main
                 U printf
```

- `main` 함수는 이 오브젝트 파일 안에 정의되어 있음 (`T`)
- `printf` 함수는 정의되어 있지 않고, **외부에서 링크될 것**임 (`U`)

즉, `hello.o`는 `main()`은 내부에 있고, `printf()`는 외부 라이브러리에서 링크될 것을 전제로 함.

## 📌 추가 팁

- 전체 심볼 보기: `nm -C hello.o` (`C`는 C++ 이름을 해석해서 보여줌)
- 정렬 없이 보기: `nm -n hello.o`
- 기호 정보 없는 경우 (strip된 경우): `nm`은 아무것도 출력하지 않음
- 디버깅용 심볼만 분리 저장:

```bash
bash
복사편집
gcc -g -o hello hello.c          # 디버깅 정보 포함
objcopy --only-keep-debug hello hello.debug
strip --strip-debug hello        # 실행 파일은 경량화
objcopy --add-gnu-debuglink=hello.debug hello  # 나중에 디버깅 가능

```

## 📘 심볼 타입 코드 요약

| 코드 | 의미 | 섹션 |
| --- | --- | --- |
| `T` | **텍스트 섹션**에 정의된 심볼 (함수 등) | 정의됨 |
| `U` | **정의되지 않은 외부 심볼** (예: 라이브러리 함수) | 미정의 |
| `D` | **초기화된 전역 변수** (data 섹션) | 정의됨 |
| `B` | **초기화되지 않은 전역 변수** (bss 섹션) | 정의됨 |
| `R` | **읽기 전용 데이터** (예: const 변수) | 정의됨 |
| `t`, `d`, `b` 등 | 위와 같지만 **로컬 심볼 (static)** |  |

---

## 🔐 strip으로 심볼 제거 (보안 목적)

```bash
bash
복사편집
strip hello      # 실행파일에서 심볼 제거
nm hello         # 이후에는 심볼이 보이지 않음
```

---

## 🚫 심볼 제거 이유

### 1. 🔐 **리버스 엔지니어링 방지**

- 심볼 정보에는 함수명, 전역 변수명, 라이브러리 함수 사용 정보 등이 포함되어 있어 **코드의 구조를 추정**할 수 있게 됩니다.
- 해커는 이 정보를 바탕으로 바이너리를 분석해 **취약점(버퍼 오버플로우 등)을 찾거나 악용**할 수 있습니다.
- 특히 함수명이 `check_password()` 또는 `admin_access()` 같은 식이면, 공격자 입장에서 매우 유용한 단서가 됩니다.

### 2. 🧳 **실행 파일 크기 감소**

- 심볼 정보는 메타데이터이므로, 이를 제거하면 실행 파일의 **크기를 줄일 수 있습니다**.
- 임베디드 시스템이나 제한된 저장 공간에서는 중요할 수 있습니다.

### 3. 🚫 **내부 구현 정보 보호**

- 오픈소스가 아닌 제품에서는 내부 구조가 노출되면 **기술 유출**로 이어질 수 있습니다.
- 기업들은 심볼 제거를 통해 자사의 **비즈니스 로직 보호**를 시도합니다.

| 목적 | 설명 |
| --- | --- |
| 보안 강화 | 내부 함수명 공개 시 리버스 엔지니어링 쉬워짐 |
| 실행파일 크기 감소 | 디버깅 정보 제거 |
| 내부 구현 보호 | 기술 유출 방지 |

---

## 💣 리버스 엔지니어링과 심볼

### ✅ 리버스 엔지니어링이란?

> 컴파일된 실행 파일을 분석하여 원래의 코드 구조나 동작을 추론하는 과정입니다.
> 
- `nm`, `objdump`, `strings` 등으로 내부 분석 가능
- Ghidra, IDA 같은 도구는 심볼명을 분석 단서로 활용
- 심볼이 있으면 `main`, `check_password` 등의 함수 추적 가능
- `strip`으로 이를 차단하여 분석 난이도 증가

### 🔧심볼이 있을 경우

```bash
bash
복사편집
$ nm hello
0000000000001149 T main
0000000000001120 T check_password

```

- 이런 정보를 보면 `check_password` 함수가 존재한다는 것을 알 수 있고,
- 공격자는 `Ghidra`, `IDA`, `objdump` 등의 도구로 진입점을 쉽게 찾습니다.

### 🔒 심볼 제거 후 (strip)

```bash
bash
복사편집
$ strip hello
$ nm hello
nm: hello: no symbols

```

- 내부 함수 이름이 **모두 제거**되어 버립니다.
- 리버스 엔지니어링 툴에서는 함수명이 `sub_401120()` 같은 식으로 표시되며 분석이 더 어려워짐.

---

## 📜 전체 컴파일 플로우 요약 다이어그램

```
scss
복사편집
hello.c
  ↓ (gcc -E)
hello.i
  ↓ (cc1)
hello.s
  ↓ (as)
hello.o
  ↓ (ld + crt0 + libc)
hello (실행파일)

```