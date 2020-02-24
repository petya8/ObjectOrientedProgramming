//--------------------------------------------------MEMORY LEAK------------------------------------------------------------------------------------------
//A memory leak occurs in C++ when you allocate memory dynamically and never give it back

void leak() {
//allocate 8 bytes from heap
double *pointer = new double;
}

int main() {
  leak(); //After running, those bytes were not released, but dynamic memory is released after the program is finished, right? Imgine this

  for(int i = 0; i < 150000; i++) { //run this on your own risk
    leak();
  }
}
