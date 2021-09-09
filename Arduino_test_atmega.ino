int ledPin = 13;
int key_s6 = 2;
int val=0;
void setup()
{
pinMode(ledPin, OUTPUT); // Set Pin13 to output mode
 pinMode(key_s6, INPUT); // Set Pin12 to output mode
}
void loop()
{
 if(digitalRead(key_s6)==0) //
 {
 while(!digitalRead(key_s6));
 val++;
 }
 if(val==1) {
digitalWrite(ledPin, HIGH); //
 }
 if(val==2)
 {
 val=0; 
 digitalWrite(ledPin, LOW); // Set a low value to the ledPin
 }
} 