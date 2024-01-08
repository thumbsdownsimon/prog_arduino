
struct Animal {
  int weight;
  bool alive;
  int ID;
  String homeContinent;
  String name;
};


void setup() {
  Serial.begin(9600);

  struct Animal gazelle;
  gazelle.name = "Gazelle";
  gazelle.alive = true;
  gazelle.homeContinent = "Africa";
  gazelle.weight = 22000;

  struct Animal penguin;
  penguin.name = "Penguin";
  penguin.alive = true;
  penguin.homeContinent = "Antarctica";
  penguin.weight = 1000;


  printAnimal(gazelle);
  printAnimal(penguin);
  
  swapWeight(&penguin, &gazelle);

  printAnimal(gazelle);
  printAnimal(penguin);
}

void loop() {}

void printAnimal(struct Animal a) {

  Serial.println(a.name);
  Serial.print("Weighs ");
  Serial.print(a.weight);
  Serial.println(" grams.");
  Serial.print("Comes from ");
  Serial.println(a.homeContinent);
  if (a.alive) {
    Serial.println("Alive.");
  } else {
    Serial.println("Deceased.");
  }
}

void swapWeight(struct Animal *a, struct Animal *b) {
  int temp = (*a).weight;

  (*a).weight = (*b).weight;
  (*b).weight = temp;
}

void rankByWeight(struct Animal *a, struct Animal *b) {
  //swaps the animal IDs so the heaviest animal has the lowest ID.
  int highestID = max(a->ID, b->ID);
  int lowestID = min(a->ID, b->ID);

  if (a->weight > b->weight) {
    a->ID = lowestID;
    b->ID = highestID;
  } else {
    b->ID = lowestID;
    a->ID = highestID;  
  }
}

