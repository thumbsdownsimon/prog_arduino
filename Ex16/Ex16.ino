void setup() {
  //fun with pointers
  Serial.begin(9600);
  int var = 5;
  int *ptrVar = &var;
  Serial.print("Address of var is ");
  Serial.print((long)&var);
  Serial.print(", and value is ");
  Serial.println(var);

  Serial.print("Address of ptrVar is ");
  Serial.print((long)&ptrVar);
  Serial.print(", and value is ");
  Serial.println((long)ptrVar);

  *ptrVar = 10;

  Serial.print("Address of var is ");
  Serial.print((long)&var);
  Serial.print(", and value is ");
  Serial.println(var);

  Serial.print("Address of ptrVar is ");
  Serial.print((long)&ptrVar);
  Serial.print(", and value is ");
  Serial.println((long)ptrVar);

}

void loop() {}