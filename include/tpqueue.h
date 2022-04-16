// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T arr[50];
  int first, last;

 public:
    TPQueue(): first(0), last(0) {}
    void push(T znach) {
      if (last - first >= size) {
        throw std::string("Is full!!!");
      } else {
        int n = last - 1;
        while (n >= first && znach.prior > arr[n % size].prior) {
          arr[(n + 1) % size] = arr[n % size];
          n--;
        }
        arr[(n + 1) % size] = znach;
        last++;
      }
    }
    T pop() {
      if (first == last) {
         throw std::string("Is empty!!!");
      } else {
        return arr[(first++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
