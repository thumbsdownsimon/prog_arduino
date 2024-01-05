void state() {
  int a[5] = { 9, 2, 42, 5, 8 };
  int *pointer = &a[0];
}


void loop() {
  Serial.printf("Address of pointer is %x\n", pointer);
  Serial.printf("Value of pointer is %d\n\n", *pointer);
  pointer++;
  
  delay(3000);
}