# Lotech Desktop Arduino Project

### Descktop Application과 Serial 통신

1. Descktop Application에서 Serial.read()로 1바이트 문자 데이터를 받아서 저장(cmd)
2. 받아서 저장된 cmd(pin number 1~8)가 넘어옴
3. pinMode로 저장된 값을 순환하면서 cmd로 받아온 번호와 같은 번호가 있는지 확인
4. 같은 번호가 있다면 해당 번호의 pinMode를 digitalWrite의 참/거짓 상태를 바꿔서 실행 