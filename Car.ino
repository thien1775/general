int b_size = 256;

char buffer[256];
char msg[256];
int joy[2];

void decode() {
  int count = 0;
  snprintf(msg,sizeof(msg),"%s","");
  char *pch;
  pch = strtok(buffer,"R");
  while (pch !=NULL) {
    joy[count] = atoi(pch);
    count++;
    pch = strtok(NULL,"R");
  }
}


void setup() {

  Serial.begin(115200);
}

void loop() {
  Serial.readBytesUntil('E',buffer,b_size);
  Serial.println(buffer);
  decode();
  String s = String("L : "+String(joy[0])+", R: "+String(joy[1]));
  Serial.println(s);
  delay(1000);

}
