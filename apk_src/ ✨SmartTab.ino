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
