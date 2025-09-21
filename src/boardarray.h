#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            if (index >= SIZE) {
            if (!entry->compare(&array[SIZE - 1])) {
            cout << entry->name << "'s score is too low to be added!" << endl;
            return;
            }
        }

            int insertPos = index;
            if (insertPos >= SIZE) insertPos = SIZE - 1;

            for (; insertPos > 0 && entry->compare(&array[insertPos - 1]); insertPos--) {
                array[insertPos] = array[insertPos - 1];
            }

            array[insertPos] = *entry;

            if (index < SIZE) {
            index++;
            }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};