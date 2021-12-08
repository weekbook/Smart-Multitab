# 3학년 2학기 무선 네트워크 기말 프로젝트

### 참여자 및 맡은 역할

+ 201744015 김현우 : 자료 조사 및 정리
+ 201744024 안성호 : 코딩 및 구현
+ 201744028 이기훈 : 코딩 및 구현

## 프로젝트 주제

Bluetooth를 이용한 원격제어 멀티탭 만들기

## 프로젝트 선정 배경과 목적

+ 일상생활에서 쓸 수 있는 활용도가 높은 제품을 만들어보고 싶었고 마침 멀티탭이 눈에 띄어서 프로젝트 주제로 선정하게 되었습니다.
+손이 닿지 않는 원거리에서도 멀티탭의 스위치 버튼을 직접 누르지 않아도 각 콘센트의 전류를 제어하기 위한 멀티탭을 구현하는게 프로젝트의 목표입니다.

## 프로젝트를 진행하는데 사용한 장치 및 부품
<p><img src="사진 모음/2구 콘센트.png" width="250" height="150"></img> 2구 콘센트</p>
<p><img src="사진 모음/HC-06 블루투스 모듈.png" width="300" height="100"></img> HC-06 블루투스 모듈</p>
<p><img src="사진 모음/srd-05vdc-sl-c 릴레이 모듈.png" width="200" height="200"></img> srd-05vdc-sl-c 릴레이 모듈</p>
<p><img src="사진 모음/아두이노UNO R3.png" width="300" height="200"></img> 아두이노UNO R3</p>

## 도안
<p><img src="사진 모음/1차 회로도.png"></img></p>

## 구현과정


## 시연
https://user-images.githubusercontent.com/67256177/145161592-518c770d-f2c3-463a-aeb4-061a8955a0a7.mp4

## 코드
```
#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

int Relaypin1 = 8;
int LED = 13;
int count = 0;
int blueTxd=2;   //Txd(Transmit Data) 송신 신호
int blueRxd=3;   //Rxd(Receive Data) 수신 신호

SoftwareSerial mySerial(blueTxd, blueRxd);  //시리얼 통신 객체선언
String myString=""; //받는 문자열

void setup() {
  pinMode(Relaypin1, OUTPUT); // RelayPin1(8번핀)을 OUTPUT으로 설정
  Serial.begin(9600);   // 시리얼모니터 
  mySerial.begin(9600); // 블루투스 시리얼 개방
  pinMode(LED, OUTPUT);  // LED(13번핀)을 OUTPUT으로 설정
}

void loop() {
  
// 릴레이 모듈 작동 실험
//  count = count + 1;
//  count = count % 2;

//  if (count == 1)
//  {
//    digitalWrite(LED, HIGH);
//    digitalWrite(Relaypin1, HIGH); 
//    delay(3000);                    
//  }else{
//    digitalWrite(LED, LOW);
//    digitalWrite(Relaypin1, LOW); 
//    delay(3000);
//  }
  while(mySerial.available())  //mySerial 값이 있다면
  {
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙인다
    delay(5);           //문자열 수신간 끊김 방지
  }
  
  if(!myString.equals(""))  //myString에 값이 있다면
  {
    Serial.println("input value: "+myString); //시리얼모니터에 블투루스 통신으로 받은값 출력
 
      if(myString=="on")  //myString 값이 'on' 이라면
      {
        digitalWrite(LED, HIGH); //LED ON
        digitalWrite(Relaypin1, HIGH); // 릴레이 모듈 전력 공급
      } else {
        digitalWrite(LED, LOW);  //LED OFF
        digitalWrite(Relaypin1, LOW); // 릴레이 모듈 전력 차단
      }
      
    myString="";  //myString 변수값 초기화
  }
}
```

## 프로젝트를 진행하면서 발생한 문제점과 그 해결방법



