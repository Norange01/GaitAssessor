int i=0;
int j = 100;

void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
   Serial.println(i);
   Serial.println(j);
   i++; 
   if (i>=100){
     i = 0;
   }
}
