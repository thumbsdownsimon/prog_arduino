void setup() {
  //fun with pointers
  Serial.begin(9600);

  
}

void loop() {

}

void exercise1() {
  //pointer to change the value of an integer variable
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

void exercise2() {
  int a[5] = { 9, 2, 42, 5, 8 };
  int *pointer = &a[0];
  while (true) {
    Serial.print("Address of pointer is ");
    Serial.print((long)pointer);
    Serial.print("Value of pointer is ");
    Serial.println((long)*pointer);
    pointer++;
    ;
    delay(3000);
  }
}

void exercise3() {

  int a = 5;
  int b = 10;
  int *ptrA = &a;
  int *ptrB = &b;

  Serial.print("a = ");
  Serial.println(a);
  Serial.print("b = ");
  Serial.println(b);

  Serial.println("Swap!");
  swap(ptrA, ptrB);

  Serial.print("a = ");
  Serial.println(a);
  Serial.print("b = ");
  Serial.println(b);

}

void swap(int *pointer_a, int *pointer_b) {
  //swap the value of two integer variables
  int temp = *pointer_a;

  *pointer_a = *pointer_b;
  *pointer_b = temp;

}