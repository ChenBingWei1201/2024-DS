#include <iostream>
#include <cstring>

struct Node {
  int key;
  Node* next;
};

// matrix multiplication
int* matrixMultiplication(int* arr) {
  int* result = new int[4];
  result[0] = arr[0] * arr[4] + arr[1] * arr[6];
  result[1] = arr[0] * arr[5] + arr[1] * arr[7];
  result[2] = arr[2] * arr[4] + arr[3] * arr[6];
  result[3] = arr[2] * arr[5] + arr[3] * arr[7];
  return result;
}

int main() {
  int k = 0;
  int* arr = new int[8];
  std::string input = "";
  std::cin >> input;
  Node* head = new Node;
  head = NULL;
  
  // use the "add to the front" singly linked list to implement a stack
  for (int i = 0; i < input.size(); i++) {
    // push the number into the stack
    if (0 <= input[i] - '0' && input[i] - '0' <= 9) {
      Node* newNode = new Node;
      newNode->key = 0;
      for (k = i; input[k] != ',' && input[k] != ']'; k++) {  
        newNode->key = newNode->key * 10 + (input[k] - '0');
      }
      i = k;
      if (head == NULL) {
        head = newNode;
        continue;
      }
      newNode->next = head;
      head = newNode;
    } else if (input[i] == ')') {
      // pop the top 8 elements from the stack
      for (int j = 7; j >=0; j--) {
        Node* temp = head;
        arr[j] = head->key;
        head = head->next;
        delete temp;
      }

      int* result = matrixMultiplication(arr);
      
      for (int j = 0; j < 4; j++) {
        Node* newNode = new Node;
        newNode->key = result[j];
        if (head == NULL) {
          head = newNode;
          continue;
        }
        newNode->next = head;
        head = newNode;
      }
    }
  }
  
  // reverse the stack to print the result
  for (int i = 0; i < 4; i++) {
    arr[i] = head->key;
    head = head->next;
  }

  // print the result
  std::cout << "[";
  for (int i = 3; i >= 0; i--) {
    std::cout << arr[i];
    if (i != 0) {
      std::cout << ",";
    }
  }
  std::cout << "]";

  delete[] arr;
  return 0;
}