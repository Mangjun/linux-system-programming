# 🚀 Linux System Programming Mastery (시스템 프로그래밍 실전반)

본 리포지토리는 리눅스 환경에서 애플리케이션과 운영체제가 상호작용하는 핵심 원리를 이해하고, 현업에서 요구하는 **시스템 프로그래밍 및 트러블슈팅 역량**을 마스터하기 위한 실습 기록입니다.

단순한 API 호출을 넘어, `gdb`를 통한 로직 디버깅, `valgrind`를 활용한 메모리 누수 탐지, 그리고 멀티 프로세스/스레드 환경에서의 동기화 문제(Deadlock, Race Condition) 등 로우레벨(Low-level)에서의 동작을 깊이 있게 분석하고 직접 해결해 나가는 과정을 담고 있습니다.

## 💻 개발 및 테스트 환경 (Development Environment)
외부 의존성이나 화려한 IDE의 도움 없이, 가장 기본적이고 표준적인 터미널 환경에서 실습을 진행하여 리눅스 환경 자체에 대한 적응력과 원초적인 디버깅 능력을 극대화합니다.

* **OS Environment:** `Ubuntu 24.04 LTS` (Docker Container)
* **SSH & Terminal:** `MobaXterm` (컨테이너 원격 접속)
* **Text Editor:** `vim` (플러그인 없는 순수 vi 환경)
* **Compiler & Build:** `gcc`, `Makefile`
* **Debugging & Profiling:** `gdb`, `valgrind`
* **Code Navigation:** `ctags`

## 📂 디렉토리 구조 및 전체 목차 (Table of Contents)
리눅스 시스템의 근간을 이루는 '파일'과 '프로세스'를 중심으로, 실무에 즉시 적용 가능한 코어 주제들로 커리큘럼을 구성했습니다.

### Phase 1: 파일 시스템과 입출력 (File I/O Subsystem)
- [x] **`01_file_basic/`**: 고수준(High-level) 표준 입출력 라이브러리 기초 (fopen, fread, fwrite 등)
- [x] **`02_file_low/`**: 저수준(Low-level) 시스템 콜 인터페이스 (open, read, write, 파일 디스크립터의 이해)
- [x] **`03_file_advanced/`**: 고급 파일 제어 (fcntl, 파일 잠금, I/O 멀티플렉싱, 메모리 맵핑 등)

### Phase 2: 프로세스와 스레드 제어 (Process & Thread Management)
- [ ] **`04_process/`**: 프로세스 생성 및 종료 (fork, exec, wait), 좀비/고아 프로세스 관리 및 프로세스 간 동기화 기법
- [ ] **`05_thread/`**: POSIX 스레드(pthread) 라이브러리 활용, 멀티 스레드 환경에서의 동기화 (Mutex, Semaphore, Condition Variable)

### Phase 3: 프로세스 간 통신과 이벤트 (Signals)
- [ ] **`06_signal/`**: 비동기적 이벤트(Signal) 처리 구조, 시그널 핸들러 등록 및 안전한(async-signal-safe) 함수 사용

---
*💡 각 디렉토리 내부에는 실습 소스 코드(`.c`, `Makefile`)가 포함되어 있습니다.*